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
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc , char *argv[]) {
	char *file = argv[1];
	int fd;
	struct flock lock;

	printf("Opening %s\n", file);

	fd = open(file, O_RDONLY);
	printf("locking.\n");

	memset(&lock, 0, sizeof(lock));

	lock.l_type = F_WRLCK;

	fcntl(fd, F_SETLKW, &lock);

	printf("locked; hit Enter to unlock... ");

	getchar();

	printf("unlocking\n");

	lock.l_type = F_UNLCK;

	fcntl(fd, F_SETLKW, &lock);

	close(fd);

	return EXIT_SUCCESS;
}
