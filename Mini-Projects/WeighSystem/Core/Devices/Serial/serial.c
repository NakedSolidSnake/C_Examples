/* include *******************************************************************************************/
#include "serial.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct serial_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Serial_ctx;

/* typedefs ******************************************************************************************/

typedef void (*SerialIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void serial_status(void *args);
static void serial_setBaudRate(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void serial_init(const void *context) __attribute__((constructor));
static void serial_init(const void *context);

/* ioctl functions entry *****************************************************************************/
SerialIoctl serial_ioctl_functions[] = {
		serial_status,
		serial_setBaudRate
};

/* global variables **********************************************************************************/
static Serial_ctx ser_ctx = {
	.init = 0,
	.ioctl_list = sizeof(serial_ioctl_functions)/sizeof(serial_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void serial_status(void *args)
{
	printf("serial_status\n");
}

static void serial_setBaudRate(void *args)
{
	printf("serial_setBaudRate\n");
}

static void serial_init(const void *context)
{
	Serial_Descriptor *serial_descriptor = context;
	if(!ser_ctx.init)
	{
		printf("Serial initialized\n");
		ser_ctx.init = 1;
	}
}

/* public functions implementation *******************************************************************/
int8_t  serial_open (const void *context)
{
	Serial_Descriptor *serial_descriptor = context;
	serial_init(context);
	printf("Serial openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t serial_write(const void *context, const void *buffer_write, uint32_t size)
{
	Serial_Descriptor *serial_descriptor = context;
	printf("Serial write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t serial_read (const void *context, void *buffer_read, uint32_t *size)
{
	Serial_Descriptor *serial_descriptor = context;
	printf("Serial read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  serial_ioctl(const void *context, uint8_t command, void *args)
{
	Serial_Descriptor *serial_descriptor = context;
	printf("Serial ioctl\n");
	/* Implement your code here */
	if(command < ser_ctx.ioctl_list){
		(*serial_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  serial_close(const void *context)
{
	Serial_Descriptor *serial_descriptor = context;
	printf("Serial close\n");
	/* Implement your code here */
	return RET_OK;
}
