#include <stdio.h>
#include <stdlib.h>
#include <aluno.h>
#include <string.h>
#include <database.h>
#include <submenu.h>

static char query[QUERY_LEN];

char *insert(void *object);

int insert_student(void)
{
    DatabaseInfo_t dbInfo = {
        "localhost",
        "root",
        "$0l1d$2r2",
        "aluno"};


    DATABASE_init(&dbInfo);

    Aluno_t * al = Aluno_new();

    if(!al)
        return -1;

    DATABASE_insert(insert, al);
    
    free(al);
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