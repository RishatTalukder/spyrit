
#ifndef TOKEN_H
#define TOKEN_H

typedef enum TokenKind
{
    // Literals and identifiers
    IDENTIFIER,
    INT,
    NUMBER,

    // Keywords
    INPUT,
    OUTPUT,

    // Symbols
    COLON,
    ASSIGN,
    NEWLINE,

    // Invalid
    EOF_TOKEN,
    INVALID
} TokenKind;

typedef struct Token
{
    TokenKind kind;
    char literal[256]; // max literal length
} Token;

const char *show_token(TokenKind kind);
Token create_token(TokenKind kind, const char *literal);

#endif