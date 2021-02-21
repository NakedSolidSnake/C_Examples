/*
 * driver_serial.c
 *
 *  Created on: 07/02/2019
 *      Author: csouza
 */


/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*SERIALIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct serial_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}SERIAL_ctx;

/*< private functions >*********************************************************************************/
static void private_serial_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
SERIALIoctl serial_ioctl_functions[] = {
		private_serial_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_serial_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static SERIAL_ctx _serial_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(serial_ioctl_functions)/sizeof(serial_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  serial_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  serial_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t serial_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t serial_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  serial_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _serial_ctx.ioctl_list_size){
		(*serial_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  serial_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
