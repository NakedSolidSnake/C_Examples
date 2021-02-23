#ifndef __VACA_H
#define __VACA_H

#include <animal.h>

typedef struct 
{
    Animal animal;    
}Vaca;

void Vaca_constructor(Vaca *vaca, int idade, int peso, const char *nome);

#endif