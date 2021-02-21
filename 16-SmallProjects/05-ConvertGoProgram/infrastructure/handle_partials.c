#include "handle_partials.h"
#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_MAX  1024

Head *Partials_getHead(const char *path, const char *filename)
{
    char buffer[BUFFER_MAX] = {0};
    Head *head = NULL;

    snprintf(buffer, BUFFER_MAX, "%s/%s", path, filename);

    FILE *file = fopen(buffer, "r");
    if(!file)
        return NULL;

    head = (Head *)malloc(sizeof(Head));
    if(head)
    {
        head->size = File_getFileSize(file);
        head->content = (char *)malloc(head->size + 1);
        if(head->content)
        {
            fread(head->content, 1, head->size, file);
            head->content[head->size] = 0;
        }
        else 
        {
            free(head);
            head = NULL;
        }
    }
    fclose(file);
    return head;
}

Menu *Partials_getMenu(const char *path, const char *filename)
{
    char buffer[BUFFER_MAX] = {0};
    Menu *menu = NULL;

    snprintf(buffer, BUFFER_MAX, "%s/%s", path, filename);

    FILE *file = fopen(buffer, "r");
    if(!file)
        return NULL;

    menu = (Menu *)malloc(sizeof(Menu));
    if(menu)
    {
        menu->size = File_getFileSize(file);
        menu->content = (char *)malloc(menu->size + 1);
        if(menu->content)
        {
            fread(menu->content, 1, menu->size, file);
            menu->content[menu->size] = 0;
        }
        else 
        {
            free(menu);
            menu = NULL;
        }
    }
    fclose(file);
    return menu;
}

Page *Partials_getPage(const char *path, const char *filename)
{
    char buffer[BUFFER_MAX] = {0};
    Page *page = NULL;

    snprintf(buffer, BUFFER_MAX, "%s/%s", path, filename);

    FILE *file = fopen(buffer, "r");
    if(!file)
        return NULL;

    page = (Page *)malloc(sizeof(Page));
    if(page)
    {
        page->size = File_getFileSize(file);
        page->content = (char *)malloc(page->size + 1);
        if(page->content)
        {
            fread(page->content, 1, page->size, file);
            page->content[page->size] = 0;
        }
        else 
        {
            free(page);
            page = NULL;
        }
    }
    fclose(file);
    return page;
}

Footer *Partials_getFooter(const char *path, const char *filename)
{
    char buffer[BUFFER_MAX] = {0};
    Footer *footer = NULL;

    snprintf(buffer, BUFFER_MAX, "%s/%s", path, filename);

    FILE *file = fopen(buffer, "r");
    if(!file)
        return NULL;

    footer = (Footer *)malloc(sizeof(Footer));
    if(footer)
    {
        footer->size = File_getFileSize(file);
        footer->content = (char *)malloc(footer->size + 1);
        if(footer->content)
        {
            fread(footer->content, 1, footer->size, file);
            footer->content[footer->size] = 0;
        }
        else 
        {
            free(footer);
            footer = NULL;
        }
    }
    fclose(file);
    return footer;
}

void Partials_freeHead(Head *head)
{
    if(head)
    {
        if(head->content)
        {
            free(head->content);
        }

        free(head);
    }
}

void Partials_freeMenu(Menu *menu)
{
    if(menu)
    {
        if(menu->content)
        {
            free(menu->content);
        }

        free(menu);
    }
}

void Partials_freePage(Page *page)
{
    if(page)
    {
        if(page->content)
        {
            free(page->content);
        }

        free(page);
    }
}

void Partials_freeFooter(Footer *footer)
{
    if(footer)
    {
        if(footer->content)
        {
            free(footer->content);
        }

        free(footer);
    }
}