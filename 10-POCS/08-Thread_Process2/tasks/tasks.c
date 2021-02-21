#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>


#ifdef PROCESS
int main(int argc, char const *argv[])
{
    work(NULL);
    return 0;
}
#endif

void *work(void *args)
{
    printf("Work.\n");
}