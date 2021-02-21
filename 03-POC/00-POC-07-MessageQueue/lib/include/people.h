#ifndef __PEOPLE_H
#define __PEOPLE_H

#define MAX_NAME_LEN    100
#define MAX_ADDR_LEN    100

typedef struct people
{
  char name[MAX_NAME_LEN];
  char addr[MAX_ADDR_LEN];
  int age;
}people_t;

int people_init(people_t *p);

int people_print(const people_t *p);

int people_register(people_t *p);

#endif
