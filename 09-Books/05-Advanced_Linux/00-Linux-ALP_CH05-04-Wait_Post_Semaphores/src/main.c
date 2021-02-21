/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int binary_semaphore_wait(int semid)
{
	struct sembuf operations[1];
	operations[0].sem_num = 0;
	operations[0].sem_op = -1;
	operations[0].sem_flg = SEM_UNDO;

	return semop(semid, operations, 1);
}

int binary_semaphore_post(int semid)
{
	struct sembuf operations[1];
	operations[0].sem_num = 0;
	operations[0].sem_op = 1;
	operations[0].sem_flg = SEM_UNDO;

	return semop(semid, operations, 1);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
