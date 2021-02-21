#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[100];
    printf("Type a string.:");
    fgets(buffer, 100 - 1, stdin);
    buffer[strlen(buffer) - 1] = 0;

    for(int i = 0; i < 4; i++)
        printf("%c", buffer[i]);
    putchar('\n');
    return EXIT_SUCCESS;
}