#include "window_effects.h"
#include <chrono>
#include <thread>

void displayStars(WINDOW *gameWin, bool &game_over)
{
  int maxY, maxX;
  getmaxyx(gameWin, maxY, maxX);

  std::vector<int> starPositions(maxY, -1); // Initialize all positions to -1 (not visible)

  while (!game_over)
  {
    // Clear the window
    werase(gameWin);

    // Update star positions
    for (int i = maxX; i > 0; --i)
    {
      if (starPositions[i] >= 0 && starPositions[i] < maxX)
      {
        mvwprintw(gameWin, i, starPositions[i], "."); // Draw the star at its position
      }

      // Move the star to the left
      starPositions[i]--;
      if (starPositions[i] <= 0)
      {
        if (rand() % 100 < 5)
        {
          starPositions[i] = maxX; // Generate a new star at the top of the screen
        }
      }
    }

    // Refresh the window to display changes
    box(gameWin, 0, 0);
    wrefresh(gameWin);

    // Sleep for a short time to control the movement speed
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}
