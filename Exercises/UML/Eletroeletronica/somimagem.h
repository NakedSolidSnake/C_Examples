#ifndef __SOMIMAGEM_H
#define __SOMIMAGEM_H

#include <eletroeletronico.h>

typedef struct 
{
    Eletroeletronico eletronico;
    int potenciaSom;
    Action entrarStandyBy;
    Action sairStandyBy;
}SomImagem;

void SomImagem_constructor(SomImagem *somImagem, int potenciaSom, int voltagem);
char *SomImagem_entrarStandyBy(void *somImagem);
char *SomImagem_sairStandyBy(void *somImagem);


#endif