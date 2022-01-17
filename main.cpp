#include <iostream>
#include "display.h"
#include "snake.h"
#include <stdlib.h>
#include <unistd.h>
#include "food.h"

int main() {
    Display display = Display(40, 40);
    Snake snake = Snake(10, 10);
    Food food = Food();
    food.newPosition();
    while(true) {
        snake.steer();
        snake.update();
        display.reset();

        display.draw('+', food.x, food.y);
        for(int i = 0; i < snake.bodyPositions.size(); i++) {
            display.draw('o', snake.bodyPositions[i][0], snake.bodyPositions[i][1]);
        }
        display.update();

        if(display.snakeOutside(snake) || snake.selfCollision())
            break;

        if(food.eaten(snake)) {
            food.newPosition();
            snake.addBodyPart();
        }
        usleep(200000);
    }
    display.close();
    system("stty sane");
    std::cout << "GAME OVER" << std::endl;
    return 0;
}