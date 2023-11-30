// main.cpp
#include <glut.h>
#include "Game.h"
#include <cmath>
#include <ctime>

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

bool reset = false;
int countdown = 60; 

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        leftPadY += padSpeed;
        break;
    case 's':
        leftPadY -= padSpeed;
        break;
    }
}

void keycode(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        rightPadY += padSpeed;

    if (key == GLUT_KEY_DOWN)
        rightPadY -= padSpeed;
}

void update(int value) {
    if (reset) {
        countdown--;
        if (countdown <= 0) {
            reset = false;
            countdown = 60;
        }
    }
    else {
        posX += speedX;
        posY += speedY;

 
        if (posX > 1.0f - radius || posX < -1.0f + radius) {
            speedX = -speedX;
        }

        if (posY > 1.0f - radius || posY < -1.0f + radius) {
            speedY = -speedY;
        }

 
        if (posX - radius < leftPadX + Width &&
            posX + radius > leftPadX &&
            posY - radius < leftPadY &&
            posY + radius > leftPadY - Height) {
            speedX = -speedX;
        }


        if (posX + radius > rightPadX &&
            posX - radius < rightPadX + Width &&
            posY - radius < rightPadY &&
            posY + radius > rightPadY - Height) {
            speedX = -speedX;
        }

 
        if (posX > 0.95f || posX < -0.95f) {
            reset = true;
            posX = 0.0f;
            posY = 0.0f;
        }
    }

    glutTimerFunc(16, update, 0);
    glutPostRedisplay();
}

void paddle() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(leftPadX, leftPadY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(leftPadX + Width, leftPadY);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(leftPadX + Width, leftPadY - Height);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(leftPadX, leftPadY - Height);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(rightPadX, rightPadY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(rightPadX + Width, rightPadY);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(rightPadX + Width, rightPadY - Height);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(rightPadX, rightPadY - Height);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = 2.0f * 3.14f * i / 360.0f;
        float x = posX + radius * std::cos(angle);
        float y = posY + radius * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    paddle();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Ping Pong Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keycode);
    glutMainLoop();
    return 0;
}
