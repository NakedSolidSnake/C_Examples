#include <eletroeletronico.h>

void Eletroeletronico_constructor(Eletroeletronico *eletronico, int voltagem)
{
    eletronico->voltagem = voltagem;
}

char *Eletroeletronico_ligar(void *eletroeletronico)
{
    return ((Eletroeletronico *)eletroeletronico)->ligar();
}

char *Eletroeletronico_desligar(void *eletroeletronico)
{
    return ((Eletroeletronico *)eletroeletronico)->desligar();
}

int Eletroeletronico_getVoltagem(Eletroeletronico *eletronico)
{
    return eletronico->voltagem;
}