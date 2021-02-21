#ifndef __CACHORRO_H
#define __CACHORRO_H

#include <animal.h>

typedef struct 
{
    Animal animal;    
}Cachorro;

void Cachorro_constructor(Cachorro *cachorro, int idade, int peso, const char *nome);

#endif