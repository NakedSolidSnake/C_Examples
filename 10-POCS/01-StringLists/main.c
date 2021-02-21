#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getList(void ***object);

int main(int argc, char const *argv[])
{

    

    // char *stringList1[] = 
    // {
    //     "First Line",
    //     "Second Line",
    //     "Third Line"
    // };

    // char *stringList2[] = 
    // {
    //     "One Line",
    //     "Two Lines",
    //     "Three Lines"
    // };

    // char **strings[] = {
    //     &stringList1,
    //     &stringList2
    // };

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", stringList1[i]);
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", stringList2[i]);
    // }

    char ***lists;

    getList(lists);

    for(int i = 0; i < 2; i++){
        
        char **list = (char **) lists[i];

        for (int i = 0; i < 3; i++)
        {
            printf("%s\n", list[i]);
        }
    }

    free(lists[0]);
    free(lists[1]);
    
    
    return 0;
}

int getList(void ***object)
{
    static char *stringList1[] = 
    {
        "First Line",
        "Second Line",
        "Third Line"
    };

    static char *stringList2[] = 
    {
        "One Line",
        "Two Lines",
        "Three Lines"
    };

    *object = (void **)malloc(sizeof (void **) * 2);
    
    if(*object == NULL)
        return -1;

    object[0] = (void **)stringList1;
    object[1] = (void **)stringList2;
    return 0;
}