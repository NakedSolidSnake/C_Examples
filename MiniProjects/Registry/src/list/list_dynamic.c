#include <list/list_dynamic.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct element{
    void *data;
    struct element *next;
};

typedef struct element Elem;

List *List_create(void)
{
    List *li = (List *)malloc(sizeof(List));
    if(li != NULL)
        *li = NULL;
    return li;
}

void List_free(List *l)
{
    if(l != NULL){
        Elem *node;
        while((*l) != NULL){
            node = *l;
            *l = (*l)->next;
            if(node->data)
                free(node->data);
            free(node);
        }
        free(l);
    }
}

int List_insert(List *l, void *data, int size)
{
    if(l == NULL)
        return 0;
    
    Elem *node = (Elem *)malloc(sizeof(Elem));
    if(node == NULL)
        return 0;

    node->data = calloc(1, size);
    memcpy(node->data, data, size);
    node->next = (*l);
    *l = node;
    return 1;    
}

int List_remove(List *l, void **data, int size)
{
    if(l == NULL)
        return 0;
    
    if((*l) == NULL)
        return 0;

    Elem *node = *l;
    *data = calloc(1, size);
    memcpy(*data, node->data, size);
    *l = node->next;
    free(node->data);
    free(node);
    return 1;
}

int List_size(List *l)
{
    if(l == NULL)
        return 0;

    int count = 0;
    Elem *node = *l;
    while(node != NULL){
        count++;
        node = node->next;
    }

    return count;
}

int List_empty(List *l)
{
    if(l == NULL)
        return 1;
    if(*l == NULL)
        return 1;
    
    return 0;
}
