#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define TITLE       "Hello, SDL"

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_FLAGS    0
#define WINDOW_DELAY_5S 5000

int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != EXIT_SUCCESS)
    {
        fprintf(stderr, "Error Initializing SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(TITLE, 
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          WINDOW_FLAGS);

    if(!window)
    {
        fprintf(stderr, "Error Creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Delay(WINDOW_DELAY_5S);

    SDL_DestroyWindow(window);
    SDL_Quit();

}
