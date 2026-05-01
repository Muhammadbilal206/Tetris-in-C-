#ifndef COLOR_H
#define COLOR_H

#include "raylib.h"

//Initializing colors
const Color DARK_RED      = { 64,  0,  0, 255 };
const Color DARK_GREEN    = {  0, 64,  0, 255 };
const Color DARK_BLUE     = {  0,  9, 43, 255 };
const Color DARK_PURPLE   = { 48,  0, 48, 255 };
const Color DARK_YELLOW   = { 64, 64,  0, 255 };
const Color DARK_PEACH    = {128, 90, 70, 255 };
const Color DARK_BROWN    = { 64, 32,  0, 255 };

class ColorRGB
{
public:
    int r, g, b, a;

    ColorRGB();
    ColorRGB(int r, int g, int b, int a = 255);
    Color GetRaylibColor() const;
};

#endif
