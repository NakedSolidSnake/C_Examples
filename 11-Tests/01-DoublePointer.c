#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char *messages[] = 
    {
        "Cristiano",
        "Marcelo",
        "Mango"
    };

    char **list = (char **)malloc(sizeof(char *) * 3);

    if(list == NULL){
        return 1;
    }

    int len = strlen(messages[0]);
    list[0] = (char *)malloc(sizeof(char) * len + 1);
    strncpy(list[0], messages[0], len);

    len = strlen(messages[1]);
    list[1] = (char *)malloc(sizeof(char) * len + 1);
    strncpy(list[1], messages[1], len);


    len = strlen(messages[2]);
    list[2] = (char *)malloc(sizeof(char) * len + 1);
    strncpy(list[2], messages[2], len);

    free(list[0]);
    free(list[1]);
    free(list[2]);

    free(list);

    return 0;
}
