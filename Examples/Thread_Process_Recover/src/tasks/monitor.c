#include "monitor.h"
#include <system_memory.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <aux.h>
#include <stdio.h>
#include <sys/types.h>

static int verifyTime(struct timespec *current, time_t timeout, processes_st *process);

int main(int argc, char const *argv[])
{
    struct timespec  current;
    time_t t = 1000000000;
    int i;
    int ret;

    systemMemory_st *mem = memoryGet();
    if(mem == NULL)
        return -1;

    clock_gettime(CLOCK_MONOTONIC, &current);
    for (i = 0; i < (mem->process_amount - 1); i++)
    {
        processes_st *process = &mem->processes[i];
        process->old = process->update = (double)current.tv_sec  + (double)current.tv_nsec /(double)1000000000;        
    }

    while(1)
    {
        sleep(2);        

        for(i = 0; i < (mem->process_amount - 1); i++)
        {   
            processes_st *process = &mem->processes[i];       
            ret = verifyTime(&current, t, process);

            if(!ret){                
                process->old = process->update;
                process->miss_count = 0;
            }else{
                           
                if(process->miss_count == 3){
                    printf("Process %s unable to respond\n", process->processName);
                    printf("Killing process %s\n", process->processName);
                    kill(process->pid, SIGKILL);
                    printf("recover process %s\n", process->processName);                    
                    pid_t pid = fork();
                    if (pid == 0)
                    {
                        execl(process->processName, process->processName, NULL);
                    }
                    else if (pid > 0)
                    { 
                        usleep(10000);
                        signal(SIGCHLD,SIG_IGN); //ignores child signal                       
                        process->pid = pid;                        
                        memoryWrite(mem, (void *)process, i);
                        process->miss_count = 0;                        
                    }
                }else {
                    printf("send signal to process %s pid %d\n", process->processName, process->pid);
                    //wait for response
                    kill(process->pid, SIGUSR1);  
                    process->miss_count ++;   
                }
                
            }
        }
        
    }
    
    return 0;
}

static int verifyTime(struct timespec *current, time_t timeout, processes_st *process)
{
    double _timeout = (timeout / 1000000000) + (timeout % 1000000000)/(double)1000000000;    
    double _current = (double)current->tv_sec  + (double)current->tv_nsec /(double)1000000000;
    return ((process->old + _timeout) > process->update);
}