#include <string>
#include "lexer.h"
#include "token.h"
#include "ast.h"
namespace SeaMonkey {
    class Parser 
    {
        private:
        Lexer* lexer;
        Token* currentToken;
        Token* peekToken;
        
        public:
        Parser(std::string input);
        void nextToken();
        bool curTokenIs(TokenType type);
        bool peekTokenIs(TokenType type);
        bool expectPeek(TokenType type);
        std::string* Errors();
        void peekError(TokenType type);
        void noPrefixParseFnError(TokenType type);
        Program* Parse();
        Statement* parseStatement();
        LetStatement* parseLetStatement();
        ReturnStatement* parseReturnStatement();
        ExpressionStatement* parseExpressionStatement();
        Expression* parseExpression(int precedence);
        int peekPrecedence();
        int curPrecedece();
        Expression parseIdentifier();
        Expression parseIntegerLiteral();
        Expression parsePrefixExpression();
        Expression parseInfixExpression(Expression left);
        Expression parseBoolean();
        Expression parseGroupedExpression();
        Expression parseIfExpression();
        BlockStatement parseBlockStatement();
        Expression parseFunctionLiteral();
        Identifier* parseFunctionParameters();
        Expression parseCallExpression(Expression function);
        Expression* parseCallArguments();
        void registerPrefix(TokenType type);
    };
}