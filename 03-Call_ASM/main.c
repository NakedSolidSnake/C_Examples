#include <stdio.h>
#include <stdlib.h>

extern int get_value_asm(int value);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>.\n", argv[0]);
        return 1;
    }
    printf("Value %d\n", get_value_asm(atoi(argv[1])));
    return 0;
}
