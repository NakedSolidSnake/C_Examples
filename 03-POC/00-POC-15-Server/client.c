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
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <string.h>

int configuracaoCliente(void)
{
    /* Descriptor client */
    int client_socket_fd;

    /* Client struct */
    struct sockaddr_in serv_addr;

    /* struct lenght */
    socklen_t addrlen = sizeof(serv_addr);

    /* Socket TCP */
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket_fd < 0)
    {
        printf("Erro no socket\n");
        exit(1);
    }

    /* Clear struct */
    bzero((char *)&serv_addr, sizeof(serv_addr));

    /* Configure family */
    serv_addr.sin_family = AF_INET;

    /* Define IP  Local Host */
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Define port to connect */
    serv_addr.sin_port = htons( 6881 );

    /* Request connection server */
    if(connect (client_socket_fd, (struct sockaddr *)&serv_addr, addrlen) < 0)
    {
        printf("connect.\n");
        exit(1);
    }

    return client_socket_fd;

}

void Client(int client_fd)
{
    /* Buffer to send to server */
    char buffer_to_server[256];
    printf("Type a message to server: ");
    do{
        scanf("%s", buffer_to_server);
        fflush(stdin);

        /* write on the socket server */
        write(client_fd, buffer_to_server, sizeof(buffer_to_server));

    }while(strcmp(buffer_to_server, "quit") != 0);

    close(client_fd);
}

int main(int argc, char *argv[])
{
    /* Clear screen */
    system("clear");

    struct sockaddr_in serv_addr;

    socklen_t addrlen = sizeof(serv_addr);

    int client_desc = configuracaoCliente();

    Client(client_desc);

    exit(0);

}
