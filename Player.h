// Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(float startX, float startY);
    void moveUp();
    void moveDown();
    float getY();
    int getScore();
    void increaseScore();

private:
    float x, y;  // Player's coordinates
    int score;  // Player's score
};

#endif
