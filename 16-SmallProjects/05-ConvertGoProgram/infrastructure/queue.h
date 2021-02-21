#ifndef __QUEUE_H
#define __QUEUE_H

struct node
{
    struct node *next;
    int *client_socket;
};

typedef struct node node_t;

void enqueue(int *client_socket);
int *dequeue();

#endif

