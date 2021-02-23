#ifndef __TELEVISAO_H
#define __TELEVISAO_H

#include <somimagem.h>

typedef struct 
{
    SomImagem somImagem;
    int tamanho;
}Televisao;

void Televisao_constructor(Televisao *televisao, int voltagem, int potenciaSom, int tamanho);
char *Televisao_mudarCanal(Televisao *televisao);

#endif