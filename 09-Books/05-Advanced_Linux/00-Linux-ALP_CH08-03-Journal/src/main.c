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
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char *journal_filename = "journal.log";

void write_journal_entry(char * entry)
{
	int fd = open(journal_filename, O_WRONLY | O_CREAT | O_APPEND, 0660);
	write(fd, entry, strlen(entry));
	write(fd, "\n", 1);
	fsync(fd);
	close(fd);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
