#pragma once
#include "Game.h"

class Shapes {
public:
    static void drawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius);
    static void drawCircleB(SDL_Renderer *renderer, int centerX, int centerY, int radius);
    static void drawPentagon(SDL_Renderer *renderer, int centerX, int centerY, int side);
    static void drawHexagon(SDL_Renderer *renderer, int centerX, int centerY, int side);
    static void drawRegularPolygon(SDL_Renderer *renderer, int centerX, int centerY, int num_sides, int radius);
    static void drawEllipse(SDL_Renderer *renderer, int xc, int yc, int rx, int ry);
    static void drawRectangleWithBorder(SDL_Renderer *renderer, int posX, int posY, int width, int height, int borderSize);
};