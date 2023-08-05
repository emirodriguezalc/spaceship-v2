#include <ncurses.h>
#include <fstream> // Include the header for file stream operations

WINDOW *gameWin = nullptr; // Declare the game window globally

void setUpGameDimensions()
{
  clear(); // Clear the screen after exiting gameLoop()
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
  if (gameWin)
  {
    delwin(gameWin);
  }

  gameWin = newwin(height, width, startY, startX);
  box(gameWin, 0, 0);
  wrefresh(gameWin);
}

void gameLoop()
{
  bool game_over = false;

  // Move the setUpGameDimensions() call here, outside of the loop
  setUpGameDimensions();

  while (!game_over)
  {
    // Clear the game window
    wclear(gameWin);
    int ch = getch();
    if (ch == 'q')
    {
      game_over = true;
      delwin(gameWin); // Delete the game window before exiting gameLoop()
      clear();         // Clear the screen after exiting gameLoop()
      refresh();       // Refresh the display using ncurses
    }
  }

  delwin(gameWin); // Delete the game window before exiting gameLoop()
  clear();         // Clear the screen after exiting gameLoop()
  refresh();       // Refresh the display using ncurses
}
