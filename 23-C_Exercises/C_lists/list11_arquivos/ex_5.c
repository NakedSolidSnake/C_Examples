/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
letras sao vogais
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isVowel(char c)
{
    bool vowel = false;
    switch (tolower(c))
    {
    case 'a' :
    case 'e' :
    case 'i' :
    case 'o' :
    case 'u' :
        vowel = true;
        break;    
    }

    return vowel;
}

int main(int argc, char *argv[])
{
    int letters = 0;
    char c;
    char letter;
    if(argc != 3)
        return -1;

    FILE *fd = fopen(argv[1], "r");
    if(fd == NULL)
        return -1;

    letter = argv[2][0];

    while(1)
    {
        c = fgetc(fd);
        if(feof(fd))
            break;
        if(c == letter)
            letters++;
    }

    fclose(fd);
    printf("Occurencies %d.\n", letters);
    return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}