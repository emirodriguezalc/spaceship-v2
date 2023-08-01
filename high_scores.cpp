#include <ncurses.h>
#include <fstream> // Include the header for file stream operations

void showHighScores()
{
    bool back_to_menu = false;

    while (!back_to_menu)
    {
        clear(); // Clear the console screen using ncurses
        std::ifstream inputFile("highest_scores.txt");
        if (!inputFile.is_open())
        {
            printw("Error opening the file. Make sure highest_scores.txt exists.");
            return; // Return without changing back_to_menu to indicate an error
        }
        printw("Highest scores:\n");
        std::string scoreStr;
        while (std::getline(inputFile, scoreStr))
        {
            printw("%s\n", scoreStr.c_str()); // Use printw to display the scores
        }

        inputFile.close(); // Close the file after reading

        printw("Press 'm' to go back to the menu.\n");
        refresh();

        int ch = getch();
        while (ch != 'm' && ch != 'M')
        {
            ch = getch();
        }

        if (ch == 'm' || ch == 'M')
        {
            back_to_menu = true; // Go back to the menu
        }
    }
}
