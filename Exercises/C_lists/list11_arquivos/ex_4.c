/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
letras sao vogais e quantas s ˜ ao consoantes.
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
    int vowels = 0;
    int consonants = 0;
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
            continue;

        if(isVowel(c))
            vowels++;
        else
            consonants++;
    }

    fclose(fd);
    printf("Vowels %d.\n", vowels);
    printf("Consonants %d.\n", consonants);
    return EXIT_SUCCESS;
}