#include "game.h"

#include <iostream>

Game::Game()
{
    gameBoard = new Board();
    score = 0;
}

void Game::start(){
    int boardDim = gameBoard->GetDimension();
    for(int row = 0; row < boardDim; ++row){
        for(int col = 0; col < boardDim; ++col){
            Tile* curTile = gameBoard->GetTile(row, col);
            if (curTile != nullptr){
                std::cout << curTile->GetValue();
            }
            else {
                std::cout << "XX";
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "The current score is " << score << std::endl;
}
