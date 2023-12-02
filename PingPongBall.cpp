// PingPongBall.cpp
#include "PingPongBall.h"
#include <windows.h>

PingPongBall::PingPongBall() : x(0.0f), y(0.0f), speedX(0.005f), speedY(0.005f), radius(0.05f) {}

PingPongBall::PingPongBall(float startX, float startY) : x(startX), y(startY), speedX(0.005f), speedY(0.005f), radius(0.05f) {}

void PingPongBall::move(float leftPadX, float leftPadY, float leftPadWidth, float leftPadHeight,
    float rightPadX, float rightPadY, float rightPadWidth, float rightPadHeight) {
    x += speedX;
    y += speedY;

    // Check for collisions with the walls
    if (x + radius > 1.0f || x - radius < -1.0f) {
        speedX = -speedX;
        PlaySound(L"Pong_SFX\\Collide_1.wav", NULL, SND_FILENAME | SND_ASYNC);
    }

    if (y + radius > 1.0f || y - radius < -1.0f) {
        speedY = -speedY;
        PlaySound(L"Pong_SFX\\Collide_2.wav", NULL, SND_FILENAME | SND_ASYNC);
    }

    // Collision with left paddle
    if (x - radius < leftPadX + leftPadWidth &&
        x + radius > leftPadX &&
        y - radius < leftPadY &&
        y + radius > leftPadY - leftPadHeight) {
        speedX = -speedX;
        PlaySound(L"Pong_SFX\\Collide_3.wav", NULL, SND_FILENAME | SND_ASYNC);
    }

    // Collision with right paddle
    if (x + radius > rightPadX &&
        x - radius < rightPadX + rightPadWidth &&
        y - radius < rightPadY &&
        y + radius > rightPadY - rightPadHeight) {
        speedX = -speedX;
        PlaySound(L"Pong_SFX\\Collide_4.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
}

void PingPongBall::reset(float startX, float startY) {
    x = startX;
    y = startY;
    speedX = 0.005f;
    speedY = 0.005f;
}

float PingPongBall::getX() const {
    return x;
}

float PingPongBall::getY() const {
    return y;
}

float PingPongBall::getRadius() const {
    return radius;
}

void PingPongBall::reverseX() {
    speedX = -speedX;
}
