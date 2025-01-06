#include "Computer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

Computer::Computer(char symbol) : symbol(symbol) {
    std::srand(std::time(0));  // Seed for random number generation
}

bool Computer::makeMove(ConnectFourBoard& board) {

    // Helper lambda for processing moves
    auto processMove = [&](const std::string& type, int row, int col, const std::string& message) {
        bool moveMade = false;
        if (type == "horizontal") moveMade = board.dropDiscToColumn(row, col, symbol);
        else if (type == "vertical")
        {
            // std::cout<< " r :" <<row <<" c " <<col <<" str " << type << " symbol " << symbol<<"\n";
             moveMade = board.dropDiscToRow(row, col, symbol);
        }
        else if (type == "diagonal_L2R") moveMade = board.dropDiscToDiagonal(row, col, symbol);
        else if (type == "diagonal_R2L") moveMade = board.dropDiscToDiagonal(row, col, symbol);
        else if (type == "gap") moveMade = board.dropDiscToGap(row, col, symbol);

        if (moveMade) {
            // std::cout << "Computer (" << symbol << ") " << message << " in column " << col + 1 << "!\n"; // 1-based index
            board.displayBoard();
        }
        return moveMade;
    };

    // Check for winning move, if there is no 3 consecutive 'O' then check if can be win.
    auto result = findWinningMove(board, 'O');
    if (processMove(result.first, result.second.first, result.second.second, "wins")) {
        return true;
    }

    // Block player winning move
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';
    ConnectFourBoard &tempBoard = board; // Simulate board
    auto blockMove = hasThreeConsecutive(tempBoard, opponentSymbol);
    if (processMove(blockMove.first, blockMove.second.first, blockMove.second.second, "blocks player")) {
        return true;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // Fallback: Random move
    int column;
    do {
        column = std::rand() % 7; // Random column selection
    } while (!board.dropDisc(column, symbol));

    std::cout << "Computer (" << symbol << ") played in column " << column + 1 << " randomly.\n";
    return true;
}

std::pair<std::string, std::pair<int, int>> Computer::findWinningMove(const ConnectFourBoard& board, char symbol) const {
    const auto& grid = board.getGrid();
    const int ROWS = 6, COLUMNS = 7;

    // Logs
    // std::cout << "Checking for winning moves...\n";

    // ------------------------
    // Horizontal Logic
    // ------------------------
    for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom row
        for (int col = 0; col < COLUMNS - 3; ++col) { // Ensure room for 4-in-a-row
            
            // Pattern 1: XXX.
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == symbol &&
                grid[row][col + 3] == '.') {

                // Gravity check
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 3] == '.') {
                    dropRow++;
                }

                if (dropRow == row) {
                    std::cout << "Horizontal Pattern 1 (XXX.) found at (" << row << ", " << col + 3 << ")\n";
                    return {"horizontal", {dropRow, col + 3}};
                }
            }

            // Pattern 2: .XXX
            if (grid[row][col] == '.' &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == symbol &&
                grid[row][col + 3] == symbol) {

                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col] == '.') {
                    dropRow++;
                }

                if (dropRow == row) {
                    std::cout << "Horizontal Pattern 2 (.XXX) found at (" << row << ", " << col << ")\n";
                    return {"horizontal", {dropRow, col}};
                }
            }

            // Pattern 3: X.XX
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == '.' &&
                grid[row][col + 2] == symbol &&
                grid[row][col + 3] == symbol) {

                int dropRow = row;
                  // This logic to check till bottom most empty. check row till bottom is empty will keep increse dropRow
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 1] == '.') {
                    dropRow++;
                }

                if (dropRow == row) {
                    std::cout << "Gap Pattern 3 (X.XX) found at (" << row << ", " << col + 1 << ")\n";
                    return {"gap", {dropRow, col + 1}};
                }
            }

            // Pattern 4: XX.X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == '.' &&
                grid[row][col + 3] == symbol) {

                int dropRow = row;
                // This logic to check till bottom most empty. check row till bottom is empty will keep increse dropRow
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 2] == '.') {
                    dropRow++;
                }

                if (dropRow == row) {
                    std::cout << "Gap Pattern 4 (XX.X) found at (" << row << ", " << col + 2 << ")\n";
                    return {"gap", {dropRow, col + 2}};
                }
            }
        }
    }

    // ------------------------
    // Vertical Check
    // ------------------------
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = ROWS - 1; row >= 2; --row) { // Ensure room for 4
            if (grid[row][col] == symbol &&
                grid[row - 1][col] == symbol &&
                grid[row - 2][col] == symbol &&
                grid[row - 3][col] == '.') { // Vertical placement

                std::cout << "Vertical Pattern found at (" << row - 3 << ", " << col << ")\n";
                return {"vertical", {row - 3, col}}; // Vertical always respects gravity
            }
        }
    }

    // ------------------------
    // Diagonal_L2R Logic
    // ------------------------
    for (int row = ROWS - 1; row >= 3; --row) { // Bottom to top
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (grid[row][col] == symbol &&
                grid[row - 1][col + 1] == symbol &&
                grid[row - 2][col + 2] == symbol &&
                grid[row - 3][col + 3] == '.') {

                int checkRow = row - 3;
                // if there is no winning then do not enter in condition
                if (checkRow == ROWS - 1 || grid[checkRow + 1][col + 3] != '.') {
                    std::cout << "Diagonal Left-to-Right found at (" << checkRow << ", " << col + 3 << ")\n";
                    return {"diagonal_L2R", {checkRow, col + 3}};
                }
            }
        }
    }

    // ------------------------
    // Diagonal_R2L Check
    // ------------------------
    for (int row = ROWS - 1; row >= 3; --row) {
        for (int col = COLUMNS - 1; col >= 3; --col) {
            if (grid[row][col] == symbol &&
                grid[row - 1][col - 1] == symbol &&
                grid[row - 2][col - 2] == symbol &&
                grid[row - 3][col - 3] == '.') {

                int checkRow = row - 3;
                if (checkRow == ROWS - 1 || grid[checkRow + 1][col - 3] != '.') {
                    std::cout << "Diagonal Right-to-Left found at (" << checkRow << ", " << col - 3 << ")\n";
                    return {"diagonal_R2L", {checkRow, col - 3}};
                }
            }
        }
    }

    return {"none", {-1, -1}}; // No winning move found
}


std::pair<std::string, std::pair<int, int>> Computer::hasThreeConsecutive(const ConnectFourBoard& board, char symbol) const {
    const auto& grid = board.getGrid();
    const int ROWS = 6, COLUMNS = 7;

    // std::cout << "Checking for three consecutive symbols...\n";

    // ------------------------
    // Gap Logic
    // ------------------------
    for (int row = ROWS - 1; row >= 0; --row) 
    { // Start from the bottom-most row
        for (int col = 0; col < COLUMNS - 3; ++col) { // Ensure room for 4-in-a-row
            // Pattern 1: X X . X
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == '.' &&
                grid[row][col + 3] == symbol) {

                // Drop the move to the lowest valid row for gravity
                int dropRow = row;
                while (dropRow < ROWS - 1 && grid[dropRow + 1][col + 2] == '.') {
                    dropRow++;
                }

                // Ensure bottom first and if no blocking find them do not insert let computer will make random decision
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

                // Ensure bottom first and if no blocking find them do not insert let computer will make random decision
                if (dropRow == row) { // Row must match, or else it's floating
                    return {"gap", {dropRow, col + 1}};
                }
            }
        }
    }


    // ------------------------
    // Horizontal Logic
    // ------------------------
    for (int row = ROWS - 1; row >= 0; --row) { // Start from the bottom row
        for (int col = 0; col < COLUMNS - 2; ++col) { // Ensure room for 3
            if (grid[row][col] == symbol &&
                grid[row][col + 1] == symbol &&
                grid[row][col + 2] == symbol) {

                // Check if left side empty in not not enter into if condition
                int candidateCol = col - 1;
                if (candidateCol >= 0 && grid[row][candidateCol] == '.') {
                    int dropRow = row;
                    while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                        dropRow++;
                    }
                    // Ensure bottom first and if no blocking find them do not insert let computer will make random decision
                    // if dropRow != to row means bottom row was empty so so no input
                    if (dropRow == row) {
                        return {"horizontal", {dropRow, candidateCol}};
                    }
                }

                //  Check if right side empty in not not enter into if condition
                candidateCol = col + 3;
                if (candidateCol < COLUMNS && grid[row][candidateCol] == '.') {
                    int dropRow = row;
                    while (dropRow < ROWS - 1 && grid[dropRow + 1][candidateCol] == '.') {
                        dropRow++;
                    }
                    if (dropRow == row) {
                        return {"horizontal", {dropRow, candidateCol}};
                    }
                }
            }
        }
    }

    // ------------------------
    // Vertical Logic
    // ------------------------
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = ROWS - 1; row >= 2; --row) { // Ensure room for 3
            if (grid[row][col] == symbol &&
                grid[row - 1][col] == symbol &&
                grid[row - 2][col] == symbol) {
                // Check for an empty space to block
                // std::cout << "Found three consecutive symbols at col " << col << "\n";
                // std::cout << "Checking row-3 position (" << row - 3 << "," << col << ")" << "\n";

                // Check for an empty space to block
                if (row - 3 >= 0 && grid[row - 3][col] == '.') { // Above block
                    // std::cout << "Valid empty slot found at row " << row - 3 << ", col " << col << "\n";
                    row-=3;
                    return {"vertical", {row, col}};
                }
            }
        }
    }

    // ------------------------
    // Diagonal Logic (bottom-left to top-right) 
    // ------------------------
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
                   // This will check bottom index if bottom index empty which not suppose to
                   // Then do not insert. 
                {
                    // Gravity check: Is the cell directly below filled or is it the bottom row?
                    if (checkRow == ROWS - 1 || grid[checkRow + 1][checkCol] != '.') {
                        std::cout << " row1- : " << checkRow << " col1- : " << checkCol << "\n";
                        return {"diagonal_L2R", {checkRow, checkCol}};
                    }
                }

            }
        }
    }

    // ------------------------
    // Diagonal Logic (bottom-Right to top-Left) 
    // ------------------------
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
                    // This will check bottom index if bottom index empty which not suppose to
                   // Then do not insert. 
                    {
                        std::cout << " row2- : " << checkRow << " col2- : " << checkCol << "\n";
                        return {"diagonal_R2L", {checkRow, checkCol}};
                    }
                }
            }
        }
    }

    return {"none", {-1, -1}}; // No blocking move found
}
