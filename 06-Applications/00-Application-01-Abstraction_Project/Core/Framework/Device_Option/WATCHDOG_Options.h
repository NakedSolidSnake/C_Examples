/*
 * Watchdog_Options.h
 *
 *  Created on: 12 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_DEVICE_OPTION_WATCHDOG_OPTIONS_H_
#define CORE_FRAMEWORK_DEVICE_OPTION_WATCHDOG_OPTIONS_H_


typedef enum Watchdog_Options{
	Watchdog_Status,
	Watchdog_Disable,
	Watchdog_Enable,
	Watchdog_Set_Handler,
	Watchdog_KeepAlive
}Watchdog_Options;

#endif /* CORE_FRAMEWORK_DEVICE_OPTION_WATCHDOG_OPTIONS_H_ */
