#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct list 
{
    Product *product;
    struct list *next;    
};

typedef struct list Element;

List *List_create(void)
{
    List *list = (List *)malloc(sizeof(list));
    if(list != NULL)
        *list = NULL;
    return list;
}

void List_destroy(List *list)
{
    if(list != NULL)
    {
        Element *node;
        while((*list) != NULL)
        {
            node = *list;
            *list = (*list)->next;
            free(node);
        }
    }
}

int List_add(List *list, Product *product)
{
    if(list == NULL)
        return -1;
    Element *node;
    node = (Element *)malloc(sizeof(Element));
    if(node == NULL)
        return -2;
    node->product = product;
    node->next = (*list);
    *list = node;
    return 0;
}

int List_remove(List *list, int id)
{
    if(list == NULL)
        return -1;

    if((*list) == NULL)
        return -2;

    Element *ant;
    Element *node = *list;

    while(node != NULL && Product_getId(node->product) != id)
    {
        ant = node;
        node = node->next;
    }

    if(node == NULL)
        return -3;

    if(node == *list)
        *list = node->next;
    else 
        ant->next = node->next;
    free(node);
    return 0;
}

int List_showAll(List *list, FILE *file)
{
    if(list == NULL)
        return -1;

    if((*list) == NULL)
        return -2;

    if(file == NULL)
        file = stdout;

    for(Element *node = *list; node != NULL; node = node->next)
    {
        fprintf(file, "ID: %d\n", Product_getId(node->product));
        fprintf(file, "NAME: %s\n", Product_getName(node->product));
        fprintf(file, "DESCRIPTION: %s\n", Product_getDescription(node->product));
        fprintf(file, "PRICE: R$ %.2lf\n\n", Product_getPrice(node->product));
    }
    return 0;
}
