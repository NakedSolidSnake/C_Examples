#ifndef __PERSON_H
#define __PERSON_H

#define MAX_PERSON_NAME     80
#define MAX_PERSON_ADDRESS  80

typedef struct  person Person_t;

Person_t *person_constructor(const char *name, const char *address, const short age);
void person_destructor(Person_t *person);

void set_person_name(Person_t *person, const char *name);
void set_person_address(Person_t *person, const char *address);
void set_person_age(Person_t *person, const short age);

char *get_person_name(Person_t *person);
char *get_person_address(Person_t *person);
int get_person_age(Person_t *person);


#endif