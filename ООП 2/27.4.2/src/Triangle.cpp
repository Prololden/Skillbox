#include "../include/Triangle.h"

Triangle::Triangle()
{
    this->figureType = TRIANGLE;
    this->side = MINIMAL_SIDE;
}

Triangle::Triangle(double side) : Triangle()
{
    this->side = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->width = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->height = side * std::pow(3,0.5) / 2 > MINIMAL_SIDE ?
                   side * std::pow(3,0.5) / 2 : MINIMAL_SIDE;
}

Triangle::Triangle(double side, int centerX, int centerY) : Triangle(side)
{
    this->centerX = centerX;
    this->centerY = centerY;
}

double Triangle::getArea()
{
    return (std::pow(side, 2) * std::pow(3, 0.5) / 4);
}

double Triangle::getHeight()
{
    return this->height;
}

double Triangle::getWidth()
{
    return this->width;
}

void Triangle::setSide(const double side)
{
    this->side = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->width = (side < MINIMAL_SIDE ? MINIMAL_SIDE : side);
    this->height = side * std::pow(3,0.5) / 2 > MINIMAL_SIDE ?
                   side * std::pow(3,0.5) / 2 : MINIMAL_SIDE;
}