/*********************************
Autor: Fernando Krein Pinheiro
Data: 04/07/2012
Linguagem: C
========= IMPORTANTE ===========
O código esta livre para usar,
citar e compartilhar desde que
mantida sua fonte e seu autor.
Obrigado.
*********************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <pthread.h>


void *servidor(void * args)
{
    /* Buffer to receive data */
    char buffer_data_recv[256];

    /* get args content */
    int sock_in = *(int *)args;

    printf("Waiting for messages...\n");

    while(1)
    {
        read(sock_in, buffer_data_recv, sizeof(buffer_data_recv));

        if(strcmp(buffer_data_recv, "quit") != 0)
        {
            printf("%s\n", buffer_data_recv);
        }
        else
        {
            /* Finish socket */
            close(sock_in);
            pthread_exit((void *)0);
        }

    }
}


int config_server(void)
{
    /* descriptor */
    int sock_fd;

    struct sockaddr_in server_addr;

    /* Create Socket as TCP */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 

    if(sock_fd < 0)
    {
        printf("socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(6881);

    if(bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("bind.\n");
        exit(1);
    }

    if(listen(sock_fd, 5) < 0)
    {
        printf("socket.\n");
        exit(1);
    }
            
    return sock_fd;        
}

int main(int argc, char *argv[])
{
    system("clear");

    struct sockaddr_in server_addr;

    int sock_fd = config_server();

    while(1)
    {
        int client_fd ;
        struct sockaddr_in client_addr;
        unsigned int client_len = (sizeof(client_addr));

        pthread_t thread;

        bzero((char *) &client_addr, sizeof (client_addr));

        printf("Waiting connection...\n");
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);

        if(client_fd < 0)
        {
            printf("accept.\n");
            exit(1);
        }

        /* Start thread */
        if(pthread_create(&thread, NULL, servidor, &client_fd) != 0)
        {
            printf("pthread_create.\n");
            exit(1);
        }

        pthread_detach(thread);
    }

    printf("Server.\n");
    return 0;
}
