#include "Computer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Computer::Computer(char symbol) : symbol(symbol) {
    std::srand(std::time(0));  // Seed for random number generation
}

bool Computer::makeMove(ConnectFourBoard& board) {

    // Helper lambda for processing moves
    auto processMove = [&](const std::string& type, int row, int col, const std::string& message) {
        bool moveMade = false;
        if (type == "column") moveMade = board.dropDiscToColumn(row, col, symbol);
        else if (type == "row") moveMade = board.dropDiscToRow(row, col, symbol);
        else if (type == "L2R") moveMade = board.dropDiscToDiagonal(row, col, symbol);
        else if (type == "R2L") moveMade = board.dropDiscToDiagonal(row, col, symbol);
        else if (type == "gap") moveMade = board.dropDiscToGap(row, col, symbol);

        if (moveMade) {
            std::cout << "Computer (" << symbol << ") " << message << " in column " << col + 1 << "!\n"; // 1-based index
            board.displayBoard();
        }
        return moveMade;
    };

    // Check for winning move, if there is no 3 consecutive 'O' then check if can be blocked.
    auto result = hasThreeConsecutive(board, 'O');
    if (processMove(result.first, result.second.first, result.second.second, "wins")) {
        return true;
    }

    // Block player's winning move
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';
    ConnectFourBoard &tempBoard = board; // Simulate board
    auto blockRes = hasThreeConsecutive(tempBoard, opponentSymbol);
    if (processMove(blockRes.first, blockRes.second.first, blockRes.second.second, "blocks player")) {
        return true;
    }

    // Fallback: Random move
    int column;
    do {
        column = std::rand() % 7; // Random column selection
    } while (!board.dropDisc(column, symbol));

    std::cout << "Computer (" << symbol << ") played in column " << column + 1 << " randomly.\n";
    return true;
}

std::pair<std::string, std::pair<int, int>> Computer::hasThreeConsecutive(const ConnectFourBoard& board, char symbol) const {
    const auto& grid = board.getGrid();
    const int ROWS = 6, COLUMNS = 7;

    // std::cout << "Checking for three consecutive symbols...\n";

    // Gap code
    for (int row = ROWS - 1; row >= 0; --row) 
    { // Start from the bottom-most row
        for (int col = 0; col < COLUMNS - 3; ++col) { // Ensure room for 4-in-a-row
            // Pattern 1: X X . X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == '.' &&
                grid[row][col + 3] == symbol) {

                // Drop the token to the lowest valid row for gravity
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 2] == '.') {
                    dropRow++;
                }

                // Ensure valid gravity placement
                if (dropRow == row) { // Row must match, or else it's floating
                    return {"gap", {dropRow, col + 2}};
                }
            }

            // Pattern 2: X . X X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == '.' &&
                grid[row][col + 2] == symbol &&
                grid[row][col + 3] == symbol) {

                // Drop the token to the lowest valid row for gravity
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 1] == '.') {
                    dropRow++;
                }

                // Ensure valid gravity placement
                if (dropRow == row) { // Row must match, or else it's floating
                    return {"gap", {dropRow, col + 1}};
                }
            }
        }
    }


    for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom row
    for (int col = 0; col < COLUMNS - 2; ++col) { // Ensure room for 3
        if (grid[row][col] == symbol &&
            grid[row][col + 1] == symbol &&
            grid[row][col + 2] == symbol) {

            // Check left side
            int candidateCol = col - 1;
            if (candidateCol >= 0 && grid[row][candidateCol] == '.') {
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                    dropRow++;
                }
                if (dropRow == row) {
                    return {"column", {dropRow, candidateCol}};
                }
            }

            // Check right side
            candidateCol = col + 3;
            if (candidateCol < COLUMNS && grid[row][candidateCol] == '.') {
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                    dropRow++;
                }
                if (dropRow == row) {
                    return {"column", {dropRow, candidateCol}};
                }
            }
        }
    }
    }



    /* for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom-most row
        for (int col = 0; col < COLUMNS - 3; ++col) { // Ensure room for 4-in-a-row
            // Pattern 1: X X . X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == '.' &&
                grid[row][col + 3] == symbol) {
                return {"gap", {row, col + 2}}; // Return the row and column of the gap
            }

            // Pattern 2: X . X X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == '.' &&
                grid[row][col + 2] == symbol &&
                grid[row][col + 3] == symbol) {
                return {"gap", {row, col + 1}}; // Return the row and column of the gap
            }
        }
    } */


    // horizental
    /* for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom row
    for (int col = 0; col < COLUMNS - 2; ++col) { // Ensure room for 3
        if (grid[row][col] == symbol &&
            grid[row][col + 1] == symbol &&
            grid[row][col + 2] == symbol) {

            // Check left side
            int candidateCol = col - 1;
            if (candidateCol >= 0 && grid[row][candidateCol] == '.') {
                // Find the lowest valid row in this column
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                    dropRow++; // Drop to the lowest available position
                }
                // Check if it's a valid drop
                if (dropRow == row) {
                    return {"column", {dropRow, candidateCol}}; // Valid drop
                }
            }

            // Check right side
            candidateCol = col + 3;
            if (candidateCol < COLUMNS && grid[row][candidateCol] == '.') {
                // Find the lowest valid row in this column
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                    dropRow++; // Drop to the lowest available position
                }
                // Check if it's a valid drop
                if (dropRow == row) {
                    return {"column", {dropRow, candidateCol}}; // Valid drop
                }
            }
        }
    }
    } */



    /* // horizental check
    for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom row
        for (int col = 0; col < COLUMNS - 2; ++col) { // Ensure room for 3
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == symbol) {
                // Check left side and gravity
                if (col - 1 >= 0 && grid[row][col - 1] == '.' && 
                   (row == ROWS - 1 || grid[row + 1][col - 1] != '.')) { // Empty space on the left
                    col-=1;
                    return {"column",{row, col}};
                }
                // Check right side
                if (col + 3 < COLUMNS && grid[row][col + 3] == '.' && (row == ROWS - 1 || grid[row + 1][col + 3] != '.')) 
                { // Empty space on the right
                    col+=3;
                    return {"column",{row, col}};
                }
            }
        }
    } */

    // Vertical check
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = ROWS - 1; row >= 2; --row) { // Ensure room for 3
            if (grid[row][col] == symbol &&
                grid[row - 1][col] == symbol &&
                grid[row - 2][col] == symbol) {
                // Check for an empty space to block
                if (row - 3 >= 0 && grid[row - 3][col] == '.') { // Above block
                    row-=3;
                    return {"row", {row, col}};
                }
            }
        }
    }

    // Diagonal check (bottom-left to top-right)
    for (int row = ROWS - 1; row >= 3; --row) { // Bottom to top
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (grid[row][col] == symbol &&
                grid[row - 1][col + 1] == symbol &&
                grid[row - 2][col + 2] == symbol) {
                // Check for an empty space to block
                int checkRow = row - 3;
                int checkCol = col + 3;

                // Check bounds and if the position is empty
                if (checkRow >= 0 && checkCol < COLUMNS && grid[checkRow][checkCol] == '.' &&
                   (checkRow == ROWS - 1 || grid[checkRow + 1][checkCol] != '.')) 
                {
                    // Gravity check: Is the cell directly below filled or is it the bottom row?
                    if (checkRow == ROWS - 1 || grid[checkRow + 1][checkCol] != '.') {
                        std::cout << " row1- : " << checkRow << " col1- : " << checkCol << "\n";
                        return {"L2R", {checkRow, checkCol}};
                    }
                }


                /* if (row + 1 < ROWS && col - 1 >= 0 && grid[row + 1][col - 1] == '.') { // Bottom-left block
                    row += 1; 
                    col -= 1; 
                    std::cout<< " row1 : "<< row <<" col1 : " << col <<"\n";
                    return {"L2R", {row, col}};
                } */
            }
        }
    }

    // Diagonal check (bottom-right to top-left)
    for (int row = ROWS - 1; row >= 3; --row) { // Bottom to top
        for (int col = COLUMNS - 1; col >= 3; --col) {
            if (grid[row][col] == symbol &&
                grid[row - 1][col - 1] == symbol &&
                grid[row - 2][col - 2] == symbol) {
                // Check for an empty space to block
                int checkRow = row - 3;
                int checkCol = col - 3;

                if (checkRow >= 0 && checkCol >= 0 && grid[checkRow][checkCol] == '.') {
                    // Ensure gravity (cell below must be filled or it's the bottom row)
                    if (checkRow == ROWS - 1 || grid[checkRow + 1][checkCol] != '.' && 
                       (checkRow == ROWS - 1 || grid[checkRow + 1][checkCol] != '.')) 
                    {
                        std::cout << " row2- : " << checkRow << " col2- : " << checkCol << "\n";
                        return {"R2L", {checkRow, checkCol}};
                    }
                }

                /* if (row + 1 < ROWS && col + 1 < COLUMNS && grid[row + 1][col + 1] == '.') { // Bottom-right block
                    row += 1; 
                    col += 1; 
                    std::cout<< " row2 : "<< row <<" col2 : " << col <<"\n";
                    return {"R2L", {row, col}};
                } */
            }
        }
    }

    return {"none", {-1, -1}}; // No blocking move found
}
