#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taskBluetooth.h"
#include "../../FileOperation/fileoperation.h"

static int8_t bluetooth_handle = -1;
static pthread_t thread_Bluetooth;

void *task_Bluetooth(void* args)
{
	const int8_t *text = "Bluetooth Thread\n";
	while(1)
	{		
		(void)device_write(bluetooth_handle, text, strlen(text));
		usleep(1000);
	}
}

int8_t Task_Bluetooth_Start(void)
{

	bluetooth_handle = device_open("Bluetooth");
	if(bluetooth_handle < 0)
	{
		while(1);
	}

	return pthread_create(&thread_Bluetooth, NULL, task_Bluetooth, NULL);
}

int8_t Task_Bluetooth_Wait_Finish(void)
{
	return (int8_t)pthread_join(thread_Bluetooth, NULL);	
}

int8_t Task_Bluetooth_Destroy(void)
{
	if(bluetooth_handle >= 0)
	{
		device_close(bluetooth_handle);
	}
	return (int8_t)pthread_cancel(thread_Bluetooth);
}