#include "environment.h"

#include "exceptions.h"
#include "callable.h"

#include <iostream>


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


std::string to_string( std::any& rhs)
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
	else if (rhs.type() == typeid(std::shared_ptr<unary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<unary_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(rhs)->getSignature());
	}
	else if (rhs.type() == typeid(std::shared_ptr<callable>)) {
		oss << (std::any_cast<std::shared_ptr<callable>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(rhs)->getSignature());
	}


	else {
		oss << "<object>";
	}
	return oss.str();
}

std::string Environment::toString(std::string tabs)
{
	std::string result{ "" };
	std::shared_ptr<Environment> e = std::make_shared<Environment>(m_enclosing);
	for (auto it = m_values.begin(); it != m_values.end(); it++) {
		result += tabs + it->first + " := " + to_string(it->second) + "\n";
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