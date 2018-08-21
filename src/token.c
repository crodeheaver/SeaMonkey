//
// Created by colby on 8/20/18.
//
#include <string.h>
#include "../includes/token.h"

char* ILLEGAL = "ILLEGAL";
char* EoF = "EOF";

char* IDENT = "IDENT";
char* INT = "INT";

char* ASSIGN = "=";
char* PLUS = "+";
char* MINUS = "-";
char* BANG = "!";
char* ASTERISK = "*";
char* SLASH = "/";
char* LT = "<";
char* GT = ">";

char* COMMA = ",";
char* SEMICOLON = ";";
char* LPAREN = "(";
char* RPAREN = ")";
char* LBRACE = "{";
char* RBRACE = "}";

char* FUNCTION = "FUNCTION";
char* LET = "LET";
char* TRUE = "TRUE";
char* FALSE = "FALSE";
char* IF = "IF";
char* ELSE = "ELSE";
char* RETURN = "RETURN";

char* EQ = "==";
char* NOT_EQ = "!=";

TokenType LookupIdentity(char* ident) {
    if(strcmp(ident, "fn")==0) {
        return FUNCTION;
    } else if(strcmp(ident, "let") ==0) {
      return LET;
    } else if(strcmp(ident, "true") ==0) {
        return TRUE;
    }else if(strcmp(ident, "false") ==0) {
        return FALSE;
    }else if(strcmp(ident, "if") ==0) {
        return IF;
    }else if(strcmp(ident, "else") ==0) {
        return ELSE;
    }else if(strcmp(ident, "return") ==0) {
        return RETURN;
    } else {
        return IDENT;
    }
}