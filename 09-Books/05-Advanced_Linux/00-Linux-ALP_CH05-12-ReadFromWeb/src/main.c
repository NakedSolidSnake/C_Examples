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
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

void get_home_page(int socket_fd)
{
	char buffer[10000];
	ssize_t numbers_characters_read;

	sprintf(buffer, "GET /\n");

	write(socket_fd, buffer, strlen(buffer));

	while(1)
	{
		numbers_characters_read  = read(socket_fd, buffer, sizeof(buffer));
		if(numbers_characters_read == 0)
			return ;

		fwrite(buffer, sizeof(char), numbers_characters_read, stdout);
	}
}

int main(int argc, char *argv[]) {
	int socket_fd;
	struct sockaddr_in name;
	struct hostent *hostinfo;

	socket_fd = socket(PF_INET, SOCK_STREAM, 0);

	name.sin_family = AF_INET;
	hostinfo = gethostbyname(argv[1]);

	if(hostinfo == NULL)
		return 1;
	else
		name.sin_addr = *((struct in_addr *) hostinfo->h_addr);

	name.sin_port = htons(80);

	if(connect(socket_fd, &name, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Connect");
		return 1;
	}

	get_home_page(socket_fd);
	return EXIT_SUCCESS;
}
