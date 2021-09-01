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


// FileSystem
std::any fs_copy_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_remove_all(std::shared_ptr<interpreter> i, _args args);
std::any fs_read_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_real_file_to_string(std::shared_ptr<interpreter> i, _args args);
std::any fs_read_line_from_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_write_to_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_write_line_to_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_count_lines(std::shared_ptr<interpreter> i, _args args);
std::any fs_current_path(std::shared_ptr<interpreter> i, _args args);
std::any fs_parent_path(std::shared_ptr<interpreter> i, _args args);
std::any fs_rename_file(std::shared_ptr<interpreter> i, _args args);
std::any fs_file_size(std::shared_ptr<interpreter> i, _args args);
std::any fs_exists(std::shared_ptr<interpreter> i, _args args);
