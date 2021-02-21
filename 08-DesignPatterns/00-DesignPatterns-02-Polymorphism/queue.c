#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int Queue_Init(Queue *const me,
                int (*isFullfunction)(Queue *const me),
                int (*isEmptyfunction)(Queue *const me),
                int (*getSizefunction)(Queue *const me),
                int (*insertfunction)(Queue *const me, int data),
                int (*removefunction)(Queue *const me))
{
   /* Initialize attributes */
   me->head = 0;
   me->size = 0;
   me->tail = 0;

   /* Initialize member function pointers */
   me->isFull = isFullfunction;
   me->isEmpty = isEmptyfunction;
   me->getSize = getSizefunction;
   me->insert = insertfunction;
   me->remove = removefunction;
   return 0;
}

int Queue_Cleanup(Queue *const me)
{
   return 0;   
}

/* Operations */

int Queue_isFull(Queue *const me)
{
   return (me->head + 1) % QUEUE_SIZE == me->tail;
}

int Queue_isEmpty(Queue *const me)
{
   return (me->head == me->tail);
}

int Queue_getSize(Queue *const me)
{
   return me->size;
}

int Queue_insert(Queue *const me, int data)
{
   if(!me->isFull(me))
   {
      me->buffer[me->head] = data;
      me->head = (me->head + 1) % QUEUE_SIZE;
      ++me->size;
      return 0;
   }
   return 1;
}

int Queue_remove(Queue *const me)
{
   int value = -9999;
   if(!me->isEmpty(me))
   {
      value = me->buffer[me->tail];
      me->tail = (me->tail + 1) % QUEUE_SIZE;
      --me->size;
   }

   return value;
}

Queue *Queue_Create(void)
{
   Queue *me = (Queue *) malloc(sizeof(Queue));
   if(me != NULL)
   {
      Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, Queue_insert, Queue_remove);
   }

   return me;
}
int Queue_Destroy(Queue *const me)
{
   if(me != NULL)
   {
      Queue_Cleanup(me);
   }
   free(me);
   return 0;
}

