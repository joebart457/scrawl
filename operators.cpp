#include "operators.h"

#include "klass_instance.h"
#include "exceptions.h"
#include "Utilities.h"

/*
* 
* Necessary for operator Auto Generation capabilites
*  
std::any equalequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<std::string>(lhs) == std::any_cast<std::string>(rhs);
}

std::any less_than_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) < std::any_cast<int>(rhs);
}

std::any index_list_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    int index = std::any_cast<int>(rhs);
    klass_instance instance = std::any_cast<klass_instance>(lhs);
    return instance.Get(std::to_string(index), location());
}

std::any add_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<std::string>(lhs) + std::any_cast<std::string>(rhs);
}

*/
 
std::any index_list_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    int index = std::any_cast<int>(rhs);
    klass_instance instance = std::any_cast<klass_instance>(lhs);
    return instance.Get(std::to_string(index), location());
}


std::any type_of_any(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return std::string(rhs.type().name());
}


std::any index_list_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    unsigned long index = std::any_cast<unsigned long>(rhs);
    klass_instance instance = std::any_cast<klass_instance>(lhs);
    return instance.Get(std::to_string(index), location());
}

std::any index_list_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
	std::string index = std::any_cast<std::string> (rhs);
	klass_instance instance = std::any_cast<klass_instance>(lhs);
	return instance.Get(index, location());
}

std::any index_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    std::string lhsVal = std::any_cast<std::string>(lhs);
    unsigned int rhsVal = std::any_cast<int>(rhs);

    if (rhsVal < lhsVal.size()) {
        return std::string(lhsVal.at(rhsVal), 1);
    }
    throw ProgramException("string index out of range", location());
}

std::any index_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    std::string lhsVal = std::any_cast<std::string>(lhs);
    unsigned long rhsVal = std::any_cast<unsigned long>(rhs);

    if (rhsVal < lhsVal.size()) {
        return std::string(lhsVal.at(rhsVal), 1);
    }
    throw ProgramException("string index out of range", location());
}


/* End Custom Defined Binary Operators */


/* Auto Generated using op_create.scrwl */


/*
-
- start not
-
*/

std::any not_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_float(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_double(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_bool(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_string(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}

std::any not_null(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return !Utilities().isTruthy(rhs);
}


/*
-
- end not
-
*/


/*
-
- start negate
-
*/

std::any negate_int(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return std::any_cast<int>(rhs);
}

std::any negate_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any negate_float(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return std::any_cast<float>(rhs);
}

std::any negate_double(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return std::any_cast<double>(rhs);
}

std::any negate_bool(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return std::any_cast<bool>(rhs);
}

std::any negate_string(std::shared_ptr<interpreter> i, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any negate_null(std::shared_ptr<interpreter> i, std::any& rhs)
{
    return std::any_cast<std::nullptr_t>(rhs);
}


/*
-
- end negate
-
*/


/*
-
- start add
-
*/

std::any add_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) + std::any_cast<int>(rhs);
}

std::any add_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) + static_cast<int>(std::any_cast<bool>(rhs));
}

std::any add_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) + std::any_cast<int>(rhs);
}

std::any add_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) + static_cast<int>(std::any_cast<bool>(rhs));
}

std::any add_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) + std::any_cast<int>(rhs);
}

std::any add_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) + static_cast<int>(std::any_cast<bool>(rhs));
}

std::any add_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) + std::any_cast<int>(rhs);
}

std::any add_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) + static_cast<int>(std::any_cast<bool>(rhs));
}

std::any add_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) + std::any_cast<int>(rhs);
}

std::any add_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) + std::any_cast<unsigned long>(rhs);
}

std::any add_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) + std::any_cast<float>(rhs);
}

std::any add_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) + std::any_cast<double>(rhs);
}

std::any add_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) + static_cast<int>(std::any_cast<bool>(rhs));
}

std::any add_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<std::string>(lhs) + std::to_string(std::any_cast<int>(rhs));
}

std::any add_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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

std::any add_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any add_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any add_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end add
-
*/


/*
-
- start subtract
-
*/

std::any subtract_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) - std::any_cast<int>(rhs);
}

std::any subtract_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) - static_cast<int>(std::any_cast<bool>(rhs));
}

std::any subtract_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) - std::any_cast<int>(rhs);
}

std::any subtract_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) - static_cast<int>(std::any_cast<bool>(rhs));
}

std::any subtract_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) - std::any_cast<int>(rhs);
}

std::any subtract_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) - static_cast<int>(std::any_cast<bool>(rhs));
}

std::any subtract_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) - std::any_cast<int>(rhs);
}

std::any subtract_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) - static_cast<int>(std::any_cast<bool>(rhs));
}

std::any subtract_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) - std::any_cast<int>(rhs);
}

std::any subtract_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) - std::any_cast<unsigned long>(rhs);
}

std::any subtract_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) - std::any_cast<float>(rhs);
}

std::any subtract_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) - std::any_cast<double>(rhs);
}

std::any subtract_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) - static_cast<int>(std::any_cast<bool>(rhs));
}

std::any subtract_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any subtract_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any subtract_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end subtract
-
*/


/*
-
- start multiply
-
*/

std::any multiply_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) * std::any_cast<int>(rhs);
}

std::any multiply_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) * static_cast<int>(std::any_cast<bool>(rhs));
}

std::any multiply_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) * std::any_cast<int>(rhs);
}

std::any multiply_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) * static_cast<int>(std::any_cast<bool>(rhs));
}

std::any multiply_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) * std::any_cast<int>(rhs);
}

std::any multiply_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) * static_cast<int>(std::any_cast<bool>(rhs));
}

std::any multiply_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) * std::any_cast<int>(rhs);
}

std::any multiply_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) * static_cast<int>(std::any_cast<bool>(rhs));
}

std::any multiply_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) * std::any_cast<int>(rhs);
}

std::any multiply_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) * std::any_cast<unsigned long>(rhs);
}

std::any multiply_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) * std::any_cast<float>(rhs);
}

std::any multiply_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) * std::any_cast<double>(rhs);
}

std::any multiply_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) * static_cast<int>(std::any_cast<bool>(rhs));
}

std::any multiply_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any multiply_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any multiply_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end multiply
-
*/


/*
-
- start divide
-
*/

std::any divide_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<int>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<int>(lhs) / rhsVal;
}

std::any divide_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    auto rhsVal = static_cast<int>(std::any_cast<bool>(rhs));
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<int>(lhs) / rhsVal;
}

std::any divide_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<int>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<unsigned long>(lhs) / rhsVal;
}

std::any divide_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    auto rhsVal = static_cast<int>(std::any_cast<bool>(rhs));
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<unsigned long>(lhs) / rhsVal;
}

std::any divide_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<int>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<float>(lhs) / rhsVal;
}

std::any divide_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    auto rhsVal = static_cast<int>(std::any_cast<bool>(rhs));
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<float>(lhs) / rhsVal;
}

std::any divide_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<int>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<double>(lhs) / rhsVal;
}

std::any divide_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    auto rhsVal = static_cast<int>(std::any_cast<bool>(rhs));
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return std::any_cast<double>(lhs) / rhsVal;
}

std::any divide_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<int>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return static_cast<int>(std::any_cast<bool>(lhs)) / rhsVal;
}

std::any divide_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<unsigned long>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return static_cast<int>(std::any_cast<bool>(lhs)) / rhsVal;
}

std::any divide_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<float>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return static_cast<int>(std::any_cast<bool>(lhs)) / rhsVal;
}

std::any divide_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = std::any_cast<double>(rhs);
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return static_cast<int>(std::any_cast<bool>(lhs)) / rhsVal;
}

std::any divide_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    auto rhsVal = static_cast<int>(std::any_cast<bool>(rhs));
    if (rhsVal == 0) {
        throw ProgramException("unable to divide by 0", location());
    }
    return static_cast<int>(std::any_cast<bool>(lhs)) / rhsVal;
}

std::any divide_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any divide_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any divide_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end divide
-
*/


/*
-
- start lessthan
-
*/

std::any lessthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) < std::any_cast<int>(rhs);
}

std::any lessthan_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) < static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) < std::any_cast<int>(rhs);
}

std::any lessthan_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) < static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) < std::any_cast<int>(rhs);
}

std::any lessthan_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) < static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) < std::any_cast<int>(rhs);
}

std::any lessthan_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) < static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) < std::any_cast<int>(rhs);
}

std::any lessthan_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) < std::any_cast<unsigned long>(rhs);
}

std::any lessthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) < std::any_cast<float>(rhs);
}

std::any lessthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) < std::any_cast<double>(rhs);
}

std::any lessthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) < static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthan_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthan_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end lessthan
-
*/


/*
-
- start lessthanequal
-
*/

std::any lessthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) <= std::any_cast<int>(rhs);
}

std::any lessthanequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) <= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) <= std::any_cast<int>(rhs);
}

std::any lessthanequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) <= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) <= std::any_cast<int>(rhs);
}

std::any lessthanequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) <= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) <= std::any_cast<int>(rhs);
}

std::any lessthanequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) <= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) <= std::any_cast<int>(rhs);
}

std::any lessthanequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) <= std::any_cast<unsigned long>(rhs);
}

std::any lessthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) <= std::any_cast<float>(rhs);
}

std::any lessthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) <= std::any_cast<double>(rhs);
}

std::any lessthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) <= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any lessthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any lessthanequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any lessthanequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end lessthanequal
-
*/


/*
-
- start greaterthan
-
*/

std::any greaterthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) > std::any_cast<int>(rhs);
}

std::any greaterthan_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) > static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) > std::any_cast<int>(rhs);
}

std::any greaterthan_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) > static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) > std::any_cast<int>(rhs);
}

std::any greaterthan_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) > static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) > std::any_cast<int>(rhs);
}

std::any greaterthan_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) > static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) > std::any_cast<int>(rhs);
}

std::any greaterthan_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) > std::any_cast<unsigned long>(rhs);
}

std::any greaterthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) > std::any_cast<float>(rhs);
}

std::any greaterthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) > std::any_cast<double>(rhs);
}

std::any greaterthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) > static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthan_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthan_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end greaterthan
-
*/


/*
-
- start greaterthanequal
-
*/

std::any greaterthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) >= std::any_cast<int>(rhs);
}

std::any greaterthanequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) >= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) >= std::any_cast<int>(rhs);
}

std::any greaterthanequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) >= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) >= std::any_cast<int>(rhs);
}

std::any greaterthanequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) >= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) >= std::any_cast<int>(rhs);
}

std::any greaterthanequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) >= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) >= std::any_cast<int>(rhs);
}

std::any greaterthanequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) >= std::any_cast<unsigned long>(rhs);
}

std::any greaterthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) >= std::any_cast<float>(rhs);
}

std::any greaterthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) >= std::any_cast<double>(rhs);
}

std::any greaterthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) >= static_cast<int>(std::any_cast<bool>(rhs));
}

std::any greaterthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}


std::any greaterthanequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any greaterthanequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}



/*
-
- end greaterthanequal
-
*/


/*
-
- start equalequal
-
*/

std::any equalequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) == std::any_cast<int>(rhs);
}

std::any equalequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) == static_cast<int>(std::any_cast<bool>(rhs));
}

std::any equalequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) == std::any_cast<int>(rhs);
}

std::any equalequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) == static_cast<int>(std::any_cast<bool>(rhs));
}

std::any equalequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) == std::any_cast<int>(rhs);
}

std::any equalequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) == static_cast<int>(std::any_cast<bool>(rhs));
}

std::any equalequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) == std::any_cast<int>(rhs);
}

std::any equalequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) == static_cast<int>(std::any_cast<bool>(rhs));
}

std::any equalequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) == std::any_cast<int>(rhs);
}

std::any equalequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) == std::any_cast<unsigned long>(rhs);
}

std::any equalequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) == std::any_cast<float>(rhs);
}

std::any equalequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) == std::any_cast<double>(rhs);
}

std::any equalequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) == static_cast<int>(std::any_cast<bool>(rhs));
}

std::any equalequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any equalequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<std::string>(lhs) == std::any_cast<std::string>(rhs);
}

std::any equalequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}


std::any equalequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}

std::any equalequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}



/*
-
- end equalequal
-
*/


/*
-
- start notequal
-
*/

std::any notequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<int>(lhs) != std::any_cast<int>(rhs);
}

std::any notequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<int>(lhs) != static_cast<int>(std::any_cast<bool>(rhs));
}

std::any notequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<unsigned long>(lhs) != std::any_cast<int>(rhs);
}

std::any notequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<unsigned long>(lhs) != static_cast<int>(std::any_cast<bool>(rhs));
}

std::any notequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<float>(lhs) != std::any_cast<int>(rhs);
}

std::any notequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<float>(lhs) != static_cast<int>(std::any_cast<bool>(rhs));
}

std::any notequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<double>(lhs) != std::any_cast<int>(rhs);
}

std::any notequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
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
    return std::any_cast<double>(lhs) != static_cast<int>(std::any_cast<bool>(rhs));
}

std::any notequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) != std::any_cast<int>(rhs);
}

std::any notequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) != std::any_cast<unsigned long>(rhs);
}

std::any notequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) != std::any_cast<float>(rhs);
}

std::any notequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) != std::any_cast<double>(rhs);
}

std::any notequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return static_cast<int>(std::any_cast<bool>(lhs)) != static_cast<int>(std::any_cast<bool>(rhs));
}

std::any notequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    throw ProgramException("Unsupported Operation", location());
}

std::any notequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return std::any_cast<std::string>(lhs) != std::any_cast<std::string>(rhs);
}

std::any notequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}


std::any notequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return true;
}

std::any notequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs)
{
    return false;
}



/*
-
- end notequal
-
*/

/* End Auto Generation */