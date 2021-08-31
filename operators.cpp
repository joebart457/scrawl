#include "operators.h"

#include "klass_instance.h"
#include "exceptions.h"
#include "Utilities.h"

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









/*
-
- int
-
*/


std::any not_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !Utilities().isTruthy(rhs);
}
std::any negate_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return -std::any_cast<int>(rhs);
}


// add


std::any add_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<int>(rhs);
}
std::any add_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<unsigned long>(rhs);
}
std::any add_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<float>(rhs);
}
std::any add_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<double>(rhs);
}
std::any add_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) + std::any_cast<bool>(rhs);
}
std::any add_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// subtract


std::any subtract_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) - std::any_cast<int>(rhs);
}
std::any subtract_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) - std::any_cast<unsigned long>(rhs);
}
std::any subtract_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) - std::any_cast<float>(rhs);
}
std::any subtract_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) - std::any_cast<double>(rhs);
}
std::any subtract_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) - std::any_cast<bool>(rhs);
}
std::any subtract_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) * std::any_cast<int>(rhs);
}
std::any multiply_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) * std::any_cast<unsigned long>(rhs);
}
std::any multiply_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) * std::any_cast<float>(rhs);
}
std::any multiply_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) * std::any_cast<double>(rhs);
}
std::any multiply_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) * std::any_cast<bool>(rhs);
}
std::any multiply_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<int>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<int>(lhs) / rhsVal;
}
std::any divide_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<unsigned long>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<int>(lhs) / rhsVal;
}
std::any divide_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<float>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<int>(lhs) / rhsVal;
}
std::any divide_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<double>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<int>(lhs) / rhsVal;
}
std::any divide_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<bool>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<int>(lhs) / rhsVal;
}
std::any divide_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<int>(rhs);
}
std::any lessthan_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<unsigned long>(rhs);
}
std::any lessthan_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<float>(rhs);
}
std::any lessthan_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<double>(rhs);
}
std::any lessthan_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) < std::any_cast<bool>(rhs);
}
std::any lessthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) <= std::any_cast<int>(rhs);
}
std::any lessthanequal_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) <= std::any_cast<unsigned long>(rhs);
}
std::any lessthanequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) <= std::any_cast<float>(rhs);
}
std::any lessthanequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) <= std::any_cast<double>(rhs);
}
std::any lessthanequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) <= std::any_cast<bool>(rhs);
}
std::any lessthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than


std::any greaterthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) > std::any_cast<int>(rhs);
}
std::any greaterthan_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) > std::any_cast<unsigned long>(rhs);
}
std::any greaterthan_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) > std::any_cast<float>(rhs);
}
std::any greaterthan_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) > std::any_cast<double>(rhs);
}
std::any greaterthan_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) > std::any_cast<bool>(rhs);
}
std::any greaterthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than equal


std::any greaterthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) >= std::any_cast<int>(rhs);
}
std::any greaterthanequal_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) >= std::any_cast<unsigned long>(rhs);
}
std::any greaterthanequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) >= std::any_cast<float>(rhs);
}
std::any greaterthanequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) >= std::any_cast<double>(rhs);
}
std::any greaterthanequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) >= std::any_cast<bool>(rhs);
}
std::any greaterthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) == std::any_cast<int>(rhs);
}
std::any equalequal_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) == std::any_cast<unsigned long>(rhs);
}
std::any equalequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) == std::any_cast<float>(rhs);
}
std::any equalequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) == std::any_cast<double>(rhs);
}
std::any equalequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) == std::any_cast<bool>(rhs);
}
std::any equalequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// Not equal


std::any notequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) != std::any_cast<int>(rhs);
}
std::any notequal_int_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) != std::any_cast<unsigned long>(rhs);
}
std::any notequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) != std::any_cast<float>(rhs);
}
std::any notequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) != std::any_cast<double>(rhs);
}
std::any notequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<int>(lhs) != std::any_cast<bool>(rhs);
}
std::any notequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


/*
-
- end int
-
*/





/*
-
- unsigned long
-
*/


std::any not_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !Utilities().isTruthy(rhs);
}
std::any negate_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return -std::any_cast<unsigned long>(rhs);
}


// add


std::any add_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) + std::any_cast<int>(rhs);
}
std::any add_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) + std::any_cast<unsigned long>(rhs);
}
std::any add_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) + std::any_cast<float>(rhs);
}
std::any add_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) + std::any_cast<double>(rhs);
}
std::any add_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) + std::any_cast<bool>(rhs);
}
std::any add_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// subtract


std::any subtract_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) - std::any_cast<int>(rhs);
}
std::any subtract_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) - std::any_cast<unsigned long>(rhs);
}
std::any subtract_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) - std::any_cast<float>(rhs);
}
std::any subtract_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) - std::any_cast<double>(rhs);
}
std::any subtract_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) - std::any_cast<bool>(rhs);
}
std::any subtract_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) * std::any_cast<int>(rhs);
}
std::any multiply_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) * std::any_cast<unsigned long>(rhs);
}
std::any multiply_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) * std::any_cast<float>(rhs);
}
std::any multiply_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) * std::any_cast<double>(rhs);
}
std::any multiply_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) * std::any_cast<bool>(rhs);
}
std::any multiply_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<int>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<unsigned long>(lhs) / rhsVal;
}
std::any divide_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<unsigned long>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<unsigned long>(lhs) / rhsVal;
}
std::any divide_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<float>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<unsigned long>(lhs) / rhsVal;
}
std::any divide_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<double>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<unsigned long>(lhs) / rhsVal;
}
std::any divide_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<bool>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<unsigned long>(lhs) / rhsVal;
}
std::any divide_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) < std::any_cast<int>(rhs);
}
std::any lessthan_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) < std::any_cast<unsigned long>(rhs);
}
std::any lessthan_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) < std::any_cast<float>(rhs);
}
std::any lessthan_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) < std::any_cast<double>(rhs);
}
std::any lessthan_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) < std::any_cast<bool>(rhs);
}
std::any lessthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) <= std::any_cast<int>(rhs);
}
std::any lessthanequal_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) <= std::any_cast<unsigned long>(rhs);
}
std::any lessthanequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) <= std::any_cast<float>(rhs);
}
std::any lessthanequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) <= std::any_cast<double>(rhs);
}
std::any lessthanequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) <= std::any_cast<bool>(rhs);
}
std::any lessthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than


std::any greaterthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) > std::any_cast<int>(rhs);
}
std::any greaterthan_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) > std::any_cast<unsigned long>(rhs);
}
std::any greaterthan_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) > std::any_cast<float>(rhs);
}
std::any greaterthan_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) > std::any_cast<double>(rhs);
}
std::any greaterthan_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) > std::any_cast<bool>(rhs);
}
std::any greaterthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than equal


std::any greaterthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) >= std::any_cast<int>(rhs);
}
std::any greaterthanequal_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) >= std::any_cast<unsigned long>(rhs);
}
std::any greaterthanequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) >= std::any_cast<float>(rhs);
}
std::any greaterthanequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) >= std::any_cast<double>(rhs);
}
std::any greaterthanequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) >= std::any_cast<bool>(rhs);
}
std::any greaterthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) == std::any_cast<int>(rhs);
}
std::any equalequal_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) == std::any_cast<unsigned long>(rhs);
}
std::any equalequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) == std::any_cast<float>(rhs);
}
std::any equalequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) == std::any_cast<double>(rhs);
}
std::any equalequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) == std::any_cast<bool>(rhs);
}
std::any equalequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// Not equal


std::any notequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) != std::any_cast<int>(rhs);
}
std::any notequal_unsignedlong_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) != std::any_cast<unsigned long>(rhs);
}
std::any notequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) != std::any_cast<float>(rhs);
}
std::any notequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) != std::any_cast<double>(rhs);
}
std::any notequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<unsigned long>(lhs) != std::any_cast<bool>(rhs);
}
std::any notequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


/*
-
- end unsigned long
-
*/





/*
-
- float
-
*/


std::any not_float(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !Utilities().isTruthy(rhs);
}
std::any negate_float(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return -std::any_cast<float>(rhs);
}


// add


std::any add_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) + std::any_cast<int>(rhs);
}
std::any add_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) + std::any_cast<unsigned long>(rhs);
}
std::any add_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) + std::any_cast<float>(rhs);
}
std::any add_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) + std::any_cast<double>(rhs);
}
std::any add_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) + std::any_cast<bool>(rhs);
}
std::any add_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// subtract


std::any subtract_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) - std::any_cast<int>(rhs);
}
std::any subtract_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) - std::any_cast<unsigned long>(rhs);
}
std::any subtract_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) - std::any_cast<float>(rhs);
}
std::any subtract_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) - std::any_cast<double>(rhs);
}
std::any subtract_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) - std::any_cast<bool>(rhs);
}
std::any subtract_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) * std::any_cast<int>(rhs);
}
std::any multiply_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) * std::any_cast<unsigned long>(rhs);
}
std::any multiply_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) * std::any_cast<float>(rhs);
}
std::any multiply_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) * std::any_cast<double>(rhs);
}
std::any multiply_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) * std::any_cast<bool>(rhs);
}
std::any multiply_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<int>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<float>(lhs) / rhsVal;
}
std::any divide_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<unsigned long>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<float>(lhs) / rhsVal;
}
std::any divide_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<float>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<float>(lhs) / rhsVal;
}
std::any divide_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<double>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<float>(lhs) / rhsVal;
}
std::any divide_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<bool>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<float>(lhs) / rhsVal;
}
std::any divide_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) < std::any_cast<int>(rhs);
}
std::any lessthan_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) < std::any_cast<unsigned long>(rhs);
}
std::any lessthan_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) < std::any_cast<float>(rhs);
}
std::any lessthan_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) < std::any_cast<double>(rhs);
}
std::any lessthan_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) < std::any_cast<bool>(rhs);
}
std::any lessthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) <= std::any_cast<int>(rhs);
}
std::any lessthanequal_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) <= std::any_cast<unsigned long>(rhs);
}
std::any lessthanequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) <= std::any_cast<float>(rhs);
}
std::any lessthanequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) <= std::any_cast<double>(rhs);
}
std::any lessthanequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) <= std::any_cast<bool>(rhs);
}
std::any lessthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than


std::any greaterthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) > std::any_cast<int>(rhs);
}
std::any greaterthan_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) > std::any_cast<unsigned long>(rhs);
}
std::any greaterthan_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) > std::any_cast<float>(rhs);
}
std::any greaterthan_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) > std::any_cast<double>(rhs);
}
std::any greaterthan_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) > std::any_cast<bool>(rhs);
}
std::any greaterthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than equal


std::any greaterthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) >= std::any_cast<int>(rhs);
}
std::any greaterthanequal_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) >= std::any_cast<unsigned long>(rhs);
}
std::any greaterthanequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) >= std::any_cast<float>(rhs);
}
std::any greaterthanequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) >= std::any_cast<double>(rhs);
}
std::any greaterthanequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) >= std::any_cast<bool>(rhs);
}
std::any greaterthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) == std::any_cast<int>(rhs);
}
std::any equalequal_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) == std::any_cast<unsigned long>(rhs);
}
std::any equalequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) == std::any_cast<float>(rhs);
}
std::any equalequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) == std::any_cast<double>(rhs);
}
std::any equalequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) == std::any_cast<bool>(rhs);
}
std::any equalequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// Not equal


std::any notequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) != std::any_cast<int>(rhs);
}
std::any notequal_float_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) != std::any_cast<unsigned long>(rhs);
}
std::any notequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) != std::any_cast<float>(rhs);
}
std::any notequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) != std::any_cast<double>(rhs);
}
std::any notequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<float>(lhs) != std::any_cast<bool>(rhs);
}
std::any notequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


/*
-
- end float
-
*/




/*
-
- int
-
*/


std::any not_double(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !Utilities().isTruthy(rhs);
}
std::any negate_double(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return -std::any_cast<double>(rhs);
}


// add


std::any add_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) + std::any_cast<int>(rhs);
}
std::any add_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) + std::any_cast<unsigned long>(rhs);
}
std::any add_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) + std::any_cast<float>(rhs);
}
std::any add_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) + std::any_cast<double>(rhs);
}
std::any add_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) + std::any_cast<bool>(rhs);
}
std::any add_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// subtract


std::any subtract_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) - std::any_cast<int>(rhs);
}
std::any subtract_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) - std::any_cast<unsigned long>(rhs);
}
std::any subtract_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) - std::any_cast<float>(rhs);
}
std::any subtract_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) - std::any_cast<double>(rhs);
}
std::any subtract_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) - std::any_cast<bool>(rhs);
}
std::any subtract_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) * std::any_cast<int>(rhs);
}
std::any multiply_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) * std::any_cast<unsigned long>(rhs);
}
std::any multiply_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) * std::any_cast<float>(rhs);
}
std::any multiply_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) * std::any_cast<double>(rhs);
}
std::any multiply_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) * std::any_cast<bool>(rhs);
}
std::any multiply_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<int>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<double>(lhs) / rhsVal;
}
std::any divide_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<unsigned long>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<double>(lhs) / rhsVal;
}
std::any divide_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<float>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<double>(lhs) / rhsVal;
}
std::any divide_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<double>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<double>(lhs) / rhsVal;
}
std::any divide_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<bool>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<double>(lhs) / rhsVal;
}
std::any divide_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) < std::any_cast<int>(rhs);
}
std::any lessthan_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) < std::any_cast<unsigned long>(rhs);
}
std::any lessthan_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) < std::any_cast<float>(rhs);
}
std::any lessthan_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) < std::any_cast<double>(rhs);
}
std::any lessthan_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) < std::any_cast<bool>(rhs);
}
std::any lessthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) <= std::any_cast<int>(rhs);
}
std::any lessthanequal_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) <= std::any_cast<unsigned long>(rhs);
}
std::any lessthanequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) <= std::any_cast<float>(rhs);
}
std::any lessthanequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) <= std::any_cast<double>(rhs);
}
std::any lessthanequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) <= std::any_cast<bool>(rhs);
}
std::any lessthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than


std::any greaterthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) > std::any_cast<int>(rhs);
}
std::any greaterthan_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) > std::any_cast<unsigned long>(rhs);
}
std::any greaterthan_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) > std::any_cast<float>(rhs);
}
std::any greaterthan_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) > std::any_cast<double>(rhs);
}
std::any greaterthan_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) > std::any_cast<bool>(rhs);
}
std::any greaterthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than equal


std::any greaterthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) >= std::any_cast<int>(rhs);
}
std::any greaterthanequal_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) >= std::any_cast<unsigned long>(rhs);
}
std::any greaterthanequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) >= std::any_cast<float>(rhs);
}
std::any greaterthanequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) >= std::any_cast<double>(rhs);
}
std::any greaterthanequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) >= std::any_cast<bool>(rhs);
}
std::any greaterthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) == std::any_cast<int>(rhs);
}
std::any equalequal_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) == std::any_cast<unsigned long>(rhs);
}
std::any equalequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) == std::any_cast<float>(rhs);
}
std::any equalequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) == std::any_cast<double>(rhs);
}
std::any equalequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) == std::any_cast<bool>(rhs);
}
std::any equalequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// Not equal


std::any notequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) != std::any_cast<int>(rhs);
}
std::any notequal_double_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) != std::any_cast<unsigned long>(rhs);
}
std::any notequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) != std::any_cast<float>(rhs);
}
std::any notequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) != std::any_cast<double>(rhs);
}
std::any notequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<double>(lhs) != std::any_cast<bool>(rhs);
}
std::any notequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


/*
-
- end double
-
*/



/*
-
- bool
-
*/


std::any not_bool (std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !(std::any_cast<bool>(rhs));
}
std::any negate_bool(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return -std::any_cast<bool>(rhs);
}


// add


std::any add_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) + std::any_cast<int>(rhs);
}
std::any add_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) + std::any_cast<unsigned long>(rhs);
}
std::any add_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) + std::any_cast<float>(rhs);
}
std::any add_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) + std::any_cast<double>(rhs);
}
std::any add_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) + std::any_cast<bool>(rhs);
}
std::any add_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// subtract


std::any subtract_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) - std::any_cast<int>(rhs);
}
std::any subtract_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) - std::any_cast<unsigned long>(rhs);
}
std::any subtract_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) - std::any_cast<float>(rhs);
}
std::any subtract_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) - std::any_cast<double>(rhs);
}
std::any subtract_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) - std::any_cast<bool>(rhs);
}
std::any subtract_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) * std::any_cast<int>(rhs);
}
std::any multiply_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) * std::any_cast<unsigned long>(rhs);
}
std::any multiply_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) * std::any_cast<float>(rhs);
}
std::any multiply_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) * std::any_cast<double>(rhs);
}
std::any multiply_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) * std::any_cast<bool>(rhs);
}
std::any multiply_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<int>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<bool>(lhs) / rhsVal;
}
std::any divide_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<unsigned long>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<bool>(lhs) / rhsVal;
}
std::any divide_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<float>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<bool>(lhs) / rhsVal;
}
std::any divide_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<double>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<bool>(lhs) / rhsVal;
}
std::any divide_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	auto rhsVal = std::any_cast<bool>(rhs);
	if (rhsVal == 0) {
		throw ProgramException("unable to divide by 0", location());
	}
	return std::any_cast<bool>(lhs) / rhsVal;
}
std::any divide_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) < std::any_cast<int>(rhs);
}
std::any lessthan_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) < std::any_cast<unsigned long>(rhs);
}
std::any lessthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) < std::any_cast<float>(rhs);
}
std::any lessthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) < std::any_cast<double>(rhs);
}
std::any lessthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) < std::any_cast<bool>(rhs);
}
std::any lessthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) <= std::any_cast<int>(rhs);
}
std::any lessthanequal_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) <= std::any_cast<unsigned long>(rhs);
}
std::any lessthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) <= std::any_cast<float>(rhs);
}
std::any lessthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) <= std::any_cast<double>(rhs);
}
std::any lessthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) <= std::any_cast<bool>(rhs);
}
std::any lessthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than


std::any greaterthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) > std::any_cast<int>(rhs);
}
std::any greaterthan_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) > std::any_cast<unsigned long>(rhs);
}
std::any greaterthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) > std::any_cast<float>(rhs);
}
std::any greaterthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) > std::any_cast<double>(rhs);
}
std::any greaterthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) > std::any_cast<bool>(rhs);
}
std::any greaterthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// greater than equal


std::any greaterthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) >= std::any_cast<int>(rhs);
}
std::any greaterthanequal_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) >= std::any_cast<unsigned long>(rhs);
}
std::any greaterthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) >= std::any_cast<float>(rhs);
}
std::any greaterthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) >= std::any_cast<double>(rhs);
}
std::any greaterthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) >= std::any_cast<bool>(rhs);
}
std::any greaterthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) == std::any_cast<int>(rhs);
}
std::any equalequal_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) == std::any_cast<unsigned long>(rhs);
}
std::any equalequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) == std::any_cast<float>(rhs);
}
std::any equalequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) == std::any_cast<double>(rhs);
}
std::any equalequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) == std::any_cast<bool>(rhs);
}
std::any equalequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// Not equal


std::any notequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) != std::any_cast<int>(rhs);
}
std::any notequal_bool_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) != std::any_cast<unsigned long>(rhs);
}
std::any notequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) != std::any_cast<float>(rhs);
}
std::any notequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) != std::any_cast<double>(rhs);
}
std::any notequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<bool>(lhs) != std::any_cast<bool>(rhs);
}
std::any notequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


/*
-
- end bool
-
*/



/*
-
- string
-
*/


std::any not_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return !Utilities().isTruthy(rhs);
}
std::any negate_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// add


std::any add_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<int>(rhs));
}
std::any add_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<unsigned long>(rhs));
}
std::any add_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<float>(rhs));
}
std::any add_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<double>(rhs));
}
std::any add_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<bool>(rhs));
}
std::any add_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) + std::any_cast<std::string>(rhs);
}


// subtract


std::any subtract_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any subtract_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any subtract_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any subtract_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any subtract_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any subtract_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// multiply


std::any multiply_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any multiply_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any multiply_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any multiply_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any multiply_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any multiply_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// divide


std::any divide_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any divide_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any divide_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any divide_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any divide_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any divide_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// index


std::any index_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	std::string lhsVal = std::any_cast<std::string>(lhs);
	unsigned int rhsVal = std::any_cast<int>(rhs);

	if (rhsVal < lhsVal.size()) {
		return std::string(lhsVal.at(rhsVal), 1);
	}
	throw ProgramException("string index out of range", location());
}
std::any index_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	std::string lhsVal = std::any_cast<std::string>(lhs);
	unsigned long rhsVal = std::any_cast<unsigned long>(rhs);

	if (rhsVal < lhsVal.size()) {
		return std::string(lhsVal.at(rhsVal), 1);
	}
	throw ProgramException("string index out of range", location());
}
std::any index_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any index_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than


std::any lessthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthan_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// less than equal


std::any lessthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthanequal_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any lessthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}



// greater than


std::any greaterthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthan_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any greaterthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}



// greater than equal


std::any greaterthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthanequal_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}

std::any greaterthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}


// equal equal


std::any equalequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any equalequal_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any equalequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any equalequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any equalequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any equalequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) == std::any_cast<std::string>(rhs);
}


// Not equal


std::any notequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any notequal_string_unsigned_long(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any notequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any notequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any notequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	throw ProgramException("unsupported operation", location());
}
std::any notequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	return std::any_cast<std::string>(lhs) != std::any_cast<std::string>(rhs);
}


/*
-
- end string
-
*/
