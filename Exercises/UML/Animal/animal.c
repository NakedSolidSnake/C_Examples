#include <animal.h>
#include <string.h>

void Animal_constructor(Animal *animal, int idade, int peso, const char *nome)
{
    animal->idade = idade;
    animal->peso = peso;

    strncpy(animal->nome, nome, NOME_LEN);
}

void Animal_som(void *animal)
{
    ((Animal *)animal)->som();
}