#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

class Food {
public:
    Food(int gridWidth, int gridHeight);

    void spawn(const Snake& snake);
    void draw();
    Position getPosition() const;

private:
    Position position;
    int gridWidth;
    int gridHeight;
};

#endif
