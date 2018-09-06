#include <string>
namespace SeaMonkey
{
	typedef std::string TokenType;

	struct Token {
		TokenType type;
		std::string literal;

		Token(TokenType type, std::string literal);
	};
}