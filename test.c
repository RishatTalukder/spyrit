/*
 * File: test.c - Test/demo file (not part of main build)
 * Purpose: Demonstrates string length output with format specifiers.
 */

#include <string.h>
#include <stdio.h>

/*
 * main: Simple demo of strlen() and printf formatting.
 * @return: 0 on successful completion
 */
int main()
{
    char *str = "n: int = input\noutput n";
    printf("You entered: %ld", strlen(str));
    return 0;
}