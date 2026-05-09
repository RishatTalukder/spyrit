/*
 * File: main.c - Main entry point
 * Purpose: Demonstrates the lexer by tokenizing sample source code.
 */

#include <stdio.h>
#include "./token/token.h"
#include "./lexer/lexer.h"

/*
 * main: Entry point. Initializes lexer with sample code and prints all tokens.
 * @return: 0 on successful completion
 */
int main() {
    char *source_code = "n: int = input\noutput n";

    Lexer my_lexer;
    init_lexer(&my_lexer, source_code);

    printf("Lexing code:\n%s\n\n", source_code);
    printf("%-15s | %s\n", "TOKEN KIND", "LITERAL");
    printf("----------------|---------\n");

    Token token;
    do {
        token = next_token(&my_lexer);
        printf("%-15s | %s\n", show_token(token.kind), token.literal);
    } while (token.kind != EOF_TOKEN);

    return 0;
}