/* include *******************************************************************************************/
#include "bluetooth.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct bluetooth_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Bluetooth_ctx;

/* typdedefs *****************************************************************************************/

typedef void (*BluetoothIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void bluetooth_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void bluetooth_init(const void *context) __attribute__((constructor));
static void bluetooth_init(const void *context);

/* ioctl functions entry ****************************************************************************/
BluetoothIoctl bluetooth_ioctl_functions[] = {
		bluetooth_status
};

/* global variables *********************************************************************************/
static Bluetooth_ctx blue_ctx = {
	.init = 0,
	.ioctl_list = sizeof(bluetooth_ioctl_functions)/sizeof(bluetooth_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void bluetooth_status(void *args)
{
	printf("bluetooth_status\n");
}

static void bluetooth_init(const void *context)
{	
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	if(!blue_ctx.init)
	{
		printf("Bluetooth initialized\n");
		blue_ctx.init = 1;
	}	
}



/* public functions implementation ******************************************************************/
int8_t  bluetooth_open (const void *context)
{
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	bluetooth_init(context);
	printf("Bluetooth openned\n");
	return RET_OK;
}

int32_t bluetooth_write(const void *context, const void *buffer_write, uint32_t size)
{
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	printf("Bluetooth write\n");
	return RET_OK;
}

int32_t bluetooth_read (const void *context, void *buffer_read, uint32_t *size)
{
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	printf("Bluetooth read\n");
	return RET_OK;
}

int8_t  bluetooth_ioctl(const void *context, uint8_t command, void *args)
{
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	printf("Bluetooth ioctl\n");
	if(command < blue_ctx.ioctl_list){
		(*bluetooth_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  bluetooth_close(const void *context)
{
	Bluetooth_Descriptor  *bluetooth_descriptor = context;
	printf("Bluetooth close\n");
	return RET_OK;
}
