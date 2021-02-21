#include <stdio.h>
#include <stdlib.h>

void init (void) __attribute__ ((constructor (101)));
void deinit (void) __attribute__ ((destructor (101)));


int main(int argc, char *argv[])
{
    
    return 0;
}

void init (void)
{
    printf("Constructor.\n");
}

void deinit (void)
{
    printf("Destructor.\n");
}