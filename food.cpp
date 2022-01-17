#include "food.h"
#include <stdlib.h>

Food::Food() {};
Food::~Food() {};

void Food::newPosition() {
    this->x = rand() % 35 + 2;
    this->y = rand() % 35 + 2;

    this->x = (this->x % 2 == 0) ? this->x : this->x + 1;
}

bool Food::eaten(Snake snake) {
    if(snake.bodyPositions[0][0] == this->x && snake.bodyPositions[0][1] == this->y)
        return true;
    else
        return false;
}