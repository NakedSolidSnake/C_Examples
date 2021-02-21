#ifndef __LINHABRANCA_H
#define __LINHABRANCA_H

#include <eletroeletronico.h>

#define CLASSICACAO_LEN     80

typedef void (*ActionVoid)(void);

typedef struct 
{
    Eletroeletronico eletroeletronico;
    char classificacao[CLASSICACAO_LEN];
    Action abrir;
    ActionVoid fechar;
}LinhaBranca;


void LinhaBranca_constructor(LinhaBranca *linhaBranca, const char *classificacao, int voltagem);

char *LinhaBranca_ligar(void *linhaBranca);
char *LinhaBranca_desligar(void *linhaBranca);
char *LinhaBranca_abrir(void * linhaBranca);
void LinhaBranca_fechar(void * linhaBranca);

#endif