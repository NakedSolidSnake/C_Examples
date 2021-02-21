#include "serial.h"
#include <stdio.h>

#define RET_OK 1

typedef struct serial_ctx{
	uint8_t init;
}Serial_ctx;

static Serial_ctx ser_ctx = {
	.init = 0
};

static void serial_init(const void *context);


static void serial_init(const void *context)
{	
	if(!ser_ctx.init)
	{
		printf("Serial initialized\n");
		ser_ctx.init = 1;
	}	
}

int8_t  serial_open (const void *context)
{
	serial_init(context);
	printf("Serial openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t serial_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("Serial write\n");
	/* Implement your code here */
}

int32_t serial_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("Serial read\n");
	/* Implement your code here */
}

int8_t  serial_ioctl(const void *context, uint8_t command, void *args)
{
	printf("Serial ioctl\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  serial_close(const void *context)
{
	printf("Serial close\n");
	/* Implement your code here */
	return RET_OK;
}
