/*
 * File: token.c - Token implementation
 * Purpose: Implements token creation and string representation utilities.
 */

#include <string.h>
#include "token.h"

/*
 * show_token: Returns the string name of a token kind.
 * @param token: The TokenKind to convert to string
 * @return: Pointer to static string representation
 */
const char *show_token(TokenKind token)
{
    switch (token)
    {
    case IDENTIFIER:
        return "identifier";
    case INT:
        return "integer";
    case INPUT:
        return "input";
    case OUTPUT:
        return "output";
    case ASSIGN:
        return "assign";
    case COLON:
        return "colon";
    case INVALID:
        return "invalid";
    case EOF_TOKEN:
        return "EOF";
    default:
        return "unknown";
    }
}

/*
 * create_token: Creates a new Token with the given kind and literal value.
 * Safely copies the literal string, ensuring null-termination even if truncated.
 * @param kind: The TokenKind for this token
 * @param literal: The string value to copy
 * @return: A new Token struct with kind and literal initialized
 */
Token create_token(TokenKind kind, const char *literal) {
    Token token;
    token.kind = kind;
    strncpy(token.literal, literal, sizeof(token.literal) - 1);
    token.literal[255] = '\0';  /* Ensure null termination */
    return token;
}