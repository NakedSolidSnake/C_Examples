#include <list/list_dynamic.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    List *l = List_create();
    assert(l != NULL);

    int number = 10;
    int *p_number;

    List_insert(l, &number, sizeof(int));

    assert(List_size(l) != 0);

    List_free(l);
    return 0;
}
