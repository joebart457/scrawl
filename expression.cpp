#include "expression.h"

#include "interpreter.h"

std::any expression::visit(std::shared_ptr<interpreter> i)
{
	return nullptr;
}

std::any assignment::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptAssignment(std::static_pointer_cast<assignment>(shared_from_this()));
}

std::any logic_and::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptLogicAnd(std::static_pointer_cast<logic_and>(shared_from_this()));
}

std::any logic_or::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptLogicOr(std::static_pointer_cast<logic_or>(shared_from_this()));
}

std::any binary::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptBinary(std::static_pointer_cast<binary>(shared_from_this()));
}

std::any unary::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptUnary(std::static_pointer_cast<unary>(shared_from_this()));
}

std::any call::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptCall(std::static_pointer_cast<call>(shared_from_this()));
}

std::any get::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptGet(std::static_pointer_cast<get>(shared_from_this()));
}

std::any group::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptGroup(std::static_pointer_cast<group>(shared_from_this()));
}

std::any expr_identifier::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptIdentifier(std::static_pointer_cast<expr_identifier>(shared_from_this()));
}

std::any primary::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptPrimary(std::static_pointer_cast<primary>(this->shared_from_this()));
}


std::any cast::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptCast(std::static_pointer_cast<cast>(this->shared_from_this()));
}


std::any initializer::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptInitializer(std::static_pointer_cast<initializer>(this->shared_from_this()));
}


std::any list_initializer::visit(std::shared_ptr<interpreter> i)
{
	return i->acceptListInitializer(std::static_pointer_cast<list_initializer>(this->shared_from_this()));
}

