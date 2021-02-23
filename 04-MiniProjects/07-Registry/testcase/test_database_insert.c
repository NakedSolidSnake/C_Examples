#include <database/db.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <domain/person.h>

#define BUF_LEN   1024
static char query[BUF_LEN];

char *insert(void *data);

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
        .insert = insert
    };


    
    assert(!initdb(&params));

    Person_t *person = person_constructor("Cristiano Silva", "Rua Nova Vida", 34);

    assert(!insertdb(&driver, person));

    person_destructor(person);

    assert(!closedb());
    return 0;
}

char *insert(void *data)
{
    Person_t *p = (Person_t *)data;
    
        
    memset(query, 0, sizeof(query));
    snprintf(query, sizeof(query), "insert into person(name, address, age) values ('%s', '%s', %d)",
                get_person_name(p), get_person_address(p), get_person_age(p));
    return query;
}
