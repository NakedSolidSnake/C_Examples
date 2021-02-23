#ifndef __GELADEIRA_H
#define __GELADEIRA_H

#include <linhabranca.h>

#define COR_LEN     20

typedef struct
{
    LinhaBranca linhaBranca;
    char cor[COR_LEN];
}Geladeira;

void Geladeira_constructor(Geladeira *geladeira, const char *classificacao, const char *cor, const int voltagem);
char *Geladeira_descongelar(Geladeira *geladeira);

#endif