/*
 * ISocketDriver.h
 *
 *  Created on: 5 de mar de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_IDRIVER_ISOCKETDRIVER_H_
#define CORE_FRAMEWORK_IDRIVER_ISOCKETDRIVER_H_

#include "types.h"

typedef struct ISocketDriver{
	int8_t (*socket)(const void *context);
	int8_t (*bind)(const void *context);
	int8_t (*listen)(const void *context);
	int8_t (*accept)(const void *context);
	int8_t (*connect)(const void *context);
	int8_t (*ioctl)(const void *context, uint8_t command, void *args);
	uint32_t (*send)(const void *context, const void *send_bf, uint32_t size);
	uint32_t (*receive)(const void *context, void *receive_bf, uint32_t size);
	int8_t (*close)(const void *context);
}ISocketDriver;

#endif /* CORE_FRAMEWORK_IDRIVER_ISOCKETDRIVER_H_ */
