#ifndef __LIST_DYNAMIC_H
#define __LIST_DYNAMIC_H

typedef struct element *List;

List *List_create(void);
void List_free(List *l);
int List_insert(List *l, void *data, int size);
int List_remove(List *l, void **data, int size);
int List_size(List *l);
int List_empty(List *l);

#endif
