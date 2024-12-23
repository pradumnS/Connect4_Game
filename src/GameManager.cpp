#include "GameManager.hpp"
#include <iostream>

// Main method to start the game
void GameManager::run() {
    displayMenu();
}

// Display menu and handle choice
void GameManager::displayMenu() {
    int choice;
    // std::cout << "Welcome to Connect4!\n";
    std::cout << "Choose an option:\n";
    std::cout << "1. Play with a Friend\n";
    std::cout << "2. Play with the Computer\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice. Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        playWithFriend();
    } else {
        playWithComputer();
    }
}

void GameManager::playWithFriend() {
   
    // Use FriendPlayer for both players
    FriendPlayer player1("Player1: ", 'X');
    FriendPlayer player2("player2: ", 'O');

    while (!board.isFull() && !checkWinner(board, 'X') && !checkWinner(board, 'O')) {
        board.displayBoard();

        // Player 1's turn
        player1.makeMove(board);
        if (checkWinner(board, 'X')) {
            board.displayBoard();
            std::cout << "Player1 :" << " wins!\n";
            return;
        }

        if (board.isFull()) break;

        // Player 2's turn
        board.displayBoard();
        player2.makeMove(board);
        if (checkWinner(board, 'O')) {
            board.displayBoard();
            std::cout << "player2 : " << " wins!\n";
            return;
        }
    }

    // Display result if it's a draw
    if (board.isFull() && !checkWinner(board, 'X') && !checkWinner(board, 'O')) {
        board.displayBoard();
        std::cout << "It's a draw!\n";
    }
}

void GameManager::playWithComputer() {
    // Use FriendPlayer for the human player
    FriendPlayer player("player1:", 'X');
    Computer computer('O');

    // Decide who starts first
    int choice;
    std::cout << "Who starts first? (1 for human, 2 for Computer): ";
    std::cin >> choice;

    // Validate input
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice. Enter 1 for Player or 2 for Computer: ";
        std::cin >> choice;
    }

    bool playerTurn = (choice == 1); // true if Player starts, false if Computer starts

    // If the computer starts first, force its first move in column 4
    if (!playerTurn) {
        board.makeMove(3, 'O'); // Column 4 (index 3 in 0-based indexing)
        // board.displayBoard(); // Show the board after the computer's move
        if (checkWinner(board, 'O')) { // Check if the computer wins immediately (unlikely)
            std::cout << "Computer wins!\n";
            return;
        }
        playerTurn = true; // Switch turn to player after computer's first move
    }

    // Game loop
    while (!board.isFull() && !checkWinner(board, 'X') && !checkWinner(board, 'O')) {
        board.displayBoard();

        if (playerTurn) {
            // Human player's turn
            player.makeMove(board);
            if (checkWinner(board, 'X')) {
                std::cout << "\n********   player wins!   ********* " << "\n";
                board.displayBoard();
                // std::cout << "player1: " << " wins!\n";
                return;
            }
        } else {
            // Computer's turn
            computer.makeMove(board);
            if (checkWinner(board, 'O')) {
                std::cout << "\n********   Computer wins!   ********* " << "\n";
                board.displayBoard();
                // std::cout << "Computer wins!\n";
                return;
            }
        }

        // Switch turns
        playerTurn = !playerTurn;

        if (board.isFull()) break; // Stop if board is full
    }

    // Display result if it's a draw
    if (board.isFull() && !checkWinner(board, 'X') && !checkWinner(board, 'O')) {
        board.displayBoard();
        std::cout << "It's a draw!\n";
    }
}

bool GameManager::checkWinner(const ConnectFourBoard& board, char currentSymbol) const {
    const auto& grid = board.getGrid();
    const int ROWS = 6, COLUMNS = 7;

    // Horizontal check (row-wise from bottom to top)
    for (int row = ROWS - 1; row >= 0; --row) {
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (grid[row][col] == currentSymbol &&
                grid[row][col + 1] == currentSymbol &&
                grid[row][col + 2] == currentSymbol &&
                grid[row][col + 3] == currentSymbol) {
                return true; // Found horizontal connect-4
            }
        }
    }

    // Vertical check (column-wise from bottom to top)
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = ROWS - 1; row >= 3; --row) { // Start from row 6 (ROWS-1) and go up to row 3
            if (grid[row][col] == currentSymbol &&
                grid[row - 1][col] == currentSymbol &&
                grid[row - 2][col] == currentSymbol &&
                grid[row - 3][col] == currentSymbol) {
                return true; // Found vertical connect-4
            }
        }
    }

    // Diagonal check (bottom-left to top-right)
    for (int row = ROWS - 1; row >= 3; --row) { // Start from bottom row and check upward
        for (int col = 0; col < COLUMNS - 3; ++col) { // Check diagonals with room for 4 columns
            if (grid[row][col] == currentSymbol &&
                grid[row - 1][col + 1] == currentSymbol &&
                grid[row - 2][col + 2] == currentSymbol &&
                grid[row - 3][col + 3] == currentSymbol) {
                return true; // Found diagonal connect-4 (bottom-left to top-right)
            }
        }
    }

    // Diagonal check (top-left to bottom-right)
    for (int row = ROWS - 1; row >= 3; --row) { // Start from bottom row and check upward
        for (int col = COLUMNS - 1; col >= 3; --col) { // Check diagonals with room for 4 columns
            if (grid[row][col] == currentSymbol &&
                grid[row - 1][col - 1] == currentSymbol &&
                grid[row - 2][col - 2] == currentSymbol &&
                grid[row - 3][col - 3] == currentSymbol) {
                return true; // Found diagonal connect-4 (bottom-right to top-left)
            }
        }
    }

    return false; // No winning condition found
}
