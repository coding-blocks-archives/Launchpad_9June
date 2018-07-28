#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "direction.h"

#include <vector>

class Board
{
public:
    Board();
    int Move(Direction dir);
    Tile* GetTile(int rCoord, int cCoord);
    int GetDimension();

    // PRINT METHODS
    void PrintBoard();

private:
    typedef std::vector<std::vector< Tile*> > vectorOfTiles;
    vectorOfTiles board;
    int dimension;

    // PRIVATE METHODS
    int moveTilesUpwards(int col);
    int moveTilesDownwards(int col);
    int moveTilesLeft(int row);
    int moveTilesRight(int row);
};

#endif // BOARD_H
