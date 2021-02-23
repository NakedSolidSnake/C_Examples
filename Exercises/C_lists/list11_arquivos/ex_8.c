/*
Fac¸a um programa que leia o conteudo de um arquivo e crie um arquivo com o mesmo ´
conteudo, mas com todas as letras min ´ usculas convertidas para mai ´ usculas. Os no- ´
mes dos arquivos serao fornecidos, via teclado, pelo usu ˜ ario. A func¸ ´ ao que converte ˜
maiuscula para min ´ uscula ´ e o toupper(). Ela ´ e aplicada em cada caractere da string.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
            
    char c;
    if(argc != 3)
        return -1;

    FILE *fd = fopen(argv[1], "r");
    if(fd == NULL)
        return -1;

    FILE *fdOut = fopen(argv[2], "w");
    if(fdOut == NULL)
        return -1;

    while(1)
    {
        if(feof(fd))
            break;
        c = fgetc(fd);        
        c = toupper(c);
         
        fwrite(&c, 1, 1, fdOut);
    }

    fclose(fdOut);
    fclose(fd);    
    return EXIT_SUCCESS;
}