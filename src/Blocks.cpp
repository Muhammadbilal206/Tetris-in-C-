#include "Blocks.h"
#include <cstdlib>

Blocks::Blocks() {}

//Function to create a new random tetromino
void Blocks::CreateTetromino()
{
    int shape = rand() % 7;
    color = ColorRGB();

    switch (shape)
    {
    case 0: // I
        blocks[0] = Block(3, 0, color);
        blocks[1] = Block(4, 0, color);
        blocks[2] = Block(5, 0, color);
        blocks[3] = Block(6, 0, color);
        break;
    case 1: // O
        blocks[0] = Block(4, 0, color);
        blocks[1] = Block(5, 0, color);
        blocks[2] = Block(4, 1, color);
        blocks[3] = Block(5, 1, color);
        break;
    case 2: // T
        blocks[0] = Block(3, 0, color);
        blocks[1] = Block(4, 0, color);
        blocks[2] = Block(5, 0, color);
        blocks[3] = Block(4, 1, color);
        break;
    case 3: // S
        blocks[0] = Block(4, 0, color);
        blocks[1] = Block(5, 0, color);
        blocks[2] = Block(3, 1, color);
        blocks[3] = Block(4, 1, color);
        break;
    case 4: // Z
        blocks[0] = Block(3, 0, color);
        blocks[1] = Block(4, 0, color);
        blocks[2] = Block(4, 1, color);
        blocks[3] = Block(5, 1, color);
        break;
    case 5: // J
        blocks[0] = Block(3, 0, color);
        blocks[1] = Block(3, 1, color);
        blocks[2] = Block(4, 1, color);
        blocks[3] = Block(5, 1, color);
        break;
    case 6: // L
        blocks[0] = Block(5, 0, color);
        blocks[1] = Block(3, 1, color);
        blocks[2] = Block(4, 1, color);
        blocks[3] = Block(5, 1, color);
        break;
    }
}

//Function to move the tetromino
void Blocks::Move(int dx, int dy)
{
    for (int i = 0; i < 4; i++)
    {
        blocks[i].position.x += dx;
        blocks[i].position.y += dy;
    }
}

//Rotate the tetromino
void Blocks::Rotate()
{
    Position center = blocks[1].position;
    for (int i = 0; i < 4; i++)
    {
        int x = blocks[i].position.y - center.y;
        int y = blocks[i].position.x - center.x;
        blocks[i].position.x = center.x - x;
        blocks[i].position.y = center.y + y;
    }
}

//Draw it
void Blocks::Draw(int cellSize, int offsetX, int offsetY)
{
    for (int i = 0; i < 4; i++)
    {
        blocks[i].Draw(cellSize, offsetX, offsetY);
    }
}
