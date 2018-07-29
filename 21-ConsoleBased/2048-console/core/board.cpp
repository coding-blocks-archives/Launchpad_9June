#include "board.h"

#include <iostream>
#include <cstdlib>

Board::Board()
{
    dimension = 4;
    for(int i = 0; i < dimension; ++i){
        board.push_back(std::vector<Tile*>(4, nullptr));
    }
    initialiseBoard();
}

void Board::initialiseBoard(){
    placeTile();
    placeTile();
}

void Board::placeTile(){
    std::pair<int, int> coord = getPosition();
    board[coord.first][coord.second] = new Tile();
}

std::pair<int, int> Board::getPosition(){
    while(true){
        int x = rand() % dimension;
        int y = rand() % dimension;
        if (board[x][y] == nullptr){
            return std::make_pair(x, y);
        }
    }
}

int Board::Move(Direction dir){
    int scoreInThisMove = 0;
    switch(dir){
    case UP:
        for(int col = 0; col < dimension; ++col){
            scoreInThisMove += moveTilesUpwards(col);
        }
        break;
    case DOWN:
        for(int col = 0; col < dimension; ++col){
            scoreInThisMove += moveTilesDownwards(col);
        }
        break;
    case LEFT:
        for(int row = 0; row < dimension; ++row){
            scoreInThisMove += moveTilesLeft(row);
        }
        break;
    case RIGHT:
        for(int row = 0; row < dimension; ++row){
            scoreInThisMove += moveTilesRight(row);
        }
        break;
    }
    return scoreInThisMove;
}

int Board::moveTilesUpwards(int col){
    int scoreInThisCol = 0;
    int destRow = 0;
    for(int srcRow = 1; srcRow < dimension; ++srcRow){
        if (board[srcRow][col] == nullptr) continue;

        if (board[destRow][col] == nullptr){
            board[destRow][col] = board[srcRow][col];
            delete board[srcRow][col];

            board[srcRow][col] = nullptr;
        }
        else {
//            dest row is NOT empty
            if (board[srcRow][col]->GetValue() ==
                board[destRow][col]->GetValue()){
                board[destRow][col]->Update();
                scoreInThisCol += board[destRow][col]->GetValue();
                delete board[srcRow][col];
                board[srcRow][col] = nullptr;
                destRow = destRow + 1;
            }
            else {
                std::swap(board[destRow + 1][col],
                          board[srcRow][col]);
                destRow = destRow + 1;
            }
        }
    }
    return scoreInThisCol;
}

int Board::moveTilesDownwards(int col){ return 0;}
int Board::moveTilesLeft(int row){return 0;}
int Board::moveTilesRight(int row){return 0;}

Tile* Board::GetTile(int rCoord, int cCoord){
    return board[rCoord][cCoord];
}

int Board::GetDimension(){
    return dimension;
}



// PRINT METHODS
void Board::PrintBoard(){
    int boardDim = dimension;
    for(int row = 0; row < boardDim; ++row){
        for(int col = 0; col < boardDim; ++col){
            Tile* curTile = this->GetTile(row, col);
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
}
