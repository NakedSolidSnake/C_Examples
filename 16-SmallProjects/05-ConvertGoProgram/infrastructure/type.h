#ifndef TYPE_H_
#define TYPE_H_


#define NAME_LEN                     80
#define DESCRIPTION_LEN              120

typedef struct 
{
    char *content;
    long size;
} Head;

typedef struct 
{
    char *content;
    long size;
} Menu;

typedef struct 
{
    char *content;
    long size;
} Page;

typedef struct 
{
    char *content;
    long size;
} Footer;

typedef struct 
{
    Head *head;
    Menu *menu;
    Page *page;
    Footer *footer;
} Partials;

typedef struct 
{
    Partials partials;
} EndpointReply;

typedef struct 
{
    int id;
    char name[NAME_LEN];
    char description[DESCRIPTION_LEN];
    double price;
    int quantity;
} Product;

#endif /* TYPE_H_ */
