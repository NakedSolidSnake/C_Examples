#include <database/db.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <domain/person.h>

#define BUF_LEN   1024
static char query[BUF_LEN];

char *select(void *data);
void retrieve(char **data, int colums);

int main(int argc, char *argv[])
{
    Database_params_t params = 
    {
        .hostname = "localhost",
        .username = "cssouza",
        .password = "senha",
        .database = "registry"
    };

    IDatabase_driver driver = 
    {
        .select = select,
        .retrieve = retrieve
    };


    
    assert(!initdb(&params));    

    assert(!selectdb(&driver, NULL));    

    assert(!closedb());
    return 0;
}

char *select(void *data)
{
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "select * from person");
    return query;
}

void retrieve(char **data, int colums)
{
    for(int i = 0; i < colums; i++)
    {
        printf("%s\n", data[i]);
    }
}