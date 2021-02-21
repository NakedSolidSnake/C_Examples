#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileoperation.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//const uint8_t *dev_name = "Bluetooth";
//const uint8_t *dev_name = "Keyboard";
//const uint8_t *dev_name = "LCD16";
//const uint8_t *dev_name = "Serial";
//const uint8_t *dev_name = "Zigbee";
const uint8_t *dev_name = "ADC";

int main(int argc, char *argv[]) {
	
	/*uint8_t handle = device_open(dev_name);
	device_close(handle);	
	handle = device_open(dev_name);
	device_close(handle);
	handle = device_open(dev_name);
	device_close(handle);
	handle = device_open(dev_name);
	device_close(handle);*/
	
	uint8_t handle = device_open(dev_name);	
	device_close(handle);
	handle = device_open(dev_name);	
	device_close(handle);
	handle = device_open(dev_name);	
	device_close(handle);
	handle = device_open(dev_name);		
	device_write(handle, NULL, 0);
	device_read(handle, NULL, 0);
	device_ioctl(handle, 0, NULL);
	device_close(handle);
	
	return 0;
}
