#include "Gridformation.h"
#include "raylib.h"

// Gridformation class constructor
Gridformation::Gridformation()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = ColorRGB(0, 0, 0, 255);
        }
}

//Checks if the cell is empty
bool Gridformation::IsCellEmpty(int x, int y)
{
    return (x >= 0 && x < 10 && y >= 0 && y < 20 && cells[y][x].r == 0 && cells[y][x].g == 0 && cells[y][x].b == 0);
}

//Checks if the block is valid for the tetrimino
bool Gridformation::IsBlockValid(Blocks& tetromino)
{
    for (int i = 0; i < 4; i++)
    {
        int x = tetromino.blocks[i].position.x;
        int y = tetromino.blocks[i].position.y;
        if (x < 0 || x >= 10 || y < 0 || y >= 20 || !IsCellEmpty(x, y))
        {
            return false;
        }
    }
    return true;
}


//This function locks the blocks in the grid
void Gridformation::LockBlocks(Blocks& tetromino)
{
    for (int i = 0; i < 4; i++)
    {
        int x = tetromino.blocks[i].position.x;
        int y = tetromino.blocks[i].position.y;
        if (y >= 0 && y < 20 && x >= 0 && x < 10)
        {
            cells[y][x] = tetromino.color;
        }
    }
}

//This function clears the row after a line is completed
void Gridformation::ClearRows(int& score, int& lines)
{
    for (int i = 20 - 1; i >= 0; i--)
    {
        bool full = true;
        for (int j = 0; j < 10; j++)
        {
            if (cells[i][j].r == 0 && cells[i][j].g == 0 && cells[i][j].b == 0)
            {
                full = false;
            }
        }
        if (full)
        {
            for (int k = i; k > 0; k--)
            {
                for (int j = 0; j < 10; j++)
                {
                    cells[k][j] = cells[k - 1][j];
                }
            }
            for (int j = 0; j < 10; j++)
            {
                cells[0][j] = ColorRGB(0, 0, 0, 255);
            }
            score += 100;
            lines = lines + 1;
            i++;
        }
    }
}

//This function draws the grid
void Gridformation::Draw(int cellSize, int offsetX, int offsetY)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            DrawRectangleLines(offsetX + j * cellSize,offsetY + i * cellSize,cellSize, cellSize, BLACK);
            if (!(cells[i][j].r == 0 && cells[i][j].g == 0 && cells[i][j].b == 0))
            {
                DrawRectangle(offsetX + j * cellSize,offsetY + i * cellSize,cellSize - 1, cellSize - 1, cells[i][j].GetRaylibColor());
            }
        }
    }
}