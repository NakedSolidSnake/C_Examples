/*
 * socketoperation.c
 *
 *  Created on: 5 de mar de 2019
 *      Author: solid
 */

#include <socketoperation.h>

int8_t  socket_open (Domain domain, COMMType commtype, Protocol protocol)
{
	return -1;
}

int8_t socket_bind(int8_t socket_handle, const void *addr, uint32_t size)
{
	return -1;
}

int8_t socket_listen(int8_t socket_handle, int32_t backlog)
{
	return -1;
}

int8_t socket_accept(int8_t socket_handle, void * addr, uint32_t size)
{
	return -1;
}

int8_t socket_connect(int8_t socket_handle, void * addr, uint32_t size)
{
	return -1;
}

int32_t socket_send(int8_t socket_handle, const void *buf, int32_t len, int16_t flags)
{
	return -1;
}

int32_t socket_receive(int8_t socket_handle, void *buf, int32_t len, int16_t flags)
{
	return -1;
}

int8_t socket_close(uint8_t socket_handle)
{
	return -1;
}
