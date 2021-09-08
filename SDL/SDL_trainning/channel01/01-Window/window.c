#include <SDL2/SDL.h>
#include <window.h>
#include <stdlib.h>

struct window_t
{
    const char *title;
    int width;
    int height;
    SDL_Window *sdl_window;
    SDL_Renderer *render;
    bool close;
};


window_t *window_constructor(const char *title, int width, int height)
{
    window_t *window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        window = malloc(sizeof (window_t));
        if(window != NULL)
        {
            window->title = title;
            window->width = width;        
            window->height = height;        
        }

        window->sdl_window = SDL_CreateWindow(window->title, 
                                              SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED,
                                              window->width,
                                              window->height,
                                              0);

        window->render = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);
    }

    return window;
}

void window_destructor(window_t *window)
{
    if(window)
    {
        if(window->sdl_window)
            SDL_DestroyWindow(window->sdl_window);
        free(window);
        window = NULL;
    }    
}
