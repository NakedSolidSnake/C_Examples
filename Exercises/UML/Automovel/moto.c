#include <moto.h>
#include <stdio.h>

static void Moto_abastecer(void *moto);

void Moto_constructor(Moto *moto, const char *marca, const char *modelo, int cilindrada)
{
    Veiculo_constructor((Veiculo *)moto, marca, modelo);
    moto->veiculo.abastecer = (Abastecer)Moto_abastecer;
    moto->cilindrada = cilindrada;
}

int Moto_getCilidradas(Moto *moto)
{
    return moto->cilindrada;
}

static void Moto_abastecer(void *moto)
{    
    printf("Moto marca: %s, modelo: %s, cilindrada: %d\n",Veiculo_getMarca(moto), Veiculo_getModelo(moto), Moto_getCilidradas(moto));
}