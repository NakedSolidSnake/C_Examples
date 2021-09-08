#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *render = NULL;

int main()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        window = SDL_CreateWindow("Chapter 1: Setting up SDL", 
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  640,
                                  480,
                                  SDL_WINDOW_SHOWN);

        if(window != NULL)
            render = SDL_CreateRenderer(window, -1, 0);
    }
    else
        return 1;

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

    SDL_RenderClear(render);

    SDL_RenderPresent(render);

    SDL_Delay(5000);

    SDL_Quit();

    return 0;
}