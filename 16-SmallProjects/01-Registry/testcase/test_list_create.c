#include <list/list_dynamic.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    List *l = List_create();
    assert(l != NULL);

    List_free(l);
    return 0;
}
