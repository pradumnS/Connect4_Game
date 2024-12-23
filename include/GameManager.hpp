/**
 * @file GameManager.hpp
 * @brief Header file defining the GameManager class for managing the Connect4 game.
 *
 * This file declares the GameManager class, which serves as the central controller 
 * for the Connect4 game. It coordinates interactions between the game board, players, 
 * and user interface, providing functionality to start and manage different game modes.
 *
 * Key Features:
 * - Provides methods to start the game and handle menu navigation.
 * - Supports two game modes: 
 *   1. Friend Mode - Two players compete against each other.
 *   2. Computer Mode - A player competes against the computer.
 * - Implements helper methods for validating moves and checking game results.
 *
 * Usage:
 * - Instantiate the GameManager class to initialize and run the game using 
 *   the `run` method.
 * - The `displayMenu` method provides options for selecting the desired 
 *   game mode and interacting with players.
 * - Helper functions like `checkWinner` handle win condition validations 
 *   and streamline the gameplay flow.
 *
 */



#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "FriendPlayer.hpp" // Corrected capitalization
#include <string>

// Explicitly declare std usage
using std::string;

// Class declaration
class GameManager
{
public:
    // Default constructor (explicit if needed)
    GameManager(void) = default;

    // Deleted copy constructor and assignment operator
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    // Main method to start the game
    void run(void);

private:
    // Helper methods for game operations
    void displayMenu(void);         // Display menu and handle choice
    void playWithFriend(void);      // Game logic for playing with a friend
    void playWithComputer(void);    // Game logic for playing against the computer

    // Validation and result check
    bool checkWinner(const ConnectFourBoard& board, char currentSymbol) const;

    // Member variables
    ConnectFourBoard board; // The game board
};

#endif // GAMEMANAGER_HPP
