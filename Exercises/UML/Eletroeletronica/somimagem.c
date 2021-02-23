#include <somimagem.h>

void SomImagem_constructor(SomImagem *somImagem, int potenciaSom, int voltagem)
{
    Eletroeletronico_constructor((Eletroeletronico *)somImagem, voltagem);
    somImagem->potenciaSom = potenciaSom;
}

char *SomImagem_entrarStandyBy(void *somImagem)
{
    return ((SomImagem *)somImagem)->entrarStandyBy();
}

char *SomImagem_sairStandyBy(void *somImagem)
{
    return ((SomImagem *)somImagem)->sairStandyBy();
}