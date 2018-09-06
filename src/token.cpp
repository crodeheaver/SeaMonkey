#include "../includes/token.h"
#include "../includes/tokens.h"

using namespace std;

namespace SeaMonkey 
{
	Token::Token(TokenType type, string literal) 
	{
		this->type = type;
		this->literal = literal;
	}
}