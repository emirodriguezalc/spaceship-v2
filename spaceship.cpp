#include "spaceship.h"
#include <chrono>
#include <thread>
void displaySpaceship(WINDOW *gameWin, bool &game_over)
{
  int maxY, maxX;
  getmaxyx(gameWin, maxY, maxX);

  while (!game_over)
  {
    // Draw the spaceship
    mvwprintw(gameWin, maxY / 2, maxX / 3, "==>");
    box(gameWin, 0, 0);

    // Refresh the window to display changes
    wrefresh(gameWin);

    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Control the update rate
  }
}
