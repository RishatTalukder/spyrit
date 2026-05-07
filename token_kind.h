
#ifndef TOKEN_KINDS
#define TOKEN_KINDS

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

#endif