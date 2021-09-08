#include <window.h>

int main()
{
    window_t *window = window_constructor("Game", 600, 480);
    window_destructor(window);
    return 0;
}