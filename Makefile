CC = gcc
CFLAGS = -Wall -Wextra -I./src

SRC = src/main.c \
      src/token/token.c \
      src/lexer/lexer.c

OUT = spyrit

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)