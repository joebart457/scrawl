#include "statement.h"

#include "interpreter.h"


void class_declaration::accept(std::shared_ptr<interpreter> i)
{
	i->acceptClassDeclaration(std::static_pointer_cast<class_declaration>(shared_from_this()));
}


void function_declaration::accept(std::shared_ptr<interpreter> i)
{
	i->acceptFunctionDeclaration(std::static_pointer_cast<function_declaration>(shared_from_this()));
}


void variable_declaration::accept(std::shared_ptr<interpreter> i)
{
	i->acceptVariableDeclaration(std::static_pointer_cast<variable_declaration>(shared_from_this()));
}


void import_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptImportStatement(std::static_pointer_cast<import_statement>(shared_from_this()));
}

void return_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptReturnStatement(std::static_pointer_cast<return_statement>(shared_from_this()));
}


void if_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptIfStatement(std::static_pointer_cast<if_statement>(shared_from_this()));
}


void while_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptWhileStatement(std::static_pointer_cast<while_statement>(shared_from_this()));
}


void break_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptBreakStatement(std::static_pointer_cast<break_statement>(shared_from_this()));
}


void directive_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptDirectiveStatement(std::static_pointer_cast<directive_statement>(shared_from_this()));
}


void block::accept(std::shared_ptr<interpreter> i)
{
	i->acceptBlock(std::static_pointer_cast<block>(shared_from_this()));
}


void expression_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptExpressionStatement(std::static_pointer_cast<expression_statement>(shared_from_this()));
}


void switch_statement::accept(std::shared_ptr<interpreter> i)
{
	i->acceptSwitchStatement(std::static_pointer_cast<switch_statement>(shared_from_this()));
}