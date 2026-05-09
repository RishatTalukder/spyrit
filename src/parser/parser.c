#include <string.h>
#include "./parser.h"
#include <stdio.h>

void parser_next_token(Parser *parser)
{
    parser->current_token = parser->peek_token;
    parser->peek_token = next_token(parser->lexer);
}

void init_parser(Parser *parser, Lexer *lexer)
{
    parser->lexer = lexer;

    parser_next_token(parser);
    parser_next_token(parser);
}

static int current_token_is(Parser *parser, TokenKind kind)
{
    return parser->current_token.kind == kind;
}

// static int peek_token_is(Parser *parser, TokenKind kind)
// {
//     return parser->peek_token.kind == kind;
// }

static ASTNode parse_variable_declaration(Parser *parser)
{
    ASTNode node;
    node.type = AST_VARIABLE_DECLARATION;

    strncpy(node.variable_decl.name, parser->current_token.literal, 256);
    parser_next_token(parser);

    parser_next_token(parser);
    strncpy(node.variable_decl.type, parser->current_token.literal, 256);
    parser_next_token(parser);

    parser_next_token(parser);
    // parser_next_token(parser);

    return node;
}

static ASTNode parse_output_statement(Parser *parser)
{
    ASTNode node;
    node.type = AST_OUTPUT_STATEMENT;

    parser_next_token(parser);
    strncpy(node.output_stmt.expression, parser->current_token.literal, 256);

    return node;
}

ASTNode parse_statement(Parser *parser) {
    if (current_token_is(parser, IDENTIFIER)) {
        return parse_variable_declaration(parser);
    } else if (current_token_is(parser, OUTPUT)) {
        return parse_output_statement(parser);
    }

    ASTNode invalid;
    invalid.type = -1;
    return invalid;
}