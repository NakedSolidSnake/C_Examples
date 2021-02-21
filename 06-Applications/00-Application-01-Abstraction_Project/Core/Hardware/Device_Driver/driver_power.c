/*
 * driver_power.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*POWERIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct power_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}POWER_ctx;

/*< private functions >*********************************************************************************/
static void private_power_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
POWERIoctl power_ioctl_functions[] = {
		private_power_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_power_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static POWER_ctx _power_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(power_ioctl_functions)/sizeof(power_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  power_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  power_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t power_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t power_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  power_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _power_ctx.ioctl_list_size){
		(*power_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  power_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
