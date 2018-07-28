#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
    Game();
    void start();
    void move();
    void PrintGame();
private:
    Board* gameBoard;
    int score;
};

#endif // GAME_H
