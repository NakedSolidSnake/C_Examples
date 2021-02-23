/* include *******************************************************************************************/
#include "keyboard.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct keyboard_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Keyboard_ctx;

/* typedefs ******************************************************************************************/

typedef void (*KeyboardIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void keyboard_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void keyboard_init(const void *context) __attribute__((constructor));
static void keyboard_init(const void *context);

/* ioctl functions entry *****************************************************************************/
KeyboardIoctl keyboard_ioctl_functions[] = {
		keyboard_status
};

/* global variables **********************************************************************************/
static Keyboard_ctx key_ctx = {
	.init = 0,
	.ioctl_list = sizeof(keyboard_ioctl_functions)/sizeof(keyboard_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void keyboard_status(void *args)
{
	printf("keyboard_status\n");
}

static void keyboard_init(const void *context)
{	
	Keyboard_Descriptor  *keyboard_descriptor = context;
	if(!key_ctx.init)
	{
		printf("Keyboard initialized\n");
		key_ctx.init = 1;
	}	
}

/* public functions implementation *******************************************************************/
int8_t  keyboard_open (const void *context)
{
	Keyboard_Descriptor  *keyboard_descriptor = context;
	keyboard_init(context);
	printf("Keyboard openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t keyboard_write(const void *context, const void *buffer_write, uint32_t size)
{
	Keyboard_Descriptor  *keyboard_descriptor = context;
	printf("Keyboard write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t keyboard_read (const void *context, void *buffer_read, uint32_t *size)
{
	Keyboard_Descriptor  *keyboard_descriptor = context;
	printf("Keyboard read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  keyboard_ioctl(const void *context, uint8_t command, void *args)
{
	Keyboard_Descriptor  *keyboard_descriptor = context;
	printf("Keyboard ioctl\n");
	/* Implement your code here */
	if(command < key_ctx.ioctl_list){
		(*keyboard_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  keyboard_close(const void *context)
{
	Keyboard_Descriptor  *keyboard_descriptor = context;
	printf("Keyboard close\n");
	/* Implement your code here */
	return RET_OK;
}

