#include "../include/Rectangle.h"

Rectangle::Rectangle()
{
    this->figureType = RECTANGLE;
    this->width = MINIMAL_SIDE;
    this->height = MINIMAL_SIDE;
}

Rectangle::Rectangle(double width, double height) : Rectangle()
{
    this->width = (width < MINIMAL_SIDE ? MINIMAL_SIDE : width);
    this->height = (height < MINIMAL_SIDE ? MINIMAL_SIDE : height);
}

Rectangle::Rectangle(double width, double height, int centerX, int centerY) : Rectangle(width, height)
{
    this->centerX = centerX;
    this->centerY = centerY;
}

double Rectangle::getArea()
{
    return (width * height);
}

void Rectangle::setWidth(const double width)
{
    this->width = (width < MINIMAL_SIDE ? MINIMAL_SIDE : width);
}

void Rectangle::setHeight(const double height)
{
    this->height = (height < MINIMAL_SIDE ? MINIMAL_SIDE : height);
}

void Rectangle::configure()
{
    int centerX = getIntFromInput("\t - Please enter center X:");
    if (centerX == -1) return;

    int centerY = getIntFromInput("\t - Please enter center Y:");
    if (centerY == -1) return;

    int color = getIntFromInput("\t - Please enter the color (1 - RED, 2 - BLUE, 3 - GREEN):");
    if (color == -1) return;
    else if (color > 3) color = 3;
    else if (color < 0) color = 0;

    double width = getDoubleFromInput("\t - Please enter the width:");
    if (width == -1) return;

    double height = getDoubleFromInput("\t - Please enter the height:");
    if (height == -1) return;

    setWidth(width);
    setHeight(height);
    setColor((Color) color);
    setCenterX(centerX);
    setCenterY(centerY);
}

void Rectangle::printInfo()
{
    std::cout << "------------ INFO ------------\n";
    std::cout << "\t - Type: " << getFigureTypeString() << "\n";
    std::cout << "\t - Center X: " << getCenterX() << "\n";
    std::cout << "\t - Center Y: " << getCenterY() << "\n";
    std::cout << "\t - Area: " << getArea() << "\n";
    std::cout << "\t - Color: " << getColorString() << "\n";
    std::cout << "\t - Outer rect (width): " << this->width << "\n";
    std::cout << "\t - Outer rect (height): " << this->height << "\n";
}