/*
Escreva um programa que:
(a) Crie/abra um arquivo texto de nome “arq.txt”
(b) Permita que o usuario grave diversos caracteres nesse arquivo, at ´ e que o usu ´ ario ´
entre com o caractere ‘0’
(c) Feche o arquivo
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fd = fopen("arq.txt", "w");
    char c;

    while((c = fgetc(stdin)) != '0'){
        fwrite(&c, 1, 1, fd);
    }

    fclose(fd);

    fd = fopen("arq.txt", "r");

    while(feof(fd))
    {
        printf("%c", fgetc(fd));
    }

    fclose(fd);

    return EXIT_SUCCESS;
}