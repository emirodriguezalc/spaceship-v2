#include <iostream>
#include <ncurses.h>
#include "menu.h"
#include "high_scores.h"

int main()
{
    int choice = 1;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    int show_menu = true;

    while (show_menu)
    {
        displayMenu(choice);

        int newChoice = handleMenuInput(choice);
        if (newChoice != choice)
        {
            choice = newChoice;
        }
        else
        {
            switch (choice)
            {
            case 1:
                // START NEW GAME
                show_menu = false;
                break;
            case 2:
                // SHOW HIGHEST SCORES
                showHighScores(); // Call showHighScores() directly without using a separate flag variable
                break;
            case 3:
                printw("Exiting the program.\n");
                endwin();
                return 0;
            }
        }
    }

    endwin(); // End ncurses window before exiting
    return 0;
}
