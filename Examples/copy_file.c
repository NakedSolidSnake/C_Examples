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
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int read_fd;
	int write_fd;

	struct stat stat_buf;
	off_t offset = 0;

	read_fd = open(argv[1], O_RDONLY);
	fstat(read_fd, &stat_buf);

	write_fd = open(argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);

	sendfile(write_fd, read_fd, & offset, stat_buf.st_size);

	close(read_fd);
	close(write_fd);


	return EXIT_SUCCESS;
}
