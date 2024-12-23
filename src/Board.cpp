#include "Board.hpp"
#include <iostream>
#include <vector>

// Initialize static variables
std::vector<std::vector<char>> ConnectFourBoard::grid(ROWS, std::vector<char>(COLUMNS, '.'));

ConnectFourBoard::ConnectFourBoard()
{
    grid = std::vector<std::vector<char>>(ROWS, std::vector<char>(COLUMNS, '.'));
}

void ConnectFourBoard::displayBoard() const {
    std::cout << "\n  1 2 3 4 5 6 7\n";
    for (const auto& row : grid) {
        std::cout << " |";
        for (char cell : row) {
            std::cout << cell << '|';
        }
        std::cout << '\n';
    }
    std::cout << "-------------------\n";
}

bool ConnectFourBoard::makeMove(int col, char symbol) {
        if (col < 0 || col >= COLUMNS) return false; // Invalid column
        for (int row = ROWS - 1; row >= 0; --row) { // Start from bottom row
            if (grid[row][col] == '.') { // Check if the cell is empty
                grid[row][col] = symbol; // Place the token
                return true;            // Move successful
            }
        }
        return false; // Column is full
    }

bool ConnectFourBoard::dropDisc(int column, char disc) {

    if (column < 0 || column >= COLUMNS) {  // Fixed upper bound check
        return false;
    }
    for (int row = ROWS - 1; row >= 0; --row) {
        if (grid[row][column] == '.') {
            grid[row][column] = disc;
            return true; // this is cauing to return before filled
        }
    }
    return false;
}

// It is the horizental check
bool ConnectFourBoard::dropDiscToColumn(int row, int column, char disc) {
    if (column < 0 || column > COLUMNS || isColumnFull(column)) {
        return false;   
    }
    if (grid[row][column] == '.')
    {
        grid[row][column] = disc;
        return true;
    }
    return false;
}

// It is the vertical check
bool ConnectFourBoard::dropDiscToRow(int row,int col, char disc) {
    // Validate the row index
    if (row < 1 || row >= ROWS) {
        return false;
    }
    if (grid[row][col] == '.') { // Check if the cell is empty
        grid[row][col] = disc; // Place the disc
        return true;
    }
    return false; // No available spot in the row
}

bool ConnectFourBoard::dropDiscToDiagonal(int row, int col, char disc)
{
    if (grid[row][col] == '.') { // Check if the spot is empty
        grid[row][col] = disc; // Place the disc
        return true;
    }
    return false;
}

bool ConnectFourBoard::dropDiscToGap(int row, int col, char disc) {
    // Validate that the position is within bounds
    if (row < 1 || row >= ROWS || col < 1 || col >= COLUMNS) {
        return false;
    }
    // Check if the specified position is empty
    if (grid[row][col] == '.') {
        grid[row][col] = disc; // Place the disc in the gap
        return true;
    }
    // If the position is not empty, return false
    return false;
}

bool ConnectFourBoard::isFull() const {
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = 0; row < ROWS; ++row) {
            if (grid[row][col] == '.') { // Consider '.' as empty
                return false;           // Board is not full
            }
        }
    }
    return true; // No empty cells found
}


bool ConnectFourBoard::isColumnFull(int column) const {
    if (column < 1 || column >= COLUMNS) {
        return false; // Out of bounds
    }
    for (int row = 0; row < ROWS; ++row) {
        if (grid[row][column] == '.') { // Look for any empty cell
            return false;               // Column is not full
        }
    }
    return true; // No empty slots found
}

const std::vector<std::vector<char>>& ConnectFourBoard::getGrid() const {
    return grid;
}

// Check if a column is available
bool ConnectFourBoard::isColumnAvailable(int column) const {
    if (column < 0 || column > COLUMNS) {
        return false; // Out of bounds
    }
    return grid[0][column] == '.'; // Check if the top cell of the column is empty
}

// Get the width of the board
int ConnectFourBoard::getWidth() const {
    return COLUMNS;
}

void ConnectFourBoard::reset(void)
{
    // Clear and resize grid
    grid.clear();
    grid.resize(ROWS, std::vector<char>(COLUMNS, '.')); // Reset to empty state
}