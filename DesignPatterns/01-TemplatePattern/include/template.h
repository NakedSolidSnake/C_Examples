#ifndef __TEMPLATE_H
#define __TEMPLATE_H



typedef void (*function_t)(void *context);

typedef struct 
{
    function_t initialize;
    function_t start;
    function_t end;
}ITemplate;


typedef struct 
{
    ITemplate base;
}Concrete;

void concreteOpen(Concrete *context);
void run(void);

#endif