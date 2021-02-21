#include <stdio.h>
#include <stdlib.h>
#include <aluno.h>
#include <string.h>
#include <database.h>
#include <submenu.h>

static char query[QUERY_LEN];

char *delete(void *object);
int select_data(void);

int delete_student(void)
{
     DatabaseInfo_t dbInfo = {
        "localhost",
        "root",
        "$0l1d$2r2",
        "aluno"};


    DATABASE_init(&dbInfo);

    int sel = select_data();

    DATABASE_delete(delete, &sel);    
    return 0;
}

char *delete(void *object)
{
    int *id;
    if (!object)
    {
        return NULL;
    }
    id = (int *)object;
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "DELETE FROM alunos WHERE ID = %d", *id);             
    return query;
}

int select_data(void)
{
    int selected;
    printf("Select a id to delete: ");
    scanf("%d", &selected);
    getchar();
    return selected;
}