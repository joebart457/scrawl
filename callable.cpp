#include "callable.h"

#include <vector>
#include <sstream>
#include <string>

#include "context.h"
#include "interpreter.h"
#include "exceptions.h"


std::string callable::getSignature()
{
	std::ostringstream oss;
	oss << m_szName << "(";

	if (m_params.size() >= 1) {
		oss << (m_params.at(0).class_specifier.size() > 0? m_params.at(0).class_specifier : m_params.at(0).type);
	}

	for (unsigned int i{ 1 }; i < m_params.size(); i++) {
		oss << "," << (m_params.at(i).class_specifier.size() > 0? m_params.at(i).class_specifier : m_params.at(i).type);
	}
	oss << ")";
	return oss.str();
}



std::any native_fn::call(std::shared_ptr<interpreter> c, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(c);
	
	std::any ret = nullptr;
	context->push_ar(m_enclosing);

	try {
		std::vector<std::any> cleanedArgs;
		if (!m_variadic) {
			if (args.size() != m_params.size()) {
				throw ProgramException("parity_mismatch", "expected " + std::to_string(m_params.size())
					+ " arguments but got " + std::to_string(args.size()), location());
			}

			for (unsigned int i{ 0 }; i < m_params.size(); i++) {
				std::any arg = c->assert_or_convert_type(m_params.at(i), args.at(i), location());
				cleanedArgs.push_back(arg);
			}
		}
		else {

			if (args.size() < m_variadic_after) {
				throw ProgramException("parity_mismatch", "expected at least " + std::to_string(m_params.size())
					+ " arguments but got " + std::to_string(args.size()), location());
			}

			unsigned int i{ 0 };
			for (i; i < m_variadic_after; i++) {
				std::any arg = c->assert_or_convert_type(m_params.at(i), args.at(i), location());
				cleanedArgs.push_back(arg);
			}

			for (unsigned int j{ i }; j < args.size(); j++) {
				cleanedArgs.push_back(args.at(j));
			}

		}

		ret = m_hFn(c, _args(cleanedArgs));
	}
	catch (ReturnException ret) {
		// Reset environment
		context->pop_ar();
		
		throw ret;
	}
	catch (PanicException pe) {
		// Reset environment
		context->pop_ar();

		throw pe;
	}
	catch (ProgramException pe) {
		// Reset environment
		context->pop_ar();

		// throw error
		throw pe;
	}

	context->pop_ar();
	return ret;

}

void native_fn::setEnclosing(std::shared_ptr<activation_record> ar)
{
	m_enclosing = ar;
}

std::shared_ptr<native_fn> native_fn::setVariadic()
{
	m_variadic = true;
	return std::static_pointer_cast<native_fn>(shared_from_this());
}

std::shared_ptr<native_fn> native_fn::setVariadicAfter(unsigned int index)
{
	if (!m_variadic) throw ProgramException("cannot set variadic index of non-variadic function", location(), Severity().FATAL());
	if (index > m_params.size()) throw ProgramException("variadic index must be less than parameter size", location(), Severity().FATAL());
	m_variadic_after = index;
	return std::static_pointer_cast<native_fn>(shared_from_this());
}

std::shared_ptr<native_fn> native_fn::registerParameter(const param& p)
{
	m_params.push_back(p);
	return std::static_pointer_cast<native_fn>(shared_from_this());
}

std::any custom_fn::call(std::shared_ptr<interpreter> c, _args arguments)
{
	check_context(c);
	std::shared_ptr<execution_context> context = c->get_context();
	check_context(context);

	// Create closure
	context->push_ar(m_enclosing);
	context->push_ar(m_szName);

	try {

		// Check parity
		if (arguments.size() != m_params.size()) {
			throw ProgramException("parity_mismatch", "expected " + std::to_string(m_params.size())
				+ " arguments but got " + std::to_string(arguments.size()), m_loc);
		}

		// Clean arguments and define parameters in this scope
		for (unsigned int i{ 0 }; i < m_params.size(); i++) {
			std::any cleanedObject = c->assert_or_convert_type(m_params.at(i), arguments.at(i), m_loc);
			context->define(m_params.at(i).name, cleanedObject, false, m_loc);
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
	catch (PanicException pe) {

		// Reset environment
		context->pop_ar();
		context->pop_ar();

		// Return value
		throw pe;
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


void custom_fn::setEnclosing(std::shared_ptr<activation_record> ar)
{
	m_enclosing = ar;
}


std::any unary_fn::call(std::shared_ptr<interpreter> c, _args args)
{
	check_context(c);
	if (args.size() != 1) {
		throw ProgramException("parity_mismatch", "expected 1 argument but got " + std::to_string(args.size()), location());
	}


	std::any cleanedArg = c->assert_or_convert_type(m_param, args.at(0), location());

	return m_hFn(c, cleanedArg);
}


std::shared_ptr<callable> unary_fn::registerParameter(const param& p)
{
	m_param = p;
	return std::static_pointer_cast<callable>(shared_from_this());
}

std::string unary_fn::getSignature()
{
	std::ostringstream oss;
	oss << m_szName << "(" << m_param.type << ")";
	return oss.str();
}


std::any binary_fn::call(std::shared_ptr<interpreter> c,  _args args)
{
	check_context(c);
	if (args.size() != m_params.size() || m_params.size() != 2) {
		throw ProgramException("parity_mismatch", "expected 2 arguments but got " + std::to_string(args.size()), location());
	}

	std::vector<std::any> cleanedArgs;
	for (unsigned int i{ 0 }; i < m_params.size(); i++) {
		std::any arg = c->assert_or_convert_type(m_params.at(i), args.at(i), location());
		cleanedArgs.push_back(arg);
	}

	return m_hFn(c, cleanedArgs.at(0), cleanedArgs.at(1));
}


std::shared_ptr<binary_fn> binary_fn::registerParameter(const param& p)
{
	m_params.push_back(p);
	return std::static_pointer_cast<binary_fn>(shared_from_this());
}