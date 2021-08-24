#pragma once

#ifndef __INCLUDE_CONTEXT_BUILDER_H
#define __INCLUDE_CONTEXT_BUILDER_H

#include <memory>
#include <any>
#include <iostream>
#include <sstream>

#include "interpreter.h"
#include "environment.h"
#include "OperatorHandler.h"
#include "Keywords.h"

#include "tokenizer.hpp"

std::any add_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs) 
{
	return std::any_cast<int>(lhs) + std::any_cast<int>(rhs);
}


std::any type_of_any(std::shared_ptr<interpreter> i, std::any& rhs) 
{
	return std::string(rhs.type().name());
}

std::any to_string(std::shared_ptr<interpreter> i, std::any& rhs)
{
	std::ostringstream oss;
	if (rhs.type() == typeid(int)) {
		oss << std::any_cast<int>(rhs);
	}
	else if (rhs.type() == typeid(bool)) {
		oss << std::any_cast<bool>(rhs);
	}
	else if (rhs.type() == typeid(float)) {
		oss << std::any_cast<float>(rhs);
	}
	else if (rhs.type() == typeid(double)) {
		oss << std::any_cast<double>(rhs);
	}
	else if (rhs.type() == typeid(unsigned long)) {
		oss << std::any_cast<unsigned long>(rhs);
	}
	else if (rhs.type() == typeid(std::string)) {
		oss << std::any_cast<std::string>(rhs);
	}
	// TODO: do this better
	else if (rhs.type() == typeid(std::shared_ptr<native_fn>)) {
		oss << (std::any_cast<std::shared_ptr<native_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<native_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<binary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<binary>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<binary_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<unary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<unary_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<callable>)) {
		oss << (std::any_cast<std::shared_ptr<callable>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(rhs)->getSignature());
	}


	else {
		oss << "<object>";
	}
	return oss.str();
}

std::any print(std::shared_ptr<interpreter> i, std::vector<std::any> args)
{
	for (auto arg : args) {
		std::cout << std::any_cast<std::string>(to_string(i, arg));
	}
	return nullptr;
}

std::any print_environment(std::shared_ptr<interpreter> i, std::vector<std::any> args)
{
	check_context(i);
	std::cout << i->getEnvironment()->toString();
	return nullptr;
}

class ContextBuilder
{
public:
	static std::shared_ptr<Environment> BuildEnvironment()
	{
		std::shared_ptr<Environment> e = std::make_shared<Environment>(nullptr);
		e->Define("to_string", 
			std::make_shared<unary_fn>("to_string", to_string)
				->registerParameter(BuildParameter("")), 
			location(), false);

		e->Define("print", 
			std::make_shared<native_fn>("print", print)
				->registerParameter(BuildParameter("")), 
			location(), false);
		e->Define("e",
			std::make_shared<native_fn>("e", print_environment),
			location(), false);

		e->Define("typeof",
			std::make_shared<unary_fn>("typeof", type_of_any)
			->registerParameter(BuildParameter("")),
			location(), false);

		return e;
	}

	static std::shared_ptr<interpreter> BuildInterpreter()
	{
		return std::make_shared<interpreter>(BuildEnvironment(), BuildOperatorHandler());
	}

	static std::shared_ptr<OperatorHandler> BuildOperatorHandler()
	{
		std::shared_ptr<OperatorHandler> opHandler = std::make_shared<OperatorHandler>();
		opHandler->registerOperator(
			std::make_shared<binary_fn>("+", add_int_int)
			->registerParameter(BuildParameter<int>())
			->registerParameter(BuildParameter<int>())
		);
		

		return opHandler;
	}

	static std::shared_ptr<tokenizer> BuildTokenizer()
	{
		const std::vector<tokenizer_rule> rules = {
			tokenizer_rule(Keywords().AND(), "&&"),
			tokenizer_rule(Keywords().OR(), "||"),
			tokenizer_rule(Keywords().TYPEOF(), "|"),
			tokenizer_rule(Keywords().CAST(), "->"),
			tokenizer_rule(Keywords().LPAREN(), "("),
			tokenizer_rule(Keywords().RPAREN(), ")"),
			tokenizer_rule(Keywords().LCURLY(), "{"),
			tokenizer_rule(Keywords().RCURLY(), "}"),
			tokenizer_rule(Keywords().LBRACKET(), "["),
			tokenizer_rule(Keywords().RBRACKET(), "]"),
			tokenizer_rule(Keywords().COMMA(), ","),
			tokenizer_rule(Keywords().SEMI(), ";"),
			tokenizer_rule(Keywords().DOT(), "."),
			tokenizer_rule(Keywords().EQUAL(), "="),
			tokenizer_rule(Keywords().EQUALEQUAL(), "=="),
			tokenizer_rule(Keywords().BANGEQUAL(), "!="),
			tokenizer_rule(Keywords().BANG(), "!"),
			tokenizer_rule(Keywords().SUBTRACT(), "-"),
			tokenizer_rule(Keywords().LESSTHAN(), "<"),
			tokenizer_rule(Keywords().LESSTHANEQUAL(), "<="),
			tokenizer_rule(Keywords().GREATERTHAN(), ">"),
			tokenizer_rule(Keywords().GREATERTHANEQUAL(), ">="),
			tokenizer_rule(Keywords().ADD(), "+"),
			tokenizer_rule(Keywords().ASTERISK(), "*"),
			tokenizer_rule(Keywords().BACKSLASH(), "/"),
			tokenizer_rule(Keywords().IF(), "if"),
			tokenizer_rule(Keywords().ELSE(), "else"),
			tokenizer_rule(Keywords().WHILE(), "while"),
			tokenizer_rule(Keywords().RETURN(), "return"),
			tokenizer_rule(Keywords().FUNCTION(), "function"),
			tokenizer_rule(Keywords().CLASS(), "class"),
			tokenizer_rule(Keywords().TRUE(), "true"),
			tokenizer_rule(Keywords().FALSE(), "false"),
			tokenizer_rule(Keywords().NUL(), "null"),

			/* types */
			tokenizer_rule(Keywords().UINT(), "uint", std::make_shared<std::string>(typeid(unsigned long).name())),
			tokenizer_rule(Keywords().INT(), "int", std::make_shared<std::string>(typeid(int).name())),
			tokenizer_rule(Keywords().FLOAT(), "float", std::make_shared<std::string>(typeid(float).name())),
			tokenizer_rule(Keywords().DOUBLE(), "double", std::make_shared<std::string>(typeid(double).name())),
			tokenizer_rule(Keywords().CHAR(), "char", std::make_shared<std::string>(typeid(char).name())),
			tokenizer_rule(Keywords().STRING(), "string", std::make_shared<std::string>(typeid(std::string).name())),
			tokenizer_rule(Keywords().IGNORE(), "ignore"),
			
			
			tokenizer_rule(Keywords().NEW(), "new"),
			tokenizer_rule(TOKEN_TYPE_EOL_COMMENT, "//"),
			tokenizer_rule(TOKEN_TYPE_STRING_ENCLOSING, "\""),
			tokenizer_rule(Keywords().IMPORT(), "import"),
			tokenizer_rule(Keywords().DIRECTIVE(), "@"),
			tokenizer_rule(Keywords().UPCARAT(), "^")
		};
		return std::make_shared<tokenizer>(rules);
	}

private:
	static param BuildParameter(std::string szType, std::string szName = "") {
		param p;
		p.name = szName;
		p.type = szType;
		return p;
	}

	template <typename Ty>
	static param BuildParameter(std::string szName = "") {
		param p;
		p.name = szName;
		p.type = typeid(Ty).name();
		return p;
	}
};

#endif