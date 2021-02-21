/*
 * driver_timer.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>
#include <debugger.h>

/*< defines >*******************************************************************************************/
typedef void (*TIMERIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct timer_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}TIMER_ctx;

/*< private functions >*********************************************************************************/
static void private_timer_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
TIMERIoctl timer_ioctl_functions[] = {
		private_timer_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_timer_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static TIMER_ctx _timer_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(timer_ioctl_functions)/sizeof(timer_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  timer_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  timer_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t timer_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t timer_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  timer_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _timer_ctx.ioctl_list_size){
		(*timer_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  timer_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
