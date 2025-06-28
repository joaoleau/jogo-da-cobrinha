#include <GLFW/glfw3.h>
#include "../include/class/snake.h"
#include "../include/class/food.h"
#include "../include/utils/draw_utils.h"
#include <string>

void keyCallback(GLFWwindow*, int, int, int, int);
void resetGame(Snake& snake, Food& food);
void renderScoreText(int score);
void renderStartScreen();
bool shouldMove(double currentTime, double& lastMoveTime, double moveInterval);
void processGameLogic(Snake& snake, Food& food, int& score, GLFWwindow* window);
void renderScene(Snake& snake, Food& food, int score, int gridWidth, int gridHeight);

bool gameStarted = false;

int main() {
    int gridWidth = 20, gridHeight = 15;
    int score = 0;

    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(1200, 800, "Cobrinha", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    Snake snake;
    Food food(gridWidth, gridHeight);
    food.spawn(snake);

    glfwSetWindowUserPointer(window, &snake);

    double lastMoveTime = 0.0;
    const double moveInterval = 0.15;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        double currentTime = glfwGetTime();

        drawBackground(gridWidth, gridHeight);

        if (gameStarted) {
            if (shouldMove(currentTime, lastMoveTime, moveInterval)) {
                processGameLogic(snake, food, score, window);
            }

            renderScene(snake, food, score, gridWidth, gridHeight);
        } else {
            renderStartScreen();
        }

        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

bool shouldMove(double currentTime, double& lastMoveTime, double moveInterval) {
    if (currentTime - lastMoveTime >= moveInterval) {
        lastMoveTime = currentTime;
        return true;
    }
    return false;
}


void processGameLogic(Snake& snake, Food& food, int& score, GLFWwindow* window) {
    Position oldTail = snake.getBody().back();

    snake.move();

    if (snake.checkCollision()) {
        resetGame(snake, food);
        score = 0;
        gameStarted = false;
        glfwSetWindowTitle(window, "Cobrinha - Score: 0");
    }

    if (snake.getHeadPosition().x == food.getPosition().x &&
        snake.getHeadPosition().y == food.getPosition().y) {
        snake.grow(oldTail);
        food.spawn(snake);
        score++;

        std::string title = "Cobrinha - Score: " + std::to_string(score);
        glfwSetWindowTitle(window, title.c_str());
    }
}

void renderScene(Snake& snake, Food& food, int score, int gridWidth, int gridHeight) {
    snake.draw();
    food.draw();
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


void resetGame(Snake& snake, Food& food) {
    snake.reset();
    food.spawn(snake);
}
