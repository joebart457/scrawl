#include "stdlib.h"


#include "db_framework.h"
#include "ufhndl.hpp"
#include "Utilities.h"

// DB Methods

std::any db_open(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = Utilities().fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");
	db->open(args.get<std::string>(0));
	return nullptr;
}


std::any db_get(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = Utilities().fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");

	std::vector<std::any> results = db->get(args.get<std::string>(0));

	std::shared_ptr<klass_definition> ls = context->get<std::shared_ptr<klass_definition>>("list");
	klass_instance results_container = ls->create();
	std::any_cast<std::shared_ptr<native_fn>>(results_container.Get("constructor", location()))->call(i, _args(results));
	return results_container;
}


std::any db_run_prepared_query(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = Utilities().fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");

	std::vector<std::any> results = db->run_prepared(
		std::any_cast<std::string>(args.at(0)),
		args.subset(2, 0),
		args.get<std::shared_ptr<klass_definition>>(1),
		false);

	std::shared_ptr<klass_definition> ls = context->get<std::shared_ptr<klass_definition>>("list");
	klass_instance results_container = ls->create();
	std::any_cast<std::shared_ptr<native_fn>>(results_container.Get("constructor", location()))->call(i, _args(results));
	return results_container;
}


// List methods
std::any list_push(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = Utilities().fetch_context(i);

	unsigned long size = context->get<unsigned long>("size");

	context->define(std::to_string(size), args.at(0), false, location());
	context->assign("size", ((unsigned long)size + 1), location());

	return nullptr;
}


std::any list_constructor(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = Utilities().fetch_context(i);

	for (unsigned int i{ 0 }; i < args.size(); i++) {
		context->define(std::to_string(i), args.at(i), false, location());
	}
	context->assign("size", (unsigned long)args.size(), location());

	return nullptr;
}





std::any to_string(std::shared_ptr<interpreter> i, std::any& rhs)
{
	return Utilities().stringify(rhs);
}


std::any print(std::shared_ptr<interpreter> i, _args args)
{
	for (unsigned int j{ 0 }; j < args.size(); j++) {
		std::cout << std::any_cast<std::string>(::to_string(i, args.at(j)));
	}
	return nullptr;
}



// DEBUG 
std::any print_environment(std::shared_ptr<interpreter> i, _args args)
{
	Utilities().fetch_context(i)->output();
	return nullptr;
}



// FileSystem
std::any fs_copy_file(std::shared_ptr<interpreter> i, _args args)
{
	FileHandle().copyFile(args.get<std::string>(0), args.get<std::string>(1));
}

std::any fs_remove_all(std::shared_ptr<interpreter> i, _args args)
{
	uintmax_t removed = FileHandle().removeAll(args.get<std::string>(0));
	return removed;
}

std::any fs_read_file(std::shared_ptr<interpreter> i, _args args)
{
	// Refactor to return list instead of native vector
	return FileHandle().readFile(args.get<std::string>(0));
}

std::any fs_real_file_to_string(std::shared_ptr<interpreter> i, _args args)
{
	return FileHandle().readFileAsString(args.get<std::string>(0));
}

std::any fs_read_line_from_file(std::shared_ptr<interpreter> i, _args args)
{
	return FileHandle().readLine(args.get<std::string>(0), args.get<unsigned long>(1));
}

std::any fs_write_to_file(std::shared_ptr<interpreter> i, _args args)
{
	FileHandle().writeToFile(args.get<std::string>(0), args.get<std::vector<std::string>>(1), args.get<bool>(2));
}

std::any fs_write_line_to_file(std::shared_ptr<interpreter> i, _args args)
{
	FileHandle().writeLine(args.get<std::string>(0), args.get<std::string>(1), args.get<bool>(2));
}

std::any fs_count_lines(std::shared_ptr<interpreter> i, _args args)
{
	unsigned long lineCount = FileHandle().countLines(args.get<std::string>(0));
	return lineCount;
}

std::any fs_current_path(std::shared_ptr<interpreter> i, _args args)
{
	return FileHandle().current_path();
}

std::any fs_parent_path(std::shared_ptr<interpreter> i, _args args)
{
	return FileHandle().parent_path(args.get<std::string>(0));
}

std::any fs_rename_file(std::shared_ptr<interpreter> i, _args args)
{
	FileHandle().rename(args.get<std::string>(0), args.get<std::string>(1));
}

std::any fs_file_size(std::shared_ptr<interpreter> i, _args args)
{
	uintmax_t size = FileHandle().file_size(args.get<std::string>(0));
	return size;
}

std::any fs_exists(std::shared_ptr<interpreter> i, _args args)
{
	return FileHandle().exists(args.get<std::string>(0));
}
