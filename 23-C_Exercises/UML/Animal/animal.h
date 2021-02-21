#ifndef __ANIMAL_H
#define __ANIMAL_H

#define NOME_LEN 80

typedef void (*Som)();

typedef struct 
{
    int idade;
    int peso;
    char nome[NOME_LEN];
    Som som;
}Animal;

void Animal_constructor(Animal *animal, int idade, int peso, const char *nome);
void Animal_som();

#endif
