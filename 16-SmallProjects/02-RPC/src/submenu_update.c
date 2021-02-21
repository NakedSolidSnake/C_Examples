#include <stdio.h>
#include <stdlib.h>
#include <aluno.h>
#include <string.h>
#include <database.h>
#include <submenu.h>

typedef struct 
{
    int id;
    Aluno_t *al;
}AlunoUpdate_t;

static char query[QUERY_LEN];
static  void getValues(AlunoUpdate_t *alUp);

char *update(void *object);

int update_student(void)
{
     DatabaseInfo_t dbInfo = {
        "localhost",
        "root",
        "$0l1d$2r2",
        "aluno"};


    DATABASE_init(&dbInfo);

    AlunoUpdate_t student;

    getValues(&student);

    DATABASE_update(update, &student);

    printf("update a student.\n");
    return 0;
}

char *update(void *object)
{
    AlunoUpdate_t *p;
    if (!object)
    {
        return NULL;
    }
    p = (AlunoUpdate_t *)object;

    if(!p->al)
        return NULL;

    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "UPDATE alunos SET nome = '%s', matricula = %d, idade = %d, curso = '%s' WHERE id = %d",
             p->al->nome, p->al->matricula, p->al->idade, p->al->curso, p->id);
    printf("%s\n", query);
    return query;
}

static  void getValues(AlunoUpdate_t *alUp)
{
    if(!alUp)
        return ;

    printf("Select ID to update: ");
    scanf("%d", &alUp->id);
    getchar();

    alUp->al = Aluno_new();

    return;
}