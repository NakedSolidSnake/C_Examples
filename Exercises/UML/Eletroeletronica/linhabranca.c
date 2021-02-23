#include <linhabranca.h>
#include <string.h>

void LinhaBranca_constructor(LinhaBranca *linhaBranca, const char *classificacao, int voltagem)
{
    Eletroeletronico_constructor((Eletroeletronico *)linhaBranca, voltagem);
    strncpy(linhaBranca->classificacao, classificacao, CLASSICACAO_LEN);
}

char *LinhaBranca_abrir(void * linhaBranca)
{
    return ((LinhaBranca *)linhaBranca)->abrir();
}

void LinhaBranca_fechar(void * linhaBranca)
{
    ((LinhaBranca *)linhaBranca)->fechar();
}