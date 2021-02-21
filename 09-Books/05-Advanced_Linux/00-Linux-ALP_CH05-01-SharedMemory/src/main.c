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
#include <sys/shm.h>
#include <sys/stat.h>

int main(void) {
	int segment_id;

	char *shared_memory;
	struct shmid_ds shmbuffer;
	int segment_size;

	const int shared_segment_size = 0x6400;

	/* Allocate a shared memory segment */
	segment_id = shmget(IPC_PRIVATE, shared_segment_size,
			IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

	/* Attach the shared memory segment */
	shared_memory = (char *) shmat(segment_id, 0, 0);

	printf("shared memory attached at address %p\n", shared_memory);

	shmctl(segment_id, IPC_STAT, &shmbuffer);
	segment_size = shmbuffer.shm_segsz;

	/* Write a string to the shared memory segment */
	sprintf(shared_memory, "Hello, world.");

	/* Detach the shared memory segment */
	shmdt(shared_memory);

	/* Reattach the shared memory segment, at different address */
	shared_memory = (char *) shmat(segment_id, (void *) 0x5000000, 0);

	printf("shared memory attached at address %p\n", shared_memory);

	printf("%s\n", shared_memory);

	/* Detach the shared memory segment */
	shmdt(shared_memory);

	/* Deallocate the shared memory */
	shmctl(segment_id, IPC_RMID, 0);

	return EXIT_SUCCESS;
}
