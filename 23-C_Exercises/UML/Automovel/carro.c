#include <carro.h>
#include <stdio.h>

static void Carro_abastecer(void *carro);

void Carro_constructor(Carro *carro,  const char *marca, const char *modelo, int portas)
{
    Veiculo_constructor((Veiculo *)carro, marca, modelo);
    carro->veiculo.abastecer = (Abastecer)Carro_abastecer;
    carro->portas = portas;
}

int Carro_getPortas(Carro *carro)
{
    return carro->portas;
}

static void Carro_abastecer(void *carro)
{
    printf("Carro marca: %s, modelo: %s, portas: %d\n",Veiculo_getMarca(carro), Veiculo_getModelo(carro),  Carro_getPortas(carro));
}