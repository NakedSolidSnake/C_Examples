#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "taskLoadCell.h"
#include "../../FileOperation/fileoperation.h"

static int8_t loadCell_handle = -1;
static pthread_t thread_LoadCell;

void *task_LoadCell(void* args)
{
	const int8_t *msg = "Thread Load Cell\n";
	while(1)
	{		
		(void)device_write(loadCell_handle, msg, strlen(msg));
		usleep(1000);
	}

	return NULL;
}

int8_t Task_LoadCell_Start(void)
{
	loadCell_handle = device_open("ADC");
	if(loadCell_handle < 0)
	{
		while(1){
			printf("Error to open ADC device\n");
			usleep(10000000);
		}
	}

	return pthread_create(&thread_LoadCell, NULL, task_LoadCell, NULL);
}

int8_t Task_LoadCell_Wait_Finish(void)
{
	return (int8_t)pthread_join(thread_LoadCell, NULL);	
}

int8_t Task_LoadCell_Destroy(void)
{
	if(loadCell_handle >= 0)
	{
		device_close(loadCell_handle);
	}
	
	return (int8_t)pthread_cancel(thread_LoadCell);
}