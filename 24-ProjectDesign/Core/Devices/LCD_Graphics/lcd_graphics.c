/* include *******************************************************************************************/
#include "lcd_graphics.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct lcd_graphics_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Lcd_graphics_ctx;

/* typedefs ******************************************************************************************/

typedef void (*LcdGraphicsIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void lcd_graphics_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void lcd_graphics_init(const void *context) __attribute__((constructor));
static void lcd_graphics_init(const void *context);

/* ioctl functions entry ****************************************************************************/
LcdGraphicsIoctl lcd_graphics_ioctl_functions[] = {
		lcd_graphics_status
};

/* global variables **********************************************************************************/
static Lcd_graphics_ctx lcd_ctx = {
	.init = 0,
	.ioctl_list = sizeof(lcd_graphics_ioctl_functions)/sizeof(lcd_graphics_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void lcd_graphics_status(void *args)
{
	printf("lcd_graphics_status\n");
}

static void lcd_graphics_init(const void *context)
{	
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	if(!lcd_ctx.init)
	{
		printf("LCD Graphics initialized\n");
		lcd_ctx.init = 1;
	}	
}

/* public functions implementation *******************************************************************/
int8_t  lcd_graphics_open (const void *context)
{
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	lcd_graphics_init(context);
	printf("LCD Graphics openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd_graphics_write(const void *context, const void *buffer_write, uint32_t size)
{
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	printf("LCD Graphics write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd_graphics_read (const void *context, void *buffer_read, uint32_t *size)
{
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	printf("LCD Graphics read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  lcd_graphics_ioctl(const void *context, uint8_t command, void *args)
{
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	printf("LCD Graphics ioctl\n");
	/* Implement your code here */
	if(command < lcd_ctx.ioctl_list){
		(*lcd_graphics_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  lcd_graphics_close(const void *context)
{
	LcdGraphics_Descriptor  *lcd_graphics_descriptor = context;
	printf("LCD Graphics close\n");
	/* Implement your code here */
	return RET_OK;
}
