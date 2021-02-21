/*
 * malloc_contro.c
 *
 *  Created on: Mar 25, 2019
 *      Author: cssouza
 */

#include <stdlib.h>
#include <stdio.h>
#include "malloc_contro.h"
#include <time.h>

#define MAX_VALUE_TO_ALLOC 1024

typedef enum{
	FREED,
	ALLOCATED
}MALLOC_STATE;

typedef struct{
	int pointer_addr;
	MALLOC_STATE state;
}malloc_status;

typedef struct{
	malloc_status status[MAX_VALUE_TO_ALLOC];
	int amount_allocated;
}malloc_control;


static malloc_control control = {
		.amount_allocated = 0,
};

static int malloc_save(int pointer_address);
static int malloc_remove(int pointer_address);
static int malloc_available(void);
static int malloc_is_empty(void);
static char *getStateMessage(MALLOC_STATE state);
static char *getTimeZone(void);


void * malloc_register(size_t size)
{
	if(malloc_available())
		return NULL;

	void *alloc = malloc(size);
	if(alloc != NULL)
	{
		malloc_save((int) alloc);
	}

	return alloc;
}

int free_register(void *ptr)
{
	int ret = EXIT_FAILURE;

	if(!malloc_is_empty())
	{
		malloc_remove((int)ptr);
		free(ptr);
		ret = EXIT_SUCCESS;
	}
	return ret;
}

int malloc_registered(void)
{
	return control.amount_allocated;
}

static int malloc_save(int pointer_address)
{
	int ret = EXIT_FAILURE;
	FILE *f = NULL;
	f = fopen("log.txt", "r+");
	if(f == NULL)
	{
		f = fopen("log.txt", "w");
	}

	if(pointer_address <= 0)
		return ret;

	for(int i = 0; i < MAX_VALUE_TO_ALLOC; i++)
	{
		if(control.status[i].state == FREED)
		{
			control.status[i].state = ALLOCATED;
			control.status[i].pointer_addr = pointer_address;
			control.amount_allocated++;

			if(f != NULL)
			{
				fseek(f, 0, SEEK_END);
				fprintf(f, "ALLOCATED: Status: [%s] Pointer Address [%08X] Time: %s\n", getStateMessage(control.status[i].state), control.status[i].pointer_addr, getTimeZone());
				fclose(f);
			}
			ret = EXIT_SUCCESS;
			break;
		}
	}
	return ret;
}

static int malloc_remove(int pointer_address)
{
	int ret = EXIT_FAILURE;

	FILE *f = NULL;
	f = fopen("log.txt", "r+");
	if(f == NULL)
	{
		f = fopen("log.txt", "w");
	}

	for(int i = 0; i < MAX_VALUE_TO_ALLOC; i++)
	{
		if(control.status[i].pointer_addr == pointer_address)
		{
			control.status[i].state = FREED;
			control.status[i].pointer_addr = 0;
			control.amount_allocated--;

			if(f != NULL)
			{
				fseek(f, 0, SEEK_END);
				fprintf(f, "ALLOCATED: Status: [%s] Pointer Address [%08X] Time: %s\n",getStateMessage(control.status[i].state), pointer_address, getTimeZone());
				fclose(f);
			}

			ret = EXIT_SUCCESS;
			break;
		}
	}
	return ret;
}

static int malloc_available(void)
{
	return control.amount_allocated == MAX_VALUE_TO_ALLOC;
}

static int malloc_is_empty(void)
{
	return control.amount_allocated == 0;
}

static char *getStateMessage(MALLOC_STATE state)
{
	switch (state) {
		case FREED:
			return "Freed";
			break;
		case ALLOCATED:
			return "Allocated";
			break;
		default:
			return NULL;
			break;
	}
}

static char *getTimeZone(void)
{
	time_t rawtime;
	struct tm *info;

	time( &rawtime );

	info = localtime( &rawtime );
	return asctime(info);
}
