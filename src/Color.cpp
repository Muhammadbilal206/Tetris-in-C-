#include "Color.h"
#include <cstdlib>

// Creating Array of dark colors
static const Color darkColors[] = {DARK_RED, DARK_GREEN, DARK_BLUE, DARK_PURPLE, DARK_YELLOW, DARK_PEACH};
static const int numDarkColors = sizeof(darkColors) / sizeof(darkColors[0]);

// Constructor for ColorRGB class
ColorRGB::ColorRGB()
{
    int randomnum = rand() % numDarkColors;
    r = darkColors[randomnum].r;
    g = darkColors[randomnum].g;
    b = darkColors[randomnum].b;
    a = darkColors[randomnum].a;
}

//Overloaded constructor for ColorRGB class
ColorRGB::ColorRGB(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;   
}

//Returns the color for tetrimino
Color ColorRGB::GetRaylibColor() const
{ 
    return { (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a };
}