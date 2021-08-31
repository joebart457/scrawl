#include "Utilities.h"

#include <sstream>

#include "callable.h"
#include "klass_instance.h"

std::string Utilities::stringify(const std::any& obj)
{
	std::ostringstream oss;
	if (obj.type() == typeid(int)) {
		oss << std::any_cast<int>(obj);
	}
	else if (obj.type() == typeid(bool)) {
		oss << std::any_cast<bool>(obj);
	}
	else if (obj.type() == typeid(float)) {
		oss << std::any_cast<float>(obj);
	}
	else if (obj.type() == typeid(double)) {
		oss << std::any_cast<double>(obj);
	}
	else if (obj.type() == typeid(unsigned long)) {
		oss << std::any_cast<unsigned long>(obj);
	}
	else if (obj.type() == typeid(std::string)) {
		oss << std::any_cast<std::string>(obj);
	}
	// TODO: do this better
	else if (obj.type() == typeid(std::shared_ptr<native_fn>)) {
		oss << (std::any_cast<std::shared_ptr<native_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<native_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<binary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<binary_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<binary_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<custom_fn>)) {
		oss << (std::any_cast<std::shared_ptr<custom_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<custom_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<unary_fn>)) {
		oss << (std::any_cast<std::shared_ptr<unary_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<callable>)) {
		oss << (std::any_cast<std::shared_ptr<callable>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<klass_definition>)) {
		oss << (std::any_cast<std::shared_ptr<klass_definition>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<klass_definition>>(obj)->toString());
	}
	else if (obj.type() == typeid(klass_instance)) {
		oss << std::any_cast<klass_instance>(obj).toString();
	}
	else if (obj.type() == typeid(nullptr)) {
		oss << "<null>";
	}
	else {
		oss << "<object>";
	}
	return oss.str();
}



bool Utilities::isTruthy(const std::any& obj)
{
	if (obj.type() == typeid(int)) {
		return std::any_cast<int>(obj);
	}
	else if (obj.type() == typeid(unsigned long)) {
		return std::any_cast<unsigned long>(obj);
	}
	else if (obj.type() == typeid(bool)) {
		return std::any_cast<bool>(obj);
	}
	else if (obj.type() == typeid(float)) {
		return std::any_cast<float>(obj);
	}
	else if (obj.type() == typeid(double)) {
		return std::any_cast<double>(obj);
	}
	else if (obj.type() == typeid(std::string)) {
		return std::any_cast<std::string>(obj).size() > 0;
	}

	throw ProgramException("Unsupported object type '" + std::string(obj.type().name()), location());
}