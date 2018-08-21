//
// Created by colby on 8/20/18.
//

#ifndef SEALION_TOKEN_H
#define SEALION_TOKEN_H

typedef char* TokenType;

typedef struct Token {
    TokenType type;
    char* literal;
} Token;

TokenType LookupIdentity(char* ident);

extern char* ILLEGAL;
extern char* EoF;

extern char* IDENT;
extern char* INT;

extern char* ASSIGN;
extern char* PLUS;
extern char* MINUS;
extern char* BANG;
extern char* ASTERISK;
extern char* SLASH;
extern char* LT;
extern char* GT;

extern char* COMMA;
extern char* SEMICOLON;
extern char* LPAREN;
extern char* RPAREN;
extern char* LBRACE;
extern char* RBRACE;

extern char* FUNCTION;
extern char* LET;
extern char* TRUE;
extern char* FALSE;
extern char* IF;
extern char* ELSE;
extern char* RETURN;

extern char* EQ;
extern char* NOT_EQ;
#endif //SEALION_TOKEN_H
