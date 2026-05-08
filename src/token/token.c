#include <string.h>
#include "token.h"

const char *show_token(TokenKind token)
{
    switch (token)
    {
    case IDENTIFIER:
        return "indentifier";
    case INT:
        return "int";
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

Token create_token(TokenKind kind, const char *literal) {
    Token token;
    token.kind = kind;
    strncpy(token.literal, literal, sizeof(token.literal));
    token.literal[255] = '\0';
    return token;
}