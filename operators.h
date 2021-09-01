#pragma once


#include <any>
#include <memory>
#include "interpreter.h"



// Native supported types are int, unsigned long, float, double, bool, std::string, --not char yet
// Custom supported types are list
// Supported binary operations are +, -, /, *, [], <, <=, >, >=, ==, !=,
// Supported unary operations are !, -


std::any type_of_any(std::shared_ptr<interpreter> i, std::any& rhs);

std::any index_list_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_list_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_list_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


/*
-
- int
-
*/

std::any not_int(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_int(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any notequal_int_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_int_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


/*
-
- unsigned long
-
*/

std::any not_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_unsignedlong(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any notequal_unsignedlong_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_unsignedlong_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);




/*
-
- float
-
*/

std::any not_float(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_float(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any notequal_float_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_float_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);




/*
-
- double
-
*/

std::any not_double(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_double(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any notequal_double_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_double_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);



/*
-
- bool
-
*/

std::any not_bool(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_bool(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any notequal_bool_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_bool_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);



/*
-
- std::string
-
*/

std::any not_string(std::shared_ptr<interpreter> i, std::any& rhs);
std::any negate_string(std::shared_ptr<interpreter> i, std::any& rhs);

std::any add_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any add_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any subtract_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any subtract_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any multiply_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any multiply_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any divide_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any divide_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any index_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any index_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any lessthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any lessthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthan_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthan_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any greaterthanequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any greaterthanequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);

std::any equalequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any notequal_string_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_string_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


/*
-
- std::nullptr_t
-
*/


std::any equalequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any equalequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);


std::any notequal_null_int(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_unsignedlong(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_float(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_double(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_bool(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_string(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
std::any notequal_null_null(std::shared_ptr<interpreter> i, std::any& lhs, std::any& rhs);
