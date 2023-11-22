// PingPongBall.h
#ifndef PINGPONGBALL_H
#define PINGPONGBALL_H

class PingPongBall {
public:
    PingPongBall(float startX, float startY);
    void move();
    void reset(float startX, float startY);
    float getX();
    float getY();
    float getRadius();

private:
    float x, y;  // Ball coordinates
    float speedX, speedY;  // Ball speed
    float radius;  // Ball radius
};

#endif
