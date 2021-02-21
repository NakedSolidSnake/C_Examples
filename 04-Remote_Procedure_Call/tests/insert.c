#include <database.h>
#include <stdio.h>
#include <stdlib.h>
#include <aluno.h>
#include <string.h>

#define QUERY_LEN 8192

static char query[QUERY_LEN];

char *insert(void *object);

int main(int argc, char const *argv[])
{
    DatabaseInfo_t dbInfo = {
        "localhost",
        "root",
        "$0l1d$2r2",
        "aluno"};

    Aluno_t alunos[] = {
        {.nome = "Cristiano Silva de Souza", .matricula = 16295242,.idade = 33, .curso = "Engenharia Eletrica"},
        {.nome = "Marcelo Alves Faustino"  , .matricula = 16295243,.idade = 28, .curso = "Engenharia Eletrica"},
        {.nome = "Samuel Dante Oliveira"   , .matricula = 16295244,.idade = 1 , .curso = "Engenharia Eletrica"},
        {.nome = "Hugo dos Santos de Souza", .matricula = 16295245,.idade = 38, .curso = "Engenharia Eletrica"},
        {.nome = "Sara de Oliveira"        , .matricula = 16295246,.idade = 32, .curso = "Engenharia Eletrica"},
        {.nome = "Jose Faustino Sobrinho"  , .matricula = 16295247,.idade = 66, .curso = "Engenharia Eletrica"}                
    };

    DATABASE_init(&dbInfo);
    for(int i = 0 ; i < (sizeof(alunos))/ sizeof(alunos[0]); i++){
        DATABASE_insert(insert, &alunos[i]);
    }
    return 0;
}

char *insert(void *object)
{
    Aluno_t *p;
    if (!object)
    {
        return NULL;
    }
    p = (Aluno_t *)object;
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "INSERT INTO alunos (nome, matricula, idade, curso) VALUES ('%s', %d, %d, '%s')",
             p->nome, p->matricula, p->idade, p->curso);
    return query;
}
