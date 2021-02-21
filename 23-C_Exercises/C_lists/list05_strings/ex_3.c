#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[100];
    printf("Type a string.:");
    fgets(buffer, 100 - 1, stdin);
    buffer[strlen(buffer) - 1] = 0;

    if(tolower(buffer[0]) == 'a')
        printf("The name is %s.\n",buffer);

    return EXIT_SUCCESS;
}