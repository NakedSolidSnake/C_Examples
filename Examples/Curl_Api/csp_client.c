#include "csp_client.h"
#include <curl/curl.h>
#include <string.h>

typedef struct 
{   
    uint8_t id;
    char query[CSP_QUERY_SIZE];
    request callback;
} csp_client_data_t;

typedef struct 
{
    csp_client_data_t csp_data[CSP_CLIENT_LIST_SIZE];
    uint8_t amount;
} csp_client_list_t;

static csp_client_list_t csp_list;

static size_t csp_got_data(char *buffer, size_t itemsize, size_t nitems, void *data);

bool csp_client_init(csp_client_t *object)
{
    memset(&csp_list, 0, sizeof(csp_list));
    
    object->context = curl_easy_init();
    if(object->context)
    {
        curl_easy_setopt(object->context, CURLOPT_WRITEFUNCTION, csp_got_data);
    }
    return object->context ? true : false;
}

bool csp_client_request_register(uint8_t id, const char *query, request callback)
{
    csp_list.csp_data[csp_list.amount].id = id;
    strncpy(csp_list.csp_data[csp_list.amount].query, query, CSP_QUERY_SIZE);
    csp_list.csp_data[csp_list.amount].callback = callback;

    csp_list.amount++;
}

bool csp_client_request_emit_by_id(csp_client_t *object, uint8_t id, char *output)
{
    bool is_ok = false;
    for(int i = 0; i < csp_list.amount; i++)
    {
        if(id == csp_list.csp_data[i].id)
        {
            is_ok = csp_client_request_emit(object, csp_list.csp_data[i].query, output, 0, csp_list.csp_data[i].callback);
            break;
        }
    }

    return is_ok;
}

bool csp_client_request_emit(csp_client_t *object, const char *query, char *output, uint32_t *size, request callback)
{
    CURLcode result;
    if(callback)
        curl_easy_setopt(object->context, CURLOPT_WRITEDATA, callback);
    //defaul callback ?

    curl_easy_setopt(object->context, CURLOPT_URL, query);

    result = curl_easy_perform(object->context);

    return result == CURLE_OK ? true : false;
}

bool csp_client_close(csp_client_t *object)
{
    bool is_init = true;
    
    if(object->context)
    {
        curl_easy_cleanup((CURL *)object->context);
    }
    else 
    {
        is_init = false;
    }
    
    return is_init;
}


static size_t csp_got_data(char *buffer, size_t itemsize, size_t nitems, void *data)
{
    size_t bytes = itemsize * nitems;
    printf("bytes = %ld.\n", bytes);
    
    request callback = data;

    callback(buffer, (uint32_t *)&bytes);

    return bytes;
}
