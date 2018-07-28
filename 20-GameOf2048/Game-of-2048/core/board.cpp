#include "board.h"

Board::Board()
{
    dimension = 4;
    for(int i = 0; i < dimension; ++i){
        board.push_back(std::vector<Tile*>(4, nullptr));
    }
}

void Board::MoveTile(Direction dir){

}


Tile* Board::GetTile(int rCoord, int cCoord){
    return board[rCoord][cCoord];
}

int Board::GetDimension(){
    return dimension;
}
