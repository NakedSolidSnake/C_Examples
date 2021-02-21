#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE               10

/* class Queue*/

typedef struct Queue Queue;

struct Queue
{
   int buffer[QUEUE_SIZE];       //save the data
   int head;
   int size;
   int tail;
   int (*isFull) (Queue *const me);
   int (*isEmpty)(Queue *const me);
   int (*getSize)(Queue *const me);
   int (*insert) (Queue *const me, int data);
   int (*remove) (Queue *const me);
};

/* Constructors and Destructors */

int Queue_Init(Queue *const me,
                int (*isFullfunction)(Queue *const me),
                int (*isEmptyfunction)(Queue *const me),
                int (*getSizefunction)(Queue *const me),
                int (*insertfunction)(Queue *const me, int data),
                int (*removefunction)(Queue *const me));

int Queue_Cleanup(Queue *const me);

/* Operations */

int Queue_isFull(Queue *const me);
int Queue_isEmpty(Queue *const me);
int Queue_getSize(Queue *const me);
int Queue_insert(Queue *const me, int data);
int Queue_remove(Queue *const me);

Queue *Queue_Create(void);
int Queue_Destroy(Queue *const me);

#endif
