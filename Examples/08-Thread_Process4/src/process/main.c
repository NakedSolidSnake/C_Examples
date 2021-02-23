#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct processList
{ 
    char name[30];    
}processList_st;

static processList_st pList[] = 
{
    {.name = "./program_a"},
    {.name = "./program_b"}
};

static int processes_amount = sizeof(pList)/sizeof(pList[0]);

int main(int argc, char const *argv[])
{

    for (int i = 0; i < processes_amount; i++)
    {
        if(fork() == 0){
            execl(pList[i].name, pList[i].name, NULL);
        }    
    }

    return 0;
}
