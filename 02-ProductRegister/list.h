#ifndef LIST_H_
#define LIST_H_

#include "product.h"
#include "list.h"
#include <stdio.h>


typedef struct list *List;

List *List_create(void);
void List_destroy(List *list);
int List_add(List *list, Product *product);
int List_remove(List *list, int id);
int List_showAll(List *list, FILE *file);


#endif /* LIST_H_ */
