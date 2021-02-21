#include "fileoperation.h"

/*     include devices      */
#include "bluetooth.h"
#include "keyboard.h"
#include "lcd16.h"
#include "lcd_graphics.h"
#include "serial.h"
#include "zigbee.h"
#include "adc.h"

/*      init devices context      */

fileoperation devices[] = 
{
	{"Bluetooth"   , 0, NULL, .open = bluetooth_open   , .write = bluetooth_write   , .read = bluetooth_read   , .ioctl = bluetooth_ioctl   , .close = bluetooth_close}, 	
	{"Keyboard"    , 0, NULL, .open = keyboard_open    , .write = keyboard_write    , .read = keyboard_read    , .ioctl = keyboard_ioctl    , .close = keyboard_close},
	{"LCD16"       , 0, NULL, .open = lcd16_open       , .write = lcd16_write       , .read = lcd16_read       , .ioctl = lcd16_ioctl       , .close = lcd16_close},
	{"LCD_Graphics", 0, NULL, .open = lcd_graphics_open, .write = lcd_graphics_write, .read = lcd_graphics_read, .ioctl = lcd_graphics_ioctl, .close = lcd_graphics_close},
	{"Serial"      , 0, NULL, .open = serial_open      , .write = serial_write      , .read = serial_read      , .ioctl = serial_ioctl      , .close = serial_close},
	{"Zigbee"      , 0, NULL, .open = zigbee_open      , .write = zigbee_write      , .read = zigbee_read      , .ioctl = zigbee_ioctl      , .close = zigbee_close},
	{"ADC"         , 0, NULL, .open = adc_open         , .write = adc_write         , .read = adc_read         , .ioctl = adc_ioctl         , .close = adc_close},
};


uint8_t devices_amount = sizeof(devices) / sizeof(devices[0]);
fileoperation *pDevices = devices;
