#include <string>
#include <map>
#include <vector>
#include "tokens.h"
#include "token.h"
namespace SeaMonkey {
	class Lexer
	{
	private:
		std::string input;
		unsigned int position;
		unsigned int readPosition;
		char ch;
		std::map<std::string, TokenType> keywords;

		void readChar();
		Token* nextToken();
		std::string readIdentifier();
		std::string readNumber();
		bool isLetter(char ch);
		void skipWhitespace();
		char peekChar();
		std::string lookupIdentity(std::string identity);
	public:
		Lexer(std::string input);
		std::vector<Token*>* Tokenize();
	};
}