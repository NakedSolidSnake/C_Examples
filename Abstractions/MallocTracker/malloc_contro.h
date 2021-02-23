/*
 * malloc_contro.h
 *
 *  Created on: Mar 25, 2019
 *      Author: cssouza
 */

#ifndef MALLOC_CONTRO_H_
#define MALLOC_CONTRO_H_

void * malloc_register(size_t size);
int free_register(void *ptr);
int malloc_registered(void);

#endif /* MALLOC_CONTRO_H_ */
