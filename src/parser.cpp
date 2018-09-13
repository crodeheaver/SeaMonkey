#include "../includes/parser.h";

namespace SeaMonkey {
    Parser::Parser(std::string input) {
        lexer = new Lexer(input);
    }

    void Parser::nextToken() {

    }

    Program* Parser::Parse() {
        Program* program = new Program();

        while(currentToken->type != constants::_EOF) {
            if(currentToken->type == constants::LET)
                return
        }

        return program;
    }
}

