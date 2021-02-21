/* include *******************************************************************************************/
#include "zigbee.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct zigbee_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Zigbee_ctx;

/* typedefs ******************************************************************************************/
typedef void (*ZigbeeIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void zigbee_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void zigbee_init(const void *context) __attribute__((constructor));
static void zigbee_init(const void *context);

/* ioctl functions entry *****************************************************************************/
ZigbeeIoctl zigbee_ioctl_functions[] = {
		zigbee_status
};

/* global variables **********************************************************************************/
static Zigbee_ctx zig_ctx = {
	.init = 0,
	.ioctl_list = sizeof(zigbee_ioctl_functions)/sizeof(zigbee_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void zigbee_status(void *args)
{
	printf("zigbee_status\n");
}

static void zigbee_init(const void *context)
{	
	ZigBee_Descriptor *zigbee_descriptor = context;
	if(!zig_ctx.init)
	{
		printf("Zigbee initialized\n");
		zig_ctx.init = 1;
	}

	(void)zigbee_descriptor;
}
	
/* public functions implementation *******************************************************************/
int8_t  zigbee_open (const void *context)
{
	ZigBee_Descriptor *zigbee_descriptor = context;
	zigbee_init(context);
	printf("Zigbee openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t zigbee_write(const void *context, const void *buffer_write, uint32_t size)
{
	ZigBee_Descriptor *zigbee_descriptor = context;
	printf("Zigbee write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t zigbee_read (const void *context, void *buffer_read, uint32_t *size)
{
	ZigBee_Descriptor *zigbee_descriptor = context;
	printf("Zigbee read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  zigbee_ioctl(const void *context, uint8_t command, void *args)
{
	ZigBee_Descriptor *zigbee_descriptor = context;
	printf("Zigbee ioctl\n");
	/* Implement your code here */
	if(command < zig_ctx.ioctl_list){
		(*zigbee_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  zigbee_close(const void *context)
{
	ZigBee_Descriptor *zigbee_descriptor = context;
	printf("Zigbee close\n");
	/* Implement your code here */
	return RET_OK;
}
