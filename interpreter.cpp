#include "interpreter.h"


#include <typeinfo>
#include <sstream>

#include "exceptions.h"
#include "environment.h"
#include "expression.h"
#include "OperatorHandler.h"

#include "klass_instance.h"
#include "context.h"


void check_context(std::shared_ptr<execution_context> c)
{
	if (c == nullptr) {
		location loc;
		throw ProgramException("cannot execute code in null execution_context", loc, Severity().FATAL());
	}
}


void check_context(std::shared_ptr<interpreter> i)
{
	if (i == nullptr) {
		location loc;
		throw ProgramException("cannot execute code in null context", loc, Severity().FATAL());
	}
}


void check_context(std::shared_ptr<interpreter> i, const location& loc)
{
	if (i == nullptr) {
		throw ProgramException("cannot execute code in null context", loc, Severity().FATAL());
	}
}



std::string createOperatorSignature(std::string szName, std::vector<std::any> args)
{
	std::ostringstream oss;
	oss << szName << "(";
	if (args.size() > 0) {
		oss << args.at(0).type().name();
	}
	for (unsigned int i{ 1 }; i < args.size(); i++) {
		oss << "," << args.at(i).type().name();
	}
	oss << ")";
	return oss.str();
}

std::shared_ptr<callable> getCallable(std::any callee) {
	if (callee.type() == typeid(std::shared_ptr<callable>)) {
		return std::any_cast<std::shared_ptr<callable>>(callee);
	}
	else if (callee.type() == typeid(std::shared_ptr<native_fn>)) {
		return std::any_cast<std::shared_ptr<native_fn>>(callee);
	}
	else if (callee.type() == typeid(std::shared_ptr<binary_fn>)) {
		return std::any_cast<std::shared_ptr<binary_fn>>(callee);
	}
	else if (callee.type() == typeid(std::shared_ptr<unary_fn>)) {
		return std::any_cast<std::shared_ptr<unary_fn>>(callee);
	}
	else if (callee.type() == typeid(std::shared_ptr<custom_fn>)) {
		return std::any_cast<std::shared_ptr<custom_fn>>(callee);
	}
	else {
		throw ProgramException("unable to convert type " + std::string(callee.type().name()) + " to callable type", location());
	}
}

bool isTruthy(std::any obj)
{
	if (obj.type() == typeid(int)) {
		return std::any_cast<int>(obj);
	}
	else if (obj.type() == typeid(unsigned long)) {
		return std::any_cast<unsigned long>(obj);
	}
	else if (obj.type() == typeid(bool)) {
		return std::any_cast<bool>(obj);
	}
	else if (obj.type() == typeid(float)) {
		return std::any_cast<float>(obj);
	}
	else if (obj.type() == typeid(double)) {
		return std::any_cast<double>(obj);
	}
	else if (obj.type() == typeid(std::string)) {
		return std::any_cast<std::string>(obj).size() > 0;
	}

	throw ProgramException("Unsupported object type '" + std::string(obj.type().name()), location());

}

interpreter::interpreter(std::shared_ptr<execution_context> context, std::shared_ptr<OperatorHandler> opHandler)
	:m_context{ context }, m_opHandler{ opHandler }{}
interpreter::interpreter()
{
	std::shared_ptr<activation_record> ar = std::make_shared<activation_record>();
	ar->environment = std::make_shared<scope<std::any>>("default_empty");
	ar->id = -1;
	m_context = std::make_shared<execution_context>(ar);
}

std::shared_ptr<execution_context> interpreter::get_context()
{
	return m_context;
}


void interpreter::interpret(std::vector<std::shared_ptr<statement>> stmts)
{
	for (unsigned int i{ 0 }; i < stmts.size(); i++) {
		acceptStatement(stmts.at(i));
	}
}

void interpreter::acceptStatement(std::shared_ptr<statement> stmt) {
	if (stmt != nullptr) {
		try {
			stmt->accept(std::static_pointer_cast<interpreter>(shared_from_this()));
		}
		catch (BreakException pe) {
			throw pe;
		}
		catch (ReturnException pe) {
			throw pe;
		}
		catch (ProgramException pe) {
			pe.addStackTrace("error in " + stmt->getType(), stmt->getLocation());
			throw pe;
		}
	}
}

void interpreter::acceptClassDeclaration(std::shared_ptr<class_declaration> class_decl)
{
	std::shared_ptr<activation_record> env = acceptBlock_KeepEnvironment(class_decl->m_body);

	m_context->define(class_decl->m_szName, 
		klass_definition(class_decl->m_szName, env),
		false,
		class_decl->m_loc);
}

void interpreter::acceptFunctionDeclaration(std::shared_ptr<function_declaration> func_decl)
{
	m_context->define(func_decl->m_szName, 
		std::make_shared<custom_fn>(func_decl->m_szName, m_context->current_ar(), func_decl->m_body->m_statements, func_decl->m_params, func_decl->m_loc), 
		false,
		func_decl->m_loc);
}


void interpreter::acceptVariableDeclaration(std::shared_ptr<variable_declaration> var_decl)
{
	if (var_decl->m_value != nullptr) {
		std::any val = acceptExpression(var_decl->m_value);
		if (var_decl->m_szTypename != "" && val.type().name() != var_decl->m_szTypename) {
			throw ProgramException("type mismatch in variable declaration: " + std::string(val.type().name()) + " != " + var_decl->m_szTypename, var_decl->m_loc);
		}
		m_context->define(var_decl->m_szName, val, false, var_decl->m_loc);
	}
	// TODO: Else do protos
}

void interpreter::acceptImportStatement(std::shared_ptr<import_statement> import_stmt)
{
	throw ProgramException("NotSupportedException", location());
}

void interpreter::acceptReturnStatement(std::shared_ptr<return_statement> return_stmt)
{
	throw ReturnException(acceptExpression(return_stmt->m_expr), return_stmt->m_loc);
}

void interpreter::acceptIfStatement(std::shared_ptr<if_statement> if_stmt)
{
	if (isTruthy(acceptExpression(if_stmt->m_condition))) {
		acceptStatement(if_stmt->m_then);
	}
	else {
		acceptStatement(if_stmt->m_elsethen); // Okay because nullptr is safe for acceptStatement()
	}
}


void interpreter::acceptWhileStatement(std::shared_ptr<while_statement> while_stmt)
{
	while (isTruthy(acceptExpression(while_stmt->m_condition))) {
		try {
			acceptStatement(while_stmt->m_then);
		}
		catch (BreakException) {
			break;
		}
	}
}

void interpreter::acceptBreakStatement(std::shared_ptr<break_statement> break_stmt)
{
	throw BreakException(break_stmt->m_loc);
}


void interpreter::acceptDirectiveStatement(std::shared_ptr<directive_statement> directive_stmt)
{
	throw ProgramException("NotSupportedException", location());
}

void interpreter::acceptBlock(std::shared_ptr<block> blk)
{
	m_context->push_ar(std::to_string(m_arIndex));
	try {
		interpret(blk->m_statements);
	}
	catch (BreakException pe) {
		m_context->pop_ar();
		throw pe;
	}
	catch (ReturnException pe) {
		m_context->pop_ar();
		throw pe;
	}
	catch (ProgramException pe) {
		m_context->pop_ar();
		throw pe;
	}
	m_context->pop_ar();
}

std::shared_ptr<activation_record> interpreter::acceptBlock_KeepEnvironment(std::shared_ptr<block> blk)
{
	m_context->push_ar(std::to_string(m_arIndex));
	try {
		interpret(blk->m_statements);
	}
	catch (BreakException pe) {
		m_context->pop_ar();
		throw pe;
	}
	catch (ReturnException pe) {
		m_context->pop_ar();
		throw pe;
	}
	catch (ProgramException pe) {
		m_context->pop_ar();
		throw pe;
	}

	return m_context->pop_ar();
}



void interpreter::acceptExpressionStatement(std::shared_ptr<expression_statement> expr_stmt)
{
	acceptExpression(expr_stmt->m_expr);
}


std::any interpreter::acceptExpression(std::shared_ptr<expression> expr)
{
	if (expr == nullptr) {
		return nullptr;
	}
	try {
		return expr->visit(std::static_pointer_cast<interpreter>(shared_from_this()));
	}
	catch (ProgramException pe) {
		pe.addStackTrace("error in " + expr->getType(), expr->getLocation());
		throw pe;
	}
}

std::any interpreter::acceptAssignment(std::shared_ptr<assignment> assignmnt)
{

	/* TODO: Test pointer effects of this*/
	std::any val = acceptExpression(assignmnt->val);
	if (assignmnt->lhs != nullptr) {
		std::any lhs = acceptExpression(assignmnt->lhs);
		if (lhs.type() == typeid(klass_instance)) {// environment
			klass_instance instance = std::any_cast<klass_instance>(lhs);
			instance.Assign(assignmnt->name, val, assignmnt->m_loc);
			return val;
		}
		if (lhs.type() == typeid(klass_definition)) {// environment
			klass_definition instance = std::any_cast<klass_definition>(lhs);
			instance.Assign(assignmnt->name, val, assignmnt->m_loc);
			return val;
		}
		throw ProgramException("invalid assignment target", assignmnt->m_loc);
	}
	else {
		m_context->assign(assignmnt->name, val, assignmnt->m_loc);
		return val;
	}
}

std::any interpreter::acceptLogicAnd(std::shared_ptr<logic_and> expr_logic_and)
{
	return isTruthy(acceptExpression(expr_logic_and->lhs)) && isTruthy(acceptExpression(expr_logic_and->rhs));
}

std::any interpreter::acceptLogicOr(std::shared_ptr<logic_or> expr_logic_or)
{
	return isTruthy(acceptExpression(expr_logic_or->lhs)) || isTruthy(acceptExpression(expr_logic_or->rhs));
}

std::any interpreter::acceptBinary(std::shared_ptr<binary> expr_binary)
{
	std::any rhs = acceptExpression(expr_binary->rhs);
	std::any lhs = acceptExpression(expr_binary->lhs);

	return m_opHandler->getOperator(createOperatorSignature(expr_binary->op, { rhs, lhs }))
		->call(std::static_pointer_cast<interpreter>(shared_from_this()), { rhs, lhs });
}


std::any interpreter::acceptUnary(std::shared_ptr<unary> expr_unary)
{
	std::any rhs = acceptExpression(expr_unary->rhs);

	return m_opHandler->getOperator(createOperatorSignature(expr_unary->op, { rhs }))
		->call(std::static_pointer_cast<interpreter>(shared_from_this()), { rhs });
}


std::any interpreter::acceptCall(std::shared_ptr<call> expr_call)
{

	std::vector<std::any> arguments;
	for (unsigned int i{ 0 }; i < expr_call->arguments.size(); i++) {
		arguments.push_back(acceptExpression(expr_call->arguments.at(i)));
	}

	std::any callee = acceptExpression(expr_call->lhs);
	
	std::shared_ptr<callable> callee_internal = getCallable(callee);
	return callee_internal->call(std::static_pointer_cast<interpreter>(shared_from_this()), arguments);
}


std::any interpreter::acceptGet(std::shared_ptr<get> expr_get)
{
	std::any lhs = acceptExpression(expr_get->lhs);
	
	if (lhs.type() == typeid(klass_instance)) {
		return std::any_cast<klass_instance>(lhs).Get(expr_get->identifier, expr_get->m_loc);
	}
	if (lhs.type() == typeid(klass_definition)) {
		return std::any_cast<klass_definition>(lhs).Get(expr_get->identifier, expr_get->m_loc);
	}

	throw ProgramException("Unable to perform get on non-container type", expr_get->m_loc);
}
std::any interpreter::acceptGroup(std::shared_ptr<group> expr_group)
{
	return acceptExpression(expr_group->m_expr);
}

std::any interpreter::acceptIdentifier(std::shared_ptr<expr_identifier> identifier)
{
	return m_context->get(identifier->name, identifier->m_loc);
}

std::any interpreter::acceptPrimary(std::shared_ptr<primary> expr_primary)
{
	return expr_primary->data;
}
std::any interpreter::acceptCast(std::shared_ptr<cast> expr_cast)
{
	throw ProgramException("NotSupportedException", location());
}


std::any interpreter::acceptInitializer(std::shared_ptr<initializer> expr_intializer)
{
	std::vector<std::any> args;
	for (auto arg : expr_intializer->arguments) {
		args.push_back(acceptExpression(arg));
	}
	std::any klass = m_context->get(expr_intializer->szTypeName, expr_intializer->m_loc);
	if (klass.type() != typeid(klass_definition)) {
		throw ProgramException("expect valid class type in initializer", expr_intializer->m_loc);
	}
	klass_definition klass_def = std::any_cast<klass_definition>(klass);
	klass_instance ki = klass_def.create();
	
	std::shared_ptr<callable> constructor = getCallable(ki.Get("constructor", expr_intializer->m_loc));
	constructor->call(std::static_pointer_cast<interpreter>(shared_from_this()), args);
	return ki;
}

std::any interpreter::acceptListInitializer(std::shared_ptr<list_initializer> expr_list_initializer)
{
	throw ProgramException("NotSupportedException", location());
}

std::any interpreter::assert_or_convert_type(std::string type, std::any obj, const location& loc)
{
	if (type != "" && obj.type().name() != type) {
		throw ProgramException("Type mismatch " + std::string(obj.type().name()) + " != " + type, loc, Severity().MEDIUM());
	}
	return obj;
}