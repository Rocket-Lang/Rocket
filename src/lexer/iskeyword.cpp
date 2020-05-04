#include <string>

namespace rocket {

	namespace lexer {

		bool isKeyword(std::string word) {

			if(word == "include"  || word == "import"   || word == "use"      || // Import-keywords
			   word == "func"     || word == "fun"      || 						 					 // Function-keywords
			   word == "return"   ||
			   word == "if"       || word == "ifnot"    || word == "else"     || // Control-Structures
			   word == "elseif"   ||
			   word == "switch"   || word == "case"     || word == "break"    ||
			   word == "continue" || word == "for"      || word == "do"       ||
			   word == "while"    || word == "loop"     ||
			   word == "int"      || word == "uint"     || word == "char"     || // Variable Types
			   word == "string"   || word == "bool"     ||
			   word == "float"	  || word == "double"	|| word == "byte"	  ||
			   word == "auto"	  ||
			   word == "type"     ||
			   word == "print"    || word == "input"    || 						 					 // Builtin IO
			   word == "AND"	  || word == "OR"		||						 									 // Operator
			   word == "asm"																										 // Inline Assembly
				){

				return true;
			}

			return false;
		}

	}

}
