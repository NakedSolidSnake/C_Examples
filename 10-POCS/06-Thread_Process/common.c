#include "common.h"
#include <stdlib.h>

#define MAX_TASKS 10

static int isCreate(List *list);

struct list
{
    TaskObject_t f[MAX_TASKS];
    int tasks;
};

List *List_create(void)
{   
    List *l = (List *)malloc(sizeof(List));
    return l;    
}

void List_add(List *list, TaskObject_t f)
{
    if(List_isFull(list))
        return;
    
    list->f[list->tasks] = f;
    list->tasks++;
}

int List_isEmpty(List *list)
{
    if(!isCreate)
        return -1;
    
    return list->tasks == 0;
}

int List_isFull(List *list)
{
    if(!isCreate)
        return -1;
    
    return list->tasks == MAX_TASKS;
}

static int isCreate(List *list)
{
    return list != NULL;
}