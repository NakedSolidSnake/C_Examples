#ifndef _CIRCULAR_BUFFER
#define _CIRCULAR_BUFFER

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
  uint8_t *buffer;
  size_t head;
  size_t tail;
  size_t size;
}Circular_Buffer_t;

Circular_Buffer_t * Circular_Buffer_Init(size_t size);

int Circular_Buffer_Reset( Circular_Buffer_t *circular_buffer );

int Circular_Buffer_Put( Circular_Buffer_t *circular_buffer, uint8_t data );

int Circular_Buffer_Get( Circular_Buffer_t *circular_buffer, uint8_t *data );

bool Circular_Buffer_Empty( Circular_Buffer_t *circular_buffer );

bool Circular_Buffer_Full( Circular_Buffer_t *circular_buffer );

 


#endif
