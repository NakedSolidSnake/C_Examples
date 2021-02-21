/*
 * fileoperation.c
 *
 *  Created on: 07/02/2019
 *      Author: csouza
 */

#include "fileoperation.h"
#include <string.h>

#define CLOSED          0
#define OPENED 			1


extern uint8_t devices_amount;
extern fileoperation *pDevices;



int8_t  device_open (const int8_t *name)
{
	if(name == NULL)
		return -1;

	for(int8_t index = 0;  index < devices_amount; index++)
	{
		if(!strcmp((char *)name, pDevices[index].device_name))
		{
			if(pDevices[index].driver == NULL)
				return -1;

			if(pDevices[index].isOpen || pDevices[index].driver->open(pDevices[index].descriptor))
			{
				pDevices[index].isOpen = OPENED;
				return index;
			}
		}
	}
	return -1;
}

int32_t device_write(uint8_t device_handle, const void *buffer_write, uint32_t size)
{
	int32_t write_count = 0;
	if(device_handle >= 0)
	{
		write_count = pDevices[device_handle].driver->write(NULL, buffer_write, size);
	}
	return write_count;
}

int32_t device_read (uint8_t device_handle, void *buffer_read, uint32_t size)
{
	int32_t read_count = 0;
	if(device_handle >= 0)
	{
		read_count = pDevices[device_handle].driver->read(NULL, buffer_read, size);
	}
	return read_count;
}

int8_t  device_ioctl(uint8_t device_handle, uint8_t command, void *args)
{
	if(device_handle >= 0)
	{
		pDevices[device_handle].driver->ioctl(NULL, command, args);
		return 0;
	}
	return -1;
}

int8_t  device_close(uint8_t device_handle)
{
	if(device_handle >= 0)
	{
		if(pDevices[device_handle].isOpen)
		{
			pDevices[device_handle].driver->close(pDevices[device_handle].descriptor);
			pDevices[device_handle].isOpen = CLOSED;
			return 0;
		}
		return 1;
	}

	return -1;
}
