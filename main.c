#include <stdio.h>
#include <stdbool.h>
#include "includes/lexer.h"

int main() {
    char* input = "let five = 5;"
                  "let ten = 10;"
                  "let add = fn(x, y) {"
                  "x + y;"
                  "};"
                  "let result = add(five, ten);"
                  "!-/*5;"
                  "5 < 10 > 5;"
                  "if (5 < 10) {"
                  "return true;"
                  "} else {"
                  "return false;"
                  "}"
                  "10 == 10;"
                  "10 != 9;";
    int i = 1;
    Token tokens[75];
    Lexer* lexer = NewLexer(input);
    Token token = nextToken(lexer);
    tokens[0] = token;
    printf("{ type:%s, literal: %s }\n", token.type, token.literal);
    while(token.type != EoF) {
        token = nextToken(lexer);
        tokens[i] = token;
        printf("{token.%s, literal: \"%s\"},\n", token.type, token.literal);
        i++;
    }
    printf("Hello, World!\n");
    return 0;
}