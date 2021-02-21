/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
vezes cada letra do alfabeto aparece dentro do arquivo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

static int letters[26];

void incLetter(int *pLetters, char c)
{
    int C = toupper(c) - 65;
    if(C >= 0 && C < 26)
    {
        pLetters[C]++;
    }

}

int main(int argc, char *argv[])
{    
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
        incLetter(letters, c);
    }

    fclose(fd);

    for(int i = 0; i < 26; i++)
    {
        printf("Letter %c Occurencies %d.\n", 'A' + i, letters[i]);
    }
    // printf("Occurencies %d.\n", letters);
    return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}