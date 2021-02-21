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
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *path = argv[1];

    int rval;

    rval = access(path, F_OK);
    if(rval == 0)
    	printf("%s exist\n", path);

    else{
    	if(errno == ENOENT)
    		printf("%s does not exist\n", path);
    	else if(errno == EACCES)
    		printf("%s is not accessible\n", path);

    	return EXIT_SUCCESS;
    }

    rval = access(path, R_OK);
    if(rval == 0)
    	printf("%s is readable\n", path);
    else
    	printf("%s is not readable (access denied)\n", path);

    rval = access (path, W_OK);
    if (rval == 0)
    	printf("%s is writable\n", path);
    else if (errno == EACCES)
    	printf("%s is not writable (access denied)\n", path);
    else if (errno == EROFS)
    	printf("%s is not writable (read-only filesystem)\n", path);

	return EXIT_SUCCESS;
}
