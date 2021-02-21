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
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int server(int client_socket)
{
	int end_connection = 0;
	while(1)
	{
		int length;
		char *text;

		if ( read (client_socket, &length,  sizeof(length)) == 0)
			return 0;
		text = (char *)malloc(length);

		read(client_socket, text, length);
		printf("%s\n", text);

		if(strcmp(text, "quit") == 0)
			end_connection = 1;

		free(text);

		if(end_connection)
			return 1;


	}
}

int main(int argc , char *argv[]) {

	const char * const socket_name = argv[1];

	int socket_fd;
	struct sockaddr_un name;
	int client_sent_quit_message;

	socket_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
	if(socket_fd  == -1)
	{
		perror("Socket: error");
		exit(1);
	}

	name.sun_family = AF_LOCAL;
	strcpy(name.sun_path, socket_name);
	int bind_ret = bind(socket_fd, &name, SUN_LEN(&name));

	if(bind_ret  == -1)
	{
		perror("Bind: error");
		exit(1);
	}


	int listen_ret = listen(socket_fd, 5);
	if(listen_ret == -1)
	{
		perror("Listen: error");
		exit(1);
	}

	do{
		struct sockaddr_un client_name;
		socklen_t client_name_len = sizeof(client_name);

		int client_socket_fd;

		client_socket_fd = accept(socket_fd, &client_name, &client_name_len);

		if(client_socket_fd == -1)
		{
			perror("Accept: error");
			exit(1);
		}

		client_sent_quit_message = server(client_socket_fd);

		close(client_socket_fd);
	}while(!client_sent_quit_message);

	close(socket_fd);
	unlink(socket_name);

	return EXIT_SUCCESS;
}
