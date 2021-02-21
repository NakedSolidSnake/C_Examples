#include "zigbee.h"
#include <stdio.h>

#define RET_OK 1

typedef struct zigbee_ctx{
	uint8_t init;
}Zigbee_ctx;

static Zigbee_ctx zig_ctx = {
	.init = 0
};

static void zigbee_init(const void *context);


static void zigbee_init(const void *context)
{	
	if(!zig_ctx.init)
	{
		printf("Zigbee initialized\n");
		zig_ctx.init = 1;
	}
}
	

int8_t  zigbee_open (const void *context)
{
	zigbee_init(context);
	printf("Zigbee openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t zigbee_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("Zigbee write\n");
	/* Implement your code here */
}

int32_t zigbee_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("Zigbee read\n");
	/* Implement your code here */
}

int8_t  zigbee_ioctl(const void *context, uint8_t command, void *args)
{
	printf("Zigbee ioctl\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  zigbee_close(const void *context)
{
	printf("Zigbee close\n");
	/* Implement your code here */
	return RET_OK;
}
