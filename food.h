#ifndef _FOOD_H_
#define _FOOD_H_
#include "snake.h"

class Food {
    public:
        int x;
        int y;
        Food();
        ~Food();
        void newPosition();
        bool eaten(Snake snake);
};
#endif