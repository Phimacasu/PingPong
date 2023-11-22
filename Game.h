// Game.h
#ifndef GAME_H
#define GAME_H

#include "PingPongBall.h"
#include "Player.h"
#include "Violation.h"

class Game {
public:
    Game();
    void run();

private:
    PingPongBall ball;
    Player player1, player2;
    int winningScore;
    void checkCollision();
    void displayScore();
    void drawScene();
    void handleKeyboard(unsigned char key, int x, int y);
    void handleSpecialKeys(int key, int x, int y);
};

#endif
