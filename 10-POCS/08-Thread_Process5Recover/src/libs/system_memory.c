#include "system_memory.h"
#include <stdlib.h>
#include <string.h>

int memoryInit(void)
{
    int ret = -1;

    shm_t shm;
    
    ret = sharedMemoryInit(&shm, MEMORY_KEY, sizeof(systemMemory_st));

    if(ret)
        return -1;

    memset(shm.shm, 0, sizeof(systemMemory_st));

    systemMemory_st *mem = (systemMemory_st *)shm.shm;
    if(mem->init)
        return 0;

    mem->init = 1;    

    return 0;
    
}

systemMemory_st *memoryGet(void)
{
    systemMemory_st *mem = NULL;
    shm_t shm;
    int ret = -1;

    ret = sharedMemoryInit(&shm, MEMORY_KEY, sizeof(systemMemory_st));

    if(ret)
        return NULL;

    mem = (systemMemory_st *)shm.shm;

    if(mem->init)
        return mem;

    return NULL;    
}

int memoryWrite(systemMemory_st * systemMemory, void *data, int offset)
{    
    processes_st *pData = (processes_st *)data;
    if(!data || !systemMemory)
        return -1;
   
    memcpy(&systemMemory->processes[offset], pData, sizeof(processes_st));

    return 0;
}