#ifndef CSP_CLIENT_H_
#define CSP_CLIENT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define CSP_CLIENT_LIST_SIZE    5
#define CSP_QUERY_SIZE          1024

typedef struct 
{
    void *context;
} csp_client_t;

typedef void (*request)(char *buffer, uint32_t *size);



bool csp_client_init(csp_client_t *object);
bool csp_client_request_register(uint8_t id, const char *query, request callback);
bool csp_client_request_emit_by_id(csp_client_t *object, uint8_t id, char *output);
bool csp_client_request_emit(csp_client_t *object, const char *query, char *output, uint32_t *size, request callback);
bool csp_client_close(csp_client_t *object);


#endif /* CSP_CLIENT_H_ */
