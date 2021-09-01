

#include <iostream>
#include <conio.h>


#include "parser.h"

#include "ContextBuilder.h"
#include "ufhndl.hpp"

int main(int argc, char** argv)
{
	std::shared_ptr<interpreter> i = ContextBuilder().BuildInterpreter();
	std::shared_ptr<tokenizer> t = ContextBuilder().BuildTokenizer();
	parser p;
	std::string input{ "" };
	bool showTokens{ false };
	std::cout << ">>> ";
	while (std::getline(std::cin, input)) {
		if (input == "exit") {
			break;
		}
		else if (input == "show-tokens") {
			showTokens = !showTokens;
			std::cout << ">>>";
			continue;
		}
		try {
			//i->interpret(p.parse(t->tokenize(input, showTokens)));
			i->interpret(p.parse(t->tokenize(FileHandle().readFileAsString("C:\\Users\\system.developer\\source\\repos\\cyber\\Utils\\op_create.scrwl"), showTokens)));
		}
		catch (ParsingException p) {
			std::cout << p.fullTrace() << std::endl;
		}
		catch (ProgramException pe) {
			std::cout << pe.fullTrace() << std::endl;
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << ">>> ";
	}

	std::cout << "Press any key to exit...";
	_getch();
}