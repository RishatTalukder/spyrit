#include <stdio.h>
#include "./token_kind.h"
#include <string.h> 

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

struct lexer
{
    char *buffer;
    unsigned int buffer_size;
    unsigned int position;
    unsigned int read_position;
    char character;
};

// Initialize the lexer
void init_lexer(struct lexer *lex, char *buffer) {
    lex->buffer = buffer;
    lex->buffer_size = strlen(buffer);
    lex->position = 0;
    lex->read_position = 0;
    read_char(lex);
}

void read_char(struct lexer *lex) {
    if (lex->read_position >= lex->buffer_size) {
        lex->character = '\0';
    }
    else {
        lex->character = lex->buffer[lex->position];
    }
    lex->position = lex->read_position;
    lex->read_position += 1;
}

void skip_whitespaces(struct lexer *lex) {
    while (lex->character == ' ' || lex->character == '\t' || lex->character == '\n' || lex->character == '\r') {
        read_char(lex);
    }
}

Token create_token(TokenKind kind, const char *literal) {
    Token token;
    token.kind = kind;
    strncpy(token.literal, literal, sizeof(token.literal));
    return token;
}

int main()
{
    TokenKind token = INPUT;

    printf("%d\n", token);

    printf("%s\n", show_token(token));

    return 0;
}