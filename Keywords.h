#pragma once

#ifndef __INCLUDE_KEYWORDS_H
#define __INCLUDE_KEYWORDS_H

#include <string>

class Keywords {
public:
	static std::string FUNCTION() { return "function"; }
	static std::string CLASS() { return "class"; }

	static std::string UINT() { return "uint"; }
	static std::string INT() { return "int"; }
	static std::string FLOAT() { return "float"; }
	static std::string DOUBLE() { return "double"; }
	static std::string CHAR() { return "char"; }
	static std::string STRING() { return "string"; }
	static std::string IGNORE(){ return "ignore"; }


	static std::string DIRECTIVE() { return "directive"; }
	static std::string IMPORT() { return "import"; }

	static std::string IF() { return "if"; }
	static std::string ELSE() { return "else"; }
	static std::string WHILE() { return "while"; }
	static std::string RETURN() { return "import"; }
	static std::string BREAK() { return "break"; }
	static std::string CONTINUE() { return "continue"; }

	static std::string LCURLY() { return "{"; }
	static std::string RCURLY() { return "}"; }
	static std::string LPAREN() { return "("; }
	static std::string RPAREN() { return ")"; }
	static std::string LBRACKET() { return "["; }
	static std::string RBRACKET() { return "]"; }

	static std::string COMMA() { return "comma"; }
	static std::string DOT() { return "dot"; }
	static std::string SEMI() { return "semi"; }
	static std::string BANG() { return "bang"; }

	static std::string EQUAL() { return "equal"; }
	static std::string EQUALEQUAL() { return "equalequal"; }
	static std::string BANGEQUAL() { return "bangequal"; }
	static std::string LESSTHAN() { return "lessthan"; }
	static std::string LESSTHANEQUAL() { return "lessthanequal"; }
	static std::string GREATERTHAN() { return "greaterthan"; }
	static std::string GREATERTHANEQUAL() { return "greaterthanequal"; }

	static std::string ADD() { return "add"; }
	static std::string SUBTRACT() { return "subtract"; }
	static std::string ASTERISK() { return "asterisk"; }
	static std::string FORWARDSLASH() { return "forwardslash"; }
	static std::string BACKSLASH() { return "backslash"; }
	static std::string UPCARAT() { return "upcarat"; }

	static std::string AND() { return "and"; }
	static std::string OR() { return "or"; }

	static std::string TYPEOF() { return "typeof"; }
	static std::string CAST() { return "cast"; }

	static std::string FALSE() { return "false"; }
	static std::string TRUE() { return "true"; }
	static std::string NUL() { return "null"; }
	static std::string NEW() { return "new"; }

};

#endif