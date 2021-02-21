/*
 * fileoperation.h
 *
 *  Created on: 7 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_FILEOPERATION_FILEOPERATION_H_
#define CORE_FRAMEWORK_FILEOPERATION_FILEOPERATION_H_

/**
 * @file This header is an interface to access all components in the system,
 * all device_driver must be created following the same signature
 */

#include <types.h>
#include <IDriver.h>

typedef struct fileoperation{
	const char *device_name;	/*!< Name of device */
	bool isOpen;				/*!< Device state  */
	const void *descriptor;		/*!< Device state  */
	const Driver *driver;
}fileoperation;


/**
 * @brief @brief This function allows initialize a device
 *
 * @param name[in]	Name about device located in BSP.c file
 * @return Get a device handle, -1 - Error
 */
int8_t  device_open (const int8_t *name);

/**
 * @brief This function allows to write data from a device
 *
 * @param device_handle
 * @param buffer_write
 * @param size Size of buffer_write
 * @return Amount of Bytes written
 */
int32_t device_write(uint8_t device_handle, const void *buffer_write, uint32_t size);

/**
 * @brief This function allows to read data from a device
 *
 * @param device_handle
 * @param buffer_read buffer to receive data
 * @param size[in]	size of buffer_read
 * @return Amount Bytes read
 */

int32_t device_read (uint8_t device_handle, void *buffer_read, uint32_t size);
/**
 * @brief This function allows to configure a device with options located at Device_Option folder
 *
 * @param device_handle
 * @param command	Command for device located on Device_Option folder
 * @param args		can be any data, for more informations look at device option on Device_Option folder
 * @return 0 - Success , -1 - Error
 */
int8_t  device_ioctl(uint8_t device_handle, uint8_t command, void *args);

/**
 * @brief This function allows to uninitialized the device
 * @param device_handle
 * @return 0 - Success , -1 - Error
 */
int8_t  device_close(uint8_t device_handle);

#endif /* CORE_FRAMEWORK_FILEOPERATION_FILEOPERATION_H_ */
