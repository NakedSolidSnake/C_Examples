#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define _GNU_SOURCE

/*
to configure coredump

$ ulimit -c --> this command shows which value is set to coredump file

$ ulimit -c unlimited --> this command set coredump to maxvalue

to get result about core file 

$ gdb ./coredump.out core

*/

int main(int argc, char const *argv[])
{
    int random;
    int *goodPointer = (int *)malloc(sizeof(int));
    int *badPointer = NULL;

    while(1)
    {
        random = rand() % 255;
        if(random == 13)
        {
            /* This operation will result a segfault*/
            *badPointer = random;
        }else
        {
            *goodPointer = random;
        }

        printf("random = %d\n", random);
        
    }

    free(goodPointer);
    return 0;
}
