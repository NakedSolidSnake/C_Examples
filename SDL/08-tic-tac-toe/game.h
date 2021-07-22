#ifndef GAME_H
#define GAME_H

#define N 3
#define SCREEN_WIDTH 640.0
#define SCREEN_HEIGHT 480.0
#define CELL_WIDTH (SCREEN_WIDTH / N)
#define CELL_HEIGHT (SCREEN_HEIGHT / N)

typedef enum 
{
    Empty,
    Player_X,
    Player_O
} Players;

typedef enum 
{
    Running = 0,
    Player_X_Won,
    Player_O_Won,
    Tie,
    Quit
} States;

typedef struct 
{
    int board[N * N];
    Players player;
    States state;
} Game;

#endif /* GAME_H */
