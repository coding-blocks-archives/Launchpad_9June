#include "tile.h"

Tile::Tile()
{
    value = 2;
}

void Tile::Update(){
    value = value * 2;
}

int Tile::GetValue(){
    return value;
}
