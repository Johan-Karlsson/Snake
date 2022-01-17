#include "snake.h"
#include "curses.h"
#include <iostream>

Snake::Snake(int x, int y) {
    this-> bodyPositions.push_back(std::vector<int>{x, y});
};

Snake::~Snake() {};

void Snake::steer() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            this->direction = (this->direction == DOWN) ? DOWN : UP;
            break;
        case KEY_DOWN:
            this->direction = (this->direction == UP) ? UP : DOWN;
            break;
        case KEY_LEFT:
            this->direction = (this->direction == RIGHT) ? RIGHT : LEFT;
            break;
        case KEY_RIGHT:
            this->direction = (this->direction == LEFT) ? LEFT : RIGHT;
            break;
    }
};

void Snake::update() {

    for(int i=this->bodyPositions.size()-1; i>0; i--) {
        this->bodyPositions[i][0] = this->bodyPositions[i-1][0];
        this->bodyPositions[i][1] = this->bodyPositions[i-1][1];
    }

    switch (this->direction) {
        case UP:
            this->bodyPositions[0][1] -= 1;
            break;
        case DOWN:
            this->bodyPositions[0][1] += 1;
            break;
        case LEFT:
            this->bodyPositions[0][0] -= 2;
            break;
        case RIGHT:
            this->bodyPositions[0][0] += 2;
            break;
    }
}

void Snake::addBodyPart() {
    this->bodyPositions.push_back(std::vector<int>(2));
}