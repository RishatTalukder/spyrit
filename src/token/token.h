
/*
 * File: token.h - Token type definitions and creation
 * Purpose: Defines the TokenKind enum and Token struct used throughout the lexer
 *          and provides utilities for token creation and string representation.
 */

#ifndef TOKEN_H
#define TOKEN_H

/*
 * TokenKind: Enumeration of all token types recognized by the lexer.
 * - IDENTIFIER: Variable names and user-defined identifiers
 * - INT: The 'int' keyword
 * - NUMBER: Numeric literals (currently not produced by lexer)
 * - INPUT: The 'input' keyword
 * - OUTPUT: The 'output' keyword
 * - COLON: Symbol ':'
 * - ASSIGN: Symbol '='
 * - NEWLINE: Newline character (currently not produced by lexer)
 * - EOF_TOKEN: End of file marker
 * - INVALID: Unknown or invalid tokens
 */
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

/*
 * Token: Represents a single token with its type and literal value.
 * - kind: The type of token (from TokenKind enum)
 * - literal[256]: The string representation of the token (max 255 chars + null terminator)
 */
typedef struct Token
{
    TokenKind kind;
    char literal[256]; /* max literal length (255 chars + null terminator) */
} Token;

/*
 * show_token: Returns the string name of a token kind.
 * @param kind: The TokenKind to convert to string
 * @return: Pointer to static string representation (e.g., "int", "identifier", "EOF")
 */
const char *show_token(TokenKind kind);

/*
 * create_token: Creates a new Token with the given kind and literal value.
 * @param kind: The TokenKind for this token
 * @param literal: The string value (will be copied; limited to 255 chars)
 * @return: A new Token struct with kind and literal initialized
 */
Token create_token(TokenKind kind, const char *literal);

#endif