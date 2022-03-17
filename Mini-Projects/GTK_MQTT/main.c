#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    view_t view;
    view_args_t view_args;

    controller_t controller;
    controller_args_t controller_args;

    view_init(&view);
    controller_init(&controller);

    view_args.argc = argc;
    view_args.argv = argv;
    view_args.controller_base = &controller.base;
    view_open(&view, &view_args);

    controller_args.view = &view.base;    
    controller_open(&controller, &controller_args);

    controller_exec(&controller);

    view_close(&view);
    controller_close(&controller);

    return 0;
}
