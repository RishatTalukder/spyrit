#ifndef PARSER_H
#define PARSER_H
#include "../lexer/lexer.h"
#include "../token/token.h"
#include "../AST/ast.h"

typedef struct Parser {
    Lexer *lexer;
    Token current_token;
    Token peek_token;
} Parser;

void init_parser(Parser *parser, Lexer *lexer);

void parser_next_token(Parser *parser);

ASTNode parse_statement(Parser *parser);

#endif