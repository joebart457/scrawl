#pragma once

#include <any>
#include <memory>

#include "callable.h"
#include "interpreter.h"



// DB Methods
std::any db_open(std::shared_ptr<interpreter> i, _args args);
std::any db_get(std::shared_ptr<interpreter> i, _args args);
std::any db_run_prepared_query(std::shared_ptr<interpreter> i, _args args);

// List methods
std::any list_push(std::shared_ptr<interpreter> i, _args args);
std::any list_constructor(std::shared_ptr<interpreter> i, _args args);


std::any to_string(std::shared_ptr<interpreter> i, std::any& rhs);


// stdlib
std::any print(std::shared_ptr<interpreter> i, _args args);
std::any print_environment(std::shared_ptr<interpreter> i, _args args);