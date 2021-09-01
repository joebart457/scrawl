#pragma once

#ifndef __INCLUDE_CONTEXT_H
#define __INCLUDE_CONTEXT_H

#include <memory>
#include <sstream>
#include <any>
#include <iostream>

#include "list_crawler.h"
#include "scope.h"
#include "location.h"
#include "exceptions.h"
#include "callable.h"
#include "OperatorHandler.h"
#include "Utilities.h"

struct activation_record {
	unsigned int id{ 0 };
	std::string szAlias;
	std::shared_ptr<scope<std::any>> environment;
};



class execution_context {
public:
	execution_context(std::shared_ptr<activation_record> ar, std::shared_ptr<OperatorHandler> opHandler)
		:m_opHandler{ opHandler }
	{
		push_ar(ar);
		if (m_opHandler == nullptr) {
			m_opHandler = std::make_shared<OperatorHandler>();
		}
	}
	~execution_context() {}

	void push_ar(std::string szAlias = "")
	{
		activation_record ar;
		ar.id = m_index;
		ar.szAlias = szAlias;
		ar.environment = std::make_shared<scope<std::any>>(szAlias);
		push_ar(std::make_shared<activation_record>(ar));
	}

	void push_ar(std::shared_ptr<activation_record> ar)
	{
		if (ar == nullptr) {
			ar = std::make_shared<activation_record>();
			ar->id = m_index;
			ar->environment = std::make_shared<scope<std::any>>("");
		}

		m_records.push_back(ar);
		m_index++;
	}

	std::shared_ptr<activation_record> pop_ar()
	{
		if (m_records.size() > 0) {
			std::shared_ptr<activation_record> ar = m_records.at(m_records.size() - 1);
			m_records.pop_back();
			return ar;
		}
		throw std::exception("unable to pop activation record; none exist");
	}

	bool exists(const std::string& szKey)
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		while (!crawler.end()) {
			if (crawler.next()->environment->exists_local(szKey)) {
				return true;
			}
		}
		return false;
	}


	std::any get(const std::string& szKey, const location& loc)
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		while (!crawler.end()) {
			std::shared_ptr<activation_record> ar = crawler.next();
			std::any out;
			if (ar->environment->get(szKey, out)) {
				return out;
			}
		}
		throw ProgramException("unable to retrieve value with key '" + szKey + "'", loc);
	}
	
	template <typename Ty>
	Ty get(const std::string& szKey)
	{
		std::any obj = get(szKey, location());
		if (obj.type() != typeid(Ty)) {
			throw ProgramException("type mismatch in assertion type " + std::string(obj.type().name()) + " != " + std::string(typeid(Ty).name()), location());
		}
		return std::any_cast<Ty>(obj);
	}

	std::shared_ptr<callable> get_callable(const std::string& szKey, const location& loc)
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		while (!crawler.end()) {
			std::shared_ptr<activation_record> ar = crawler.next();
			std::any out;
			if (ar->environment->get(szKey, out)) {
				return retrieve_callable(out);
			}
		}
		throw ProgramException("unable to retrieve callable with key '" + szKey + "'", loc);
	}


	void assign(const std::string& szKey, std::any value, const location& loc)
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		while (!crawler.end()) {
			std::shared_ptr<activation_record> ar = crawler.next();
			if (ar->environment->assign(szKey, value)) {
				return;
			}
		}
		throw ProgramException("unable to assign value to key '" + szKey + "'; key not found or type mismatch", loc);
	}
	

	void define(const std::string& szKey, std::any value, bool overwrite, const location& loc)
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		while (!crawler.end()) {
			std::shared_ptr<activation_record> ar = crawler.next();
			if (ar->environment->define(szKey, value, overwrite)) {
				return;
			}
		}
		throw ProgramException("unable to define value to key '" + szKey + "'; key already defined", loc);
	}

	
	void output(const std::string& exclude = "")
	{
		for (unsigned int i{ 0 }; i < m_records.size(); i++) {
			std::cout << toString(*m_records.at(i), exclude) << "\n";
		}
	}

	execution_context top()
	{
		rlist_crawler<std::shared_ptr<activation_record>> crawler(m_records);
		return execution_context({ crawler.back() }, m_opHandler);
	}


	std::shared_ptr<callable> retrieve_callable(std::any callee) {
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


	std::shared_ptr<activation_record> current_ar()
	{
		if (m_records.size() == 0) throw ProgramException("no activation record to execute", location(), Severity().CRITICAL());
		return m_records.at(m_records.size() - 1);
	}


	std::shared_ptr<callable> getOperator(const std::string& szName)
	{
		return m_opHandler->getOperator(szName);
	}

	std::shared_ptr<callable> getOperator(const std::string& szName, std::vector<std::any> args)
	{
		return m_opHandler->getOperator(Utilities().createOperatorSignature(szName, args));
	}

private:

	std::string toString(const activation_record& ar, const std::string& exclude = "")
	{
		std::ostringstream oss;
		oss << "<" << ar.szAlias << ":" << ar.id << ">";
		oss << "\r\n\t" << ar.environment->toString();
		oss << "\r\n</" << (ar.szAlias.empty() ? ":" + std::to_string(ar.id) : ar.szAlias) << ">";
		return oss.str();
	}

	unsigned int m_index{ 0 };
	std::vector<std::shared_ptr<activation_record>> m_records;
	std::shared_ptr<OperatorHandler> m_opHandler{ nullptr };
};

#endif