/*
 * driver_i2c.c
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>
#include <debugger.h>

/*< defines >*******************************************************************************************/
typedef void (*I2CIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct i2c_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}I2C_ctx;

/*< private functions >*********************************************************************************/
static void private_i2c_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
I2CIoctl i2c_ioctl_functions[] = {
		private_i2c_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_i2c_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static I2C_ctx _i2c_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(i2c_ioctl_functions)/sizeof(i2c_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  i2c_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  i2c_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t i2c_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t i2c_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  i2c_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _i2c_ctx.ioctl_list_size){
		(*i2c_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  i2c_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
