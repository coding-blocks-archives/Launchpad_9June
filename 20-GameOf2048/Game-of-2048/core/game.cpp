#include "game.h"

#include <iostream>

Game::Game()
{
    gameBoard = new Board();
    score = 0;
}

void Game::start(){
    PrintGame();
    move();
}

void Game::PrintGame(){
    gameBoard->PrintBoard();
    std::cout << "The current score is " << score << std::endl;
}

void Game::move(){
    std::cout << "Enter you Move ";
    char choice;
    std::cin >> choice;

    switch(choice){
    case 'u':
        score += gameBoard->Move(UP);
        break;
    case 'd':
        score += gameBoard->Move(DOWN);
        break;
    case 'l':
        score += gameBoard->Move(LEFT);
        break;
    case 'r':
        score += gameBoard->Move(RIGHT);
        break;
    }
    PrintGame();
}
