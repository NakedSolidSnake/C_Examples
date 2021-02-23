#include <database/db.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <domain/person.h>

#define BUF_LEN   1024
static char query[BUF_LEN];

char *delete(void *data);

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
        .delete = delete
    };
    
    assert(!initdb(&params));
   
    assert(!deletedb(&driver, NULL));

    assert(!closedb());
    return 0;
}

char *delete(void *data)
{
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "delete from person");                
    return query;
}
