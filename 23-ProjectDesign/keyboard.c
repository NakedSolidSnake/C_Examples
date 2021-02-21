#include "keyboard.h"
#include <stdio.h>

#define RET_OK 1

typedef struct keyboard_ctx{
	uint8_t init;
}Keyboard_ctx;

static Keyboard_ctx key_ctx = {
	.init = 0
};

static void keyboard_init(const void *context);


static void keyboard_init(const void *context)
{	
	if(!key_ctx.init)
	{
		printf("Keyboard initialized\n");
		key_ctx.init = 1;
	}	
}

int8_t  keyboard_open (const void *context)
{
	keyboard_init(context);
	printf("Keyboard openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t keyboard_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("Keyboard write\n");
	/* Implement your code here */
}

int32_t keyboard_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("Keyboard read\n");
	/* Implement your code here */
}

int8_t  keyboard_ioctl(const void *context, uint8_t command, void *args)
{
	printf("Keyboard ioctl\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  keyboard_close(const void *context)
{
	printf("Keyboard close\n");
	/* Implement your code here */
	return RET_OK;
}

