// Violation.h
#ifndef VIOLATION_H
#define VIOLATION_H

class Violation {
public:
    static bool wallCollision(float x, float y, float radius);
    static bool weakHit(float ballY, float playerY, float paddleHeight);
};

#endif
