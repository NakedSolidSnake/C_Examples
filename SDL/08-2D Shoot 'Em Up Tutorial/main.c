#include <structs.h>
#include <string.h>
#include <init.h>
#include <draw.h>
#include <input.h>

int main(int argc, char *argv[])
{
    App app;
    memset(&app, 0, sizeof(App));

    initSDL(&app);

    // atexit(cleanup);

    while(1)
    {
        prepareScene(&app);

        doInput();

        presentScene(&app);

        SDL_Delay(16);
    }

    return 0;
}
