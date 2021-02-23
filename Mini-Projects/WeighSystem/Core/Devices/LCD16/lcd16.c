/* include *******************************************************************************************/
#include "lcd16.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct lcd16_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Lcd16_ctx;

/* typedefs ******************************************************************************************/

typedef void (*Lcd16Ioctl)(void *parameter);

/* private functions *********************************************************************************/
static void lcd16_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void lcd16_init(const void *context) __attribute__((constructor));
static void lcd16_init(const void *context);

/* ioctl functions entry *****************************************************************************/
Lcd16Ioctl lcd16_ioctl_functions[] = {
		lcd16_status
};

/* global variables **********************************************************************************/
static Lcd16_ctx lcd_ctx = {
	.init = 0,
	.ioctl_list = sizeof(lcd16_ioctl_functions)/sizeof(lcd16_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void lcd16_status(void *args)
{
	printf("lcd16_status\n");
}

static void lcd16_init(const void *context)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	if(!lcd_ctx.init)
	{
		printf("LCD16 initialized\n");
		lcd_ctx.init = 1;
	}
}

/* public functions implementation *******************************************************************/
int8_t  lcd16_open (const void *context)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	lcd16_init(context);
	printf("LCD16 openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd16_write(const void *context, const void *buffer_write, uint32_t size)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	printf("LCD16 write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t lcd16_read (const void *context, void *buffer_read, uint32_t *size)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	printf("LCD16 read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  lcd16_ioctl(const void *context, uint8_t command, void *args)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	printf("LCD16 ioctl\n");
	/* Implement your code here */
	if(command < lcd_ctx.ioctl_list){
		(*lcd16_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  lcd16_close(const void *context)
{
	Lcd16_Descriptor *lcd16_descriptor = context;
	printf("LCD16 close\n");
	/* Implement your code here */
	return RET_OK;
}
