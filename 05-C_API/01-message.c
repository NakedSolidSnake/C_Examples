#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage : %s <message>.\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("%s\n", argv[1]);
    return EXIT_SUCCESS;
}
