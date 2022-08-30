#include "../include/Equalsided.h"

double Equalsided::getSide() const
{
    return this->side;
}

void Equalsided::printInfo()
{
    std::cout << "------------ INFO ------------\n";
    std::cout << "\t - Type: " << getFigureTypeString() << "\n";
    std::cout << "\t - Center X: " << getCenterX() << "\n";
    std::cout << "\t - Center Y: " << getCenterY() << "\n";
    std::cout << "\t - Area: " << getArea() << "\n";
    std::cout << "\t - Color: " << getColorString() << "\n";
    std::cout << "\t - Outer rect (width): " << getWidth() << "\n";
    std::cout << "\t - Outer rect (height): " << getHeight() << "\n";
    std::cout << "\t - Side: " << getSide() << "\n";
}

void Equalsided::configure()
{
    int centerX = getIntFromInput("\t - Please enter center X:");
    if (centerX == -1) return;

    int centerY = getIntFromInput("\t - Please enter center Y:");
    if (centerY == -1) return;

    int color = getIntFromInput("\t - Please enter the color (1 - RED, 2 - BLUE, 3 - GREEN):");
    if (color == -1) return;
    else if (color > 3) color = 3;
    else if (color < 0) color = 0;

    double side = getDoubleFromInput("\t - Please enter the side:");
    if (side == -1) return;

    setSide(side);
    setColor((Color) color);
    setCenterX(centerX);
    setCenterY(centerY);
}