#include "../include/Circle.h"

Circle::Circle()
{
    this->figureType = CIRCLE;
    this->radius = MINIMAL_RADIUS;
    this->width = 2 * radius;
    this->height = 2 * radius;
}

Circle::Circle(double radius) : Circle()
{
    this->radius = (radius < MINIMAL_RADIUS ? MINIMAL_RADIUS : radius);
    this->width = 2 * radius;
    this->height = 2 * radius;
}

Circle::Circle(double radius, int centerX, int centerY) : Circle(radius)
{
    this->centerX = centerX;
    this->centerY = centerY;
}

double Circle::getRadius() const
{
    return this->radius;
}

double Circle::getArea()
{
    return (M_PI * std::pow(radius, 2));
}

void Circle::setRadius(const double radius)
{
    this->radius = (radius < MINIMAL_RADIUS ? MINIMAL_RADIUS : radius);
    this->width = 2 * radius;
    this->height = 2 * radius;
}

void Circle::printInfo()
{
    std::cout << "------------ INFO ------------\n";
    std::cout << "\t - Type: " << getFigureTypeString() << "\n";
    std::cout << "\t - Center X: " << getCenterX() << "\n";
    std::cout << "\t - Center Y: " << getCenterY() << "\n";
    std::cout << "\t - Area: " << getArea() << "\n";
    std::cout << "\t - Color: " << getColorString() << "\n";
    std::cout << "\t - Outer rect (width): " << this->width << "\n";
    std::cout << "\t - Outer rect (height): " << this->height << "\n";
    std::cout << "\t - Radius: " << getRadius() << "\n";
}

void Circle::configure()
{
    int centerX = getIntFromInput("\t - Please enter center X:");
    if (centerX == -1) return;

    int centerY = getIntFromInput("\t - Please enter center Y:");
    if (centerY == -1) return;

    int color = getIntFromInput("\t - Please enter the color (1 - RED, 2 - BLUE, 3 - GREEN):");
    if (color == -1) return;
    else if (color > 3) color = 3;
    else if (color < 0) color = 0;

    double r = getDoubleFromInput("\t - Please enter the radius:");
    if (r == -1) return;

    setRadius(r);
    setColor((Color) color);
    setCenterX(centerX);
    setCenterY(centerY);
}