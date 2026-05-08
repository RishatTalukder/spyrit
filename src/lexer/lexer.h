#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"

typedef struct Lexer {
    char *buffer;
    unsigned int buffer_size;
    unsigned int position;
    unsigned int read_position;
    char character;
} Lexer;

void init_lexer(Lexer *lex, char *buffer);
Token next_token(Lexer *lex);

#endif