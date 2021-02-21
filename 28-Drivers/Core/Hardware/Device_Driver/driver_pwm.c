/*
 * driver_power.c
 *
 *  Created on: 17 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>
#include <debugger.h>

/*< defines >*******************************************************************************************/
typedef void (*PWMIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct pwm_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}PWM_ctx;

/*< private functions >*********************************************************************************/
static void private_pwm_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
PWMIoctl pwm_ioctl_functions[] = {
		private_pwm_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_pwm_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static PWM_ctx _pwm_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(pwm_ioctl_functions)/sizeof(pwm_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  pwm_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  pwm_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t pwm_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t pwm_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  pwm_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _pwm_ctx.ioctl_list_size){
		(*pwm_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  pwm_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
