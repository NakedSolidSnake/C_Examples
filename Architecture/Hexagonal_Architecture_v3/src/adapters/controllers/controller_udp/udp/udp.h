#ifndef UDP_H
#define UDP_H
#ifndef SERVER_UDP_H_
#define SERVER_UDP_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 */
typedef void (*Event)(const char *buffer, size_t buffer_size, void *data);

/**
 * @brief 
 * 
 */
typedef struct 
{
    int socket;
    int port;
    char *buffer;
    size_t buffer_size;
    Event on_receive_message;
} UDP_Server;


/**
 * @brief 
 * 
 * @param server 
 * @return true 
 * @return false 
 */
bool UDP_Server_Init(UDP_Server *server);

/**
 * @brief 
 * 
 * @param server 
 * @param user_data 
 * @return true 
 * @return false 
 */
bool UDP_Server_Run(UDP_Server *server, void *user_data);


#endif /* UDP_SERVER_H_ */


#endif /* UDP_H */
