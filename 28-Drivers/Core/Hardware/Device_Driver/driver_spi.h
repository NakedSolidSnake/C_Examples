/*
 * driver_spi.h
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SPI_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SPI_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  spi_init (const void *descriptor);
int8_t  spi_open (const void *descriptor);
int32_t spi_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t spi_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  spi_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  spi_close(const void *descriptor);

const Driver spi_driver = {
		.init  = spi_init,
		.open  = spi_open,
		.write = spi_write,
		.read  = spi_read,
		.ioctl = spi_ioctl,
		.close = spi_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SPI_H_ */
