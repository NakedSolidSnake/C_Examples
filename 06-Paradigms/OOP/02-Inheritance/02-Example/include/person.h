#ifndef __PERSON_H
#define __PERSON_H

#define MAX_NAME_LEN    80

typedef struct person Person_t;

Person_t *Person_new(const char * const name, const int age);
void Person_delete(Person_t *person);

char *Person_getName(const Person_t *person);
int Person_getAge(const Person_t *person);

char *Person_toString(const Person_t *person);

#endif