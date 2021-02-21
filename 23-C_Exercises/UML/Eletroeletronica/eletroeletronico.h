#ifndef __ELETROELETRONICO_H
#define __ELETROELETRONICO_H

typedef char *(*Action)(void);

typedef struct 
{
    int voltagem;
    Action ligar;
    Action desligar;
}Eletroeletronico;

void Eletroeletronico_constructor(Eletroeletronico *eletronico, int voltagem);

char *Eletroeletronico_ligar(void *eletroeletronico);
char *Eletroeletronico_desligar(void *eletroeletronico);

int Eletroeletronico_getVoltagem(Eletroeletronico *eletronico);

#endif