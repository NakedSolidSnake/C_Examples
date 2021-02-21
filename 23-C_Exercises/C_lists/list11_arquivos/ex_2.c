/*
Faça um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
linhas esse arquivo possui.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int line = 0;
    char c;
    if(argc != 2)
        return -1;

    FILE *fd = fopen(argv[1], "r");
    if(fd == NULL)
        return -1;

    while(1)
    {
        c = fgetc(fd);
        if(feof(fd))
            break;
        if(c == '\n')
            line++;
    }

    fclose(fd);
    printf("Lines %d.\n", line);
    return EXIT_SUCCESS;
}