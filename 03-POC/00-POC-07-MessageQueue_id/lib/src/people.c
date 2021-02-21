#include <people.h>
#include <stdio.h>
#include <string.h>


int people_init(people_t *p)
{
  if(p == NULL)
    return -1;
  memset(p, 0, sizeof(people_t));
  return 0;
}

int people_print(const people_t *p)
{
  printf("Name: %s", p->name);
  printf("Age: %d\n", p->age);
  printf("Address: %s", p->addr);
}

int people_register(people_t *p)
{
  if(p == NULL)
    return -1;
  
  printf("Enter name: ");
  fgets(p->name, sizeof(p->name), stdin);
  printf("Enter age: ");
  scanf("%d", &p->age);
  getchar();
  printf("Enter address: ");
  fgets(p->addr, sizeof(p->addr), stdin);
}
