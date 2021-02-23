#include <submenu.h>
#include <aluno.h>
#include <stdio.h>

Aluno_t *Aluno_new(void)
{
    Aluno_t *al = (Aluno_t *)malloc(sizeof(Aluno_t));

    fputs("Insert a student name: ", stdout);
    fgets(al->nome, sizeof(al->nome), stdin);
    al->nome[strlen(al->nome) - 1] = 0;
    fputs("Insert a register number: ", stdout);
    scanf(" %d", &al->matricula);
    fputs("Insert student\'s age: ", stdout);
    scanf("%d", &al->idade);
    getchar();
    fputs("Insert student\'s course: ", stdout);
    fgets(al->curso, sizeof(al->curso), stdin);
    al->curso[strlen(al->curso) - 1] = 0;

    return al;
}