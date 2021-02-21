/*
 * socketoperation.h
 *
 *  Created on: 5 de mar de 2019
 *      Author: solid
 */

#ifndef CORE_FRAMEWORK_FILEOPERATION_SOCKETOPERATION_H_
#define CORE_FRAMEWORK_FILEOPERATION_SOCKETOPERATION_H_

#include <types.h>
#include <ISocketDriver.h>

//typedef enum Domain{
//	BLUETOOTH_CLASSIC,
//	BLUETOOTH_BLE,
//	WIFI
//}Domain;
//
//typedef enum COMMType{
//
//}COMMType;
//
//typedef enum Protocol{
//
//}Protocol;
//
//typedef struct socketoperation{
//	Domain domain;				/*!< Domain*/
//	bool isOpen;				/*!< Device state  */
//	const void *descriptor;		/*!< Device state  */
//	const ISocketDriver *socketdriver;
//}socketoperation;
//
///**
// *
// * @param domain
// * @param commtype
// * @param protocol
// * @return
// */
//int8_t  socket_open (Domain domain, COMMType commtype, Protocol protocol);
//
///**
// *
// * @param socket_handle
// * @param addr
// * @param size
// * @return
// */
//int8_t socket_bind(int8_t socket_handle, const void *addr, uint32_t size);
//
///**
// *
// * @param socket_handle
// * @param backlog
// * @return
// */
//int8_t socket_listen(int8_t socket_handle, int32_t backlog);
//
///**
// *
// * @param socket_handle
// * @param addr
// * @param size
// * @return
// */
//int8_t socket_accept(int8_t socket_handle, void * addr, uint32_t size);
//
///**
// *
// * @param socket_handle
// * @param addr
// * @param size
// * @return
// */
//int8_t socket_connect(int8_t socket_handle, void * addr, uint32_t size);
//
///**
// *
// * @param socket_handle
// * @param buf
// * @param len
// * @param flags
// * @return
// */
//int32_t socket_send(int8_t socket_handle, const void *buf, int32_t len, int16_t flags);
//
///**
// *
// * @param socket_handle
// * @param buf
// * @param len
// * @param flags
// * @return
// */
//int32_t socket_receive(int8_t socket_handle, void *buf, int32_t len, int16_t flags);
//
///**
// *
// * @param socket_handle
// * @return
// */
//int8_t socket_close(uint8_t socket_handle);

#endif /* CORE_FRAMEWORK_FILEOPERATION_SOCKETOPERATION_H_ */
