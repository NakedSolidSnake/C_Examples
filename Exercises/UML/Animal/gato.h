#ifndef __GATO_H
#define __GATO_H

#include <animal.h>

typedef struct 
{
    Animal animal;    
}Gato;

void Gato_constructor(Gato *gato, int idade, int peso, const char *nome);

#endif