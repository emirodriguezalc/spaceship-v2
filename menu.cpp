#include <ncurses.h>
#include "high_scores.h"
#include "game_loop.h"

void displayMenu(int selectedItem)
{
    clear(); // Clear the console screen using ncurses

    printw("Menu Options:\n");
    printw(selectedItem == 1 ? "> 1. START NEW GAME\n" : "  1. START NEW GAME\n");
    printw(selectedItem == 2 ? "> 2. SHOW SCORES\n" : "  2. SHOW SCORES\n");
    printw(selectedItem == 3 ? "> 3. EXIT\n" : "  3. EXIT\n");

    refresh(); // Refresh the display using ncurses
}

int handleMenuInput(int selectedItem)
{
    int ch = getch();
    switch (ch)
    {
    case KEY_UP:
        return (selectedItem > 1) ? selectedItem - 1 : selectedItem;
    case KEY_DOWN:
        return (selectedItem < 3) ? selectedItem + 1 : selectedItem;
    case '\n': // Check for Enter key as '\n'
        switch (selectedItem)
        {
        case 1:
            // START NEW GAME
            gameLoop();
            break;
        case 2:
            // SHOW HIGHEST SCORES
            showHighScores(); // Call showHighScores() directly without using a separate flag variable
            break;
        case 3:
            printw("Exiting the program.\n");
            exit(0);
            return 1;
        }
        // in case I press the number directly
    default:
        return selectedItem;
    }
}

void menuLoop()
{
    int choice = 1;
    bool show_menu = true;

    while (show_menu)
    {
        displayMenu(choice);

        choice = handleMenuInput(choice);
    }
}
