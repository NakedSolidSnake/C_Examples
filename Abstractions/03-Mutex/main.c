/*
 * main.c
 *
 *  Created on: 29/01/2019
 *      Author: csouza
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Semaphore{
	int locked;
}Semaphore;

int Mutex_Create(void **mutex);
int Mutex_Take(void **mutex);
int Mutex_Give(void **mutex);
int Mutex_Destroy(void **mutex);


int Print_List(void ***list);

char *lista[] = {
		"Nome",
		"ano"
};

Print_List(&lista);

int main(int argc, char **argv) {

	int ret;
	Semaphore *mutex = NULL;

	ret = Mutex_Create((void **)&mutex);
	if(ret == 0)
	{
		printf("Mutex Created value %p\n", (int *)mutex);
	}

	ret = Mutex_Take((void **)&mutex);
	if(ret == 0)
	{
		printf("Resource taked\n");
	}

	ret = Mutex_Take((void **)&mutex);
	if(ret == 0)
	{
		printf("Resource taked\n");
	}else{
		printf("Resource Busy\n");
	}

	ret = Mutex_Give((void **)&mutex);
	if(ret == 0)
	{
		printf("Resource Given\n");
	}

	ret = Mutex_Destroy((void **)&mutex);
	if(ret == 0)
	{
		printf("Mutex Destroyed value %p\n", (int *)mutex);
	}

	return EXIT_SUCCESS;
}

int Mutex_Create(void **mutex)
{
	Semaphore *semaphore;
	semaphore = (Semaphore *)malloc(sizeof(int) * 1);
	if(semaphore == NULL)
	{
		return -2;
	}

	semaphore->locked = 0;
	*mutex = semaphore;
	return 0;
}

int Mutex_Take(void **mutex)
{
	Semaphore *semaphore = (Semaphore *) *mutex;
	if(semaphore == NULL)
		return -1;

	if(semaphore->locked)
	{
		return 1;
	}

	semaphore->locked = 1;
	return 0;
}

int Mutex_Give(void **mutex)
{
	Semaphore *semaphore = (Semaphore *) *mutex;
	if(semaphore == NULL)
		return -1;
	if(semaphore->locked)
		semaphore->locked = 0;
	return 0;
}

int Mutex_Destroy(void **mutex)
{
	Semaphore *semaphore = (Semaphore *) *mutex;
	if(semaphore == NULL)
	{
		return -1;
	}

	if(semaphore == NULL)
	{
		return -2;
	}

	free(semaphore);

	return 0;
}
