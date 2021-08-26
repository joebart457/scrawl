#pragma once


#include <memory>
#include <any>

#include "environment.h"
#include "context.h"
#include "exceptions.h"

class klass_instance {
public:
	klass_instance(const std::string& type, const std::string& signature, std::shared_ptr<activation_record> ar)
		:m_szType{ type }, m_szSignature{ signature }, m_ar{ ar } {}
	~klass_instance() {}

	bool Exists(const std::string& szName) {
		return m_ar->environment->exists_local(szName);
	}

	void Define(std::string szName, std::any value, const location& loc, bool overwrite) {
		if (!m_ar->environment->define(szName, value, overwrite)) {
			throw ProgramException("unable to define value " + szName, loc);
		}
	}

	void Assign(std::string szName, std::any value, const location& loc) {
		if (!m_ar->environment->assign(szName, value)) {
			throw ProgramException("unable to assign value " + szName, loc);
		}
	}

	std::any Get(std::string szName, const location& loc) {
		std::any out;
		if (!m_ar->environment->get(szName, out)) {
			throw ProgramException("unable to get value from key " + szName, loc);
		}
		return out;
	}

	std::string getSignature()
	{
		return m_szSignature;
	}

	std::string getType()
	{
		return m_szType;
	}

	std::string toString()
	{
		return m_ar->environment->toString();
	}

private:
	std::string m_szSignature{ "class_instance_0" };
	std::string m_szType{ "class_instance" };
	std::shared_ptr<activation_record> m_ar;
};

class klass_definition {
public:
	klass_definition(std::string szName, std::shared_ptr<activation_record> ar)
		:m_szName{ szName }, m_ar{ ar }{}
	~klass_definition() {}

	klass_instance create()
	{

		std::string alias = m_szName + "_instance_" + std::to_string(m_refIndex);
		std::shared_ptr<activation_record> ar = std::make_shared<activation_record>();
		ar->environment = m_ar->environment->copy();
		ar->szAlias = alias;
		m_refIndex = m_refIndex + 1;
		auto m = ar->environment->lookup();
		for (auto it = m->begin(); it != m->end(); it++) {
			if (it->second.type() == typeid(std::shared_ptr<custom_fn>)) {
				std::shared_ptr<custom_fn> fn = std::any_cast<std::shared_ptr<custom_fn>>(it->second);
				fn = std::make_shared<custom_fn>(*fn.get());
				fn->setEnclosing(ar);
				ar->environment->define(it->first, fn, true);
			} 
			else if (it->second.type() == typeid(std::shared_ptr<native_fn>)) {
				std::shared_ptr<native_fn> fn = std::any_cast<std::shared_ptr<native_fn>>(it->second);
				fn = std::make_shared<native_fn>(*fn.get());
				fn->setEnclosing(ar);
				ar->environment->define(it->first, fn, true);
			}
		}
		return klass_instance(m_szName, alias, ar);
	}

	bool Exists(const std::string& szName) {
		return m_ar->environment->exists_local(szName);
	}

	void Define(std::string szName, std::any value, const location& loc, bool overwrite) {
		if (!m_ar->environment->define(szName, value, overwrite)) {
			throw ProgramException("unable to define value " + szName, loc);
		}
	}

	void Assign(std::string szName, std::any value, const location& loc) {
		if (!m_ar->environment->assign(szName, value)) {
			throw ProgramException("unable to assign value " + szName, loc);
		}
	}

	std::any Get(std::string szName, const location& loc) {
		std::any out;
		if (!m_ar->environment->get(szName, out)) {
			throw ProgramException("unable to get value from key " + szName, loc);
		}
		return out;
	}

	std::string toString()
	{
		return m_ar->environment->toString();
	}

	std::string getSignature()
	{
		return "class " + m_szName + " :r" + std::to_string(m_refIndex);
	}

private:

	unsigned int m_refIndex{ 0 };
	std::string m_szName{ "" };
	std::shared_ptr<activation_record> m_ar;
};