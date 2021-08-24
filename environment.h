
#ifndef __INCLUDE_ENVIRONMENT_H
#define __INCLUDE_ENVIRONMENT_H

#include <string>
#include <any>
#include <memory>
#include <map>

#include "location.h"

class Environment:
	std::enable_shared_from_this<Environment>
{
public:
	Environment(std::shared_ptr<Environment> environment)
		:m_enclosing{ environment }{}
	~Environment(){}

	bool Exists(const std::string& szKey);
	bool Exists_Local(const std::string& szKey);

	void Define(std::string szName, std::any value, const location& loc, bool overwrite);
	void Assign(std::string szName, std::any value, const location& loc);
	std::any Get(std::string szName, const location& loc);
	void Delete(std::string szName, const location& loc);
	void Delete_NoThrow(std::string szName, const location& loc);
	std::shared_ptr<Environment> Copy();
	void SetEnclosing(std::shared_ptr<Environment> enclosing);
	std::shared_ptr<Environment> GetEnclosing();
	std::string toString(std::string tabs = "");
private:

	std::shared_ptr<Environment> m_enclosing;
	std::map<std::string, std::any> m_values;
};

#endif