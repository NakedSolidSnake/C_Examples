#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_string(void **str);

int main(int argc, char const *argv[])
{
    char * mesg_recv = NULL;

    if(get_string((void **)&mesg_recv))
        return -1;

    printf("%s\n", mesg_recv);

    free(mesg_recv);
    
    return 0;
}

int get_string(void **str)
{
    const char *message = "it is the way he goes";
    *str = malloc(strlen (message) + 1);
    if(*str == NULL)
        return -1;

    strncpy(*str, message, strlen(message));

    return 0;
}