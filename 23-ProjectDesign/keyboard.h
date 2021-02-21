#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <stdint.h>

int8_t  keyboard_open (const void *context);
int32_t keyboard_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t keyboard_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  keyboard_ioctl(const void *context, uint8_t command, void *args);
int8_t  keyboard_close(const void *context);

#endif
