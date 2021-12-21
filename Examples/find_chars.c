#include <stdio.h>
#include <string.h>


int main()
{
    const char *str = "Pessoa\nCristiano\nOutro\n    \n";
    int items = 0;
    char *ptr = strchr(str, '\n');
    while(ptr != NULL)
    {
        if(*ptr == '\n')
            items++;

        ptr = strchr(ptr + 1, '\n');
    }

    printf("Items: %d\n", items);
    return 0;
}