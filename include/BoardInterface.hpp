/**
 * @file DiscDropper.hpp
 * @brief Header file defining the BoardInterface class for the Connect4 game.
 *
 * This file declares the BoardInterface, which serves as an abstract base class 
 * for managing the Connect4 board operations. It enforces a standardized interface 
 * for derived classes, ensuring consistency and flexibility in handling different 
 * implementations of the board management system.
 *
 * Key Features:
 * - Declares pure virtual methods to enforce implementation of core board operations 
 *   in derived classes.
 * - Supports methods for dropping discs into specific columns, rows, diagonals, and gaps.
 * - Provides a method for displaying the board state and validating whether the board 
 *   is full.
 * - Ensures proper memory management and extensibility through a virtual destructor.
 *
 */


#ifndef DISCDROPPER_HPP
#define DISCDROPPER_HPP

#include <vector>

// Explicitly using std::vector
using std::vector;

// Abstract class BoardInterface
class BoardInterface
{
public:
    // Rule 8-4-1: Virtual destructor to ensure proper cleanup in derived classes
    // virtual ~BoardInterface(void) = default;

    // Pure virtual methods
    virtual bool isFull(void) const = 0;                     
    virtual void displayBoard(void) const = 0;               
    virtual const vector<vector<char>>& getGrid(void) const = 0;

    virtual bool dropDisc(int column, char disc) = 0;     // Fixed-width integers (MISRA Rule 8-1-1)
    virtual bool dropDiscToColumn( int row,  int col, char disc) = 0;
    virtual bool dropDiscToRow( int row,  int col, char disc) = 0;
    virtual bool dropDiscToDiagonal( int row,  int col, char disc) = 0;
    virtual bool dropDiscToGap( int row,  int col, char disc) = 0;
};

#endif // DISCDROPPER_HPP
