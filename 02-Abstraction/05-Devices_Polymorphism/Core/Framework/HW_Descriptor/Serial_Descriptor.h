/*
 * Serial_Descriptor.h
 *
 *  Created on: 7 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_HW_DESCRIPTOR_SERIAL_DESCRIPTOR_H_
#define CORE_HARDWARE_HW_DESCRIPTOR_SERIAL_DESCRIPTOR_H_

#include <types.h>

typedef struct Serial_Descriptor{
	uint8_t id;
	const uint8_t *serial_name;
}Serial_Descriptor;

#endif /* CORE_HARDWARE_HW_DESCRIPTOR_SERIAL_DESCRIPTOR_H_ */
