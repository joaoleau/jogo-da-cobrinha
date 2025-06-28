#include "../include/class/snake.h"
#include <GLFW/glfw3.h>

extern bool gameStarted;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Snake* snake = static_cast<Snake*>(glfwGetWindowUserPointer(window));

    if (action == GLFW_PRESS) {
        if (!gameStarted && key == GLFW_KEY_SPACE) {
            gameStarted = true;
            return;
        }

        if (gameStarted) {
            switch (key) {
                case GLFW_KEY_UP:    snake->setDirection(0, 1); break;
                case GLFW_KEY_DOWN:  snake->setDirection(0, -1); break;
                case GLFW_KEY_LEFT:  snake->setDirection(-1, 0); break;
                case GLFW_KEY_RIGHT: snake->setDirection(1, 0); break;
            }
        }
    }
}
