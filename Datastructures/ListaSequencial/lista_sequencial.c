#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;

    return li;
}

void libera_lista(Lista *li)
{
    free(li);
}

int busca_lista_pos(Lista *li, unsigned int pos, struct aluno *al)
{
    if(li == NULL || !pos || pos > li->qtd)
        return 0;

    *al = li->dados[pos - 1];
    return 1;
}

int busca_lista_mat(Lista *li, int mat, struct aluno *al)
{
    if (li == NULL)
        return 0;

    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd)
        return 0;

    *al = li->dados[i];
    return 1;
}

int insere_lista_final(Lista *li, struct aluno al)
{
    if(li == NULL)
        return 0;

    if(li->qtd == MAX)
        return 0;

    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
    if(li == NULL)
        return 0;

    if(li->qtd == MAX)
        return 0;

    int index;

    for (index = (li->qtd - 1); index >= 0; index--)
        li->dados[index + 1] = li->dados[index];

    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
    if(li == NULL)
        return 0;

    if(li->qtd == MAX)
        return 0;

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for (k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_item(Lista *li, int mat)
{
    if(li == NULL)
        return 0;

    if(li->qtd == 0)
        return 0;

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd) //element not found
        return 0;

    for(k = i; k < li->qtd -1; k++)
        li->dados[k] = li->dados[k + 1];

    li->qtd--;

    return 1;
}

/*
int remove_lista_item_otimizado(Lista *li, int mat)
{
    if(li == NULL)
        return 0;

    if(li->qtd == 0)
        return 0;

    int i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd) //element not found
        return 0;

    // for(k = i; k < li->qtd -1; k++)
    //     li->dados[k] = li->dados[k + 1];

    li->qtd--;

    li->dados[i] = li->dados[li->qtd];

    return 1;
}
*/

int remove_lista_inicio(Lista *li, int mat)
{
    if(li == NULL)
        return 0;

    if(li->qtd == 0)
        return 0;

    int k;
    for (k = 0; k < (li->qtd - 1); k++)
        li->dados[k] = li->dados[k + 1];

    li->qtd--;
    return 1;
}

int remove_lista_final(Lista *li, int mat)
{
    if(li == NULL)
        return 0;

    if(li->qtd == 0)
        return 0;

    li->qtd--;
    return 1;
}

int tamanho_lista(Lista *li)
{
    if(li == NULL)
        return -1;

    else 
        return li->qtd;
}

int lista_cheia(Lista *li)
{
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista *li)
{
    if(li == NULL)
        return -1;
    return li->qtd == 0;
}