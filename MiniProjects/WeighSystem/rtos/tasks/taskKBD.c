#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "taskKBD.h"
#include "../../FileOperation/fileoperation.h"

static int8_t kbd_handle = -1;
pthread_t thread_KBD;

void *task_KBD(void* args)
{	
	const int8_t *msg = "Thread Keyboard\n";

	while(1)
	{
		(void)device_write(kbd_handle, msg, strlen(msg));
		usleep(100000);
	}

	return NULL;
}

int8_t Task_KBD_Start(void)
{
	kbd_handle = device_open("Keyboard");
	if(kbd_handle < 0)
	{
		while(1);
	}

	return (int8_t)pthread_create(&thread_KBD, NULL, task_KBD, NULL);
}

int8_t Task_KBD_Wait_Finish(void)
{
	return (int8_t)pthread_join(thread_KBD, NULL);
}

int8_t Task_KBD_Destroy(void)
{
	if(kbd_handle >= 0)
	{
		device_close(kbd_handle);
	}
	
	return (int8_t)pthread_cancel(thread_KBD);
}
