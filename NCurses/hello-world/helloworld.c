#include <ncurses.h>

/*

sudo apt-get install libncurses5-dev

*/

int main()
{
    initscr();
    printw("Hello World !!!\n");
    refresh();
    getch();
    endwin();

    return 0;
}