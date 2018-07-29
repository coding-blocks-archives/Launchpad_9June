#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "direction.h"

#include <vector>
#include <utility>

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
    std::pair<int, int> getPosition();
    void placeTile();
    void initialiseBoard();


};

#endif // BOARD_H
