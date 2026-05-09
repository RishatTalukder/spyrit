#include <string.h>
#include <ctype.h>
#include "lexer.h"

// These are internal helper functions
// 'static' means they are private to this file only
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

void init_lexer(Lexer *lex, const char *buffer)
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
        if (isalpha(lex->character))
        {
            char word_buffer[256];
            int i = 0;

            while (isalpha(lex->character))
            {
                word_buffer[i++] = lex->character;
                read_char(lex);
            }
            word_buffer[i] = '\0';

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
            char invalid_buffer[2] = {lex->character, '\0'};
            token = create_token(INVALID, invalid_buffer);
            read_char(lex);
        }
        break;
    }
    return token;
}