/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *read_from_file(const char *filename, size_t length)
{
	char *buffer;
	int fd;

	ssize_t bytes_read;

	buffer = (char *) malloc(length);

	if(buffer == NULL)
	{
		return NULL;
	}

	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		free(buffer);
		return NULL;
	}

	bytes_read = read(fd, buffer, length);
	if(bytes_read <= 0)
	{
		free(buffer);
		close(fd);
		return NULL;
	}

	close(fd);
	return buffer;
}

int main(void) {
	char b[10];
	char *p = read_from_file("file.txt", 10);
	if(p == NULL)
		return EXIT_FAILURE;
	memcpy(b, p, 10);
	free(p);
	printf("%s\n", b);
	return EXIT_SUCCESS;
}
