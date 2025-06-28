#include <GL/freeglut.h>
#include "../include/class/snake.h"
#include "../include/class/food.h"
#include "../include/utils/draw_utils.h"
#include "../include/utils/keycallback.h"
#include <string>

bool gameStarted = false;
int gridWidth = 20, gridHeight = 15;
int score = 0;
Snake snake;
Food* food;
double lastMoveTime = 0.0;
const double moveInterval = 150;

void resetGame();
void processGameLogic();
void renderScene();
void renderScoreText(int score);
void renderStartScreen();
bool shouldMove(int currentTime);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    drawBackground(gridWidth, gridHeight);

    if (gameStarted) {
        if (shouldMove(currentTime)) {
            processGameLogic();
            lastMoveTime = currentTime;
        }
        renderScene();
    } else {
        renderStartScreen();
    }

    glutSwapBuffers();
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Cobrinha");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    snake = Snake();
    food = new Food(gridWidth, gridHeight);
    food->spawn(snake);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyCallback);
    glutSpecialFunc(specialKeyCallback);

    lastMoveTime = glutGet(GLUT_ELAPSED_TIME);

    glutMainLoop();

    return 0;
}

bool shouldMove(int currentTime) {
    return (currentTime - lastMoveTime) >= moveInterval;
}

void resetGame() {
    snake.reset();
    food->spawn(snake);
    score = 0;
    glutSetWindowTitle("Cobrinha - Score: 0");
}

void processGameLogic() {
    Position oldTail = snake.getBody().back();
    snake.move();

    if (snake.checkCollision()) {
        resetGame();
        gameStarted = false;
    }

    if (snake.getHeadPosition().x == food->getPosition().x &&
        snake.getHeadPosition().y == food->getPosition().y) {
        snake.grow(oldTail);
        food->spawn(snake);
        score++;

        std::string title = "Cobrinha - Score: " + std::to_string(score);
        glutSetWindowTitle(title.c_str());
    }
}

void renderScene() {
    snake.draw();
    food->draw();
    renderScoreText(score);
}

void renderScoreText(int score) {
    std::string scoreText = "Score: " + std::to_string(score);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 1200, 800, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(10, 20, 0);
    glScalef(5.0f, 5.0f, 1.0f);

    drawText(0, 0, scoreText.c_str());

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void renderStartScreen() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 1200, 800, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(480, 250, 0);
    glScalef(5.0f, 5.0f, 1.0f);
    drawText(0, 0, "COBRINHA");

    glLoadIdentity();
    glTranslatef(370, 400, 0);
    glScalef(3.0f, 3.0f, 1.0f);
    drawText(0, 0, "Pressione ESPACO para comecar");

    glLoadIdentity();
    glTranslatef(800, 780, 0);
    glScalef(2.5f, 2.5f, 1.0f);
    drawText(0, 0, "Joao Vitor Leal - SP3122972");

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
