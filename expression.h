#pragma once

#include <string>
#include <vector>
#include <any>
#include <memory>

#include "location.h"

class interpreter;

class expression :
	public std::enable_shared_from_this<expression>
{
public:
	expression(const std::string& szRepr, const location& loc)
		:m_loc{ loc }, m_szRepr{ szRepr }{}
	~expression() {}

	virtual std::any visit(std::shared_ptr<interpreter> i);

	virtual std::string getType() { return m_szRepr; }
	virtual location getLocation() { return m_loc; }

protected:
	location m_loc;
	std::string m_szRepr{ "expression" };
};


class assignment :
	public expression {
	friend class interpreter;
public:
	assignment(
		std::shared_ptr<expression> lhs, // parent object <nullable>
		std::string name,					  // name of assignment target variable
		std::shared_ptr<expression> val, // value to assign 
		const location& loc
	)
		: expression("assignment", loc), lhs{ lhs }, name{ name }, val{ val }{}
	~assignment() {}

	virtual std::any visit(std::shared_ptr<interpreter> i);

protected:
	std::shared_ptr<expression> lhs{ nullptr };
	std::string name;
	std::shared_ptr<expression> val{ nullptr };
};


class logic_or :
	public expression {
	friend class interpreter;
public:
	logic_or(
		std::shared_ptr<expression> lhs, // left hand side
		std::shared_ptr<expression> rhs, // right hand side
		const location& loc
	)
		:expression("logic_or", loc), lhs{ lhs }, rhs{ rhs }{}
	~logic_or() {}

	virtual std::any visit(std::shared_ptr<interpreter> c);

protected:
	std::shared_ptr<expression> lhs{ nullptr };
	std::shared_ptr<expression> rhs{ nullptr };
};


class logic_and :
	public expression {
	friend class interpreter;
public:
	logic_and(
		std::shared_ptr<expression> lhs, // left hand side
		std::shared_ptr<expression> rhs, // right hand side
		const location& loc
	)
		:expression("logic_and", loc), lhs{ lhs }, rhs{ rhs }{}
	~logic_and() {}


	virtual std::any visit(std::shared_ptr<interpreter> c);


protected:
	std::shared_ptr<expression> lhs{ nullptr };
	std::shared_ptr<expression> rhs{ nullptr };
};



class binary :
	public expression {
	friend class interpreter;
public:
	binary(
		std::shared_ptr<expression> lhs,	  // left hand side
		std::string op,						  // operation to perform ie "*" or "/"
		std::shared_ptr<expression> rhs,	  // right hand side
		const location& loc
	)
		:expression("binary", loc), lhs{ lhs }, op{ op }, rhs{ rhs }{}
	~binary() {}


	virtual std::any visit(std::shared_ptr<interpreter> c);

protected:
	std::shared_ptr<expression> lhs;
	std::string op;
	std::shared_ptr<expression> rhs;
};



class unary :
	public expression {
	friend class interpreter;
public:
	unary(
		std::string op,						  // operation to perform ie "-" or "!"
		std::shared_ptr<expression> rhs,	  // right hand side
		const location& loc
	)
		:expression("unary", loc), op{ op }, rhs{ rhs }{}
	~unary() {}


	virtual std::any visit(std::shared_ptr<interpreter> c);

protected:
	std::string op;
	std::shared_ptr<expression> rhs;
};


class call :
	public expression {
	friend class interpreter;
public:
	call(
		std::shared_ptr<expression> lhs,							// left hand side
		std::vector<std::shared_ptr<expression>> arguments,			// arguments list
		const location& loc
	)
		:expression("call", loc), lhs{ lhs }, arguments{ arguments }{}
	~call() {}

	virtual std::any visit(std::shared_ptr<interpreter> i);

protected:
	std::shared_ptr<expression> lhs;
	std::vector<std::shared_ptr<expression>> arguments;
};



class get :
	public expression {
	friend class parser;
	friend class interpreter;
public:
	get(
		std::shared_ptr<expression> lhs, // left hand side
		std::string identifier,				  // name of variable to retrieve
		const location& loc
	)
		:expression("get", loc), lhs{ lhs }, identifier{ identifier }{}
	~get() {}


	virtual std::any visit(std::shared_ptr<interpreter> i);

protected:
	std::shared_ptr<expression> lhs;
	std::string identifier;
};



class group :
	public expression {
	friend class interpreter;
public:
	group(
		std::shared_ptr<expression> expr, // expression to evaluate
		const location& loc
	)
		:expression("group", loc), m_expr{ expr }{}
	~group() {}

	virtual std::any visit(std::shared_ptr<interpreter> c);

protected:
	std::shared_ptr<expression> m_expr;
};


class expr_identifier :
	public expression {
	friend class parser;
	friend class interpreter;
public:
	expr_identifier(
		std::string name,					  // name of identifier
		const location& loc
	)
		:expression("identifier", loc), name{ name }{}
	~expr_identifier() {}

	virtual std::any visit(std::shared_ptr<interpreter> c);

protected:
	std::string name;
};



class primary :
	public expression {
	friend class interpreter;
public:
	primary(
		std::any data,							  // Object
		const location& loc
	)
		:expression("primary", loc), data{ data }{}
	~primary() {}


	virtual std::any visit(std::shared_ptr<interpreter> i);


protected:
	std::any data;
};


class cast :
	public expression {
	friend class interpreter;
public:
	cast(
		std::shared_ptr<expression> lhs,						// left hand side
		std::string op,												// operation to execute
		std::string szTypeName,										// type to cast to
		const location& loc											// location of expr
	)
		:expression("cast", loc), lhs{ lhs }, op{ op }, szTypeName{ szTypeName }{}
	~cast() {}

	virtual std::any visit(std::shared_ptr<interpreter> i);


protected:
	std::shared_ptr<expression> lhs;
	std::string op;
	std::string szTypeName;
};


class initializer :
	public expression {
	friend class parser;
	friend class interpreter;
public:
	initializer(
		std::string szTypeName,											// typename to initialize
		std::vector<std::shared_ptr<expression>> arguments,		// arguments to pass to constructor
		const location& loc											// location of expression
	)
		:expression("intializer", loc), szTypeName{ szTypeName }, arguments{ arguments }{}
	~initializer() {}


	virtual std::any visit(std::shared_ptr<interpreter> i);


protected:
	std::string szTypeName;
	std::vector<std::shared_ptr<expression>> arguments;
};


class list_initializer :
	public expression {
	friend class interpreter;
public:
	list_initializer(
		std::vector<std::shared_ptr<expression>> elements, // list of elements to initialize
		const location& loc									// location of expression
	)
		:expression("list_initializer", loc), elements{ elements }{}
	~list_initializer() {}

	virtual std::any visit(std::shared_ptr<interpreter> i);

protected:
	std::vector<std::shared_ptr<expression>> elements;
};