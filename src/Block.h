#pragma once
#include "raylib.h"
#include "Color.h"
#include "position.h"

class Block
{
public:
    Position position;
    ColorRGB color;

    Block();
    Block(int x, int y, ColorRGB colorr);

    virtual void Draw(int cellSize, int offsetX, int offsetY);
    virtual ~Block() = default;
};
