#pragma once


#include "interpreter.h"
#include <memory>
#include <any>
#include <string>
#include "klass_instance.h"



std::any add_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<int>(rhs);
}


std::any less_than_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<int>(rhs);
}


std::any type_of_any(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return std::string(rhs.type().name());
}

std::any index_list_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	unsigned long index = std::any_cast<unsigned long>(rhs);
	klass_instance instance = std::any_cast<klass_instance>(lhs);
	return instance.Get(std::to_string(index), location());
}

std::any index_list_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	int index = std::any_cast<int>(rhs);
	klass_instance instance = std::any_cast<klass_instance>(lhs);
	return instance.Get(std::to_string(index), location());
}

std::any index_list_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	std::string index = std::any_cast<std::string> (rhs);
	klass_instance instance = std::any_cast<klass_instance>(lhs);
	return instance.Get(index, location());
}