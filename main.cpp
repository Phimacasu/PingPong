#include <glut.h>
#include <cmath>
#include <ctime>
#include <string>
#include <windows.h>
#include "PingPongBall.h"

// Game class declaration (assuming it's defined in "Game.h")
#include "Game.h"

Game game;

float radius = 0.05f;
float posX = 0.0f;
float posY = 0.0f;
float speedX = 0.02f;
float speedY = 0.015f;

float Width = 0.05f;
float Height = 0.25f;
float leftPadX = -1.0f;
float leftPadY = 0.0f;
float rightPadX = 0.94f;
float rightPadY = 0.0f;
float padSpeed = 0.035f;

PingPongBall ball;  // Create an instance of PingPongBall

void score() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.2f, 0.8f);
    std::string scoreText = "Player 1: " + std::to_string(scorePlayer1);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(0.1f, 0.8f);
    scoreText = "Player 2: " + std::to_string(scorePlayer2);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }


    if (gameOver) {
        glRasterPos2f(-0.1f, 0.5f);
        std::string winnerText = (scorePlayer1 >= 10) ? "Player 1 wins!" : "Player 2 wins!";
        for (char c : winnerText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

void update(int value) {
if (!gameOver) {
    if (reset) {
        countdown--;
        if (countdown <= 0) {
            reset = false;
            countdown = 60;
        }
    }
   else{
    ball.move(leftPadX, leftPadY, Width, Height, rightPadX, rightPadY, Width, Height);
    if ((ball.getX() - ball.getRadius() < leftPadX + Width &&
        ball.getX() + ball.getRadius() > leftPadX &&
        ball.getY() - ball.getRadius() < leftPadY &&
        ball.getY() + ball.getRadius() > leftPadY - Height) ||
        (ball.getX() + ball.getRadius() > rightPadX &&
            ball.getX() - ball.getRadius() < rightPadX + Width &&
            ball.getY() - ball.getRadius() < rightPadY &&
            ball.getY() + ball.getRadius() > rightPadY - Height)) {
        // Ball collided with a paddle, change its direction
        ball.reverseX();
    }

    // Check for collisions with boundaries
    if (ball.getY() + ball.getRadius() > 1.0f || ball.getY() - ball.getRadius() < -1.0f) {
        ball.reset(0.0f, 0.0f);
    }
    if (ball.getX() + ball.getRadius() < leftPadX || ball.getX() - ball.getRadius() > rightPadX) {
        ball.reset(0.0f, 0.0f);
    }
        if (posX > 0.95f) {
        reset = true;
        posX = 0.0f;
        posY = 0.0f;
        scorePlayer1++;
    }

    if (posX < -0.95f) {
        reset = true;
        posX = 0.0f;
        posY = 0.0f;
        scorePlayer2++;
    }

    if (scorePlayer1 >= 10 || scorePlayer2 >= 10) {
        gameOver = true;
    	}
    }
  
    glutTimerFunc(16, update, 0);
}
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    // Your keyboard handling logic here...
    switch (key) {
    case 'w':
        if (leftPadY + padSpeed < 1.3f - Height) {
            leftPadY += padSpeed;
        }
        break;
    case 's':
        if (leftPadY - padSpeed > -1.3f) {
            leftPadY -= padSpeed;
        }
        break;
    case 'i':  // Controls for the second player
        if (rightPadY + padSpeed < 1.3f - Height) {
            rightPadY += padSpeed;
        }
        break;
    case 'k':
        if (rightPadY - padSpeed > -1.3f) {
            rightPadY -= padSpeed;
        }
        break;
    }
}

void specialKeys(int key, int x, int y) {
    // Your special key handling logic here...
    switch (key) {
    case GLUT_KEY_UP:
        if (rightPadY + padSpeed < 1.0f - Height) {
            rightPadY += padSpeed;
        }
        break;
    case GLUT_KEY_DOWN:
        if (rightPadY - padSpeed > -1.0f) {
            rightPadY -= padSpeed;
        }
        break;
    }
}

void reshape(int w, int h) {
    // Your reshape logic here...
}

void paddle() {
    // Draw left paddle
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(leftPadX, leftPadY);
    glVertex2f(leftPadX + Width, leftPadY);
    glVertex2f(leftPadX + Width, leftPadY - Height);
    glVertex2f(leftPadX, leftPadY - Height);
    glEnd();

    // Draw right paddle
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(rightPadX, rightPadY);
    glVertex2f(rightPadX + Width, rightPadY);
    glVertex2f(rightPadX + Width, rightPadY - Height);
    glVertex2f(rightPadX, rightPadY - Height);
    glEnd();
}

void display() {
    // Your display logic here...

    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the ball
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = 2.0f * 3.14f * i / 360.0f;
        float x = ball.getX() + radius * std::cos(angle);
        float y = ball.getY() + radius * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw paddles
    paddle();

    glutSwapBuffers();
}

void init() {
    // Your initialization logic here...
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Pong Game");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(16, update, 0);

    init();

    glutMainLoop();
    return 0;
}
