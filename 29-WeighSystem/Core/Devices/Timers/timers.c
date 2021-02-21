/* include *******************************************************************************************/
#include "timers.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct timer_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Timer_ctx;

/* typedefs ******************************************************************************************/

typedef void (*TimerIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void timer_status(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void serial_init(const void *context) __attribute__((constructor));
static void timer_init(const void *context);

/* ioctl functions entry *****************************************************************************/
TimerIoctl timer_ioctl_functions[] = {
		timer_status,
};

/* global variables **********************************************************************************/
static Timer_ctx timer_ctx = {
	.init = 0,
	.ioctl_list = sizeof(timer_ioctl_functions)/sizeof(timer_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void timer_status(void *args)
{
	printf("timer_status\n");
}

static void timer_init(const void *context)
{
	Timer_Descriptor *timer_descriptor = context;
	if(!timer_ctx.init)
	{
		printf("Timer initialized\n");
		timer_ctx.init = 1;
	}
}



/* public functions implementation *******************************************************************/
int8_t  timer_open (const void *context)
{
	Timer_Descriptor *timer_descriptor = context;
	timer_init(context);
	printf("Timer openned\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t timer_write(const void *context, const void *buffer_write, uint32_t size)
{
	Timer_Descriptor *timer_descriptor = context;
	printf("Timer write\n");
	/* Implement your code here */
	return RET_OK;
}

int32_t timer_read (const void *context, void *buffer_read, uint32_t *size)
{
	Timer_Descriptor *timer_descriptor = context;
	printf("Timer read\n");
	/* Implement your code here */
	return RET_OK;
}

int8_t  timer_ioctl(const void *context, uint8_t command, void *args)
{
	Timer_Descriptor *timer_descriptor = context;
	printf("Timer ioctl\n");
	/* Implement your code here */
	if(command < timer_ctx.ioctl_list){
		(*timer_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  timer_close(const void *context)
{
	Timer_Descriptor *timer_descriptor = (Timer_Descriptor *)context;
	printf("Timer close\n");
	/* Implement your code here */
	return RET_OK;
}
