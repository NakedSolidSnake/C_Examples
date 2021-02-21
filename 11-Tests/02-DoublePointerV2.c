#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char **list;
}Data_t;

void fill(Data_t **data, char **messages);

int main(int argc, char const *argv[])
{

    char *messages[] = 
    {
        "Cristiano",
        "Marcelo",
        "Mango"
    };

    Data_t *data = NULL;
    fill(&data, messages);

    // Data_t *data = (Data_t *)malloc(sizeof(Data_t));

    // //char ***lists = (char ***)malloc(sizeof(char **) * 3);

    // // *lists = (char **)malloc(sizeof(char *) * 3);

    // if(data == NULL){
    //     return 1;
    // }

    // data->list = (char **)malloc(sizeof(char *));

    // int len = strlen(messages[0]);
    // data->list[0] = (char *)malloc(sizeof(char) * len + 1);
    // strncpy(data->list[0], messages[0], len);

    // len = strlen(messages[1]);
    // data->list[1] = (char *)malloc(sizeof(char) * len + 1);
    // strncpy(data->list[1], messages[1], len);


    // len = strlen(messages[2]);
    // data->list[2] = (char *)malloc(sizeof(char) * len + 1);
    // strncpy(data->list[2], messages[2], len);

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", data->list[i]);
    // }
    

    // free(data->list[0]);
    // free(data->list[1]);
    // free(data->list[2]);

    // free(data->list);

    // free(data);

    return 0;
}

void fill(Data_t **data, char **messages)
{
    *data = (Data_t *)malloc(sizeof(Data_t));

    //char ***lists = (char ***)malloc(sizeof(char **) * 3);

    // *lists = (char **)malloc(sizeof(char *) * 3);

    if(*data == NULL){
        return 1;
    }

    (*data)->list = (char **)malloc(sizeof(char *));

    int len = strlen(messages[0]);
    (*data)->list[0] = (char *)malloc(sizeof(char) * len + 1);
    strncpy((*data)->list[0], messages[0], len);

    len = strlen(messages[1]);
    (*data)->list[1] = (char *)malloc(sizeof(char) * len + 1);
    strncpy((*data)->list[1], messages[1], len);


    len = strlen(messages[2]);
    (*data)->list[2] = (char *)malloc(sizeof(char) * len + 1);
    strncpy((*data)->list[2], messages[2], len);

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", (*data)->list[i]);
    }
    

    free((*data)->list[0]);
    free((*data)->list[1]);
    free((*data)->list[2]);

    free((*data)->list);

    free(*data);
}