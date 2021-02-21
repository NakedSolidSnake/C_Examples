#ifndef __PQUEUE_H
#define __PQUEUE_H

#include <sys/types.h>

#define QUEUE_BUFFER    1024

typedef struct queue_msg
{
  long id;
  char b[QUEUE_BUFFER];
}queue_t;

int queue_init(const char *queue_name);

int queue_send(int queue_id, const queue_t * q); 

int queue_delete(int queue_id);

ssize_t queue_recv(int queue_id, queue_t *q, long type);

#endif
