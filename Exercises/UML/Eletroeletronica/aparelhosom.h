#ifndef __APARELHOSOM_H
#define __APARELHOSOM_H

#include <somimagem.h>

#define MARCA_LEN   80

typedef struct 
{
    SomImagem somImagem;
    char marca[MARCA_LEN];
}AparelhoSom;

void AparelhoSom_constructor(AparelhoSom *aparelhoSom, int voltagem, int potenciaSom, const char *marca);
char *AparelhoSom_mudarEstacao(AparelhoSom *aparelhoSom);

#endif