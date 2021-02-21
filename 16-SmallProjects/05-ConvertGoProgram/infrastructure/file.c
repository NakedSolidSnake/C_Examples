#include "file.h"
#include "handle_partials.h"

#define PATH    "../templates"

EndpointReply *File_getPageFromFile(const char *pathFile)
{
    EndpointReply *_data = NULL;

    _data = (char *)malloc(sizeof(EndpointReply));
    if (_data)
    {
        _data->partials.head = Partials_getHead(PATH, "head.html");
        _data->partials.menu = Partials_getMenu(PATH, "menu.html");
        _data->partials.page = Partials_getPage(PATH, pathFile);
        _data->partials.footer = Partials_getFooter(PATH, "footer.html");    
    }    
    return _data;
}

long File_getFileSize(FILE *file)
{    
    long size = -1;
    if(file)
    {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        rewind(file);
    }
    
    return size;
}

long File_getAllPartialsSize(EndpointReply *endpoint)
{
    long size = 0;
    if(endpoint->partials.head)
        size += endpoint->partials.head->size;
    
    if(endpoint->partials.menu)
        size += endpoint->partials.menu->size;
    
    if(endpoint->partials.page)
        size += endpoint->partials.page->size;

    if(endpoint->partials.footer)
        size += endpoint->partials.footer->size;

    return size;
}