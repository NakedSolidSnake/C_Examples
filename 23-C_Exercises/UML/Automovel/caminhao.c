#include <caminhao.h>
#include <stdio.h>

static void Caminhao_abastecer(void *caminhao);

void Caminhao_constructor(Caminhao *caminhao, const char *marca, const char *modelo, int capacidade)
{
    Veiculo_constructor((Veiculo *)caminhao, marca, modelo);
    caminhao->veiculo.abastecer = (Abastecer)Caminhao_abastecer;
    caminhao->capacidade = capacidade;
}

int Caminhao_getCapacidade(Caminhao *caminhao)
{
    return caminhao->capacidade;
}

static void Caminhao_abastecer(void *caminhao)
{    
    printf("Caminhao marca: %s, modelo: %s, capacidade: %d\n",Veiculo_getMarca(caminhao), Veiculo_getModelo(caminhao), Caminhao_getCapacidade(caminhao));
}