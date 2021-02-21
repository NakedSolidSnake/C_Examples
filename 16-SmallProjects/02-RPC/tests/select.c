#include <database.h>
#include <stdio.h>
#include <stdlib.h>
#include <aluno.h>
#include <string.h>

#define QUERY_LEN 8192

static char query[QUERY_LEN];

char *select();

int main(int argc, char const *argv[])
{
    DatabaseInfo_t dbInfo = {
        "localhost",
        "root",
        "$0l1d$2r2",
        "aluno"
        };    

    DATABASE_init(&dbInfo);
    Data_t *data = NULL;
    DATABASE_select(select, &data);

    printData(data);

    DATABASE_selectFree(&data);
    
    return 0;
}

char *select()
{  
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "SELECT * FROM alunos");
    return query;
}

void printData(Data_t *data){
    for (int i = 0; i < data->listsAmount; i++)
    {
        Request_t *d = &(data)->l[i];
        for(int j = 0; j < d->listItems; j++){
            printf("%s ", d->list[j]);
        }
        printf("\n");
    }    
}