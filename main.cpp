#include <iostream>
#include <ncurses.h>
#include "menu.h"

int main()
{
  int choice = 1;

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  int show_menu = true;

  while (show_menu)
  {
    displayMenu(choice); // Just print the options with > or without depending if its selected or not

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
        show_menu = false;
        break;
      case 3:
        printw("Exiting the program.\n");
        endwin();
        return 0;
      }
    }
  }

  endwin();
  return 0;
}
