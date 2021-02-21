#include <vaca.h>
#include <stdio.h>

static void Vaca_mugir(void);

void Vaca_constructor(Vaca *vaca, int idade, int peso, const char *nome)
{
    Animal_constructor((Animal *)vaca, idade, peso, nome);
    vaca->animal.som = Vaca_mugir;
}

static void Vaca_mugir(void)
{
    printf("Muu Muu.\n");
}