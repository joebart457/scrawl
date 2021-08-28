#pragma once

#include <string>
#include <vector>
#include <map>
#include <any>
#include <sstream>

#include "exceptions.h"
#include "db_helper.h"


class SQLiteObject {
public:
	SQLiteObject(std::any& value)
	{
		m_dataType = extractTypeFromValue(value);
		m_value = value;
	}
	SQLiteObject(int type, std::any value) {}

	~SQLiteObject(){}

	std::string to_inner_query_value() {
		/* Gives string representation of object value to be placed in query*/
		if (m_value.type() == typeid(int)) {
			return std::to_string(std::any_cast<int>(m_value));
		}
		if (m_value.type() == typeid(std::string)) {
			return "'" + std::any_cast<std::string>(m_value) + "'";
		}
		if (m_value.type() == typeid(float)) {
			return std::to_string(std::any_cast<float>(m_value));
		}
		if (m_value.type() == typeid(nullptr)) {
			return "NULL";
		}
		throw ProgramException("SQLiteObject not convertible to string: type is" + std::string(m_value.type().name()), location());
	}

private:

	int extractTypeFromValue(std::any val)
	{
		if (val.type() == typeid(int)) {
			return SQLITE_INTEGER;
		}
		if (val.type() == typeid(std::string)) {
			return SQLITE_TEXT;
		}
		if (val.type() == typeid(float)) {
			return SQLITE_FLOAT;
		}
		if (val.type() == typeid(nullptr)) {
			return SQLITE_NULL;
		}
		throw ProgramException("type not convertible to sqlite type: " + std::string(val.type().name()), location());
	}

	bool isValidSQLiteType(int type) {
		switch (type) {
		case SQLITE_NULL:
		case SQLITE_INTEGER:
		case SQLITE_FLOAT:
		case SQLITE_TEXT:
			return true;
		default:
			return false;
		}
	}

	int m_dataType{ SQLITE_NULL };
	std::any m_value{ nullptr };
};

class DbColumnConstraint {
public:
	static std::string PRIMARY_KEY() { return "PRIMARY KEY"; }
	static std::string FOREIGN_KEY() { return "FOREIGN KEY"; }
	static std::string AUTOINCREMENT() { return "AUTOINCREMENT"; }
	static std::string NOT_NULL() { return "NOT NULL"; }
	static std::string DEFAULT() { return "DEFAULT"; }
	static std::string UNIQUE() { return "UNIQUE"; }
	static std::string CHECK() { return "CHECK"; }
};


class db_column_constraint {
public:
	db_column_constraint(){}
	~db_column_constraint(){}

	virtual std::string get() = 0;
};

class db_constraint_not_null
	: public db_column_constraint {
public:
	db_constraint_not_null(){}
	~db_constraint_not_null(){}

	virtual std::string get()
	{
		return DbColumnConstraint().NOT_NULL();
	}
};

class db_constraint_primary_key
	: public db_column_constraint {
public:
	db_constraint_primary_key() {}
	~db_constraint_primary_key() {}

	virtual std::string get()
	{
		return DbColumnConstraint().PRIMARY_KEY();
	}
};

class db_constraint_autoincrement
	: public db_column_constraint {
public:
	db_constraint_autoincrement() {}
	~db_constraint_autoincrement() {}

	virtual std::string get()
	{
		return DbColumnConstraint().AUTOINCREMENT();
	}
};

class db_constraint_unique
	: public db_column_constraint {
public:
	db_constraint_unique() {}
	~db_constraint_unique() {}

	virtual std::string get()
	{
		return DbColumnConstraint().UNIQUE();
	}
};

class db_constraint_default
	: public db_column_constraint {
public:
	db_constraint_default(SQLiteObject obj)
		:m_value{ obj }{}
	~db_constraint_default() {}

	virtual std::string get()
	{
		return DbColumnConstraint().DEFAULT() + " " + m_value.to_inner_query_value();
	}

private:

	SQLiteObject m_value;
};

class db_constraint_check
	: public db_column_constraint {
public:
	db_constraint_check(const std::string& expression)
		:m_szExpression{ expression } 
	{
		validate();
	}

	~db_constraint_check() {}

	virtual std::string get()
	{
		return DbColumnConstraint().CHECK() + "(" + m_szExpression+")";
	}

private:
	void validate() {
		if (m_szExpression.size() == 0) {
			throw ProgramException("sqlite column creation constraint CHECK: expression must have value", location());
		}
	}

	std::string m_szExpression;
};





class db_column {
public:
	db_column(const std::string name, int type = SQLITE_TEXT)
		:m_szName{ name }
	{
		extract_type(type);
	}

	~db_column() {}

	db_column& NOT_NULL()
	{
		if (!m_notNull) {
			m_constraints.push_back(std::make_shared<db_constraint_not_null>());
			m_notNull = true;
		}
		return *this;
	}

	db_column& PRIMARY_KEY()
	{
		if (!m_primaryKey) {
			m_primaryKey = true;
		}
		return *this;
	}

	db_column& AUTOINCREMENT()
	{
		if (!m_autoIncrement) {
			m_autoIncrement = true;
		}
		return *this;
	}

	db_column& UNIQUE()
	{
		if (!m_unique) {
			m_constraints.push_back(std::make_shared<db_constraint_unique>());
			m_unique = true;
		}
		return *this;
	}

	db_column& CHECK(const std::string& expression)
	{
		if (!m_check) {
			m_constraints.push_back(std::make_shared<db_constraint_check>(expression));
			m_check = true;
		}
		return *this;
	}

	db_column& DEFAULT(const SQLiteObject& obj)
	{
		if (!m_default) {
			m_constraints.push_back(std::make_shared<db_constraint_default>(obj));
			m_default = true;
		}
		return *this;
	}

	db_column& FOREIGN_KEY(const std::string& references)
	{
		if (!m_foreignKey) {
			m_szReferences = references;
			m_foreignKey = true;
		}
		return *this;
	}


	std::string to_desc_string()
	{
		std::ostringstream oss;
		oss << "\"" << m_szName <<"\"" << " " << m_szDataType;
		for (auto constraint : m_constraints) {
			oss << " " << constraint->get();
		}
		return oss.str();
	}

	std::string additional_constraints() {
		std::ostringstream oss;
		if (m_foreignKey) {
			oss << ",\n\t" << DbColumnConstraint().FOREIGN_KEY() << "(" << m_szName << ")" << " REFERENCES " << m_szReferences << "";
		}
		if (m_primaryKey) {
			oss << ",\n\t" << DbColumnConstraint().PRIMARY_KEY() << "(" << m_szName << (m_autoIncrement ? " " + DbColumnConstraint().AUTOINCREMENT() : "") << ")";
		}
		return oss.str();
	}


private:



	void extract_type(int type) {
		switch (type) {
		case SQLITE_INTEGER:
		{
			m_szDataType = "INTEGER";
			break;
		}
		case SQLITE_FLOAT:
		{
			m_szDataType = "REAL";
			break;
		}
		case SQLITE_TEXT:
		{
			m_szDataType = "TEXT";
			break;
		}
		default:
			throw ProgramException("sqlite table creation column has invalid type: " + std::to_string(type), location());
		}
	}

	std::vector<std::shared_ptr<db_column_constraint>> m_constraints;

	std::string m_szName{ "" };
	std::string m_szReferences{ "" };
	std::string m_szDataType{ "" };

	bool m_notNull{ false };
	bool m_autoIncrement{ false };
	bool m_primaryKey{ false };
	bool m_check{ false };
	bool m_default{ false };
	bool m_unique{ false };
	bool m_foreignKey{ false };
};


class db_table {
public:
	db_table(const std::string& name, std::vector<db_column> columns)
		:m_szName{ name }, m_columns{ columns }{}
	db_table(const std::string& name)
		:m_szName{ name }{}
	~db_table(){}

	db_table& add_column(db_column column) {
		m_columns.push_back(column);
		return *this;
	}

	db_table& IF_NOT_EXISTS() {
		m_ifNotExists = true;
		return *this;
	}

	std::string get_creation_query()
	{
		std::ostringstream oss;
		oss << "CREATE TABLE " << (m_ifNotExists ? "IF NOT EXISTS" : "") << "\""+m_szName+"\"" << "(";
		if (m_columns.size() > 0) {
			oss << "\n\t" << m_columns.at(0).to_desc_string();
		}
		for (unsigned int i{ 1 }; i < m_columns.size(); i++) {
			oss << ",\n\t" << m_columns.at(i).to_desc_string();
		}
		for (auto column : m_columns) {
			oss << column.additional_constraints();
		}

		oss << "\n);";
		return oss.str();
	}

private:
	std::string m_szName{ "" };
	std::vector<db_column> m_columns;


	bool m_ifNotExists{ false };
};


class db_framework {
public:
	db_framework(){}
	~db_framework(){}

};