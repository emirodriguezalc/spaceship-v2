#include <iostream>
#include <ncurses.h>
#include "menu.h"

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    menuLoop();

    endwin(); // End ncurses window before exiting
    return 0;
}