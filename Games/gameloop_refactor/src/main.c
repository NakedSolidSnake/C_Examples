#include <game.h>

int main(void)
{
    Game game;
    Game_Initialize(&game);
    Game_Run(&game);

    return 0;
}