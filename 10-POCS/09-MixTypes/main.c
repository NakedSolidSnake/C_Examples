#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_FUNCTION
}eType;

typedef struct Types
{
    eType type;
    void *data;
}Types_t;


static void print(void);

int main(int argc, char *argv[])
{
    int a = 10;
    float dec = 25.63;
    char *string = "String";

    Types_t types[4] = {
        {.type = TYPE_INT, .data = &a},
        {.type = TYPE_FLOAT, .data = &dec},
        {.type = TYPE_STRING, .data = string},
        {.type = TYPE_FUNCTION, .data = print}
    };


    for(int i = 0; i < 4; i++)
    {
        Types_t *t = (void *)&types[i].type;
        if(t->type == TYPE_INT){
            printf("int value : %d\n", *(int *)t->data);
        }else if(t->type == TYPE_FLOAT){
            printf("int value : %f\n", *(float *)t->data);
        }else if(t->type == TYPE_STRING){
            printf("int value : %s\n", (char *)t->data);
        }else if(t->type == TYPE_FUNCTION){
            void (*function)(void) = t->data;
            function();
        }
    }

    return 0;
}

static void print(void)
{
    printf("I am a function.\n");
}