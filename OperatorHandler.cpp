#include "OperatorHandler.h"


#include "exceptions.h"

void OperatorHandler::registerOperator(std::shared_ptr<callable> op)
{
	if (op == nullptr) return;
	m_operators[op->getSignature()] = op;
}

std::shared_ptr<callable> OperatorHandler::getOperator(std::string szName)
{
	if (m_operators.count(szName)) {
		return m_operators[szName];
	}
	throw ProgramException("Undefined operator '" + szName + "'", location(), Severity().CRITICAL());
}