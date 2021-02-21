#ifndef __COMMON_H
#define __COMMON_H

#define MAX_PROGRAM_NAME        40

typedef struct list List;

typedef void *(*Function_t)(void *context);

typedef struct 
{
    char name[MAX_PROGRAM_NAME];
    Function_t f;
}TaskObject_t;

List *List_create(void);
void List_add(List *list, TaskObject_t f);
int List_isEmpty(List *list);
int List_isFull(List *list);


#endif