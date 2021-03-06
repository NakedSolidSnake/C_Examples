#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define TITLE "Loading an Image"
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_FLAGS    0
#define SCROLL_SPEED    300

int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        fprintf(stderr, "Error Initializing SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(TITLE,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          WINDOW_FLAGS);

    if(!window)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    //Creates a renderer using hardware graphics
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, render_flags);
    if(!render)
    {
        printf("Error creating renderer :%s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return EXIT_FAILURE;
    }

    //Load image into memory
    SDL_Surface *surface = IMG_Load("hello.png");
    if(!surface)
    {
        printf("Error creating surface: %s\n", SDL_GetError());
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //load image to graphics hardware's memory
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    if(!texture)
    {
        printf("Error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // struct to hold the position and size of the sprite
    SDL_Rect dest;

    // get the dimensions of texture
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    // position the sprite at the bottom center of the window
    // origin is the top left corner, positive y is down
    dest.x = (WINDOW_WIDTH - dest.w) / 2;

    // require float resolution for y position
    float y_pos = WINDOW_HEIGHT;

    while(dest.y >= -dest.h)
    {
        // clear window
        SDL_RenderClear(render);

        dest.y = (int)y_pos;

        //draw the image to the window
        SDL_RenderCopy(render, texture, NULL, &dest);
        SDL_RenderPresent(render);

        // update sprite position
        y_pos -= (float)SCROLL_SPEED / 60;

        SDL_Delay(1000/60);        

    }

    // free resources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}