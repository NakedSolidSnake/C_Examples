/*
 * driver_adc.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*AdcIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct adc_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}Adc_ctx;

/*< private functions >*********************************************************************************/
static void private_adc_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
AdcIoctl adc_ioctl_functions[] = {
		private_adc_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_adc_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static Adc_ctx ad_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(adc_ioctl_functions)/sizeof(adc_ioctl_functions[0])
};

/*< public functions >**********************************************************************************/

int8_t  adc_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  adc_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t adc_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t adc_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  adc_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < ad_ctx.ioctl_list_size){
		(*adc_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  adc_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
