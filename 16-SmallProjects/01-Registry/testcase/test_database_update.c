#include <database/db.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <domain/person.h>

#define BUF_LEN   1024
static char query[BUF_LEN];

char *update(void *data);

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
        .update = update
    };


    
    assert(!initdb(&params));

    Person_t *person = person_constructor("Sara de Oliveira", "Rua Nova Vida", 32);

    assert(!updatedb(&driver, person));

    person_destructor(person);

    assert(!closedb());
    return 0;
}

char *update(void *data)
{
    Person_t *p = (Person_t *)data;
    
        
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "update person set name='%s', address='%s', age=%d where id=%d",
                get_person_name(p), get_person_address(p), get_person_age(p), 1);
    return query;
}
