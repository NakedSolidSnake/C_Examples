#include <pqueue.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int queue_init(const char *queue_name)
{
  key_t key;
  int msg_id;

  key = ftok(queue_name, 65);
  msg_id = msgget(key, 0666 | IPC_CREAT);

  return msg_id;
}

int queue_send(int queue_id, const queue_t * q) 
{
  return msgsnd(queue_id, q, sizeof(queue_t), 0);
}

int queue_delete(int queue_id)
{
  return msgctl (queue_id, IPC_RMID, NULL);
}

ssize_t queue_recv(int queue_id, queue_t *q, long type)
{
  ssize_t len;
  len = msgrcv(queue_id, q, sizeof(queue_t), type, 0);
  return len;  
}

