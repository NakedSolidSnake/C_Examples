#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>
#include "queue.h"

#define SERVERPORT      8989
#define BUFSIZE         4096
#define SOCKETERROR     (-1)
#define SERVER_BACKLOG  100
#define THREAD_POLL_SIZE    20

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr    SA;

pthread_t thread_pool[THREAD_POLL_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *handle_connection(void *args);
int check(int exp, const char *msg);

void *thread_function(void *args);

int main(int argc, char const *argv[])
{
    int server_socket, client_socket, addr_size;
    SA_IN server_addr, client_addr;

    for (int i = 0; i < THREAD_POLL_SIZE; i++)
    {
        pthread_create(&thread_pool[i], NULL, thread_function, NULL);
    }
    

    check((server_socket = socket(AF_INET, SOCK_STREAM, 0)), "Failed to create socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVERPORT);

    check(bind(server_socket, (SA*)&server_addr, sizeof(server_addr)), "Bind Failed!");

    check(listen(server_socket, SERVER_BACKLOG), "Listen Failed!");

    while(true)
    {
        printf("Waiting for connections...\n");

        addr_size = sizeof(SA_IN);
        
        check(client_socket = accept(server_socket, (SA*)&client_addr, (socklen_t *)&addr_size), "Accept Failed!");

        printf("Connected!\n");

        // pthread_t t;
        int *pclient = malloc(sizeof(int));
        *pclient = client_socket;
        pthread_mutex_lock(&mutex);
        enqueue(pclient);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        // pthread_create(&t, NULL, handle_connection, pclient);
    }
    return 0;
}

void *thread_function(void *args)
{
    while(true){
        int *pclient;
        pthread_mutex_lock(&mutex);
        if((pclient = dequeue()) == NULL){
            pthread_cond_wait(&cond, &mutex);
            pclient = dequeue();
        }        
        pthread_mutex_unlock(&mutex);
        if(pclient != NULL){
            handle_connection(pclient);
        }
    }
}

int check(int exp, const char *msg)
{
    if(exp == SOCKETERROR){
        perror(msg);
        exit(1);
    }

    return exp;
}

void *handle_connection(void *args)
{
    char buffer[BUFSIZE];
    size_t bytes_read;

    int client_socket = *(int *)args;

    free(args);

    int msgsize = 0;
    char actualpath[_PC_PATH_MAX + 1];

    while((bytes_read = read(client_socket, buffer+msgsize, sizeof(buffer) - msgsize - 1)) > 0){
        msgsize += bytes_read;
        if(msgsize > BUFSIZE - 1 || buffer[msgsize - 1] == '\n')
            break;
    }

    check(bytes_read, "recv error");
    buffer[msgsize - 1] = 0;

    printf("REQUEST: %s\n", buffer);
    fflush(stdout);

    if(realpath(buffer, actualpath) == NULL){
        printf("Error (bad path): %s\n", buffer);
        close(client_socket);
        return NULL;
    }

    FILE *fp = fopen(actualpath, "r");
    if(fp == NULL){
        printf("Error(open): %s\n", buffer);
        close(client_socket);
        return NULL;
    }

    while((bytes_read = fread(buffer, 1, BUFSIZE, fp)) > 0){
        printf("sending %zu bytes\n", bytes_read);
        write(client_socket, buffer, bytes_read);
    }

    close(client_socket);
    fclose(fp);
    printf("Closing connection\n");
    return NULL;
}