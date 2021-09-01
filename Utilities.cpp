#include "Utilities.h"

#include <sstream>

#include "callable.h"
#include "klass_instance.h"
#include "interpreter.h"


void Utilities::check_context(std::shared_ptr<interpreter> i)
{
	if (i == nullptr) {
		location loc;
		throw ProgramException("cannot execute code using null interpreter", loc, Severity().FATAL());
	}
}

std::shared_ptr<execution_context> Utilities::fetch_context(std::shared_ptr<interpreter> i)
{
	std::shared_ptr<execution_context> context_ptr = nullptr;
	if (i != nullptr) {
		context_ptr = i->get_context();
	}
	if (i == nullptr || context_ptr == nullptr) {
		location loc;
		throw ProgramException("cannot execute code in null context", loc, Severity().FATAL());
	}
	return context_ptr;
}


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


std::string Utilities::createOperatorSignature(const std::string& szName, std::vector<std::any> args)
{
	std::ostringstream oss;
	oss << szName << "(";
	if (args.size() > 0) {
		std::string type_name = args.at(0).type().name();
		if (args.at(0).type() == typeid(klass_instance)) {
			type_name = std::any_cast<klass_instance>(args.at(0)).getType();
		}
		oss << type_name;
	}
	for (unsigned int i{ 1 }; i < args.size(); i++) {
		std::string type_name = args.at(i).type().name();
		if (args.at(i).type() == typeid(klass_instance)) {
			type_name = std::any_cast<klass_instance>(args.at(i)).getType();
		}
		oss << "," << type_name;
	}
	oss << ")";
	return oss.str();
}


std::shared_ptr<callable> Utilities::getCallable(std::any callee) {
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


std::string Utilities::getTypeString(std::any& obj)
{
	if (obj.type() == typeid(klass_instance)) {
		return std::any_cast<klass_instance>(obj).getType();
	}
	return obj.type().name();
}