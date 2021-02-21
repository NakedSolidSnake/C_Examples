/*
 * driver_usb.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>
#include <debugger.h>

/*< defines >*******************************************************************************************/
typedef void (*USBIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct usb_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}USB_ctx;

/*< private functions >*********************************************************************************/
static void private_usb_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
USBIoctl usb_ioctl_functions[] = {
		private_usb_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_usb_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static USB_ctx _usb_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(usb_ioctl_functions)/sizeof(usb_ioctl_functions[0])
};

/*< public functions >**********************************************************************************/

int8_t  usb_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  usb_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t usb_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t usb_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  usb_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _usb_ctx.ioctl_list_size){
		(*usb_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  usb_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
