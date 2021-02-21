#include "lcd_graphics.h"
#include <stdio.h>

#define RET_OK 1

typedef struct lcd_graphics_ctx{
	uint8_t init;
}Lcd_graphics_ctx;

static Lcd_graphics_ctx lcd_ctx = {
	.init = 0
};

static void lcd_graphics_init(const void *context);


static void lcd_graphics_init(const void *context)
{	
	if(!lcd_ctx.init)
	{
		printf("LCD Graphics initialized\n");
		lcd_ctx.init = 1;
	}	
}

int8_t  lcd_graphics_open (const void *context)
{
	lcd_graphics_init(context);
	printf("LCD Graphics openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd_graphics_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("LCD Graphics write\n");
	/* Implement your code here */
}

int32_t lcd_graphics_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("LCD Graphics read\n");
	/* Implement your code here */
}

int8_t  lcd_graphics_ioctl(const void *context, uint8_t command, void *args)
{
	printf("LCD Graphics ioctl\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  lcd_graphics_close(const void *context)
{
	printf("LCD Graphics close\n");
	/* Implement your code here */
	return RET_OK;
}
