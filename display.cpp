#include <iostream>
#include <string>
#include "display.h"
#include "curses.h"

using namespace std;

Display::Display(int width, int height) : width(width), height(height) {
    std::vector<char> emptyTableRow(width, ' ');
    for (int y = 0; y < height; y++)
        this->table.push_back(emptyTableRow);
    
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    this->win = newwin(width, height, 0, 0);
}

Display::~Display() {}

void Display::draw(char symbol, int x, int y) {
    this->table[y][x] = symbol;
}

void Display::update() {
    wclear(this->win);
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            waddch(this->win, (chtype)(unsigned char)this->table[y][x]);
        }
    }
    wrefresh(this->win);
}

void Display::reset() {
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            if(this->onEdge(x, y))
                this->table[y][x] = '#';
            else
                this->table[y][x] = ' ';
        }
    }
}

bool Display::snakeOutside(Snake snake) {
    for(int i=0; i < snake.bodyPositions.size(); i++) {
        int x = snake.bodyPositions[i][0];
        int y = snake.bodyPositions[i][1];
        if(x <= 1 || y <= 1 || x >= (this->width - 2) || y >= (this->height - 2))
            return true;
    }
    return false;
}

bool Display::onEdge(int x, int y) {
    bool leftVertical = x == 1 && 0 < y && y < (this->width - 2);
    bool rightVertical = x == (this->width - 2) && 0 < y && y < (this->width - 2);
    bool upperHorizontal = y == 1 && 0 < x && x < (this->width - 2);
    bool lowerHorizontal = y == (this->height - 2) && 0 < x && x < (this->width - 2);
    if(leftVertical || rightVertical || upperHorizontal || lowerHorizontal)
        return true;
    else
        return false;
}

void Display::close() {
    wclear(this->win);
    wrefresh(this->win);
    delwin(this->win);
}