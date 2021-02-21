/*
 * tasks.c
 *
 *  Created on: 05/11/2018
 *      Author: csouza
 */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tasks/tasks_control.h"


int8_t Tasks_Init(void)
{

	while(Task_Bluetooth_Start())
	{

	}

	while(Task_KBD_Start())
	{

	}

	while(Task_LCD_Start())
	{

	}

	while(Task_LoadCell_Start())
	{

	}

	while(Task_MQTT_Start())
	{

	}

	return 0;
}

int8_t Tasks_Wait_Finish(void)
{
	while(Task_Bluetooth_Wait_Finish())
	{

	}

	while(Task_KBD_Wait_Finish())
	{

	}

	while(Task_LCD_Wait_Finish())
	{

	}

	while(Task_LoadCell_Wait_Finish())
	{

	}

	while(Task_MQTT_Wait_Finish())
	{

	}

	return 0;
}