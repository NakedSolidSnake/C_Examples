#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 80


typedef struct 
{
    char name[MAX_NAME_LEN];
    int age;
}Person_t;

typedef struct 
{
    Person_t person[10];
    int amount;
}Persons_t;

static Persons_t persons;

void printPersons(const Persons_t *persons);
void add(Person_t person);

int main(int argc, char const *argv[])
{
    Person_t cristiano = {.name = "Cristiano", .age = 33};
    Person_t sara = {.name = "Sara", .age = 31};

    add(cristiano);
    add(sara);
    printPersons(&persons);
    
    return 0;
}

void printPersons(const Persons_t *persons)
{
    for (int i = 0; i < persons->amount; i++)
    {
        Person_t *p = &persons->person[i];
        printf("Name: %s\tAge: %d\n", p->name, p->age);
    }    
}

void add(Person_t person)
{
    persons.person[persons.amount] = person;
    persons.amount++;
}