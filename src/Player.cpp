#include "Player.hpp"
#include <iostream>


// Constructor
Player::Player(const std::string& name, char symbol) : name(name), symbol(symbol) {}

// Getters
std::string Player::getName() const {
    return name;
}

char Player::getSymbol() const {
    return symbol;
}

void Player::makeMove(ConnectFourBoard& board) {
    // Default implementation
}

