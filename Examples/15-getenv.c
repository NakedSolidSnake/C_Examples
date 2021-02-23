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


//const char *export_server_name = "export SERVER_NAME=backup-server.elsewhere.net";

int main(void) {


//	system(export_server_name);

	char *server_name = getenv("SERVER_NAME");



	if(server_name == NULL)
	{
		server_name = "server.my-company.com";
	}

	printf("Accessing server %s\n", server_name);

	return EXIT_SUCCESS;
}
