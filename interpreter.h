#pragma once

#include <any>
#include <memory>
#include <map>
#include <string>
#include <vector>

#include "statement.h"
#include "expression.h"

class execution_context;
struct activation_record;

class interpreter:
	public std::enable_shared_from_this<interpreter>
{
public:
	interpreter(std::shared_ptr<execution_context> context);
	~interpreter(){}

	void interpret(std::vector<std::shared_ptr<statement>> stmts);

	void acceptStatement(std::shared_ptr<statement> stmt);
	void acceptClassDeclaration(std::shared_ptr<class_declaration> class_decl);
	void acceptFunctionDeclaration(std::shared_ptr<function_declaration> func_decl);
	void acceptVariableDeclaration(std::shared_ptr<variable_declaration> var_decl);
	void acceptImportStatement(std::shared_ptr<import_statement> import_stmt);
	void acceptReturnStatement(std::shared_ptr<return_statement> return_stmt);
	void acceptIfStatement(std::shared_ptr<if_statement> if_stmt);
	void acceptWhileStatement(std::shared_ptr<while_statement> while_stmt);
	void acceptBreakStatement(std::shared_ptr<break_statement> break_stmt);
	void acceptDirectiveStatement(std::shared_ptr<directive_statement> directive_stmt);
	void acceptBlock(std::shared_ptr<block> blk);
	void acceptExpressionStatement(std::shared_ptr<expression_statement> expr_statement);
	void acceptSwitchStatement(std::shared_ptr<switch_statement> switch_stmt);
	void acceptRunRecoverStatement(std::shared_ptr<run_recover_statement> rr_stmt);
	void acceptPanicStatement(std::shared_ptr<panic_statement> panic_stmt);


	std::any acceptExpression(std::shared_ptr<expression> expr);
	std::any acceptAssignment(std::shared_ptr<assignment> assignmnt);
	std::any acceptLogicAnd(std::shared_ptr<logic_and> expr_logic_and);
	std::any acceptLogicOr(std::shared_ptr<logic_or> expr_logic_or);
	std::any acceptBinary(std::shared_ptr<binary> expr_binary);
	std::any acceptUnary(std::shared_ptr<unary> expr_unary);
	std::any acceptCall(std::shared_ptr<call> expr_call);
	std::any acceptGet(std::shared_ptr<get> expr_get);
	std::any acceptGroup(std::shared_ptr<group> expr_group);
	std::any acceptIdentifier(std::shared_ptr<expr_identifier> identifier);
	std::any acceptPrimary(std::shared_ptr<primary> expr_primary);
	std::any acceptCast(std::shared_ptr<cast> expr_cast);
	std::any acceptInitializer(std::shared_ptr<initializer> expr_intializer);
	std::any acceptListInitializer(std::shared_ptr<list_initializer> expr_list_initializer);

	std::any assert_or_convert_type(const param& p, std::any obj, const location& loc);


	std::shared_ptr<execution_context> get_context();
private:

	std::shared_ptr<activation_record> acceptBlock_KeepEnvironment(std::shared_ptr<block> blk);
	std::shared_ptr<execution_context> m_context{ nullptr };
	unsigned int m_arIndex{ 0 };
};

