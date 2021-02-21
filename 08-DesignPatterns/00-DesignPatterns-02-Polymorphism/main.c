#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{

   int j, k, h, t;

   /* Test normal queue */
   Queue *queue;

   queue = Queue_Create();
   k = 1000;

   for(j = 0; j < QUEUE_SIZE; j++)
   {
      h = queue->head;
      queue->insert(queue, k);
      printf("inserting %d at position %d, size = %d\n", k--, h, queue->getSize(queue));
   }

   printf("Inserted %d elements\n", queue->getSize(queue));
   
   for(j = 0; j < QUEUE_SIZE; j++)
   {
      t = queue->tail;
      k = queue->remove(queue);
      printf("Removing %d at position %d, size = %d\n", k, t, queue->getSize(queue));  
   }

   printf("Last item removed = %d\n", k);
   printf("Current queue size %d\n", queue->getSize(queue));

   puts("Queue test");

   return 0;
}
