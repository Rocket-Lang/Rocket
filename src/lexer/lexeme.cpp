#include <string>

namespace rocket {

	namespace lexer {

		enum LexemeKey {

			UNKNOWN  = 0,
			KEYWORD  = 1, // A known keyword of the language
			WORD     = 2, // A word that is not from the language (e.g. variable-names)
			STRING   = 3,
			CHAR     = 4,
			SPECIAL  = 5, // A single special character OR a known sequence of those
			INTEGER  = 6,
			FLOAT    = 7,
			NEWLINE  = 8,
		};


		class Lexeme {
		public:

			LexemeKey key;
			std::string value;

			Lexeme() {

			}

			Lexeme(LexemeKey key, std::string value) {

				this->key = key;
				this->value = value;
			}

		};

	}

}
