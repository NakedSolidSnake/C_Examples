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
    int line = 0;
    const char *output = "out.txt";
    char c;
    if(argc != 2)
        return -1;

    FILE *fd = fopen(argv[1], "r");
    if(fd == NULL)
        return -1;

    FILE *fdOut = fopen(output, "w");
    if(fdOut == NULL)
        return -1;

    while(1)
    {
        c = fgetc(fd);
        if(feof(fd))
            break;
        if(isVowel(c)){
            c = '*';
        }
         
        fwrite(&c, 1, 1, fdOut);
    }

    fclose(fdOut);
    fclose(fd);
    printf("Lines %d.\n", line);
    return EXIT_SUCCESS;
}