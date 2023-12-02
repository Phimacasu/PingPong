// Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();                    // Default constructor
    Player(float startX, float startY);
    void moveUp(bool player1Input);   // Updated to take input parameter
    void moveDown(bool player1Input); // Updated to take input parameter
    float getY();
    int getScore();
    void increaseScore();

private:
    float x, y;  // Player's coordinates
    int score;   // Player's score
};

#endif // PLAYER_H