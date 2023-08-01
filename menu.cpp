#include <ncurses.h>

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
    // in case i press the number directly
  default:
    return selectedItem;
  }
}