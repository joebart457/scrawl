#pragma once

#include <memory>

#include "db_framework.h"
#include "db_helper.h"
#include "scope.h"

#include "exceptions.h"
#include "Utilities.h"

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
			m_db->run_prepared(szInsertQueryTemplate, { it->first, it->second.type().name(), Utilities().stringify(it->second) }, nullptr, false);
		}


	}



private:

	std::string ToString() {

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