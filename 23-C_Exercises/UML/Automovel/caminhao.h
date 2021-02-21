#ifndef __CAMINHAO_H
#define __CAMINHAO_H

#include <veiculo.h>

typedef struct 
{
    Veiculo veiculo;   
    int capacidade;
}Caminhao;

void Caminhao_constructor(Caminhao *caminhao, const char *marca, const char *modelo, int capacidade);
int Caminhao_getCapacidade(Caminhao *caminhao);

#endif