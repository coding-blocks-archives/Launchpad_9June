#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "direction.h"

#include <vector>

class Board
{
public:
    Board();
    void MoveTile(Direction dir);
    Tile* GetTile(int rCoord, int cCoord);
    int GetDimension();
private:
    typedef std::vector<std::vector< Tile*> > vectorOfTiles;

    vectorOfTiles board;
    int dimension;

};

#endif // BOARD_H
