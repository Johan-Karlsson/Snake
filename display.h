#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <string>
#include <vector>
#include "curses.h"
#include "snake.h"

/*
*
* Coordinate system:
*   -----> x
*   |
*   |
*   ˇy
*
*/
class Display {
    private:
        const int width;
        const int height;
        WINDOW* win;
        std::vector<std::vector<char> > table;

    public:
        Display(int width, int height);
        ~Display();

        void draw(char symbol, int x, int y);
        void update();
        void reset();
        bool onEdge(int x, int y);
        bool snakeOutside(Snake snake);
        void close();
};

#endif