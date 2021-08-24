#pragma once

#include <memory>
#include <any>

#include "scope.h"
#include "location.h"
#include "exceptions.h"

class native_object {
public:
	native_object()
	{
		m_env = std::make_shared<scope<std::any>>("native_object");
	}
	~native_object(){}


	virtual void Define(std::string szName, std::any value, const location& loc, bool overwrite) {
		if (!m_env->define(szName, value, overwrite)) {
			throw ProgramException("unable to define value " + szName, loc);
		}
	}

	virtual void Assign(std::string szName, std::any value, const location& loc) {
		if (!m_env->assign(szName, value)) {
			throw ProgramException("unable to assign value " + szName, loc);
		}
	}

	virtual std::any Get(std::string szName, const location& loc) {
		std::any out;
		if (!m_env->get(szName, out)) {
			throw ProgramException("unable to get value from key" + szName, loc);
		}
		return out;
	}

private:
	std::shared_ptr<scope<std::any>> m_env{ nullptr };

};


class list_object 
: public native_object {
public:



};