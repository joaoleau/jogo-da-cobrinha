#include "../include/utils/keycallback.h"
#include "../include/class/snake.h"
#include <GL/freeglut.h>

extern bool gameStarted;
extern Snake snake;

void keyCallback(unsigned char key, int x, int y) {
    if (!gameStarted && key == ' ') {
        gameStarted = true;
    }
    if (key == 27) {
        exit(0);
    }
}

void specialKeyCallback(int key, int x, int y) {
    if (!gameStarted) return;

    switch (key) {
        case GLUT_KEY_UP:    snake.setDirection(0, 1); break;
        case GLUT_KEY_DOWN:  snake.setDirection(0, -1); break;
        case GLUT_KEY_LEFT:  snake.setDirection(-1, 0); break;
        case GLUT_KEY_RIGHT: snake.setDirection(1, 0); break;
    }
}
