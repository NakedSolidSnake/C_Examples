/*
 * driver_spi.c
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>
#include <debugger.h>

/*< defines >*******************************************************************************************/
typedef void (*SPIIoctl)(void *parameter);

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/
typedef struct spi_ctx{
	uint8_t init;
	uint8_t ioctl_list_size;
}SPI_ctx;

/*< private functions >*********************************************************************************/
static void private_spi_getStatus(void *args);

/*< ioctl functions entry >*****************************************************************************/
SPIIoctl spi_ioctl_functions[] = {
		private_spi_getStatus
};

/*< private functions implementation >******************************************************************/
static void private_spi_getStatus(void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
}

/*< Context variables >*********************************************************************************/
static SPI_ctx _spi_ctx = {
	.init = STATUS_UNINITIALIZED,
	.ioctl_list_size = sizeof(spi_ioctl_functions)/sizeof(spi_ioctl_functions[0])
};


/*< public functions >**********************************************************************************/

int8_t  spi_init (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  spi_open (const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t spi_write(const void *descriptor, const void *buffer_write, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int32_t spi_read (const void *descriptor, void *buffer_read, uint32_t size)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  spi_ioctl(const void *descriptor, uint8_t command, void *args)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	if(command < _spi_ctx.ioctl_list_size){
		(*spi_ioctl_functions[command])(args);
		return ERROR_RET_OK;
	}
	return ERROR_NOT_IMPLEMENTED;
}

int8_t  spi_close(const void *descriptor)
{
	DEBUG_LOG("[%s] [%s] [%d]\n", __FILE__, __func__, __LINE__);
	return ERROR_NOT_IMPLEMENTED;
}
