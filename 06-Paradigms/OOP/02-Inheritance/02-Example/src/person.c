#include <person.h>
#include <string.h>

struct person{
    char name[MAX_NAME_LEN + 1];
    int age;
};

Person_t *Person_new(const char * const name, const int age)
{
    Person_t *person = (Person_t *)malloc(sizeof(person));
    if(person)
    {
        strncpy(person->name, name, MAX_NAME_LEN);
        person->age = age;
    }

    return person;
}

void Person_delete(Person_t *person)
{
    if(person)
        free(person);
}

char *Person_getName(const Person_t *person)
{
    return person->name;
}

int Person_getAge(const Person_t *person)
{
    return person->age;
}

char *Person_toString(const Person_t *person)
{
    char buffer[100] = {0};
    snprintf(buffer, 100, "name: %s ,age : %d", person->name, person->age);
    return strndup(buffer, strlen(buffer) + 1);
}
