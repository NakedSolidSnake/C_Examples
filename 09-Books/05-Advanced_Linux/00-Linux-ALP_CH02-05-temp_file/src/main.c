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
#include <string.h>
#include <unistd.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char *buffer, size_t length)
{
	char temp_filename[] = "/tmp/temp_file.XXXXXX";

	int fd = mkstemp(temp_filename);

	unlink(temp_filename);

	write(fd, &length, sizeof(length));

	write(fd, buffer, length);

	return fd;
}


char *read_temp_file(temp_file_handle temp_file, size_t* length)
{
	char *buffer;

	int fd = temp_file;

	lseek (fd, 0, SEEK_SET);

	read(fd, length, sizeof(*length));

	buffer = (char *)malloc(*length);

	read (fd, buffer, *length);

	close(fd);

	return buffer;
}

#define MAX_BUFFER_READ 1024

int main(void) {

	temp_file_handle file_handle;

	char *message = "This is a message to temp file\n";
	char *p = NULL;
	char buffer_rd[MAX_BUFFER_READ];

	int msg_size = strlen(message);

	memset(buffer_rd, 0, sizeof(buffer_rd));

	file_handle = write_temp_file(message, msg_size);

	if(file_handle == -1)
	{
		return EXIT_FAILURE;
	}

	p = read_temp_file(file_handle, (size_t *)&msg_size);

	if(p == NULL)
		return EXIT_FAILURE;

	memcpy(buffer_rd, p, msg_size);

	printf("[%s]\n", buffer_rd);

	free(p);

	return EXIT_SUCCESS;
}
