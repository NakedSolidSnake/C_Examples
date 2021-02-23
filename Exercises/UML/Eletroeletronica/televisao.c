#include <televisao.h>
#include <stdio.h>

static char *Televisao_entrarStandyBy(void);
static char *Televisao_sairStandyBy(void);
static char *Televisao_ligar(void);
static char *Televisao_desligar(void);

void Televisao_constructor(Televisao *televisao, int voltagem, int potenciaSom, int tamanho)
{
    SomImagem_constructor((SomImagem *)televisao, potenciaSom, voltagem);
    televisao->tamanho = tamanho;
    televisao->somImagem.entrarStandyBy = Televisao_entrarStandyBy;
    televisao->somImagem.sairStandyBy = Televisao_sairStandyBy;
    televisao->somImagem.eletronico.ligar = Televisao_ligar;
    televisao->somImagem.eletronico.desligar = Televisao_desligar;
}

char *Televisao_mudarCanal(Televisao *televisao)
{
    (void)televisao;
    return "Change channel";
}

static char *Televisao_entrarStandyBy(void)
{
    return "Televisao em StandyBy";
}

static char *Televisao_sairStandyBy(void)
{
    printf("Televisao Normal\n");
    return NULL;
}

static char *Televisao_ligar(void)
{
    printf("Televisao ligada\n");
    return NULL;
}

static char * Televisao_desligar(void)
{
    printf("Televisão desligada\n");
    return NULL;
}