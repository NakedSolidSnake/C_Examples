/*
 * driver_system.c
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*SYSTEMIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct system_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}SYSTEM_ctx;

/*< private functions >*********************************************************************************/
static void private_system_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
SYSTEMIoctl system_ioctl_functions[] = {
		private_system_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_system_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static SYSTEM_ctx _system_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(system_ioctl_functions)/sizeof(system_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  system_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  system_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t system_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t system_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  system_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _system_ctx.ioctl_list_size){
		(*system_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  system_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
