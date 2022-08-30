#include "../include/Square.h"

Square::Square()
{
    this->figureType = SQUARE;
}

Square::Square(double side) : Square()
{
    this->side = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->width = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->height = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
}

Square::Square(double side, int centerX, int centerY) : Square(side)
{
    this->centerX = centerX;
    this->centerY = centerY;
}

double Square::getHeight()
{
    return this->height;
}

double Square::getWidth()
{
    return this->width;
}

double Square::getArea()
{
    return (width * height);
}

void Square::setSide(const double side)
{
    this->side = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->width = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->height = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
}