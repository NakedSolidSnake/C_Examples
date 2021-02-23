#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    unsigned char segundos;
    unsigned char minutos;
    unsigned char hora;
}Horario;

typedef struct 
{
    unsigned char dia;
    unsigned char mes;
    unsigned int ano; 
}Data;

typedef struct 
{
    Data data;
    Horario horario;
    char descricao[120];
}Compromisso;

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}