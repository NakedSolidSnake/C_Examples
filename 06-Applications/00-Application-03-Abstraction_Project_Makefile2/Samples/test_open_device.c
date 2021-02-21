/*
 * test_open_device.c
 *
 *  Created on: 07/02/2019
 *      Author: csouza
 */


#include "Samples.h"
#include "fileoperation.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void OpenDevice(void)
{
	int8_t fd = -1;
	int32_t size = 1;
	while(1)
	{
		const int8_t *b = (const int8_t *)"Hello World\n";
		int8_t c[1];

		fd =  device_open((const int8_t *)"Test");
		device_write(fd, b, (uint32_t)strlen((char *)b));
		device_read(fd, &c[0], size );
		device_ioctl(fd, 0, NULL);
		device_close(fd);
	}

}
