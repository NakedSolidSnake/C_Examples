#include "bluetooth.h"

#include <stdio.h>

#define RET_OK 1

typedef struct bluetooth_ctx{
	uint8_t init;
}Bluetooth_ctx;

static Bluetooth_ctx blue_ctx = {
	.init = 0
};

static void bluetooth_init(const void *context);


static void bluetooth_init(const void *context)
{	
	if(!blue_ctx.init)
	{
		printf("Bluetooth initialized\n");
		blue_ctx.init = 1;
	}	
}



int8_t  bluetooth_open (const void *context)
{
	bluetooth_init(context);
	printf("Bluetooth openned\n");
	return RET_OK;
}

int32_t bluetooth_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("Bluetooth write\n");
}

int32_t bluetooth_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("Bluetooth read\n");
}

int8_t  bluetooth_ioctl(const void *context, uint8_t command, void *args)
{
	printf("Bluetooth ioctl\n");
	return RET_OK;
}

int8_t  bluetooth_close(const void *context)
{
	printf("Bluetooth close\n");
	return RET_OK;
}
