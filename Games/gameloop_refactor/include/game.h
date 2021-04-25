#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

typedef struct
{
    double x;
    double y;
} Point;

typedef struct 
{
    double width;
    double height;
} Dimension;

typedef struct 
{
    double vx;
    double vy;
} Speed;

typedef struct 
{
    Point point;
    Dimension dimension;
    Speed speed;
} Object;

typedef struct 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool is_running;
    int last_frame_time;
    Object paddle;
    Object ball;
} Game;

typedef struct 
{
    void (*setup)(Game *game);
    void (*input_process)(Game *game);
    void (*colision)(Game *game);
    void (*render)(Game *game);
} Game_Interface;


// bool Game_Initialize(Game *game, Game_Interface *game_interface);
// bool Game_Run(Game *game, Game_Interface *game_interface);

bool Game_Initialize(Game *game);
bool Game_Run(Game *game);


#endif /* GAME_H_ */
