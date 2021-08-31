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

#include "operators.h"
#include "db_framework.h"







// Operators




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
			tokenizer_rule(Keywords().SWITCH(), "switch"),
			tokenizer_rule(Keywords().CASE(), "case"),
			tokenizer_rule(Keywords().DEFAULT(), "default"),
			tokenizer_rule(Keywords().TRY(), "try"),
			tokenizer_rule(Keywords().CATCH(), "catch"),


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