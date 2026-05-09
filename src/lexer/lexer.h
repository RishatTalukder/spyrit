/*
 * File: lexer.h - Lexical analyzer interface
 * Purpose: Defines the Lexer structure and interface for tokenizing source code.
 */

#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"

/*
 * Lexer: State machine for lexical analysis of source code.
 * - buffer: Pointer to the source code string to be tokenized
 * - buffer_size: Total length of the buffer
 * - position: Current position in the buffer (points to current token start)
 * - read_position: Next position to read from (one ahead of current)
 * - character: The current character being examined
 */
typedef struct Lexer {
    char *buffer;
    unsigned int buffer_size;
    unsigned int position;
    unsigned int read_position;
    char character;
} Lexer;

/*
 * init_lexer: Initializes a Lexer with a source code buffer.
 * @param lex: Pointer to Lexer struct to initialize
 * @param buffer: Pointer to source code string (will be referenced, not copied)
 * Note: buffer must remain valid for the lifetime of the Lexer
 */
void init_lexer(Lexer *lex, char *buffer);

/*
 * next_token: Extracts and returns the next token from the source.
 * Advances the lexer's position past the returned token.
 * @param lex: Pointer to initialized Lexer
 * @return: Token struct containing the kind and literal of next token
 * Note: Returns EOF_TOKEN when end of buffer is reached
 */
Token next_token(Lexer *lex);

#endif