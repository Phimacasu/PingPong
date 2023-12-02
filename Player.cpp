// Player.cpp
#include "Player.h"

// Implement the default constructor
Player::Player() : x(0.0f), y(0.0f), score(0) {
    // Initialization code for Player
}

// Implement the parameterized constructor
Player::Player(float startX, float startY) : x(startX), y(startY), score(0) {
    // Initialization code for Player with provided values
}

// Implement other member functions as before
void Player::moveUp(bool player1Input) {
    if (player1Input) {
        // Implementation for moveUp for player 1
    }
    else {
        // Implementation for moveUp for player 2
    }
}

void Player::moveDown(bool player1Input) {
    if (player1Input) {
        // Implementation for moveDown for player 1
    }
    else {
        // Implementation for moveDown for player 2
    }
}

float Player::getY() {
    // Implementation for getY function
    return y;
}

int Player::getScore() {
    // Implementation for getScore function
    return score;
}

void Player::increaseScore() {
    // Implementation for increaseScore function
    score++;
}
