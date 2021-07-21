#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    const int width = 800;
    const int height = 600;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    SDL_Delay(5000);


    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
