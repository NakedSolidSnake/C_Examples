#include <geladeira.h>
#include <string.h>
#include <stdio.h>

static char *Geladeira_ligar(void);
static char *Geladeira_desligar(void);
static char *Geladeira_abrir(void);
static void Geladeira_fechar(void);


void Geladeira_constructor(Geladeira *geladeira, const char *classificacao, const char *cor, const int voltagem)
{
    LinhaBranca_constructor((LinhaBranca *)geladeira, classificacao, voltagem);
    strncpy(geladeira->cor, cor, COR_LEN);
    geladeira->linhaBranca.abrir = Geladeira_abrir;
    geladeira->linhaBranca.fechar = Geladeira_fechar;
    geladeira->linhaBranca.eletroeletronico.desligar = Geladeira_desligar;
    geladeira->linhaBranca.eletroeletronico.ligar = Geladeira_ligar;
}

char *Geladeira_descongelar(Geladeira *geladeira)
{
    (void)geladeira;
    printf("Geladeira Descongelada.\n");
    return NULL;
}

static char *Geladeira_ligar(void)
{
    printf("Geladeira Ligada.\n");
    return NULL;
}

static char *Geladeira_desligar(void)
{
    printf("Geladeira Desligada.\n");
    return NULL;
}

static char *Geladeira_abrir(void)
{
    return strndup("Geladeira Aberta.\n", strlen("Geladeira Aberta.\n"));
}

static void Geladeira_fechar(void)
{
    printf("Geladeira Fechada.\n");
}