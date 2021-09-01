#pragma once


#include <any>
#include <memory>
#include <vector>
#include <string>

class callable;
class execution_context;
class interpreter;

class Utilities
{
public:
	static void check_context(std::shared_ptr<interpreter> c);
	static std::shared_ptr<execution_context> fetch_context(std::shared_ptr<interpreter> i);
	static std::string stringify(const std::any& obj);
	static bool isTruthy(const std::any& obj);
	static std::string createOperatorSignature(const std::string& szName, std::vector<std::any> args);
	static std::shared_ptr<callable> getCallable(std::any callee);
	static std::string getTypeString(std::any& obj);
};

