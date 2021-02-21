/*
 * POWER_Options.h
 *
 *  Created on: 17 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_DEVICE_OPTION_POWER_OPTIONS_H_
#define CORE_FRAMEWORK_DEVICE_OPTION_POWER_OPTIONS_H_

typedef enum POWER_Options{
	Power_Status,
	Power_Shutdown,
	Power_Reset,
	Power_Sleep,
	Power_DeepSleep,
	Power_Hibernate
 }POWER_Options;

#endif /* CORE_FRAMEWORK_DEVICE_OPTION_POWER_OPTIONS_H_ */
