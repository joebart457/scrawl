#pragma once

#ifndef __INCLUDE_CALLABLE_H
#define __INCLUDE_CALLABLE_H


#include <any>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "statement.h"

class interpreter;
struct activation_record;

class callable :
	public std::enable_shared_from_this<callable>
{
public:
	callable(std::string szName)
		:m_szName{ szName }{}
	callable(std::string szName, std::vector<param> params)
		:m_szName{ szName }, m_params{ params } {}

	virtual std::any call(std::shared_ptr<interpreter> c, ::std::vector<std::any> arguments) = 0;

	virtual std::string getSignature();

protected:
	std::string m_szName{ "" };
	std::vector<param> m_params;
};


typedef std::any(*func)(std::shared_ptr<interpreter>, std::vector<std::any>);

class native_fn :
	public callable {
public:
	native_fn(std::string szName, func fn, std::shared_ptr<activation_record> enclosing = nullptr)
		:callable(szName), m_hFn{ fn }, m_enclosing{ enclosing } {}
	native_fn(native_fn& fn)
		:callable(fn.m_szName, fn.m_params), m_hFn{ fn.m_hFn }, m_enclosing{ fn.m_enclosing }, m_variadic{ fn.m_variadic }, m_variadic_after{ fn.m_variadic_after } {}
	~native_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args);

	void setEnclosing(std::shared_ptr<activation_record> ar);
	std::shared_ptr<native_fn> setVariadic();
	std::shared_ptr<native_fn> setVariadicAfter(unsigned int index);

	std::shared_ptr<native_fn> registerParameter(const param& p);

private:
	func m_hFn;
	std::shared_ptr<activation_record> m_enclosing{ nullptr };
	bool m_variadic{ false };
	unsigned int m_variadic_after{ 0 };
};


class custom_fn :
	public callable {
public:
	custom_fn(std::string szName, std::shared_ptr<activation_record> ar, std::vector<std::shared_ptr<statement>> body, std::vector<param> parameters, const location& loc)
		:callable{ szName, parameters }, m_enclosing{ ar }, m_body{ body }, m_loc{ loc } {}
	custom_fn(custom_fn& fn)
		:callable{ fn.m_szName, fn.m_params }, m_enclosing{ fn.m_enclosing }, m_body{ fn.m_body }, m_loc{ fn.m_loc }{}

	~custom_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> arguments);

	void setEnclosing(std::shared_ptr<activation_record> ar);
private:
	std::shared_ptr<activation_record> m_enclosing;
	std::vector<std::shared_ptr<statement>> m_body;
	location m_loc;
};


typedef std::any(*unary_func)(std::shared_ptr<interpreter>, std::any&);


class unary_fn :
	public callable {
public:
	unary_fn(std::string szName, unary_func fn)
		:callable(szName), m_hFn{ fn } {}
	~unary_fn() {}

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args);


	std::shared_ptr<callable> registerParameter(const param& p);

	virtual std::string getSignature();


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

	std::any call(std::shared_ptr<interpreter> c, std::vector<std::any> args);

	std::shared_ptr<binary_fn> registerParameter(const param& p);

private:
	binary_func m_hFn;
};



#endif