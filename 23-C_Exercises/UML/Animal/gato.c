#include <gato.h>
#include <stdio.h>

static void Gato_miado(void);

void Gato_constructor(Gato *gato, int idade, int peso, const char *nome)
{
    Animal_constructor((Animal *)gato, idade, peso, nome);
    gato->animal.som = Gato_miado;
}

static void Gato_miado(void)
{
    printf("Meow Meow.\n");
}