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
#include <unistd.h>

int main(void) {
	FILE *stream = popen("sort", "w");

	fprintf(stream, "This is a test\n");
	fprintf(stream, "Hello, world.\n");
	fprintf(stream, "My Dog has fleas\n");
	fprintf(stream, "This program is great.\n");
	fprintf(stream, "One fish, two fish.\n");

	return pclose(stream);
}
