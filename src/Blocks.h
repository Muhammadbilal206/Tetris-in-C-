#pragma once
#include "Block.h"

class Blocks : public Block
{
public:
    Blocks();

    void CreateTetromino();
    void Move(int dx, int dy);
    void Rotate();
    void Draw(int cellSize, int offsetX, int offsetY) override;
    Block blocks[4];
    ColorRGB color;
};
