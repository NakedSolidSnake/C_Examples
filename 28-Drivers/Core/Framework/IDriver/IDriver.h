/*
 * IDriver.h
 *
 *  Created on: 7 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_IDRIVER_IDRIVER_H_
#define CORE_FRAMEWORK_IDRIVER_IDRIVER_H_

#include "types.h"

typedef struct Driver{
	int8_t (*init)(const void *context);
	int8_t (*open)(const void *context);
	int32_t(*write)(const void *context, const void *wr_buffer, uint32_t size);
	int32_t(*read)(const void *context, void *rd_buffer, uint32_t size);
	int8_t (*ioctl)(const void *context, uint8_t command, void *args);
	int8_t (*close)(const void *context);
}Driver;

#endif /* CORE_FRAMEWORK_IDRIVER_IDRIVER_H_ */
