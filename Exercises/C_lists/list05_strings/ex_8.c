#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *numbers = "0011001";
    char *pNumbers = numbers;
    int ones = 0;
    int zeros;


    while(*pNumbers != '\0')
    {
        if(*pNumbers == '1')
            ones++;
        pNumbers++;
    }

    printf("Numbers one = %d.\n", ones);
    return EXIT_SUCCESS;
}