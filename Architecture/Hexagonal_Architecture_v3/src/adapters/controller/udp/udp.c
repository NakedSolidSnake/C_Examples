#include <udp.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

bool UDP_Server_Init(UDP_Server *server)
{
    bool status = false;
    struct sockaddr_in server_addr;

    do
    {
        if(!server || !server->buffer || !server->buffer_size)
            break;

        server->socket = socket(AF_INET, SOCK_DGRAM, 0);
        if(server->socket < 0)
            break;

        memset(&server_addr, 0, sizeof(server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(server->port);

        int yes = 1;
        if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, (void*)&yes, sizeof(yes)) < 0)
            break;

        if (bind(server->socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
            break;

        status = true;
        
    } while(false);

    return status;
}

bool UDP_Server_Run(UDP_Server *server, void *user_data)
{
    bool status = false;
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    size_t read_size;

    if(server->socket > 0)
    {
        read_size = recvfrom(server->socket, server->buffer, server->buffer_size, MSG_WAITALL,
                                    (struct sockaddr *)&client_addr, &len); 
        server->buffer[read_size] = 0;
        server->on_receive_message(server->buffer, read_size, user_data);
        memset(server->buffer, 0, server->buffer_size);
        status = true;
    }

    return status;
}