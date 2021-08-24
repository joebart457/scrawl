#pragma once

#include "callable.h"

#include <map>
#include <string>
#include <memory>


class OperatorHandler
{
public:
	OperatorHandler(){}
	~OperatorHandler(){}

	void registerOperator(std::shared_ptr<callable> op);
	std::shared_ptr<callable> getOperator(std::string szName);

private:
	std::map<std::string, std::shared_ptr<callable>> m_operators;
};

