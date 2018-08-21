//
// Created by colby on 8/20/18.
//

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../includes/lexer.h"

Lexer* NewLexer(char* input) {
    Lexer* lexer = malloc(sizeof(struct Lexer));
    lexer->input = input;
    readChar(lexer);
    return lexer;
}

void readChar(Lexer* lexer) {
    if(lexer->readPosition >= strlen(lexer->input)) {
        lexer->ch = 0;
    }
    else {
        lexer->ch = lexer->input[lexer->readPosition];
    }

    lexer->position = lexer->readPosition;
    lexer->readPosition += 1;
}

Token newToken(TokenType tokenType, char ch) {
    char *str = malloc(2*sizeof(char));
    str[0] = ch;
    str[1] = '\0';
    Token token = { .type = tokenType, .literal = str };
    return token;
}

Token nextToken(Lexer* lexer) {
    Token token;
    skipWhitespace(lexer);
    switch(lexer->ch) {
        case '=':
            if(peekChar(lexer) == '=') {
                readChar(lexer);
                Token tok = {.literal = "==", .type = EQ};
                token = tok;
            } else {
                token = newToken(ASSIGN, lexer->ch);
            }
            break;
        case '+':
            token = newToken(PLUS, lexer->ch);
            break;
        case '-':
            token = newToken(MINUS, lexer->ch);
            break;
        case '!':
            if(peekChar(lexer) == '=') {
                readChar(lexer);
                Token tok ={.literal = "!=", .type = NOT_EQ};
                token = tok;
            } else {
                token = newToken(BANG, lexer->ch);
            }
            break;
        case '/':
            token = newToken(SLASH, lexer->ch);
            break;
        case '*':
            token = newToken(ASTERISK, lexer->ch);
            break;
        case '<':
            token = newToken(LT, lexer->ch);
            break;
        case '>':
            token = newToken(GT, lexer->ch);
            break;
        case ';':
            token = newToken(SEMICOLON, lexer->ch);
            break;
        case '(':
            token = newToken(LPAREN, lexer->ch);
            break;
        case ')':
            token = newToken(RPAREN, lexer->ch);
            break;
        case ',':
            token = newToken(COMMA, lexer->ch);
            break;
        case '{':
            token = newToken(LBRACE, lexer->ch);
            break;
        case '}':
            token = newToken(RBRACE, lexer->ch);
            break;
        case 0:
            token.literal = "";
            token.type = EoF;
            break;
        default:
            if (isalpha(lexer->ch) || lexer->ch == '_') {
                token.literal = readIdentifier(lexer);
                token.type = LookupIdentity(token.literal);
                return token;
            } else if(isdigit(lexer->ch)) {
                token.type = INT;
                token.literal = readNumber(lexer);
                return token;
            } else {
                token = newToken(ILLEGAL, lexer->ch);
            }
            break;
    }
    readChar(lexer);
    return token;
}

char* readIdentifier(Lexer* lexer) {
    int position = lexer->position;
    while(isalpha(lexer->ch) || lexer->ch == '_') {
        readChar(lexer);
    }

    int difference = lexer->position - position;

    char* subbuff = malloc(difference+1);
    memcpy( subbuff, &lexer->input[position], difference);
    subbuff[difference] = '\0';

    return subbuff;
}

char* readNumber(Lexer* lexer) {
    int position = lexer->position;
    while(isdigit(lexer->ch)) {
        readChar(lexer);
    }

    int difference = lexer->position - position;

    char* subbuff = malloc(difference+1);
    memcpy( subbuff, &lexer->input[position], difference);
    subbuff[difference] = '\0';

    return subbuff;
}

void skipWhitespace(Lexer* lexer) {
    while(isspace(lexer->ch)) {
        readChar(lexer);
    }
}

char peekChar(Lexer* lexer) {
    if(lexer->readPosition >= strlen(lexer->input)) {
        return 0;
    }
    else {
        return lexer->input[lexer->readPosition];
    }
}