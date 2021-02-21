/*
 * driver_dma.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_DMA_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_DMA_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  dma_init (const void *descriptor);
int8_t  dma_open (const void *descriptor);
int32_t dma_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t dma_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  dma_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  dma_close(const void *descriptor);

const FileDriver dma_driver = {
		.init  = dma_init,
		.open  = dma_open,
		.write = dma_write,
		.read  = dma_read,
		.ioctl = dma_ioctl,
		.close = dma_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_DMA_H_ */
