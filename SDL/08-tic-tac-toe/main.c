#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "./game.h"
#include "./logic.h"
#include "./rendering.h"

typedef struct 
{
    void *window;
    void *renderer;
    const char *title;
    const int x_pos;    
    const int y_pos;
    const int width;
    const int height;
} Window;

bool Window_Init(Window *window);
bool Render_Init(Window *window);
bool Window_Draw(Window *window, const Game *game);

bool Window_Init(Window *window)
{
    bool status = true;

    do 
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
            break;
        }

        window->window = (void *)SDL_CreateWindow(window->title,
                                              window->x_pos,
                                              window->y_pos,
                                              window->width,
                                              window->height,                                          
                                              SDL_WINDOW_SHOWN);

        if (window->window == NULL)
        {
            fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
            break;
        }

        status = true;

    } while(false);

    return status;   
}

bool Render_Init(Window *window)
{
    bool status = true;

    window->renderer = SDL_CreateRenderer(window->window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    if (window->renderer == NULL) {
        SDL_DestroyWindow(window->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        status = false;
    }

    return status;
}

bool Window_Draw(Window *window, const Game *game)
{
    SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
    SDL_RenderClear(window->renderer);
    render_game(window->renderer, game);
    SDL_RenderPresent(window->renderer);

    return true;
}

int main(int argc, char *argv[])
{
    Window window = 
    {
        .title = "Procedural",
        .x_pos = SDL_WINDOWPOS_CENTERED,
        .y_pos = SDL_WINDOWPOS_CENTERED,
        .width = SCREEN_WIDTH,
        .height = SCREEN_HEIGHT
    };

    if(Window_Init(&window) == false)
        return EXIT_FAILURE;

    if(Render_Init(&window) == false)
        return EXIT_FAILURE;

    Game game = {
        .board = 
        { Empty, Empty, Empty,
          Empty, Empty, Empty,
          Empty, Empty, Empty
        },
        .player = Player_X,
        .state = Running
    };

    SDL_Event e;
    while (game.state != Quit) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                game.state = Quit;
                break;

            case SDL_MOUSEBUTTONDOWN:
                click_on_cell(&game,
                              e.button.y / CELL_HEIGHT,
                              e.button.x / CELL_WIDTH);
                break;

            default: {}
            }
        }

        Window_Draw(&window, (const Game *)&game);
    }

    SDL_DestroyWindow(window.window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
