#include "stdlib.h"


#include "db_framework.h"
#include "Utilities.h"

// DB Methods

std::any db_open(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");
	db->open(args.get<std::string>(0));
	return nullptr;
}


std::any db_get(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

	std::shared_ptr<db_helper> db = context->get<std::shared_ptr<db_helper>>("db");

	std::vector<std::any> results = db->get(args.get<std::string>(0));

	std::shared_ptr<klass_definition> ls = context->get<std::shared_ptr<klass_definition>>("list");
	klass_instance results_container = ls->create();
	std::any_cast<std::shared_ptr<native_fn>>(results_container.Get("constructor", location()))->call(i, _args(results));
	return results_container;
}


std::any db_run_prepared_query(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

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
	std::shared_ptr<execution_context> context = fetch_context(i);

	unsigned long size = context->get<unsigned long>("size");

	context->define(std::to_string(size), args.at(0), false, location());
	context->assign("size", ((unsigned long)size + 1), location());

	return nullptr;
}


std::any list_constructor(std::shared_ptr<interpreter> i, _args args)
{
	std::shared_ptr<execution_context> context = fetch_context(i);

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
	fetch_context(i)->output();
	return nullptr;
}
