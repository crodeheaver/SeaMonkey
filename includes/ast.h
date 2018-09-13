#include <string>
#include "token.h"
namespace SeaMonkey
{
struct Node
{
	Token token;
	std::string tokenLiteral();
	std::string toString();
};

struct Statement : Node
{
};

struct Expression : Node
{
};

struct Program : Node
{
	Program();
	Statement statements[];
	std::string tokenLiteral();
};

struct Identifier : Expression {
	std::string value;
};

struct LetStatement : Statement 
{
	Identifier* name;
	Expression* value;
};

struct ReturnStatement : Statement {
	Expression* ReturnValue;
};

struct ExpressionStatement : Statement {
	Expression* expression;
};

struct BlockStatement : Statement {
	Statement statements[];
};

struct Boolean : Expression {
	bool value;
};

struct IntegerLiteral : Expression {
	int64_t value;
};

struct PrefixExpression : Expression {
	std::string Operator;
};

struct InfixExpression : Expression {
	Expression Left;
	std::string Operator;
	Expression Right;
};

struct IfExpression : Expression {
	Expression Condition;
	BlockStatement Consequence;
	BlockStatement Alternative;
};

struct FunctionLiteral : Expression {
	Identifier parameters[];
	BlockStatement body;
};

struct CallExpression : Expression {
	Expression function;
	Expression arguments[];
};

} // namespace SeaMonkey