# spyrit

Just wanted try to make a programming langauge I guess.

I always dreamed of a language that is syntactically simple like python but type safe like c or c++ and compiled to machine code like c. That's why I named it `spyrit` instead of `spirit`.

So, for now I was thinking of a language like below.

```
n: int = input

i: int = 0

while i < n:
    print i
    i = i + 1
```

I think I'll be happy if I can run this code without any error in my own hand-made compiler.

I'm using `c` as a base language. I could've chosen C++ but why not torture myself. Actually I'm writting C code after 4 years.

## Project Structure

spyrit/
├── src/
│   ├── main.c          # Entry point
│   ├── token/
│   │   ├── token.h     # Token types and struct definitions
│   │   └── token.c     # Token helper functions
│   └── lexer/
│       ├── lexer.h     # Lexer struct definition
│       └── lexer.c     # Lexer implementation
└── Makefile

## How to Build

make

## How to Run

./spyrit

## Stages

- [x] Lexer
- [ ] Parser
- [ ] AST
- [ ] Code Generator
