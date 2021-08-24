#pragma once


#include <memory>
#include "environment.h"
#include "context.h"
#include "exceptions.h"

class klass_instance {
public:
	klass_instance(std::shared_ptr<activation_record> environment)
		:m_environment{ environment }{}
	~klass_instance() {}

	void Define(std::string szName, std::any value, const location& loc, bool overwrite) {
		m_environment->Define(szName, value, loc, overwrite);
	}

	void Assign(std::string szName, std::any value, const location& loc) {
		m_environment->Assign(szName, value, loc);
	}

	std::any Get(std::string szName, const location& loc) {
		return m_environment->Get(szName, loc);
	}

	void Delete(std::string szName, const location& loc)
	{
		m_environment->Delete(szName, loc);
	}

	void Delete_NoThrow(std::string szName, const location& loc){
		m_environment->Delete_NoThrow(szName, loc);
	}

private:
	std::shared_ptr<activation_record> m_environment;
};


class klass_definition {
public:
	klass_definition(std::string szName, std::shared_ptr<activation_record> ar)
		:m_szName{ szName }, m_ar{ ar }{}
	~klass_definition() {}

	klass_instance create()
	{
		return klass_instance();
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
			throw ProgramException("unable to get value from key" + szName, loc);
		}
	}

private:

	std::string m_szName{ "" };
	std::shared_ptr<activation_record> m_ar;
};