#ifndef _PEOPLE_H
#define _PEOPLE_H

#define MAX_NAME       80
#define MAX_ADDRESS    100

typedef struct people
{
  char name[MAX_NAME];
  char address[MAX_ADDRESS];
}people_t;

#endif 
