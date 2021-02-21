/* include *******************************************************************************************/
#include "outputs.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct outputs_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Outputs_ctx;

/* typedefs ******************************************************************************************/

typedef void (*OutputsIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void outputs_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void keyboard_init(const void *context) __attribute__((constructor));
static void outputs_init(const void *context);

/* ioctl functions entry *****************************************************************************/
OutputsIoctl outputs_ioctl_functions[] = {
		outputs_status
};

/* global variables **********************************************************************************/
static Outputs_ctx outputs_ctx = {
	.init = 0,
	.ioctl_list = sizeof(outputs_ioctl_functions)/sizeof(outputs_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void outputs_status(void *args)
{
	printf("outputs_status\n");
}

static void outputs_init(const void *context)
{	
	Outputs_Descriptor  *outputs_descriptor = context;
	if(!outputs_ctx.init)
	{
		printf("Outputs initialized\n");
		outputs_ctx.init = 1;
	}	
}

/* public functions implementation *******************************************************************/
int8_t  outputs_open (const void *context)
{
	Outputs_Descriptor  *outputs_descriptor = context;
	outputs_init(context);
	printf("Outputs openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t outputs_write(const void *context, const void *buffer_write, uint32_t size)
{
	Outputs_Descriptor  *outputs_descriptor = context;
	printf("Outputs write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t outputs_read (const void *context, void *buffer_read, uint32_t *size)
{
	Outputs_Descriptor  *outputs_descriptor = context;
	printf("Outputs read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  outputs_ioctl(const void *context, uint8_t command, void *args)
{
	Outputs_Descriptor  *outputs_descriptor = context;
	printf("Outputs ioctl\n");
	/* Implement your code here */
	if(command < outputs_ctx.ioctl_list){
		(*outputs_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  outputs_close(const void *context)
{
	Outputs_Descriptor  *outputs_descriptor = context;
	printf("Outputs close\n");
	/* Implement your code here */
	return RET_OK;
}

