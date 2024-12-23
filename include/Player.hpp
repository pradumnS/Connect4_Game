/**
 * @file Player.hpp
 * @brief Header file defining the Player class for the Connect4 game.
 *
 * This file declares the Player class, which serves as an abstract base class 
 * for all player types in the Connect4 game. It provides a standard interface 
 * for making moves and retrieving player information, ensuring consistency 
 * across different player implementations.
 *
 * Key Features:
 * - Defines a common interface for player actions, including making moves 
 *   and retrieving player details such as name and symbol.
 * - Implements a virtual destructor to ensure proper cleanup in derived classes.
 *
 * Usage:
 * - The Player class cannot be instantiated directly. It must be inherited 
 *   by concrete implementations such as `FriendPlayer` and `Computer`.
 * - Derived classes must implement the pure virtual `makeMove` method to define 
 *   specific move strategies.
 * - Getter methods (`getName` and `getSymbol`) provide read-only access to 
 *   player attributes, ensuring data integrity.
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Board.hpp"
#include <string>

// Use namespace std explicitly (MISRA Rule 5-1-1)
using std::string;

// Declare the class
class Player 
{
public:
    //No dynamic memory allocation allowed mentioned explicit
    explicit Player(const string& playerName, char playerSymbol);

    // Virtual destructor
    virtual ~Player() = default;

    // Pure virtual function for making a player move
    virtual void makeMove(ConnectFourBoard& board) = 0;

    // Getter methods should be declared 'const' for safety
    string getName(void) const;  // Add void in parameter list (Rule 8-3-1)
    char getSymbol(void) const;

protected:
    // Member variables must be private (Rule 8-7-1)
    string name;
    char symbol; // player 

private:
    // Copy and assignment operations deleted to enforce rule 12-8-1
    Player(const Player&) = delete;             
    Player& operator=(const Player&) = delete;  
};

#endif // PLAYER_HPP
