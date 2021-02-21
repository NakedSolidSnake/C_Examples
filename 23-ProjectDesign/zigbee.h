#ifndef _ZIGBEE_H
#define _ZIGBEE_H

#include <stdint.h>

int8_t  zigbee_open (const void *context);
int32_t zigbee_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t zigbee_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  zigbee_ioctl(const void *context, uint8_t command, void *args);
int8_t  zigbee_close(const void *context);

#endif
