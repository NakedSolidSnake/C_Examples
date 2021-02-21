/*
 * tasks.c
 *
 *  Created on: 05/11/2018
 *      Author: csouza
 */

#include "tasks.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static int8_t Task_LCD_Init(void);
static int8_t Task_Keyboard_Init(void);
static int8_t Task_LoadCell_Init(void);


void *LoadCellThread(void * args)
{
	while(1)
	{
		printf("Thread Load Cell\n");
		usleep(1000);
	}

	return NULL;
}


void *KeyboardThread(void * args)
{
	while(1)
	{
		printf("Thread Keyboard\n");
		usleep(1000);
	}

	return NULL;
}

void *LCDThread(void * args)
{
	while(1)
	{
		printf("Thread LCD\n");
		usleep(1000);
	}

	return NULL;
}


int8_t Tasks_Init(void)
{

	while(Task_LCD_Init())
	{

	}

	while(Task_Keyboard_Init())
	{

	}

	while(Task_LoadCell_Init())
	{

	}

	return 0;
}


static int8_t Task_LCD_Init(void)
{
	pthread_t threadLCD;
	return pthread_create(&threadLCD, NULL, LCDThread, NULL);
}

static int8_t Task_Keyboard_Init(void)
{
	pthread_t threadKeyboard;
	return pthread_create(&threadKeyboard, NULL, KeyboardThread, NULL);
}

static int8_t Task_LoadCell_Init(void)
{
	pthread_t threadLoadCell;
	return pthread_create(&threadLoadCell, NULL, LoadCellThread, NULL);
}
