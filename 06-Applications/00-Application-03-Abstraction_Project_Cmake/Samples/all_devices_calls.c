/*
 * all_devices_calls.c
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */


#include "Samples.h"
#include "fileoperation.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern fileoperation *pDevices;
extern uint8_t devices_amount;

void AllDeviceCalls(void)
{
	for(int i = 0; i < devices_amount; i++)
	{
		printf("pDevices[%d].device_name = %s\n", i, pDevices[i].device_name);
		pDevices[i].driver->init(NULL);
		pDevices[i].driver->open(NULL);
		pDevices[i].driver->write(NULL, NULL, 0);
		pDevices[i].driver->read(NULL, NULL, 0);
		pDevices[i].driver->ioctl(NULL, 0, NULL);
		pDevices[i].driver->close(NULL);
		printf("--------------------------------------------------------------\n");
	}
}
