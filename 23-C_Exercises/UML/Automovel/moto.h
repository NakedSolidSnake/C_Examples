#ifndef __MOTO_H
#define __MOTO_H

#include <veiculo.h>

typedef struct 
{
    Veiculo veiculo;   
    int cilindrada;
}Moto;

void Moto_constructor(Moto *moto, const char *marca, const char *modelo, int cilindrada);
int Moto_getCilidradas(Moto *moto);

#endif