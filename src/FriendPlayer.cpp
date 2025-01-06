#include "FriendPlayer.hpp"
#include <iostream>
#include <limits>

FriendPlayer::FriendPlayer(const std::string& name, char symbol)
    : Player(name, symbol) {}


void FriendPlayer::makeMove(ConnectFourBoard& board) {
    int column;
    bool validMove = false;

    if (board.isFull()) {
        std::cout << "The board is full! No moves can be made.\n";
        return; // Exit immediately
    }

    while (!validMove) {
        std::cout << name << " enter your move (1-7) : ";
        // std::cin >> column;

        if (!(std::cin >> column)) { // Check if input is NOT an integer
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";

            // Clear the error state and discard invalid input
            std::cin.clear();                 // Clear error flag
            std::cin.ignore(10000, '\n');     // Ignore up to 10,000 characters or until a newline
            continue;                         // Retry input
        }
        // Validate input range (1 to 7)
        if (column < 1 || column > 7) {
            std::cout << "Invalid input. Please enter a column number between 1 and 7.\n";
        }
        // Check if the selected column is available
        else if (!board.isColumnAvailable(column - 1)) { // Convert to 0-based index
            std::cout << "Column " << column << " is full. Please choose another column.\n";
        } 
        // Valid input and column is available
         else {
        // Drop disc and validate success
            if (!board.dropDisc(column - 1, symbol)) {
                std::cout << "Failed to drop disc. Please try again.\n";
                continue;
            }
        validMove = true; // Move was successful
        }
    }
     
    // Valid input and column is available
}


