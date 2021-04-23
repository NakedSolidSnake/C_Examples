#include <stdio.h>
#include <stdlib.h>

void callback(int parms, void *args);

int main()
{
    int args = 10;

    on_exit(callback, &args);

    // exit(EXIT_SUCCESS);
    exit(-1);
}

void callback(int parms, void *args)
{
    printf("Params: %d , My args %d.\n", parms, *(int *)args);
}