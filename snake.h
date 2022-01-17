#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <vector>

class Snake {
    private:
        enum Direction {LEFT, RIGHT, UP, DOWN};
        Direction direction = UP;
    public:
        std::vector<std::vector<int> > bodyPositions;
        Snake(int x, int y);
        ~Snake();

        void steer();

        void update();

        void addBodyPart();

        bool selfCollision() {
            for (int i = 0; i < this->bodyPositions.size(); i++) {
                for (int j = 0; j < this->bodyPositions.size(); j++) {
                    if(i != j && this->bodyPositions[i][0] == this->bodyPositions[j][0] && this->bodyPositions[i][1] == this->bodyPositions[j][1]) 
                        return true;
                }
            }
            return false;
        }
};

#endif