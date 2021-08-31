#pragma once

#include <string>
#include <any>

class Utilities
{
public:
	static std::string stringify(const std::any& obj);
	bool isTruthy(const std::any& obj)
};

