#pragma once

#include <any>
#include <memory>
#include <vector>
#include <sstream>

#include "interpreter.h"
#include "environment.h"
#include "exceptions.h"

class callable :
	public std::enable_shared_from_this<callable>
{
public:
	callable(std::string szName)
		:m_szName{ szName }{}

	virtual std::any call(std::shared_ptr<interpreter> c, ::std::vector<std::any> arguments) = 0;


	virtual std::shared_ptr<callable> registerParameter(const param& p)
	{
		m_params.push_back(p);
		return shared_from_this();
	}

	virtual std::string getSignature() 
	{
		std::ostringstream oss;
		oss << m_szName << "(";

		if (m_params.size() >= 1) {
			oss << m_params.at(0).type;
		}

		for (unsigned int i{ 1 }; i < m_params.size(); i++) {
			oss << "," << m_params.at(i).type;
		}
		oss << ")";
		return oss.str();
	}

protected:
	std::string m_szName{ "" };
	std::vector<param> m_params;
};


typedef std::any(*func)(std::shared_ptr<interpreter>, std::vector<std::any>);

class native_fn :
	public callable {
public:
	native_fn(std::string szName, func fn)
		:callable(szName), m_hFn{ fn } {}
	~native_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args)
	{
		check_context(c);
		if (args.size() != m_params.size()) {
			throw ProgramException("parity_mismatch", "expected " + std::to_string(m_params.size())
				+ " arguments but got " + std::to_string(args.size()), location());
		}

		std::vector<::std::any> cleanedArgs;
		for (unsigned int i{ 0 }; i < m_params.size(); i++) {
			std::any arg = c->assert_or_convert_type(m_params.at(i).type, args.at(i), location());
			cleanedArgs.push_back(arg);
		}

		return m_hFn(c, cleanedArgs);
	}


private:
	func m_hFn;
};


class custom_fn :
	public callable {
public:
	custom_fn(std::string szName, std::shared_ptr<activation_record> ar, std::vector<std::shared_ptr<statement>> body, std::vector<param> parameters, const location& loc)
		:callable{ szName }, m_enclosing{ ar }, m_body{ body }, m_parameters{ parameters }, m_loc{ loc } {}
	~custom_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> arguments)
	{
		check_context(c);
		std::shared_ptr<execution_context> context = c->get_context();
		check_context(context);

		// Create closure
		context->push_ar(m_enclosing);
		context->push_ar(m_szName);

		try {
			
			// Check parity
			if (arguments.size() != m_parameters.size()) {
				throw ProgramException("parity_mismatch", "expected " + std::to_string(m_parameters.size())
					+ " arguments but got " + std::to_string(arguments.size()), m_loc);
			}

			// Clean arguments and define parameters in this scope
			for (unsigned int i{ 0 }; i < m_parameters.size(); i++) {
				std::any cleanedObject = c->assert_or_convert_type(m_parameters.at(i).type, arguments.at(i), m_loc);
				context->define(m_parameters.at(i).name, cleanedObject, false, m_loc);
			}

			// Execute function body
			c->interpret(m_body);
		}
		catch (ReturnException ret) {

			// Reset environment
			context->pop_ar();
			context->pop_ar();

			// Return value
			return ret.value();
		}
		catch (ProgramException pe) {

			// Reset environment
			context->pop_ar();
			context->pop_ar();

			// throw error
			throw pe;
		}
		//Reset Environment
		context->pop_ar();
		context->pop_ar();

		// If there are no errors and no return has been caught
		// just return null value
		return nullptr;
	}

private:
	std::shared_ptr<activation_record> m_enclosing;
	std::vector<std::shared_ptr<statement>> m_body;
	std::vector<param> m_parameters;
	location m_loc;
};


typedef std::any(*unary_func)(std::shared_ptr<interpreter>, std::any&);


class unary_fn :
	public callable {
public:
	unary_fn(std::string szName, unary_func fn)
		:callable(szName), m_hFn{ fn } {}
	~unary_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args)
	{
		check_context(c);
		if (args.size() != 1) {
			throw ProgramException("parity_mismatch", "expected 1 argument but got " + std::to_string(args.size()), location());
		}


		std::any cleanedArg = c->assert_or_convert_type(m_param.type, args.at(0), location());

		return m_hFn(c, cleanedArg);
	}


	std::shared_ptr<callable> registerParameter(const param& p)
	{
		m_param = p;
		return std::static_pointer_cast<callable>(shared_from_this());
	}

	virtual std::string getSignature()
	{
		std::ostringstream oss;
		oss << m_szName << "(" << m_param.type << ")";
		return oss.str();
	}


private:
	unary_func m_hFn;
	param m_param;
};



typedef std::any(*binary_func)(std::shared_ptr<interpreter>, std::any&, std::any&);

class binary_fn :
	public callable {
public:
	binary_fn(std::string szName, binary_func fn)
		:callable(szName), m_hFn{ fn } {}
	~binary_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args)
	{
		check_context(c);
		if (args.size() != m_params.size() || m_params.size() != 2) {
			throw ProgramException("parity_mismatch", "expected 2 arguments but got " + std::to_string(args.size()), location());
		}

		std::vector<std::any> cleanedArgs;
		for (unsigned int i{ 0 }; i < m_params.size(); i++) {
			std::any arg = c->assert_or_convert_type(m_params.at(i).type, args.at(i), location());
			cleanedArgs.push_back(arg);
		}

		return m_hFn(c, cleanedArgs.at(0), cleanedArgs.at(1));
	}


private:
	binary_func m_hFn;
};

