/**
 * @file Computer.hpp
 * @brief Header file defining the Computer class for the Connect4 game.
 *
 * This file declares the Computer class, which represents the computer player 
 * in the Connect4 game. It is responsible for making intelligent moves based 
 * on the current state of the board and predefined strategies.
 *
 * Key Features:
 * - Implements logic for the computer to make moves on the board.
 * - Detects patterns such as three consecutive symbols to make strategic decisions.
 * - Uses explicit constructors to prevent implicit conversions
 *
 * Design Considerations:
 * - Integrates with the ConnectFourBoard class to validate and execute moves.
 * - Uses standard C++ containers (e.g., `std::pair`) for efficiency and readability.
 *
 * Usage:
 * - This class can be instantiated to represent the computer player, 
 *   leveraging its `makeMove` function to interact with the board.
 * - The `hasThreeConsecutive` method provides decision-making support for 
 *   identifying potential winning or blocking moves.
 *
 */


#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Board.hpp"
#include <utility> // For std::pair
#include <string>  // For std::string

// Explicitly declare std pair and string
using std::pair;
using std::string;

// Class declaration
class Computer
{
public:
    // Constructor explicit to prevent unintended conversions.
    explicit Computer(char computerSymbol);

    // Member functions
    bool makeMove(ConnectFourBoard& board); // Perform a move of computer

private:
    //Member variables
    char symbol; // Symbol used by the computer ('O')

    //Checks three consecutive same pattern
    pair<string, pair<int32_t, int32_t>> hasThreeConsecutive(
        const ConnectFourBoard& board, char checkSymbol) const;

    pair<string, pair<int32_t, int32_t>> findWinningMove(
        const ConnectFourBoard& board, char checkSymbol) const;

    //Deleted copy constructor and assignment operator
    Computer(const Computer&) = delete;
    Computer& operator=(const Computer&) = delete;
};

#endif // COMPUTER_HPP
