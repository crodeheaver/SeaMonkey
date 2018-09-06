#include "../includes/lexer.h"
#include <ctype.h>

using namespace std;

namespace SeaMonkey {
	Lexer::Lexer(string input)
	{
		this->input = input;
		ch = 0;
		position = 0;
		readPosition = 0;
		readChar();
		
		keywords = { { "fn", constants::FUNCTION }, { "let", constants::LET } };
	}

	Token* Lexer::nextToken()
	{
		Token* token;

		skipWhitespace();

		switch (ch) {
		case '=':
			if (peekChar() == '=')
			{
				char ch = this->ch;
				readChar();
				token = new Token(constants::EQ, string(1, ch) + string(1, this->ch));
			}
			else
			{
				token = new Token(constants::ASSIGN, string(1, ch));
			}
			break;
		case '+':
			token = new Token(constants::PLUS, string(1, ch));
			break;
		case '-':
			token = new Token(constants::MINUS, string(1, ch));
			break;
		case '!':
			if (peekChar() == '=')
			{
				char ch = this->ch;
				readChar();
				token = new Token(constants::NOT_EQ, string(1, ch) + string(1, this->ch));
			}
			else
			{
				token = new Token(constants::BANG, string(1, ch));
			}
			break;
		case '/':
			token = new Token(constants::SLASH, string(1, ch));
			break;
		case '*':
			token = new Token(constants::ASTERISK, string(1, ch));
			break;
		case '<':
			token = new Token(constants::LT, string(1, ch));
			break;
		case '>':
			token = new Token(constants::GT, string(1, ch));
			break;
		case ';':
			token = new Token(constants::SEMICOLON, string(1, ch));
			break;
		case '(':
			token = new Token(constants::LPAREN, string(1, ch));
			break;
		case ')':
			token = new Token(constants::RPAREN, string(1, ch));
			break;
		case ',':
			token = new Token(constants::COMMA, string(1, ch));
			break;
		case '{':
			token = new Token(constants::LBRACE, string(1, ch));
			break;
		case '}':
			token = new Token(constants::RBRACE, string(1, ch));
			break;
		case 0:
			token = new Token(constants::_EOF, "");
			break;
		default:
			if (isLetter(ch))
			{
				string literal = readIdentifier();
				TokenType type = lookupIdentity(literal);
				return new Token(type, literal);
			}
			else if (isdigit(ch))
			{
				string literal = readNumber();
				TokenType type = constants::INT;
				return new Token(type, literal);
			}
			else 
			{
				token = new Token(constants::ILLEGAL, string(1, ch));
			}
			break;
		}

		readChar();

		return token;
	}

	void Lexer::skipWhitespace()
	{
		while (isspace(ch))
		{
			readChar();
		}
	}

	char Lexer::peekChar()
	{
		if (readPosition >= input.length())
		{
			return 0;
		}
		else
		{
			return input[readPosition];
		}
	}


	void Lexer::readChar()
	{
		if (readPosition >= input.length())
		{
			ch = 0;
		}
		else
		{
			ch = this->input[readPosition];
		}
		position = readPosition;
		readPosition += 1;
	}

	string Lexer::readIdentifier() 
	{
		unsigned int position = this->position;
		while (isLetter(ch))
		{
			readChar();
		}
		return input.substr(position, this->position - position);
	}

	string Lexer::readNumber()
	{
		unsigned int position = this->position;
		while (isdigit(ch))
		{
			readChar();
		}
		return input.substr(position, this->position - position);
	}

	TokenType Lexer::lookupIdentity(string identity)
	{
		TokenType token = keywords[identity];

		if (token.empty())
			return token;
		
		return constants::IDENT;
	}

	bool Lexer::isLetter(char ch)
	{
		return isalpha(ch) || ch == '_';
	}

	vector<Token*>* Lexer::Tokenize()
	{
		vector<Token*>* tokens = new vector<Token*>();
		Token* token;
		do
		{
			token = nextToken();
			tokens->push_back(token);
		} while (token->type != constants::_EOF);
		return tokens;
	}
}