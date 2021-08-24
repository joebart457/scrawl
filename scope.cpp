#include "scope.h"

#include "callable.h"

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<T>& ptr) {
	if (ptr == nullptr) {
		out << "null";
		return out;
	}
	else {
		out << *ptr;
		return out;
	}
}

std::ostream& operator<<(std::ostream& out, const std::any& obj) {
	if (obj.type() == typeid(int)) {
		out << std::any_cast<int>(obj);
	}
	else if (obj.type() == typeid(bool)) {
		out << std::any_cast<bool>(obj);
	}
	else if (obj.type() == typeid(float)) {
		out << std::any_cast<float>(obj);
	}
	else if (obj.type() == typeid(double)) {
		out << std::any_cast<double>(obj);
	}
	else if (obj.type() == typeid(unsigned long)) {
		out << std::any_cast<unsigned long>(obj);
	}
	else if (obj.type() == typeid(std::string)) {
		out << std::any_cast<std::string>(obj);
	}
	// TODO: do this better
	else if (obj.type() == typeid(std::shared_ptr<native_fn>)) {
		out << (std::any_cast<std::shared_ptr<native_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<native_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<custom_fn>)) {
		out << (std::any_cast<std::shared_ptr<custom_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<custom_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<binary_fn>)) {
		out << (std::any_cast<std::shared_ptr<binary_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<binary_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<unary_fn>)) {
		out << (std::any_cast<std::shared_ptr<unary_fn>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<unary_fn>>(obj)->getSignature());
	}
	else if (obj.type() == typeid(std::shared_ptr<callable>)) {
		out << (std::any_cast<std::shared_ptr<callable>>(obj) == nullptr ? "<null>" : std::any_cast<std::shared_ptr<callable>>(obj)->getSignature());
	}
	else {
		out << "<object>";
	}
	return out;
}