/*
 * server.h
 *
 *  Created on: Apr 24, 2019
 *      Author: cssouza
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include <sys/types.h>


extern const char *program_name;

extern int verbose;

extern void *xmalloc(size_t size);

extern void *xrealloc(void *ptr, size_t size);

extern char *xstrdup(const char *s);

extern void system_error(const char *operation);

extern void error(const char *cause, const char *message);

extern char *get_self_executable_directory(void);

struct server_module{
	void *handle;

	const char *name;

	void (*generate_function)(int);
};

extern char *module_dir;

extern void module_close(struct server_module *module);

extern void server_run (struct in_addr local_address, uint16_t port);


#endif /* SERVER_H_ */
