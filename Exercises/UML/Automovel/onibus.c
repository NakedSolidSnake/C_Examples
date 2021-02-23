#include <onibus.h>
#include <stdio.h>

static void Onibus_abastecer(void *onibus);

void Onibus_constructor(Onibus *onibus, const char *marca, const char *modelo, int lugares)
{
    Veiculo_constructor((Veiculo *)onibus, marca, modelo);
    onibus->veiculo.abastecer = (Abastecer)Onibus_abastecer;
    onibus->lugares = lugares;
}

int Onibus_getLugares(Onibus *onibus)
{
    return onibus->lugares;
}

static void Onibus_abastecer(void *onibus)
{    
    printf("Onibus marca: %s, modelo: %s, lugares: %d\n", Veiculo_getMarca(onibus), Veiculo_getModelo(onibus),Onibus_getLugares(onibus));
}