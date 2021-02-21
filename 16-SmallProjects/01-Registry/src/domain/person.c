#include <domain/person.h>
#include <string.h>
#include <stdlib.h>

static int is_person_valid(Person_t *person);


struct person{
    int id;
    char name[MAX_PERSON_NAME + 1];
    char address[MAX_PERSON_ADDRESS + 1];
    short age;
};

Person_t *person_constructor(const char *name, const char *address, const short age)
{
    Person_t *person = (Person_t *)calloc(1, sizeof(struct person));
    if(!person)
        return NULL;
    person->id = -1;
    strncpy(person->name, name, MAX_PERSON_NAME);
    strncpy(person->address, address, MAX_PERSON_ADDRESS);
    person->age = age;
    return person;
}

void person_destructor(Person_t *person)
{
    free(person);    
}

int get_person_id(Person_t *person)
{
    if(is_person_valid(person)){
        return person->id;
    }

    return -1;
}

void set_person_name(Person_t *person, const char *name)
{
    if(is_person_valid(person)){
        memset(person->name, 0, MAX_PERSON_NAME);
        strncpy(person->name, name, MAX_PERSON_NAME);
    }
}

void set_person_address(Person_t *person, const char *address)
{
    if(is_person_valid(person)){
        memset(person->address, 0, MAX_PERSON_ADDRESS);
        strncpy(person->address, address, MAX_PERSON_ADDRESS);
    }
}

void set_person_age(Person_t *person, const short age)
{
    if(is_person_valid(person)){
        person->age = age;
    }
}

char *get_person_name(Person_t *person)
{
    if(is_person_valid(person)){
        return person->name;
    }
    return NULL;
}

char *get_person_address(Person_t *person)
{
    if(is_person_valid(person)){
        return person->address;
    }

    return NULL;
}

int get_person_age(Person_t *person)
{
    if(is_person_valid(person)){
        return person->age;
    }

    return -1;
}

static int is_person_valid(Person_t *person)
{
    return (person != NULL);
}