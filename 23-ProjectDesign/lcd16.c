#include "lcd16.h"
#include <stdio.h>

#define RET_OK 1

typedef struct lcd16_ctx{
	uint8_t init;
}Lcd16_ctx;

static Lcd16_ctx lcd_ctx = {
	.init = 0
};

static void lcd16_init(const void *context);


static void lcd16_init(const void *context)
{	
	if(!lcd_ctx.init)
	{
		printf("LCD16 initialized\n");
		lcd_ctx.init = 1;
	}	
}

int8_t  lcd16_open (const void *context)
{
	lcd16_init(context);
	printf("LCD16 openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd16_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("LCD16 write\n");
	/* Implement your code here */
}

int32_t lcd16_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("LCD16 read\n");
	/* Implement your code here */
}

int8_t  lcd16_ioctl(const void *context, uint8_t command, void *args)
{
	printf("LCD16 ioctl\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  lcd16_close(const void *context)
{
	printf("LCD16 close\n");
	/* Implement your code here */
	return RET_OK;
}
