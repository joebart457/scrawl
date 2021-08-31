#include "environment.h"

#include "exceptions.h"
#include "callable.h"
#include "Utilities.h"


bool Environment::Exists(const std::string& szKey)
{
	if (m_values.count(szKey)) {
		return true;
	}
	if (m_enclosing != nullptr) {
		return m_enclosing->Exists(szKey);
	}
	return false;
}

bool Environment::Exists_Local(const std::string& szKey)
{
	return m_values.count(szKey);
}

void Environment::Define(std::string szName, std::any value, const location& loc, bool overwrite = false)
{
	if (overwrite) {
		m_values[szName] = value;
	}
	else {
		if (m_values.count(szName)) {
			throw ProgramException("Redefinition of variable '" + szName + "'", loc);
		}
		else {
			m_values[szName] = value;
		}
	}
}

void Environment::Assign(std::string szName, std::any value, const location& loc)
{
	if (m_values.count(szName)) {
		m_values[szName] = value;
	}
	else if (m_enclosing != nullptr) {
		m_enclosing->Assign(szName, value, loc);
	}
	else {
		throw ProgramException("Variable '" + szName + "' is undefined.", loc);
	}
}

std::any Environment::Get(std::string szName, const location& loc)
{
	if (m_values.count(szName)) {
		return m_values[szName];
	}
	else if (m_enclosing != nullptr) {
		return m_enclosing->Get(szName, loc);
	}
	else {
		throw ProgramException("Undeclared identifier '" + szName + "'", loc);
	}
}


void Environment::Delete(std::string szName, const location& loc)
{
	if (m_values.count(szName)) {
		m_values.erase(szName);
	}
	else {
		throw ProgramException("Unable to erase value. Variable is undefined '" + szName + "'", loc);
	}
}

void Environment::Delete_NoThrow(std::string szName, const location& loc)
{
	m_values.erase(szName);
}

std::shared_ptr<Environment> Environment::Copy() {
	std::shared_ptr<Environment> e = std::make_shared<Environment>(nullptr);
	for (auto it = m_values.begin(); it != m_values.end(); it++) {


		std::any val = std::any(it->second);
		e->m_values[it->first] = val;
	}
	return e;
}


void Environment::SetEnclosing(std::shared_ptr<Environment> enclosing)
{
	m_enclosing = enclosing;
}



std::string Environment::toString(std::string tabs)
{
	std::string result{ "" };
	std::shared_ptr<Environment> e = std::make_shared<Environment>(m_enclosing);
	for (auto it = m_values.begin(); it != m_values.end(); it++) {
		result += tabs + it->first + " := " + Utilities().stringify(it->second) + "\n";
	}

	if (m_enclosing != nullptr) {
		result += m_enclosing->toString(tabs + "\t");
	}

	return result;
}

std::shared_ptr<Environment> Environment::GetEnclosing()
{
	return m_enclosing;
}