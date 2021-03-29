#include <lista_sequencial.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    struct aluno alunos[] = 
    {
        {.matricula = 1, "Cristiano", .n1 = 10, .n2 = 8, .n3 = 5},
        {.matricula = 2, "Jorge", .n1 = 10, .n2 = 8, .n3 = 5},
        {.matricula = 3, "Marcelo", .n1 = 10, .n2 = 8, .n3 = 5},
        {.matricula = 4, "Jose", .n1 = 10, .n2 = 8, .n3 = 5},
        {.matricula = 5, "Sara", .n1 = 10, .n2 = 8, .n3 = 5},

    };

    int size = sizeof(alunos) / sizeof(alunos[0]);

    Lista *lista = cria_lista();

    printf("Tamanho da Lista: %d.\n", tamanho_lista(lista));
    printf("Lista Cheia: %d.\n", lista_cheia(lista));
    printf("Lista Vazia: %d.\n", lista_vazia(lista));

    for (int i = 0; i < size; i++)
        insere_lista_inicio(lista, alunos[i]);
    
    printf("Tamanho da Lista: %d.\n", tamanho_lista(lista));


    struct  aluno al;
    
    busca_lista_mat(lista, 5, &al);

    if(strcmp(al.nome, "Sara") == 0)
        printf("Achou a pessoa.\n");
    
    remove_lista_item(lista, 2);

    printf("Tamanho da Lista: %d.\n", tamanho_lista(lista));




    libera_lista(lista);
    return 0;
}
