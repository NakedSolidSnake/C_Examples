#ifndef GAME_H
#define GAME_H

#define N 3
#define SCREEN_WIDTH 640.0
#define SCREEN_HEIGHT 480.0
#define CELL_WIDTH (SCREEN_WIDTH / N)
#define CELL_HEIGHT (SCREEN_HEIGHT / N)


// #define EMPTY 0
// #define PLAYER_X 1
// #define PLAYER_O 2

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

// #define RUNNING_STATE 0
// #define PLAYER_X_WON_STATE 1
// #define PLAYER_O_WON_STATE 2
// #define TIE_STATE 3
// #define QUIT_STATE 4

typedef struct {
    int board[N * N];
    Players player;
    States state;
} game_t;

#endif /* GAME_H */
