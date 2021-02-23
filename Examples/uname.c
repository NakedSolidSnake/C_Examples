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
#include <sys/utsname.h>

int main(void) {
	struct utsname u;
	uname(&u);

	printf("%s release %s (version %s) on %s\n", u.sysname, u.release, u.version, u.machine);

	return EXIT_SUCCESS;
}
