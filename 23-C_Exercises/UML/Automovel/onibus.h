#ifndef __ONIBUS_H
#define __ONIBUS_H

#include <veiculo.h>

typedef struct 
{
    Veiculo veiculo;   
    int lugares;
}Onibus;

void Onibus_constructor(Onibus *onibus, const char *marca, const char *modelo, int lugares);
int Onibus_getLugares(Onibus *onibus);

#endif