#include <ncurses.h>
#include <fstream>
#include <thread>
#include "window_effects.h"

void setUpGameDimensions(WINDOW **gameWin) // Change the parameter to a pointer to the pointer
{
  clear();
  refresh();

  curs_set(0); // Hide the cursor

  int height, width;
  int margin = 2;
  getmaxyx(stdscr, height, width); // Get terminal dimensions

  width = height * 3;
  int setHeight = height - margin;
  int setWidth = width - margin;

  // Center the window in the terminal
  int startY = (LINES - height) / 2;
  int startX = (COLS - width) / 2;

  // Delete the previous gameWin if it exists
  if (*gameWin) // Dereference the pointer to check if it's not nullptr
  {
    delwin(*gameWin); // Dereference the pointer to delete the window
  }

  *gameWin = newwin(height, width, startY, startX); // Dereference the pointer to set the window
  wrefresh(*gameWin); // Dereference the pointer to refresh the window
}

void gameLoop()
{
  bool game_over = false;
  WINDOW *gameWin_displayStars = nullptr;
  WINDOW *gameWin_spaceship = nullptr;

  // Set up the window for the stars
  setUpGameDimensions(&gameWin_displayStars); // Pass a pointer to the pointer

  // Set up the window for the spaceship
  displayStars(gameWin_displayStars, game_over);

  while (!game_over)
  {
    // Clear the stars window
    wclear(gameWin_displayStars);

    int ch = getch();
    if (ch == 'q') // Exit
    {
      game_over = true;
      delwin(gameWin_displayStars);
      clear();
      refresh();
    }
  }

  delwin(gameWin_displayStars);
  clear();
  refresh();
}
