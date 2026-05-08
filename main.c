#include <stdio.h>
#include "./token_kind.h"
#include <string.h>
#include <ctype.h>

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

void read_char(struct lexer *lex)
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

// Initialize the lexer
void init_lexer(struct lexer *lex, char *buffer)
{
    lex->buffer = buffer;
    lex->buffer_size = strlen(buffer);
    lex->position = 0;
    lex->read_position = 0;
    read_char(lex);
}

void skip_whitespaces(struct lexer *lex)
{
    while (lex->character == ' ' || lex->character == '\t' || lex->character == '\n' || lex->character == '\r')
    {
        read_char(lex);
    }
}

Token create_token(TokenKind kind, const char *literal)
{
    Token token;
    token.kind = kind;
    strncpy(token.literal, literal, sizeof(token.literal));
    token.literal[255] = '\0';
    return token;
}

Token next_token(struct lexer *lex)
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
        read_char(lex);
        break;
    default:
        if (isalpha(lex->character))
        {
            char word_bufer[256];
            int word_bufer_index = 0;

            while (isalpha(lex->character))
            {
                word_bufer[word_bufer_index++] = lex->character;
                read_char(lex);
            }

            word_bufer[word_bufer_index] = '\0';

            if (strcmp(word_bufer, "int") == 0)
            {
                return create_token(INT, word_bufer);
            }
            else if (strcmp(word_bufer, "input") == 0)
            {
                return create_token(INPUT, word_bufer);
            }
            else if (strcmp(word_bufer, "output") == 0)
            {
                return create_token(OUTPUT, word_bufer);
            }
            else
            {
                return create_token(IDENTIFIER, word_bufer);
            }
        }
        else
        {
            char invalid_buffer[2] = {lex->character, '\0'};

            token = create_token(INVALID, invalid_buffer);
        }
        break;
    }
    return token;
}

int main()
{
    char *source_code = "n: int = input\noutput n";

    struct lexer my_lexer;
    init_lexer(&my_lexer, source_code);

    printf("Lexing code:\n%s\n\n", source_code);
    printf("%-15s | %s\n", "TOKEN KIND", "LITERAL");
    printf("----------------|---------\n");

    Token token;

    do
    {
        token = next_token(&my_lexer);
        printf("%-15s | %s\n", show_token(token.kind), token.literal);
    } while (token.kind != EOF_TOKEN);

    return 0;
}