/*
 * File: lexer.c - Lexical analyzer implementation
 * Purpose: Implements tokenization of source code.
 *          Scans input for keywords (int, input, output), identifiers, symbols, and whitespace.
 */

#include <string.h>
#include <ctype.h>
#include "lexer.h"

/*
 * read_char: Advances the lexer to the next character in the buffer.
 * Updates lexer->character and lexer->position.
 * Sets character to '\0' (EOF) if at end of buffer.
 * This is an internal helper function.
 */
static void read_char(Lexer *lex)
{
    if (lex->read_position >= lex->buffer_size)
    {
        lex->character = '\0';
    }
    else
    {
        lex->character = lex->buffer[lex->read_position];
    }
    lex->position = lex->read_position;
    lex->read_position += 1;
}

/*
 * skip_whitespaces: Advances past any whitespace characters (space, tab, newline, carriage return).
 * Moves the lexer to the next non-whitespace character.
 * This is an internal helper function.
 */
static void skip_whitespaces(Lexer *lex)
{
    while (lex->character == ' ' ||
           lex->character == '\t' ||
           lex->character == '\n' ||
           lex->character == '\r')
    {
        read_char(lex);
    }
}

void init_lexer(Lexer *lex, char *buffer)
{
    lex->buffer = buffer;
    lex->buffer_size = strlen(buffer);
    lex->position = 0;
    lex->read_position = 0;
    read_char(lex);
}

Token next_token(Lexer *lex)
{
    Token token;
    skip_whitespaces(lex);

    switch (lex->character)
    {
    case '=':
        token = create_token(ASSIGN, "=");
        read_char(lex);
        break;
    case ':':
        token = create_token(COLON, ":");
        read_char(lex);
        break;
    case '\0':
        token = create_token(EOF_TOKEN, "");
        break;
    default:
        /* Handle alphabetic characters (keywords and identifiers) */
        if (isalpha(lex->character))
        {
            char word_buffer[256];
            int i = 0;

            /* Accumulate consecutive alphabetic characters */
            while (isalpha(lex->character) && i < 255)
            {
                word_buffer[i++] = lex->character;
                read_char(lex);
            }
            word_buffer[i] = '\0';

            /* Check if accumulated word is a keyword */
            if (strcmp(word_buffer, "int") == 0)
                return create_token(INT, word_buffer);
            else if (strcmp(word_buffer, "input") == 0)
                return create_token(INPUT, word_buffer);
            else if (strcmp(word_buffer, "output") == 0)
                return create_token(OUTPUT, word_buffer);
            else
                return create_token(IDENTIFIER, word_buffer);
        }
        else
        {
            /* Unknown or invalid character */
            char invalid_buffer[2] = {lex->character, '\0'};
            token = create_token(INVALID, invalid_buffer);
            read_char(lex);
        }
        break;
    }
    return token;
}