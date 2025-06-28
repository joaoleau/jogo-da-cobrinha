#include "../include/class/food.h"
#include <cstdlib>
#include <ctime>

Food::Food(int width, int height)
    : gridWidth(width), gridHeight(height) {
    std::srand(std::time(nullptr));
    position = {5, 5};
}

void Food::spawn(const Snake& snake) {
    bool valid = false;
    while (!valid) {
        position.x = std::rand() % gridWidth;
        position.y = std::rand() % gridHeight;

        valid = true;
        for (const auto& segment : snake.getBody()) {
            if (segment.x == position.x && segment.y == position.y) {
                valid = false;
                break;
            }
        }
    }
}

void Food::draw() {
    float cellWidth = 2.0f / gridWidth;
    float cellHeight = 2.0f / gridHeight;

    float x = position.x * cellWidth - 1.0f;
    float y = position.y * cellHeight - 1.0f;

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x, y);
    glVertex2f(x + cellWidth, y);
    glVertex2f(x + cellWidth, y + cellHeight);
    glVertex2f(x, y + cellHeight);
    glEnd();

}

Position Food::getPosition() const {
    return position;
}
