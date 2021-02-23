#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "taskLCD.h"
#include "../../FileOperation/fileoperation.h"

static int8_t lcd_handle = -1;
static pthread_t thread_LCD;

void *task_LCD(void* args)
{
	const int8_t *msg = "Thread LCD\n";
	while(1)
	{		
		(void)device_write(lcd_handle, msg, strlen(msg));
		usleep(1000);
	}

	return NULL;
}

int8_t Task_LCD_Start(void)
{

	lcd_handle = device_open("LCD16");
	if(lcd_handle < 0)
	{
		while(1);
	}

	return pthread_create(&thread_LCD, NULL, task_LCD, NULL);
}

int8_t Task_LCD_Wait_Finish(void)
{
	return (int8_t)pthread_join(thread_LCD, NULL);
}

int8_t Task_LCD_Destroy(void)
{
	if(lcd_handle >= 0)
	{
		device_close(lcd_handle);
	}
	return (int8_t)pthread_cancel(thread_LCD);
}