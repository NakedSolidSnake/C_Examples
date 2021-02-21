#ifndef __CARRO_H
#define __CARRO_H

#include <veiculo.h>

typedef struct 
{
    Veiculo veiculo;   
    int portas;
}Carro;


void Carro_constructor(Carro *carro,  const char *marca, const char *modelo, int portas);
int Carro_getPortas(Carro *carro);

#endif