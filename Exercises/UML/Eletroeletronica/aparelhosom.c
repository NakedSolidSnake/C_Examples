#include <aparelhosom.h>
#include <stdio.h>
#include <string.h>

static char *AparelhoSom_entrarStandyBy(void);
static char *AparelhoSom_sairStandyBy(void);
static char *AparelhoSom_ligar(void);
static char * AparelhoSom_desligar(void);

void AparelhoSom_constructor(AparelhoSom *aparelhoSom, int voltagem, int potenciaSom, const char *marca)
{
    SomImagem_constructor((SomImagem *)aparelhoSom, potenciaSom, voltagem);
    strncpy(aparelhoSom->marca, marca, MARCA_LEN);
    aparelhoSom->somImagem.entrarStandyBy = AparelhoSom_entrarStandyBy;
    aparelhoSom->somImagem.sairStandyBy = AparelhoSom_sairStandyBy;
    aparelhoSom->somImagem.eletronico.ligar = AparelhoSom_ligar;
    aparelhoSom->somImagem.eletronico.desligar = AparelhoSom_desligar;

}

char *AparelhoSom_mudarEstacao(AparelhoSom *aparelhoSom)
{
    printf("Troca de Estacao.\n");
    return NULL;
}

static char *AparelhoSom_entrarStandyBy(void)
{
    return "Aparelho de Som em StandyBy";
}

static char *AparelhoSom_sairStandyBy(void)
{
    printf("Aparelho de Som Normal\n");
    return NULL;
}

static char *AparelhoSom_ligar(void)
{
    printf("Aparelho de Som ligado\n");
    return NULL;
}

static char * AparelhoSom_desligar(void)
{
    printf("Aparelho de Som desligado\n");
    return NULL;
}