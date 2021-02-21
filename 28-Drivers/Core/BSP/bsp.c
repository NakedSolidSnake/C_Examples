/*
 * bsp.c
 *
 *  Created on: 7 de fev de 2019
 *      Author: solid
 */


/* include *******************************************************************************************/
#include "fileoperation.h"
#include <stdlib.h>

#include <driver_adc.h>
#include <driver_dma.h>
#include <driver_eeprom.h>
#include <driver_flash.h>
#include <driver_gpio.h>
#include <driver_i2c.h>
#include <driver_power.h>
#include <driver_pwm.h>
#include <driver_serial.h>
#include <driver_spi.h>
#include <driver_system.h>
#include <driver_timer.h>
#include <driver_usb.h>
#include <driver_watchdog.h>

/* defines *******************************************************************************************/

/* global variables **********************************************************************************/



fileoperation devices[] =
{
	{.device_name = "ADC"      , .isOpen = 0, .descriptor = NULL   , .driver  = &adc_driver     },
	{.device_name = "DMA"      , .isOpen = 0, .descriptor = NULL   , .driver  = &dma_driver     },
	{.device_name = "EEPROM"   , .isOpen = 0, .descriptor = NULL   , .driver  = &eeprom_driver  },
	{.device_name = "FLASH"    , .isOpen = 0, .descriptor = NULL   , .driver  = &flash_driver   },
	{.device_name = "GPIO"     , .isOpen = 0, .descriptor = NULL   , .driver  = &gpio_driver    },
	{.device_name = "I2C"      , .isOpen = 0, .descriptor = NULL   , .driver  = &i2c_driver     },
	{.device_name = "POWER"    , .isOpen = 0, .descriptor = NULL   , .driver  = &power_driver   },
	{.device_name = "PWM"      , .isOpen = 0, .descriptor = NULL   , .driver  = &pwm_driver     },
	{.device_name = "SERIAL"   , .isOpen = 0, .descriptor = NULL   , .driver  = &serial_driver  },
	{.device_name = "SPI"      , .isOpen = 0, .descriptor = NULL   , .driver  = &spi_driver     },
	{.device_name = "SYSTEM"   , .isOpen = 0, .descriptor = NULL   , .driver  = &system_driver  },
	{.device_name = "TIMER"    , .isOpen = 0, .descriptor = NULL   , .driver  = &timer_driver   },
	{.device_name = "USB"      , .isOpen = 0, .descriptor = NULL   , .driver  = &usb_driver     },
	{.device_name = "WATCHDOG" , .isOpen = 0, .descriptor = NULL   , .driver  = &watchdog_driver},
};


uint8_t devices_amount = sizeof(devices) / sizeof(devices[0]);
fileoperation *pDevices = devices;
