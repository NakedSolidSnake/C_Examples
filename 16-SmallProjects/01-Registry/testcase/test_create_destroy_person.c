#include <domain/person.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Person_t * person = person_constructor("Cristiano Silva de Souza", "Rua Nova Vida", 34);
    assert(person != NULL);

    person_destructor(person);
    
    return 0;
}
