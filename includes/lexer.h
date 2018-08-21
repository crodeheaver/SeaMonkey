//
// Created by colby on 8/20/18.
//

#ifndef SEALION_LEXER_H
#define SEALION_LEXER_H

#include "token.h"

typedef struct Lexer {
    char* input;
    int position;
    int readPosition;
    char ch;
} Lexer;

Lexer* NewLexer(char* input);
void readChar(Lexer* lexer);
Token newToken(TokenType tokenType, char ch);
Token nextToken(Lexer* lexer);
char* readIdentifier(Lexer* lexer);
void skipWhitespace(Lexer* lexer);
char* readNumber(Lexer* lexer);
char peekChar(Lexer* lexer);

#endif //SEALION_LEXER_H
