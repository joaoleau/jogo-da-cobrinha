#include "snake.h"
#include <GLFW/glfw3.h>

Snake::Snake() : alive(true), dirX(1), dirY(0) {
    body.push_back({10, 7});
}

void Snake::move() {
    if (!alive) return;
    Position newHead = { body.front().x + dirX, body.front().y + dirY };
    body.insert(body.begin(), newHead);
    body.pop_back();
}

void Snake::grow(Position tail) {
    body.push_back(tail);
}

void Snake::draw() {
    float cellWidth = 2.0f / 20;
    float cellHeight = 2.0f / 15;

    for (const Position& segment : body) {
        float x = segment.x * cellWidth - 1.0f;
        float y = segment.y * cellHeight - 1.0f;

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + cellWidth, y);
        glVertex2f(x + cellWidth, y + cellHeight);
        glVertex2f(x, y + cellHeight);
        glEnd();

        float padding = 0.01f;
        glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x + padding, y + padding);
        glVertex2f(x + cellWidth - padding, y + padding);
        glVertex2f(x + cellWidth - padding, y + cellHeight - padding);
        glVertex2f(x + padding, y + cellHeight - padding);
        glEnd();
    }
}


void Snake::reset() {
    alive = true;
    body.clear();
    body.push_back({10, 7});
    dirX = 1;
    dirY = 0;
}

bool Snake::checkCollision() {
    Position head = body.front();

    if (head.x < 0 || head.x >= 20 || head.y < 0 || head.y >= 15) {
        alive = false;
        return true;
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].x == head.x && body[i].y == head.y) {
            alive = false;
            return true;
        }
    }

    return false;
}


bool Snake::isAlive() const {
    return alive;
}

void Snake::setDirection(int dx, int dy) {
    if (alive) {
        if (dx == -dirX && dy == -dirY) return;
        dirX = dx;
        dirY = dy;
    }
}

Position Snake::getHeadPosition() {
    return body.front();
}

const std::vector<Position>& Snake::getBody() const {
    return body;
}
