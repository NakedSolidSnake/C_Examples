#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <system_memory.h>
#include <string.h>

typedef struct processList
{ 
    char name[30];    
}processList_st;

static processList_st pList[] = 
{
    {.name = "./program_a"},
    {.name = "./program_b"},
    {.name = "./program_monitor"}
};

static int processes_amount = sizeof(pList)/sizeof(pList[0]);

int main(int argc, char const *argv[])
{

    systemMemory_st *mem;

    if(memoryInit() == -1){
        return -1;
    }

    mem = memoryGet();
    if(mem == NULL){
        return -1;
    }


    for (int i = 0; i < processes_amount; i++)
    {
        pid_t pid = fork();
        if(pid == 0){
            execl(pList[i].name, pList[i].name, NULL);
        } 
        else if(pid > 0){
            processes_st process;
            memset(&process, 0, sizeof(processes_st));
            process.pid = pid;
            process.recover = 0;
            strncpy(process.processName, pList[i].name, strlen(pList[i].name) + 1);
            memoryWrite(mem, (void *)&process, i);
        }
        else{
            exit(1);
        }
    }

    mem->process_amount = processes_amount;

    return 0;
}
