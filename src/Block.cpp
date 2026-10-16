#include "Block.h"
#include "raylib.h"

Block::Block() {}

//Overloaded constructor for Block class
Block::Block(int x_i, int y_i, ColorRGB colorr):position(x_i,y_i)
{
    color = colorr;
}

//Function to draw the block
void Block::Draw(int cellSize, int offsetX, int offsetY)
{
    DrawRectangle(offsetX + position.x * cellSize,offsetY + position.y * cellSize, cellSize - 1, cellSize - 1, color.GetRaylibColor());
}
    