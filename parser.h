#pragma once

#include <vector>

#include "parser_interface.hpp"
#include "statement.h"
#include "expression.h"
#include "exceptions.h"
#include "Keywords.h"



class parser
{
public:
	parser() {}
	~parser() {}

	std::vector<std::shared_ptr<statement>> parse(std::vector<token> toks)
	{

		m_pi.init(toks);

		std::vector<std::shared_ptr<statement>> stmts;
		while (!m_pi.atEnd() && !m_pi.match(TOKEN_TYPE_EOF)) {
			stmts.push_back(parse_all());
		}
		return stmts;
	}

	std::vector<std::shared_ptr<statement>> parse_toplevel(std::vector<token> toks)
	{

		m_pi.init(toks);

		std::vector<std::shared_ptr<statement>> stmts;
		while (!m_pi.atEnd() && !m_pi.match(TOKEN_TYPE_EOF)) {
			stmts.push_back(parse_declarations());
		}
		return stmts;
	}


	std::shared_ptr<statement> parse_declarations() {
		if (m_pi.match(Keywords().FUNCTION())) {
			return parse_function_declaration();
		}

		if (m_pi.match(Keywords().CLASS())) {
			return parse_class_declaration();
		}

		if (match_variable_declaration()) {
			return parse_variable_declaration();
		}

		throw ParsingException("unrecognized token in toplevel: " + m_pi.current().toStr() + "; expect declaration only in toplevel",  m_pi.current().loc());
	}

	std::shared_ptr<statement> parse_all()
	{
		if (m_pi.match(Keywords().DIRECTIVE())) {
			return parse_directive();
		}

		if (m_pi.match(Keywords().IMPORT())) {
			return parse_import();
		}

		if (m_pi.match(Keywords().FUNCTION())) {
			return parse_function_declaration();
		}

		if (m_pi.match(Keywords().CLASS())) {
			return parse_class_declaration();
		}

		if (match_variable_declaration()) {
			return parse_variable_declaration();
		}

		if (m_pi.match(Keywords().IF())) {
			return parse_if();
		}
		if (m_pi.match(Keywords().SWITCH())) {
			return parse_switch();
		}
		if (m_pi.match(Keywords().WHILE())) {
			return parse_while();
		}
		if (m_pi.match(Keywords().RETURN())) {
			return parse_return();
		}
		if (m_pi.match(Keywords().BREAK())) {
			token tok = m_pi.previous();
			m_pi.consume(Keywords().SEMI(), "expect ';' after 'break'");
			return std::make_shared<break_statement>(tok.loc());
		}
		if (m_pi.match(Keywords().RUN())) {
			return parse_run_recover();
		}
		if (m_pi.match(Keywords().PANIC())) {
			return parse_panic();
		}
		if (m_pi.match(Keywords().LCURLY())) {
			return parse_block();
		}

		return parse_expression_stmt();
	}


	std::shared_ptr<statement> parse_statement()
	{
		if (m_pi.match(Keywords().IF())) {
			return parse_if();
		}
		if (m_pi.match(Keywords().WHILE())) {
			return parse_while();
		}
		if (m_pi.match(Keywords().RETURN())) {
			return parse_return();
		}
		if (m_pi.match(Keywords().BREAK())) {
			token tok = m_pi.previous();
			m_pi.consume(Keywords().SEMI(), "expect ';' after 'break'");
			return std::make_shared<break_statement>(tok.loc());
		}
		if (m_pi.match(Keywords().LCURLY())) {
			return parse_block();
		}

		if (m_pi.match(Keywords().FUNCTION())) {
			return parse_function_declaration();
		}

		if (match_variable_declaration()) {
			return parse_variable_declaration();
		}
		if (m_pi.match(Keywords().RUN())) {
			return parse_run_recover();
		}
		if (m_pi.match(Keywords().PANIC())) {
			return parse_panic();
		}
		if (m_pi.match(Keywords().SWITCH())) {
			return parse_switch();
		}
		return parse_expression_stmt();
	}

	std::shared_ptr<function_declaration> parse_function_declaration()
	{
		token name = m_pi.consume(TOKEN_TYPE_WORD, "expect function name");
		m_pi.consume(Keywords().LPAREN(), "expect '(' in function declaration");

		std::vector<param> parameters;
		if (!m_pi.match(Keywords().RPAREN())) {
			do {
				if (match_variable_declaration()) {
					param p;
					if (match_builtin()) {
						p.type = m_pi.previous().lexeme();
					}
					else {
						p.type = m_pi.consume(TOKEN_TYPE_WORD, "expect type specifier in parameter").lexeme();
						p.class_specifier = p.type;
					}
					p.name = m_pi.consume(TOKEN_TYPE_WORD, "expect variable name in parameter").lexeme();
					if (m_pi.match(Keywords().EQUAL())) {
						p.default_value = parse_expression();
					}
					parameters.push_back(p);
				}
				else {
					throw ParsingException("expect parameter list in function declaration", name.loc());
				}
			} while (!m_pi.atEnd() && m_pi.match(Keywords().COMMA()));
			m_pi.consume(Keywords().RPAREN(), "expect syntax: function <id>(*params){ //... }");
		}
		m_pi.consume(Keywords().LCURLY(), "expect function body");
		std::shared_ptr<block> body = parse_block();
		return std::make_shared<function_declaration>(name.lexeme(), parameters, body, name.loc());
	}

	std::shared_ptr<class_declaration> parse_class_declaration()
	{
		token id = m_pi.consume(TOKEN_TYPE_WORD, "expect syntax group <identifier> { // ...}");
		m_pi.consume(Keywords().LCURLY(), "expect syntax group <identifier> { // ...}");
		std::shared_ptr<block> body = parse_block();
		return std::make_shared<class_declaration>(id.lexeme(), body, id.loc());
	}

	std::shared_ptr<directive_statement> parse_directive()
	{
		token directive = m_pi.consume(TOKEN_TYPE_WORD, "expect directive name");
		return std::make_shared<directive_statement>(directive.lexeme(), directive.loc());
	}

	std::shared_ptr<import_statement> parse_import()
	{
		token tok = m_pi.previous();
		std::shared_ptr<expression> expr = parse_expression();
		return std::make_shared<import_statement>(expr, tok.loc());
	}


	std::shared_ptr<variable_declaration> parse_variable_declaration()
	{
		std::string type;
		if (match_builtin()) {
			type = m_pi.previous().lexeme();
		}
		else {
			type = m_pi.consume(TOKEN_TYPE_WORD, "expect type specifier in declaration").lexeme();
		}
		token name = m_pi.consume(TOKEN_TYPE_WORD, "expect variable name in declaration");
		std::shared_ptr<expression> expr = nullptr;
		if (m_pi.match(Keywords().EQUAL())) {
			expr = parse_expression();
		}
		m_pi.consume(Keywords().SEMI(), "expect ';' at end of statement");
		return std::make_shared<variable_declaration>(type, name.lexeme(), expr, name.loc());
	}

	std::shared_ptr<if_statement> parse_if()
	{
		token tok = m_pi.consume(Keywords().LPAREN(), "Expect (<condition>) stmt after 'if'.");
		std::shared_ptr<expression> expr = parse_expression();
		m_pi.consume(Keywords().RPAREN(), "Expect (<condition>) stmt after 'if'.");
		std::shared_ptr<statement> body = parse_statement();
		std::shared_ptr<statement> elseDo = nullptr;
		if (m_pi.match(Keywords().ELSE())) {
			elseDo = parse_statement();
		}
		return std::make_shared<if_statement>(expr, body, elseDo, tok.loc());
	}

	std::shared_ptr<switch_statement> parse_switch()
	{
		token tok = m_pi.consume(Keywords().LPAREN(), "Expect (<testval>) after 'switch'.");
		std::shared_ptr<expression> expr = parse_expression();
		m_pi.consume(Keywords().RPAREN(), "Expect (<testval>) after 'switch'.");
		m_pi.consume(Keywords().LCURLY(), "Expect '{' after switch (<testval>)");
		std::vector<switch_case> switch_cases;
		switch_case sc;
		bool expectCase = true;
		do {
			if (m_pi.match(Keywords().CASE())) {
				expectCase = false;
				sc.cases.push_back(parse_expression());
				m_pi.consume(Keywords().COLON(), "Expect ':' after test value in switch case");
			}
			else if (!expectCase && m_pi.match(Keywords().LCURLY())) {
				sc.then = parse_block();
				switch_cases.push_back(sc);
			} 
			else if (m_pi.match(Keywords().DEFAULT())) {
				expectCase = false;
				m_pi.consume(Keywords().COLON(), "Expect ':' after 'default' in switch case");
				sc.isDefault = true;
			}
			throw ParsingException("Unexpected token in switch case", m_pi.current().loc());
		} while (m_pi.current().type() == Keywords().CASE() || m_pi.current().type() == Keywords().DEFAULT() || m_pi.current().type() == Keywords().LCURLY());
		return std::make_shared<switch_statement>(expr, switch_cases, tok.loc());
	}

	std::shared_ptr<while_statement> parse_while()
	{
		token tok = m_pi.consume(Keywords().LPAREN(), "Expect (<condition>) stmt after 'while'.");
		std::shared_ptr<expression> expr = parse_expression();
		m_pi.consume(Keywords().RPAREN(), "Expect (<condition>) stmt after 'while'.");
		std::shared_ptr<statement> body = parse_statement();

		return std::make_shared<while_statement>(expr, body, tok.loc());
	}

	std::shared_ptr<return_statement> parse_return()
	{
		token tok = m_pi.previous();
		std::shared_ptr<expression> expr;
		if (!m_pi.match(Keywords().SEMI())) {
			expr = parse_expression();
			m_pi.consume(Keywords().SEMI(), "Expect ';' at end of return statement.");
		}
		else {
			expr = std::make_shared<primary>(nullptr, tok.loc());
		}
		return std::make_shared<return_statement>(expr, tok.loc());
	}

	std::shared_ptr<run_recover_statement> parse_run_recover()
	{
		token tok = m_pi.previous();
		std::shared_ptr<statement> run = parse_statement();
		m_pi.consume(Keywords().RECOVER(), "Expect recover clause.");
		if (m_pi.match(Keywords().ON())){}
		std::string type{ "" };
		if (match_builtin()) {
			type = m_pi.previous().lexeme();
		}
		else {
			type = m_pi.consume(TOKEN_TYPE_WORD, "expect type specifier in declaration").lexeme();
		}
		std::string name{ "" };
		if (m_pi.match(TOKEN_TYPE_WORD)) {
			name = m_pi.previous().lexeme();
		}

		m_pi.consume(Keywords().SEMI(), "Expect ';' at end of recover statement.");

		return std::make_shared<run_recover_statement>(run, type, name, tok.loc());
	}


	std::shared_ptr<panic_statement> parse_panic()
	{
		token tok = m_pi.previous();
		std::shared_ptr<expression> expr;
		m_pi.consume(Keywords().LPAREN(), "Expect '(' after 'panic'");
		if (!m_pi.match(Keywords().RPAREN())) {
			expr = parse_expression();
			m_pi.consume(Keywords().RPAREN(), "Expect enclosing ')' in panic");
			m_pi.consume(Keywords().SEMI(), "Expect ';' at end of panic statement.");
		}
		else {
			expr = std::make_shared<primary>(nullptr, tok.loc());
			m_pi.consume(Keywords().SEMI(), "Expect ';' at end of panic statement.");
		}
		return std::make_shared<panic_statement>(expr, tok.loc());
	}


	std::shared_ptr<block> parse_block()
	{
		std::vector<std::shared_ptr<statement>> stmts;
		while (!m_pi.match(Keywords().RCURLY())) {
			stmts.push_back(parse_statement());
		}
		token prev = m_pi.previous();
		return std::make_shared<block>(stmts, prev.loc());
	}

	std::shared_ptr<expression_statement> parse_expression_stmt()
	{
		std::shared_ptr<expression> expr = parse_expression();
		token tok = m_pi.consume(Keywords().SEMI(), "Expect ';' at end of statement");
		return std::make_shared<expression_statement>(expr, tok.loc());
	}

	std::shared_ptr<expression> parse_expression()
	{
		return parse_assignment();
	}

	std::shared_ptr<expression> parse_assignment() {
		std::shared_ptr<expression> expr = parse_or();

		if (m_pi.match(Keywords().EQUAL())) {
			token tok = m_pi.previous();
			std::shared_ptr<expression> value = parse_assignment();
			if (std::shared_ptr<expr_identifier> id = std::dynamic_pointer_cast<expr_identifier> (expr)) {
				return std::make_shared<assignment>(nullptr, id->name, value, tok.loc());
			}
			else if (std::shared_ptr<get> g = std::dynamic_pointer_cast<get>(expr)) {
				return std::make_shared<assignment>(g->lhs, g->identifier, value, tok.loc());
			}
			else {
				throw ParsingException("Invalid assignment target.", m_pi.previous().loc());
			}
		}

		return expr;
	}

	std::shared_ptr<expression> parse_or() {
		std::shared_ptr<expression> expr = parse_and();
		while (m_pi.match(Keywords().OR())) {
			token tok = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_expression();
			expr = std::make_shared<logic_or>(expr, rhs, tok.loc());
		}
		return expr;
	}

	std::shared_ptr<expression> parse_and() {
		std::shared_ptr<expression> expr = parse_equality();
		while (m_pi.match(Keywords().AND())) {
			token tok = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_equality();
			expr = std::make_shared<logic_and>(expr, rhs, tok.loc());
		}
		return expr;
	}


	std::shared_ptr<expression> parse_equality() {
		std::shared_ptr<expression> expr = parse_comparison();
		while (m_pi.match(Keywords().EQUALEQUAL()) || m_pi.match("notequal")) {
			token op = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_comparison();
			expr = std::make_shared<binary>(expr, op.lexeme(), rhs, op.loc());

		}
		return expr;
	}

	std::shared_ptr<expression> parse_comparison() {
		std::shared_ptr<expression> expr = parse_term();
		while (m_pi.match(Keywords().LESSTHAN()) || m_pi.match(Keywords().LESSTHANEQUAL()) || m_pi.match(Keywords().GREATERTHAN()) || m_pi.match(Keywords().GREATERTHANEQUAL())) {
			token op = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_term();
			expr = std::make_shared<binary>(expr, op.lexeme(), rhs, op.loc());
		}
		return expr;
	}

	std::shared_ptr<expression> parse_term() {
		std::shared_ptr<expression> expr = parse_factor();
		while (m_pi.match(Keywords().ADD()) || m_pi.match(Keywords().SUBTRACT())) {
			token op = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_factor();
			expr = std::make_shared<binary>(expr, op.lexeme(), rhs, op.loc());
		}

		return expr;
	}

	std::shared_ptr<expression> parse_factor() {
		std::shared_ptr<expression> expr = parse_unary();
		while (m_pi.match(Keywords().ASTERISK()) || m_pi.match(Keywords().FORWARDSLASH()) || m_pi.match(Keywords().UPCARAT())) {
			token op = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_unary();
			expr = std::make_shared<binary>(expr, op.lexeme(), rhs, op.loc());
		}
		return expr;
	}


	std::shared_ptr<expression> parse_unary() {
		if (m_pi.match(Keywords().BANG()) || m_pi.match(Keywords().SUBTRACT()) || m_pi.match(Keywords().TYPEOF())) {
			token op = m_pi.previous();
			std::shared_ptr<expression> rhs = parse_unary();
			return std::make_shared<unary>(op.lexeme(), rhs, op.loc());
		}
		return parse_call();
	}

	std::shared_ptr<expression> parse_call()
	{
		std::shared_ptr<expression> expr = parse_primary();
		while (true) {
			if (m_pi.match(Keywords().DOT())) {
				token name = m_pi.consume(TOKEN_TYPE_WORD, "expect 'IDENTIFIER' after '.'");
				expr = std::make_shared<get>(expr, name.lexeme(), name.loc());
			}
			else if (m_pi.match(Keywords().LPAREN())) {
				token tok = m_pi.previous();
				std::vector<std::shared_ptr<expression>> args;
				if (!m_pi.match(Keywords().RPAREN())) {
					do {
						args.push_back(parse_expression());
					} while (!m_pi.atEnd() && m_pi.match(Keywords().COMMA()));
					m_pi.consume(Keywords().RPAREN(), "expect enclosing ')' in function call");
				}
				expr = std::make_shared<call>(expr, args, tok.loc());
			}
			else if (m_pi.match(Keywords().CAST())) {
				std::string op = m_pi.previous().lexeme();
				token type = m_pi.consume(TOKEN_TYPE_WORD, "expected syntax: <expr>::<typename> for cast");
				expr = std::make_shared<cast>(expr, op, type.lexeme(), type.loc());
			}
			else if (m_pi.match(Keywords().LBRACKET())) {
				std::string op = m_pi.previous().lexeme();
				std::shared_ptr<expression> lhs = parse_expression();
				m_pi.consume(Keywords().RBRACKET(), "expect enclosing ]");
				expr = std::make_shared<binary>(expr, op, lhs, m_pi.current().loc());
			}
			else {
				break;
			}
		}
		return expr;
	}


	std::shared_ptr<expression> parse_primary() {

		if (m_pi.match(Keywords().FALSE())) {
			token value = m_pi.previous();
			return std::make_shared<primary>(false, value.loc());
		}
		if (m_pi.match(Keywords().TRUE())) {
			token value = m_pi.previous();
			return std::make_shared<primary>(true, value.loc());
		}
		if (m_pi.match(Keywords().NUL())) {
			token value = m_pi.previous();
			return std::make_shared<primary>(nullptr, value.loc());
		}

		if (m_pi.match(TOKEN_TYPE_FLOAT)) {
			token value = m_pi.previous();
			try {
				return std::make_shared<primary>(std::stof(value.lexeme()), value.loc());
			}
			catch (std::invalid_argument) {
				throw ParsingException("unable to parse float value at: " + value.toStr(), m_pi.previous().loc());
			}
			catch (std::out_of_range) {
				throw ParsingException("unable to parse float value at: " + value.toStr(), m_pi.previous().loc());
			}
		}

		if (m_pi.match(TOKEN_TYPE_INTEGER)) {
			token value = m_pi.previous();
			try {
				return std::make_shared<primary>(std::stoi(value.lexeme()), value.loc());
			}
			catch (std::invalid_argument) {
				throw ParsingException("unable to parse integer value at: " + value.toStr(), m_pi.previous().loc());
			}
			catch (std::out_of_range) {
				throw ParsingException("unable to parse integer value at: " + value.toStr(), m_pi.previous().loc());
			}
		}

		if (m_pi.match(TOKEN_TYPE_UNSIGNED)) {
			token value = m_pi.previous();
			try {
				return std::make_shared<primary>(std::stoul(value.lexeme()), value.loc());
			}
			catch (std::invalid_argument) {
				throw ParsingException("unable to parse integer value at: " + value.toStr(), m_pi.previous().loc());
			}
			catch (std::out_of_range) {
				throw ParsingException("unable to parse integer value at: " + value.toStr(), m_pi.previous().loc());
			}
		}

		if (m_pi.match(TOKEN_TYPE_DOUBLE)) {
			token value = m_pi.previous();
			try {
				return std::make_shared<primary>(std::stod(value.lexeme()), value.loc());
			}
			catch (std::invalid_argument) {
				throw ParsingException("unable to parse double value at: " + value.toStr(), m_pi.previous().loc());
			}
			catch (std::out_of_range) {
				throw ParsingException("unable to parse double value at: " + value.toStr(), m_pi.previous().loc());
			}
		}


		if (m_pi.match(TOKEN_TYPE_STRING)) {
			token value = m_pi.previous();
			return std::make_shared<primary>(value.lexeme(), value.loc());
		}

		if (m_pi.match(TOKEN_TYPE_WORD)) {
			token value = m_pi.previous();
			return std::make_shared<expr_identifier>(value.lexeme(), value.loc());
		}

		if (m_pi.match(Keywords().LPAREN())) {
			token tok = m_pi.previous();
			std::shared_ptr<expression> expr = parse_expression();
			m_pi.consume(Keywords().RPAREN(), "expect ')' after expression in group.");
			return std::make_shared<group>(expr, tok.loc());
		}

		if (m_pi.match(Keywords().NEW())) {
			token name = m_pi.consume(TOKEN_TYPE_WORD, "expect sytnax: new <typename>(<initializer-list>)");
			m_pi.consume(Keywords().LPAREN(), "expect arguments list in initializer");
			std::vector<std::shared_ptr<expression>> args;
			if (!m_pi.match(Keywords().RPAREN())) {
				do {
					args.push_back(parse_expression());
				} while (!m_pi.atEnd() && m_pi.match(Keywords().COMMA()));
				m_pi.consume(Keywords().RPAREN(), "expect enclosing ')' in function call");
			}

			return std::make_shared<initializer>(name.lexeme(), args, name.loc());
		}

		if (m_pi.match(TOKEN_TYPE_INJECTED_STRING)) {
			token tok = m_pi.previous();
			throw ParsingException("token type '" + std::string(TOKEN_TYPE_INJECTED_STRING) + "' is not supported", tok.loc());
		}

		if (m_pi.match(Keywords().LBRACKET())) {
			token tok = m_pi.previous();
			std::vector<std::shared_ptr<expression>> args;
			if (!m_pi.match(Keywords().RBRACKET())) {
				do {
					args.push_back(parse_expression());
				} while (!m_pi.atEnd() && m_pi.match(Keywords().COMMA()));
				m_pi.consume(Keywords().RBRACKET(), "expect enclosing ']' in list initialization");
			}
			return std::make_shared<list_initializer>(args, tok.loc());
		}

		throw ParsingException("unexpected token in primary \"" + m_pi.current().toStr() + "\"", m_pi.current().loc());
	}

private:

	bool match_builtin() {
		for (unsigned int i{ 0 }; i < builtin_typenames.size(); i++) {
			if (m_pi.match(builtin_typenames.at(i))) return true;
		}
		return false;
	}

	bool match_builtin(const std::string& type) {
		for (unsigned int i{ 0 }; i < builtin_typenames.size(); i++) {
			if (type == builtin_typenames.at(i)) return true;
		}
		return false;
	}

	const std::vector<std::string> builtin_typenames {
		Keywords().UINT(),
		Keywords().INT(),
		Keywords().FLOAT(),
		Keywords().DOUBLE(),
		Keywords().CHAR(),
		Keywords().STRING(),
		Keywords().BOOL()
	};

	bool match_variable_declaration() {
		if (m_pi.current().type() == TOKEN_TYPE_WORD || match_builtin(m_pi.current().type())) {
			if (m_pi.peekMatch(1, TOKEN_TYPE_WORD)) {
				return true;
			}
			return false;
		}
		return false;
	}

	parser_interface m_pi;
};