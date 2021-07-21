#include <stdio.h>
#include <SDL2/SDL.h>

#define RETURN_OK   0

int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) != RETURN_OK)
    {
        fprintf(stderr, "Error SDL initializing %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }


    fprintf(stdout, "Initialized\n");

    SDL_Quit();
}
