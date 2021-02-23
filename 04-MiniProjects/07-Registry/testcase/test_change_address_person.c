#include <domain/person.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *name = "Cristiano Silva de Souza";
    char *address = "Rua Nova Vida";
    short age = 34;
    Person_t * person = person_constructor(name, address, age);
    assert(person != NULL);

    set_person_address(person, "Rua Tomaraca");
    
    assert(strcmp(get_person_address(person), address) != 0);

    person_destructor(person);
    
    return 0;
}