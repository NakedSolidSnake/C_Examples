#include "csp_client.h"
#include <curl/curl.h>
#include <string.h>

#define CSP_MEMORY_SIZE (1024 * 8)

typedef struct 
{
   char response[CSP_MEMORY_SIZE];
   size_t size;
} csp_memory_t;

typedef struct 
{   
    uint8_t id;
    char path[CSP_PATH_SIZE];
    request callback;
} csp_client_data_t;

typedef struct 
{
    csp_client_data_t csp_data[CSP_CLIENT_LIST_SIZE];
    uint8_t amount;
} csp_client_list_t;

static const char *content_type[] = 
{
    "Content-Type: application/json"
};

static csp_client_list_t csp_list;

static size_t csp_got_data(char *data, size_t itemsize, size_t nitems, void *user_data);

static const char *csp_get_content_type(csp_content content);

bool csp_client_init(csp_client_t *object, csp_content content)
{
    memset(&csp_list, 0, sizeof(csp_list));

    if (curl_global_init(CURL_GLOBAL_ALL))
        return false;
    
    object->context = curl_easy_init();
    if(object->context)
    {
        object->content = csp_get_content_type(content);
        curl_easy_setopt(object->context, CURLOPT_WRITEFUNCTION, csp_got_data);
    }
    return object->context ? true : false;
}

bool csp_client_request_register(uint8_t id, const char *path, const char *data,  const char *method, request callback)
{
    bool is_ok = false;
    if(csp_list.amount < CSP_CLIENT_LIST_SIZE)
    {
        csp_list.csp_data[csp_list.amount].id = id;
        strncpy(csp_list.csp_data[csp_list.amount].path, path, CSP_PATH_SIZE);
        csp_list.csp_data[csp_list.amount].callback = callback;

        csp_list.amount++;

        is_ok = true;
    }

    return is_ok;
}

bool csp_client_request_emit_by_id(csp_client_t *object, uint8_t id, char *output)
{
    bool is_ok = false;
    for(int i = 0; i < csp_list.amount; i++)
    {
        if(id == csp_list.csp_data[i].id)
        {
            is_ok = csp_client_request_emit(object, csp_list.csp_data[i].path, output, 0, csp_list.csp_data[i].callback);
            break;
        }
    }

    return is_ok;
}

bool csp_client_request_emit(csp_client_t *object, const char *path, const char *data, const char *method, request callback)
{
    csp_memory_t memory = {0};
    struct curl_slist *headers = NULL;
    CURLcode result;
    
    headers = curl_slist_append(headers, object->content);
    curl_easy_setopt(object->context, CURLOPT_WRITEDATA, &memory);

    if(method)
    {
        if(strcmp(method, "POST") == 0)
        {
            curl_easy_setopt(object->context, CURLOPT_POSTFIELDS, data);
            curl_easy_setopt(object->context, CURLOPT_POSTFIELDSIZE, -1L);
        }

        else if(strcmp(method, "PUT") == 0)
        {
            curl_easy_setopt(object->context, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(object->context, CURLOPT_POSTFIELDS, data);            
        }

        else if(strcmp(method, "DELETE") == 0)
        {
            curl_easy_setopt(object->context, CURLOPT_CUSTOMREQUEST, "DELETE");
        }        
    }

    curl_easy_setopt(object->context, CURLOPT_URL, path);

    result = curl_easy_perform(object->context);

    if (callback && result == CURLE_OK) 
    {
        callback(memory.response, (uint32_t *)&memory.size);
    }
    curl_slist_free_all(headers);
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


static size_t csp_got_data(char *data, size_t itemsize, size_t nitems, void *user_data)
{
    size_t bytes = itemsize * nitems;

    csp_memory_t *mem = (csp_memory_t *)user_data;

    memcpy(&(mem->response[mem->size]), data, bytes);
    mem->size += bytes;
    mem->response[mem->size] = 0;
    return bytes;
}

static const char *csp_get_content_type(csp_content content)
{
    return content_type[content];
}