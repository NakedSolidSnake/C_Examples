#include <cachorro.h>
#include <stdio.h>

static void Cachorro_latir(void);

void Cachorro_constructor(Cachorro *cachorro, int idade, int peso, const char *nome)
{
    Animal_constructor((Animal *)cachorro, idade, peso, nome);
    cachorro->animal.som = Cachorro_latir;
}

static void Cachorro_latir(void)
{
    printf("Bark Bark.\n");
}