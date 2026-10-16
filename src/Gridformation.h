#ifndef GRID_H
#define GRID_H

#include "Color.h"
#include "Blocks.h"

class Gridformation
{
public:
    ColorRGB cells[20][10];

    Gridformation();
    bool IsCellEmpty(int x, int y);
    bool IsBlockValid(Blocks& tetromino);
    void LockBlocks(Blocks& tetromino);
    void ClearRows(int& score, int& lines);
    void Draw(int cellSize, int offsetX, int offsetY);
};

#endif