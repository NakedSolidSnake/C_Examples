/*
 * driver_watchdog.c
 *
 *  Created on: 13 de fev de 2019
 *      Author: solid
 */


/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*WATCHDOGIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct watchdog_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}WATCHDOG_ctx;

/*< private functions >*********************************************************************************/
static void private_watchdog_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
WATCHDOGIoctl watchdog_ioctl_functions[] = {
		private_watchdog_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_watchdog_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static WATCHDOG_ctx _watchdog_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(watchdog_ioctl_functions)/sizeof(watchdog_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  watchdog_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  watchdog_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t watchdog_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t watchdog_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  watchdog_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _watchdog_ctx.ioctl_list_size){
		(*watchdog_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  watchdog_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
