#ifndef __SYSTEM_MEMORY_H
#define __SYSTEM_MEMORY_H

#define MAX_PROCESS_NAME    60
#define MAX_PROCESS         3

#define MEMORY_KEY          65

#include <time.h>
#include <sharedmemory/sharedmemory.h>

/**
 * @brief struct to hold data from each process
 * 
 */
typedef struct processes
{
    int pid;
    char processName[MAX_PROCESS_NAME];
    time_t update;
    time_t old; 
    int miss_count;
    int recover;   
}processes_st;

/**
 * @brief struct to register how many processes are in
 * the system.
 * 
 */
typedef struct systemMemory
{
    processes_st processes[MAX_PROCESS];
    int process_amount;
    shm_t shm;
    int init;
}systemMemory_st;

int memoryInit(void);
systemMemory_st *memoryGet(void);
int memoryWrite(systemMemory_st * systemMemory, void *data, int offset);
#endif