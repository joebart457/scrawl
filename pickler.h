#pragma once

#include <memory>

#include "db_framework.h"
#include "db_helper.h"
#include "scope.h"

#include "exceptions.h"
class Pickler
{
public: 
	Pickler(std::shared_ptr<db_helper> helper)
		:m_db{helper}
	{
	}

	~Pickler(){}

	void Pickle(std::shared_ptr<scope<std::any>> environment)
	{
		std::string szName = ToTableName(environment->m_szAlias);

		db_table(szName, {
			db_column("id", SQLITE_INTEGER).NOT_NULL().PRIMARY_KEY().AUTOINCREMENT(),
			db_column("name", SQLITE_TEXT).NOT_NULL().UNIQUE(),
			db_column("type", SQLITE_TEXT).NOT_NULL(),
			db_column("value",SQLITE_TEXT)
			}).create(m_db);

		std::string szInsertQueryTemplate = "INSERT INTO " + szName + " (name, type, value) VALUES (?, ?, ?);";

		auto lookup = environment->m_lookup;
		for (auto it = lookup.begin(); it != lookup.end(); it++) {
			m_db->run_prepared(szInsertQueryTemplate, { it->first, it->second.type().name(), it->second }, nullptr, false);
		}


	}



private:

	std::string ToString() {

	}

	std::any to_string(std::shared_ptr<interpreter> i, std::any& rhs)
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
		else if (rhs.type() == typeid(std::shared_ptr<custom_fn>)) {
			oss << (std::any_cast<std::shared_ptr<custom_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<custom_fn>>(rhs)->getSignature());
		}
		else if (rhs.type() == typeid(std::shared_ptr<unary_fn>)) {
			oss << (std::any_cast<std::shared_ptr<unary_fn>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(rhs)->getSignature());
		}
		else if (rhs.type() == typeid(std::shared_ptr<callable>)) {
			oss << (std::any_cast<std::shared_ptr<callable>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(rhs)->getSignature());
		}
		else if (rhs.type() == typeid(std::shared_ptr<klass_definition>)) {
			oss << (std::any_cast<std::shared_ptr<klass_definition>>(rhs) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<klass_definition>>(rhs)->toString());
		}
		else if (rhs.type() == typeid(klass_instance)) {
			oss << std::any_cast<klass_instance>(rhs).toString();
		}
		else {
			oss << "<object>";
		}
		return oss.str();
	}

	std::string ToTableName(const std::string& raw)
	{
		std::string szCleanTableName{ "" };
		for (unsigned int i{0}; i< raw.size(); i++) {
			if (isalnum(raw.at(i))) {
				szCleanTableName.push_back(raw.at(i));
			}
			else if (isspace(raw.at(i))) {
				szCleanTableName.push_back('_');
			}
		}
	}
	
	void Validate()
	{
		if (m_db == nullptr) {
			throw ProgramException("unable to construct Pickler. Db was null.", location());
		}
	}

	std::shared_ptr<db_helper> m_db;

};