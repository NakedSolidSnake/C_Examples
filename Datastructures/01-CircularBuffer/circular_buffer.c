#include "circular_buffer.h"


struct circular_buffer {
  uint8_t *buffer;
  size_t head;
  size_t tail;
  size_t size;
};

Circular_Buffer_t * Circular_Buffer_Init(size_t size)
{
  Circular_Buffer_t *circular_buffer = NULL;
 // circular_buffer = (Circular_Buffer_t *)malloc()
}

int Circular_Buffer_Reset( Circular_Buffer_t *circular_buffer )
{
   int ret = -1;
   
   if(circular_buffer)
   {
     circular_buffer->head = 0;
     circular_buffer->tail = 0;
     ret = 0;     
   }
   return ret;
}

int Circular_Buffer_Put( Circular_Buffer_t *circular_buffer, uint8_t data )
{
  return 0;   
}

int Circular_Buffer_Get( Circular_Buffer_t *circular_buffer, uint8_t *data )
{
  int ret = 1;
  if(circular_buffer && data !Circular_Buffer_Empty(circular_buffer))
  {
    *data = circular_buffer->buffer[circular_buffer->tail];
    circular_buffer->tail = (circular_buffer->tail + 1) % circular_buffer->size;
    ret = 0;
  }
  return ret;
}

bool Circular_Buffer_Empty( Circular_Buffer_t *circular_buffer )
{
   return(circular_buffer->head == circular_buffer->tail);
}

bool Circular_Buffer_Full( Circular_Buffer_t *circular_buffer )
{
   return((circular_buffer->head + 1) % circular_buffer->size) == circular_buffer->tail;
}
