#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "json.h"

static bool processJsonSubItem(struct json_object *object, const IHandler *ihandler_list, size_t ihandler_size);
static void handlePrimitiveData(eType type, struct json_object *val, void **data);

bool processJson(void *buffer, const IHandler *ihandler_list, size_t ihandler_size)
{
    struct json_object *parsed_json;
    parsed_json = json_tokener_parse(buffer);
    return processJsonSubItem(parsed_json, ihandler_list, ihandler_size);
}

bool getJsonFromFile(const char *filename, void *buffer, size_t b_size)
{
    FILE *fd;
    bool ret = false;
    fd = fopen(filename,"r");
    if(fd != NULL)
    {
	    fread(buffer, 1, b_size, fd);
	    fclose(fd);
        ret = true;
    }

    return ret;
}

static bool processJsonSubItem(struct json_object *object, const IHandler *ihandler_list, size_t ihandler_size)
{
    json_object_object_foreach(object, key, val)
    {
        for (int i = 0; i < ihandler_size; i++)
        {
            if (strcmp(key, ihandler_list[i].token) == 0 && i < ihandler_size)
            {
                if (ihandler_list[i].type == eType_Object)
                {
                    struct json_object *inner_json;
                    json_object_object_get_ex(object, key, &inner_json);
                    processJsonSubItem(inner_json, ihandler_list[i].child, ihandler_list[i].size);
                }
                else
                    handlePrimitiveData(ihandler_list[i].type, val, ihandler_list[i].data);
                break;
            }
        }
    }

    return true;
}

static void handlePrimitiveData(eType type, struct json_object *val, void **data)
{
    switch (type)
    {
    case eType_Int:
    {
        int *_data = (int *)data;
        *_data = json_object_get_int(val);
    }
        break;

    case eType_Double:
    {
        double *_data = (double *)data;
        *_data = json_object_get_double(val);
    }
        break;
    
    case eType_String:
    {
        char **_data = (char **)data;
        *_data = (char *)json_object_get_string(val);
    }
        break;

    case eType_Boolean:
    {
        bool *_data = (bool *)data;
        *_data = json_object_get_boolean(val);
    }
        break;
    
    default:
        break;
    }
}