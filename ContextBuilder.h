#pragma once

#ifndef __INCLUDE_CONTEXT_BUILDER_H
#define __INCLUDE_CONTEXT_BUILDER_H

#include <memory>
#include <any>
#include <iostream>
#include <sstream>

#include "db_helper.h"
#include "interpreter.h"
#include "environment.h"
#include "OperatorHandler.h"
#include "Keywords.h"
#include "context.h"
#include "tokenizer.hpp"
#include "klass_instance.h"


#include "db_framework.h"


// DB Methods
std::any db_table_create(std::shared_ptr<interpreter> i, _args args)
{
	db_table table("company", {
		db_column("id", SQLITE_INTEGER)
			.PRIMARY_KEY()
			.NOT_NULL()
			.AUTOINCREMENT(),
		db_column("name")
			.NOT_NULL(),
		db_column("country_id", SQLITE_INTEGER)
			.FOREIGN_KEY("country(id)"),
		db_column("random_column").UNIQUE()
		});
	return table.get_creation_query();
}


std::any db_open(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");
	db->open(args.get<std::string>(0));
	return nullptr;
}


std::any db_get(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");

	std::vector<std::any> results = db->get(args.get<std::string>(0));

	std::shared_ptr<klass_definition> ls = context->get<std::shared_ptr<klass_definition>>("list");
	klass_instance results_container = ls->create();
	std::any_cast<std::shared_ptr<native_fn>>(results_container.Get("constructor", location()))->call(i, _args(results));
	return results_container;
}


std::any db_run_prepared_query(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");
	
	std::vector<std::any> results = db->run_prepared(
		std::any_cast<std::string>(args.at(0)),
		args.subset(2, 0), 
		args.get<std::shared_ptr<klass_definition>>(1),
		false);

	std::shared_ptr<klass_definition> ls = context->get<std::shared_ptr<klass_definition>>("list");
	klass_instance results_container = ls->create();
	std::any_cast<std::shared_ptr<native_fn>>(results_container.Get("constructor", location()))->call(i, _args(results));
	return results_container;
}


// List methods
std::any list_push(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	unsigned long size = context->get<unsigned long>("size");

	context->define(std::to_string(size), args.at(0), false, location());
	context->assign("size", ((unsigned long)size + 1), location());

	return nullptr;
}


std::any list_constructor(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	for (unsigned int i{ 0 }; i < args.size(); i++) {
		context->define(std::to_string(i), args.at(i), false, location());
	}
	context->assign("size", (unsigned long)args.size(), location());

	return nullptr;
}


// Operators


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
		oss << (std::any_cast<std::shared_ptr<binary_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<binary_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<custom_fn>)) {
		oss << (std::any_cast<std::shared_ptr<custom_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<custom_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<unary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<unary_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<callable>)) {
		oss << (std::any_cast<std::shared_ptr<callable>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<klass_definition>)) {
		oss << (std::any_cast<std::shared_ptr<klass_definition>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<klass_definition>>(rhs)->toString());
	}
	else if (rhs.type() == typeid(klass_instance)) {
		oss << std::any_cast<klass_instance>(rhs).toString();
	}
	else {
		oss << "<object>";
	}
	return oss.str();
}


// stdlib
std::any print(std::shared_ptr<interpreter> i, _args args)
{
	for (unsigned int j{ 0 }; j < args.size(); j++) {
		std::cout << std::any_cast<std::string>(::to_string(i, args.at(j)));
	}
	return nullptr;
}

std::any print_environment(std::shared_ptr<interpreter> i, _args args)
{
	fetch_context(i)->output();
	return nullptr;
}


class ContextBuilder
{
public:
	static std::shared_ptr<scope<std::any>> BuildDefaultScope()
	{
		std::shared_ptr<scope<std::any>> e = std::make_shared<scope<std::any>>("default");
		e->define("to_string", 
			std::make_shared<unary_fn>("to_string", to_string)
				->registerParameter(BuildParameter("")), 
			true);

		e->define("print", 
			std::make_shared<native_fn>("print", print)
				->registerParameter(BuildParameter("")), 
			true);
		e->define("e",
			std::make_shared<native_fn>("e", print_environment),
			true);

		e->define("typeof",
			std::make_shared<unary_fn>("typeof", type_of_any)
			->registerParameter(BuildParameter("")),
			true);


		std::shared_ptr<activation_record> list_env_ar = std::make_shared<activation_record>();
		list_env_ar->szAlias = "list";
		list_env_ar->environment = std::make_shared<scope<std::any>>();
		list_env_ar->environment->define("push",
			std::make_shared<native_fn>("push", list_push, list_env_ar)->registerParameter(BuildParameter("")));

		list_env_ar->environment->define("constructor",
			std::make_shared<native_fn>("constructor", list_constructor, list_env_ar)->setVariadic());

		list_env_ar->environment->define("size",
			(unsigned long)0);

		e->define("list",
			std::make_shared<klass_definition>("list", list_env_ar),
			true);


		std::shared_ptr<activation_record> db_env_ar = std::make_shared<activation_record>();
		db_env_ar->szAlias = "db";
		db_env_ar->environment = std::make_shared<scope<std::any>>();
		db_env_ar->environment->define("open",
			std::make_shared<native_fn>("open", db_open, db_env_ar)->registerParameter(BuildParameter<std::string>()), true);

		db_env_ar->environment->define("run_prepared",
			std::make_shared<native_fn>("run_prepared", db_run_prepared_query, db_env_ar)
			->registerParameter(BuildParameter<std::string>())
			->registerParameter(BuildParameter<std::shared_ptr<klass_definition>>())
			->setVariadic()
			->setVariadicAfter(2), 
			true
		);


		std::shared_ptr<activation_record> db_env_dbtypes_ar = std::make_shared<activation_record>();
		db_env_dbtypes_ar->szAlias = "dbTypes";
		db_env_dbtypes_ar->environment = std::make_shared<scope<std::any>>();

		db_env_dbtypes_ar->environment->define("INTEGER", std::string("INTEGER"), true);
		db_env_dbtypes_ar->environment->define("REAL", std::string("REAL"), true);
		db_env_dbtypes_ar->environment->define("TEXT", std::string("TEXT"), true);

		db_env_ar->environment->define("Types",
			std::make_shared<klass_definition>("Types", db_env_dbtypes_ar), true);

		db_env_ar->environment->define("db",
			std::make_shared<db_helper>(),
			true);
		db_env_ar->environment->define("table_example",
			std::make_shared<native_fn>("table_example", db_table_create),
			true);


		e->define("Database", 
			std::make_shared<klass_definition>("Database", db_env_ar),
			true);

		return e;
	}

	static std::shared_ptr<interpreter> BuildInterpreter()
	{
		return std::make_shared<interpreter>(BuildExecutionContext(), BuildOperatorHandler());
	}

	static std::shared_ptr<execution_context> BuildExecutionContext() 
	{
		std::shared_ptr<activation_record> default_ar = std::make_shared<activation_record>();
		default_ar->id = 0;
		default_ar->environment = BuildDefaultScope();
		return std::make_shared<execution_context>(default_ar);
	}

	static std::shared_ptr<OperatorHandler> BuildOperatorHandler()
	{
		std::shared_ptr<OperatorHandler> opHandler = std::make_shared<OperatorHandler>();
		opHandler->registerOperator(
			std::make_shared<binary_fn>("+", add_int_int)
			->registerParameter(BuildParameter<int>())
			->registerParameter(BuildParameter<int>())
		);

		opHandler->registerOperator(
			std::make_shared<binary_fn>("<", less_than_int_int)
			->registerParameter(BuildParameter<int>())
			->registerParameter(BuildParameter<int>())
		);

		opHandler->registerOperator(
			std::make_shared<binary_fn>("<", less_than_int_int)
			->registerParameter(BuildParameter<int>())
			->registerParameter(BuildParameter<int>())
		);

		opHandler->registerOperator(
			std::make_shared<binary_fn>("[", index_list_int)
			->registerParameter(BuildParameter<klass_definition>("", "list"))
			->registerParameter(BuildParameter<int>())
		);

		opHandler->registerOperator(
			std::make_shared<binary_fn>("[", index_list_unsigned_long)
			->registerParameter(BuildParameter<klass_definition>("", "list"))
			->registerParameter(BuildParameter<unsigned long>())
		);
		opHandler->registerOperator(
			std::make_shared<binary_fn>("[", index_list_string)
			->registerParameter(BuildParameter<klass_definition>("", "list"))
			->registerParameter(BuildParameter<std::string>())
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
			tokenizer_rule(Keywords().BREAK(), "break"),


			/* types */
			tokenizer_rule(Keywords().UINT(), "uint", std::make_shared<std::string>(typeid(unsigned long).name())),
			tokenizer_rule(Keywords().INT(), "int", std::make_shared<std::string>(typeid(int).name())),
			tokenizer_rule(Keywords().FLOAT(), "float", std::make_shared<std::string>(typeid(float).name())),
			tokenizer_rule(Keywords().DOUBLE(), "double", std::make_shared<std::string>(typeid(double).name())),
			tokenizer_rule(Keywords().CHAR(), "char", std::make_shared<std::string>(typeid(char).name())),
			tokenizer_rule(Keywords().STRING(), "string", std::make_shared<std::string>(typeid(std::string).name())),
			tokenizer_rule(TOKEN_TYPE_WORD, "_ty", std::make_shared<std::string>("")),
			
			
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
	static param BuildParameter(std::string szName = "", std::string class_specifier = "") {
		param p;
		p.name = szName;
		p.type = typeid(Ty).name();
		p.class_specifier = class_specifier;
		return p;
	}
};

#endif