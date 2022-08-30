#include "../include/point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setX(const int newX)
{
    this->x = newX;
}

void Point::setY(const int newY)
{
    this->y = newY;
}

void Point::setPoint(const int newX, const int newY)
{
    this->x = newX;
    this->y = newY;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::add(Point &p)
{
    this->x += p.x;
    this->y += p.y;
}