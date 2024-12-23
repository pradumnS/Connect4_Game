/**
 * @file Board.hpp
 * @brief Header file defining the ConnectFourBoard class for the Connect4 game.
 *
 * This file contains the declaration of the ConnectFourBoard class, which implements
 * the BoardInterface to represent and manage the game board for Connect4. It provides 
 * methods for manipulating and displaying the board state, validating moves, and 
 * managing game-specific logic such as dropping discs into columns, rows, diagonals, 
 * and gaps.
 *
 * Key Features:
 * - Implements core board functionalities, including move validation, board reset, 
 *   and checking if the board or a column is full.
 * - Provides multiple strategies for placing discs on the board (e.g., columns, rows, 
 *   diagonals, and gaps).
 *
 * Design Considerations:
 * - Uses a 2D vector to model the board grid with predefined dimensions (6 rows x 7 columns).
 * - Adheres to the SOLID principles, ensuring scalability and maintainability.
 * - Protects against copy operations by deleting the copy constructor and assignment operator.
 *
 * Usage:
 * - The class can be instantiated to create a Connect4 board and is designed for extensibility,
 *   allowing integration with player and computer strategies.
 *
 * @author [Your Name]
 * @date December 2024
 */


#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "BoardInterface.hpp"

using std::vector;

// Define the ConnectFourBoard class
class ConnectFourBoard : public BoardInterface
{
public:
    // Constructor
    ConnectFourBoard(void);
    void reset(void); // Declaration

    bool makeMove(int col, char symbol);

    // Virtual destructor for derived classes
    virtual ~ConnectFourBoard(void) = default;

    // Member functions with const correctness checks if specifc column available
    bool isColumnAvailable( int column) const;
    // checks if specifc column full
    bool isColumnFull( int column) const;
    // checks if the entire board is full
    bool isFull(void) const override;

    // display current state of board
    void displayBoard(void) const override;

    const vector<vector<char>>& getGrid(void) const override;

    // It will add player or computer move into board
    bool dropDisc( int column, char disc) override;
    // Drop disc methods for different placements
    bool dropDiscToColumn( int row,  int col, char disc) override;
    bool dropDiscToRow( int row,  int col, char disc) override;
    bool dropDiscToDiagonal( int row,  int col, char disc) override;
    bool dropDiscToGap( int row,  int col, char disc) override;

private:
    
    // Private methods
     int getWidth(void) const;

    // Static member variables (Rule 8-11-1: Avoid static variables where possible)
    static vector<vector<char>> grid;

    // Constants (Rule 8-5-1: Use 'constexpr' for constants)
    static constexpr int ROWS = 6;      // could be used  int
    static constexpr int COLUMNS = 7;

    // Rule 12-8-1: Deleted copy constructor and assignment operator
    ConnectFourBoard(const ConnectFourBoard&) = delete;
    ConnectFourBoard& operator=(const ConnectFourBoard&) = delete;
};

#endif // BOARD_HPP
