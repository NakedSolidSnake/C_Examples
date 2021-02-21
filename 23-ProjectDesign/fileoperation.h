#ifndef _FILE_OPERATION
#define _FILE_OPERATION

#include <stdint.h>
#include <stdbool.h>

typedef struct fileoperation{
	const char *device_name;
	bool isOpen;
	void *context;	
	int8_t  (*open) (const void *context);
	int32_t (*write)(const void *context,  const void *buffer_write, uint32_t size); 
	int32_t (*read) (const void *context,  void *buffer_read, uint32_t *size);
	int8_t  (*ioctl)(const void *context,  uint8_t command, void *args);
	int8_t  (*close)(const void *context);			
}fileoperation;

int8_t  device_open (const uint8_t *name);
int32_t device_write(uint8_t device_handle, const void *buffer_write, uint32_t size); 
int32_t device_read (uint8_t device_handle, void *buffer_read, uint32_t *size);
int8_t  device_ioctl(uint8_t device_handle, uint8_t command, void *args);
int8_t  device_close(uint8_t device_handle);

#endif

