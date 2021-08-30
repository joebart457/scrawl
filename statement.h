#pragma once

#include <string>
#include <memory>
#include <vector>

#include "location.h"



class interpreter;
class expression;
class block;

class statement:
	public std::enable_shared_from_this<statement>
{
public:
	statement(const std::string& szType, const location& loc)
		:m_szType{ szType }, m_loc{ loc }{}
	~statement(){}

	virtual void accept(std::shared_ptr<interpreter> i) = 0;
	virtual std::string getType() { return m_szType; }
	virtual location getLocation() { return m_loc; }

protected:
	std::string m_szType{ "" };
	location m_loc;
};

struct param
{
	std::string name;
	std::string type;
	std::string class_specifier;
	std::shared_ptr<expression> default_value{ nullptr };
};

class class_declaration :
	public statement {
	friend class interpreter;
public:
	class_declaration(
		std::string szName,							// name of class
		std::shared_ptr<block> body,				// class defintion
		const location& loc							// location of statement
	): statement("class_declaration", loc), m_szName{ szName }, m_body{ body } {}

	~class_declaration(){}

	virtual void accept(std::shared_ptr<interpreter> i);

protected:
	std::string m_szName;
	std::shared_ptr<block> m_body;
};


class function_declaration :
	public statement {
	friend class interpreter;
public:
	function_declaration(
		std::string szName,							// name of function
		std::vector<param> params,					// list of parameters
		std::shared_ptr<block> body,				// block of code to execute
		const location& loc							// location of statement
	) : statement("function_declaration", loc), m_szName{ szName }, m_params{ params }, m_body{ body } {}

	~function_declaration()
	{
		m_params.clear();
	}

	virtual void accept(std::shared_ptr<interpreter> i);

protected:
	std::string m_szName;
	std::vector<param> m_params;
	std::shared_ptr<block> m_body;
};


class variable_declaration :
	public statement {
	friend class interpreter;
public:
	variable_declaration(const std::string& szTypename, const std::string szName, std::shared_ptr<expression> value, const location& loc)
		:statement("variable_declaration", loc), m_szTypename{ szTypename }, m_szName{ szName }, m_value{ value }{}
	~variable_declaration(){}

	virtual void accept(std::shared_ptr<interpreter> i);

private:
	std::string m_szTypename{ "" };
	std::string m_szName{ "" };
	std::shared_ptr<expression> m_value{ nullptr };
};


class import_statement :
	public statement {
	friend class interpreter;
public:
	import_statement(std::shared_ptr<expression> expr, const location& loc)
		:statement("import_statement", loc), m_expr{ expr } {}
	~import_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
private:
	std::shared_ptr<expression> m_expr{ nullptr };
};


class return_statement :
	public statement {
	friend class interpreter;
public:
	return_statement(std::shared_ptr<expression> expr, const location& loc)
		:statement("return_statement", loc), m_expr{ expr } {}
	~return_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
private:
	std::shared_ptr<expression> m_expr{ nullptr };
};


class if_statement :
	public statement {
	friend class interpreter;
public:
	if_statement(std::shared_ptr<expression> condition, std::shared_ptr<statement> then, std::shared_ptr<statement> elsethen, const location& loc)
		:statement("if_statement", loc), m_condition{ condition }, m_then{ then }, m_elsethen{ elsethen }{}
	~if_statement(){}

	virtual void accept(std::shared_ptr<interpreter> i);

private:
	std::shared_ptr<expression> m_condition{ nullptr };
	std::shared_ptr<statement> m_then{ nullptr };
	std::shared_ptr<statement> m_elsethen{ nullptr };
};


class while_statement :
	public statement {
	friend class interpreter;
public:
	while_statement(std::shared_ptr<expression> condition, std::shared_ptr<statement> then, const location& loc)
		:statement("while_statement", loc), m_condition{ condition }, m_then{ then }{}
	~while_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);

private:
	std::shared_ptr<expression> m_condition{ nullptr };
	std::shared_ptr<statement> m_then{ nullptr };
};


class break_statement :
	public statement {
	friend class interpreter;
public:
	break_statement(const location& loc)
		:statement("break_statement", loc){}
	~break_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
};

class directive_statement :
	public statement {
	friend class interpreter;
public:
	directive_statement(std::string szDirective, const location& loc)
		:statement("directive_statement", loc), m_szDirective{ szDirective } {}
	~directive_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
private:
	std::string m_szDirective{ "" };
};


class block :
	public statement {
	friend class interpreter;
public:
	block(std::vector<std::shared_ptr<statement>> statements, const location& loc)
		:statement("block", loc), m_statements{ statements }{}
	~block() {}

	virtual void accept(std::shared_ptr<interpreter> i);

private:
	std::vector<std::shared_ptr<statement>> m_statements;
};


class expression_statement :
	public statement {
	friend class interpreter;
public:
	expression_statement(std::shared_ptr<expression> expr, const location& loc)
		:statement("expression_statement", loc), m_expr{ expr } {}
	~expression_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
private:
	std::shared_ptr<expression> m_expr{ nullptr };
};

struct switch_case {
	std::vector<std::shared_ptr<expression>> cases;
	std::shared_ptr<statement> then;
	bool isDefault = false;
};


class switch_statement :
	public statement {
	friend class interpreter;
public:
	switch_statement(std::shared_ptr<expression> expr,
		std::vector<switch_case> cases,
		const location& loc)
		:statement("switch_statement", loc), m_testValue{ expr }, m_cases{ cases } {}
	~switch_statement() {}

	virtual void accept(std::shared_ptr<interpreter> i);
private:
	std::shared_ptr<expression> m_testValue{ nullptr };
	std::vector<switch_case> m_cases;
};
