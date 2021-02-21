#ifndef _SERIAL_H
#define _SERIAL_H

#include <stdint.h>

int8_t  serial_open (const void *context);
int32_t serial_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t serial_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  serial_ioctl(const void *context, uint8_t command, void *args);
int8_t  serial_close(const void *context);

#endif
