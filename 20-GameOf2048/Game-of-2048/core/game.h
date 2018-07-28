#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
    Game();
    void start();

private:
    Board* gameBoard;
    int score;
};

#endif // GAME_H
