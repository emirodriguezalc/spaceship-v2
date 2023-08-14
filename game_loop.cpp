#include <ncurses.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "window_effects.h"
#include "spaceship.h"

void setUpGameDimensions(WINDOW **gameWin) // Change the parameter to a pointer to the pointer
{
  clear();
  refresh();

  curs_set(0); // Hide the cursor

  int height, width;
  int margin = 4;
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
  wrefresh(*gameWin);                               // Dereference the pointer to refresh the window
}

void gameLoop()
{
  bool game_over = false;
  WINDOW *gameWin_stars = nullptr;
  WINDOW *gameWin_spaceship = nullptr;

  // Set up the main game window
  setUpGameDimensions(&gameWin_stars);     // Pass a pointer to the pointer
  setUpGameDimensions(&gameWin_spaceship); // Pass a pointer to the pointer

  // Run the displayStars and displaySpaceship functions in separate threads
  std::thread starsThread(displayStars, gameWin_stars, std::ref(game_over));
  std::thread spaceshipThread(displaySpaceship, gameWin_spaceship, std::ref(game_over));

  // Wait for both threads to finish
  starsThread.join();
  spaceshipThread.join();

  // Cleanup and exit
  delwin(gameWin_stars);
  delwin(gameWin_spaceship);
  endwin(); // Close the ncurses environment
}
