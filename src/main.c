/*
 * File: main.c - Main entry point
 * Purpose: Demonstrates the lexer by tokenizing sample source code.
 */

#include <stdio.h>
#include "./token/token.h"
#include "./lexer/lexer.h"
#include "./AST/ast.h"
#include "./parser/parser.h"

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

    // // Lexer
    // Lexer my_lexer;
    init_lexer(&my_lexer, source_code);

    // Parser
    Parser my_parser;
    init_parser(&my_parser, &my_lexer);

    printf("Parsing code:\n%s\n\n", source_code);

    // Parse both statements
    ASTNode node1 = parse_statement(&my_parser);
    print_ast_node(&node1);

    parser_next_token(&my_parser); // move to next statement
    
    ASTNode node2 = parse_statement(&my_parser);
    print_ast_node(&node2);


    return 0;
}