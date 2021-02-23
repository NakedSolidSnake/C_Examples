#include <domain/person.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *name = "Cristiano Silva de Souza";
    char *address = "Rua Nova Vida";
    short age = 33;
    Person_t * person = person_constructor(name, address, age);
    assert(person != NULL);

    set_person_age(person, 34);
    
    assert(get_person_age(person) != age);

    person_destructor(person);
    
    return 0;
}