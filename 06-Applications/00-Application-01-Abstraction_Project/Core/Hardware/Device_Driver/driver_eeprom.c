/*
 * driver_eeprom.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <debugger.h>
#include <IFileDriver.h>

/*< defines >*******************************************************************************************/
typedef void (*EEPROMIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct eeprom_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}EEPROM_ctx;

/*< private functions >*********************************************************************************/
static void private_eeprom_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
EEPROMIoctl eeprom_ioctl_functions[] = {
		private_eeprom_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_eeprom_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static EEPROM_ctx _eeprom_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(eeprom_ioctl_functions)/sizeof(eeprom_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  eeprom_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  eeprom_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t eeprom_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t eeprom_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  eeprom_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _eeprom_ctx.ioctl_list_size){
		(*eeprom_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  eeprom_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
