#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csp_client.h"

//apt-get install libcurl4-gnutls-dev

static void read_json(char *buffer, size_t *size);
static void read_json_item_5(char *buffer, size_t *size);
static void read_json_item_8(char *buffer, size_t *size);

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


    is_ok = csp_client_request_emit(&client, "https://jsonplaceholder.typicode.com/posts/1", buffer, 0, read_json);
    if(is_ok)
    {
        printf("Received.\n");
        printf("%s.\n", buffer);
    }

    csp_client_close(&client);   
    return 0;
}

static void read_json(char *buffer, size_t *size)
{
    printf("data: %s\n", buffer);
    printf("size: %d\n", *size);
}

static void read_json_item_5(char *buffer, size_t *size)
{
    printf("data: %s\n", buffer);
}

static void read_json_item_8(char *buffer, size_t *size)
{
    printf("data: %s\n", buffer);
}
