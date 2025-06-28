#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <GLFW/glfw3.h>

struct Position { int x, y; }; 

class Snake {
    bool alive;
public:
    Snake();

    void move();
    void grow(Position tail);
    void draw();
    void reset();
    bool checkCollision();
    bool isAlive() const;
    void setDirection(int dx, int dy);

    Position getHeadPosition();
    const std::vector<Position>& getBody() const;

private:
    std::vector<Position> body;
    int dirX, dirY;
};

#endif
