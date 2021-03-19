#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csp_client.h"

//apt-get install libcurl4-gnutls-dev

#define CSP_GET_ITEM_5  5
#define CSP_GET_ITEM_8  8

static void read_json(char *buffer, uint32_t *size);
static void read_json_item_5(char *buffer, uint32_t *size);
static void read_json_item_8(char *buffer, uint32_t *size);

int main(void)
{
    char buffer[1024] = {0};
    bool is_ok;
    csp_client_t client;
    if(csp_client_init(&client) == false)
    {
        fprintf(stderr, "Error CSP not init.\n");
        return EXIT_FAILURE;
    }

    csp_client_request_register(CSP_GET_ITEM_5, "https://jsonplaceholder.typicode.com/posts/5", read_json_item_5);
    csp_client_request_register(CSP_GET_ITEM_8, "https://jsonplaceholder.typicode.com/posts/8", read_json_item_8);

    csp_client_request_emit_by_id(&client, CSP_GET_ITEM_5, buffer);
    csp_client_request_emit_by_id(&client, CSP_GET_ITEM_8, buffer);


    is_ok = csp_client_request_emit(&client, "https://jsonplaceholder.typicode.com/posts/1", buffer, 0, read_json);
    if(is_ok)
    {
        printf("Received.\n");
    }

    csp_client_close(&client);   
    return 0;
}

static void read_json(char *buffer, uint32_t *size)
{
    printf("data: %s\n", buffer);
    printf("size: %d\n", *size);
}

static void read_json_item_5(char *buffer, uint32_t *size)
{
    printf("Get item 5\n");
    printf("data: %s\n", buffer);
    printf("size: %d\n", *size);
}

static void read_json_item_8(char *buffer, uint32_t *size)
{
    printf("Get item 8\n");
    printf("data: %s\n", buffer);
    printf("size: %d\n", *size);
}
