#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    
    char buffer[100];
    printf("Type a string.:");
    fgets(buffer, 100 - 1, stdin);
    buffer[strlen(buffer) - 1] = 0;

    char *p = buffer;
    while(*p != '\0')
    {        
        p++;
    }

    printf("String size is %ld.\n", p - buffer);

    return EXIT_SUCCESS;
}