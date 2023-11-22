// main.cpp
#include <GL/glut.h>
#include "Game.h"

Game game;

void display() {
    game.run();
}

void reshape(int w, int h) {
    // Reshape code
}

void keyboard(unsigned char key, int x, int y) {
    game.handleKeyboard(key, x, y);
}

void specialKeys(int key, int x, int y) {
    game.handleSpecialKeys(key, x, y);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Ping Pong Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
