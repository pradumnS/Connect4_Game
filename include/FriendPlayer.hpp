/**
 * @file FriendPlayer.hpp
 * @brief Header file defining the FriendPlayer class for the Connect4 game.
 *
 * This file declares the FriendPlayer class, which represents a human player 
 * participating in the Connect4 game against another human player (friend mode). 
 * It inherits from the Player class and implements functionality for making moves 
 * on the game board.
 *
 * Key Features:
 * - Supports player-specific moves in a two-player (friend) mode.
 * - Overrides the `makeMove` function to handle human input for gameplay.
 * - Ensures safe object creation and prevents unintentional copying through 
 *   deleted copy constructors and assignment operators.
 *
 * Usage:
 * - The FriendPlayer class can be instantiated to represent a human player in a 
 *   two-player game mode, enabling interactive gameplay through the `makeMove` method.
 * - It relies on the `ConnectFourBoard` class to validate and execute moves.
 *
 */

#ifndef FRIENDPLAYER_HPP
#define FRIENDPLAYER_HPP

#include "Player.hpp"
#include "Board.hpp"
#include <string>

// Explicitly declare std string 
using std::string;

// FriendPlayer class inheriting from Player
class FriendPlayer : public Player
{
public:
    // Explicit constructor to prevent implicit conversions
    FriendPlayer(const string& playerName, char playerSymbol);

    // Overrides the makeMove function for a friend player
    bool makeMove(ConnectFourBoard& board) override;

private:
    // Deleted copy constructor and assignment operator
    FriendPlayer(const FriendPlayer&) = delete;
    FriendPlayer& operator=(const FriendPlayer&) = delete;

};

#endif // FRIENDPLAYER_HPP
