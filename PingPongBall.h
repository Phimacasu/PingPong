// PingPongBall.h
#pragma once

class PingPongBall {
private:
    float x;
    float y;
    float speedX;
    float speedY;
    float radius;

public:
    PingPongBall();
    PingPongBall(float startX, float startY);

    void move(float leftPadX, float leftPadY, float leftPadWidth, float leftPadHeight,
        float rightPadX, float rightPadY, float rightPadWidth, float rightPadHeight);
    void reset(float startX, float startY);

    float getX() const;
    float getY() const;
    float getRadius() const;
    void reverseX();  // Added function to reverse the ball's X direction
};
