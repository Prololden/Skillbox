#include "../include/Figure.h"

Color Figure::getColor() const
{
    return this->color;
}

int Figure::getCenterX() const
{
    return this->centerX;
}

int Figure::getCenterY() const
{
    return this->centerY;
}

void Figure::setColor(const Color color)
{
    this->color = color;
}

void Figure::setCenterX(const int centerX)
{
    this->centerX = centerX;
}

void Figure::setCenterY(const int centerY)
{
    this->centerY = centerY;
}

FigureType Figure::getFigureType() const
{
    return figureType;
}

std::string Figure::getFigureTypeString()
{
    switch (figureType)
    {
        case 0:
            return "NOT DEFINED";
        case 1:
            return "TRIANGLE";
        case 2:
            return "SQUARE";
        case 3:
            return "CIRCLE";
        case 4:
            return "RECTANGLE";
        default:
            return "NOT DEFINED";
    }
}

std::string Figure::getColorString()
{
    switch (color)
    {
        case 0:
            return "NONE";
        case 1:
            return "RED";
        case 2:
            return "BLUE";
        case 3:
            return "GREEN";
        default:
            return "NONE";
    }
}

double Figure::getHeight() const
{
    return this->height;
}

double Figure::getWidth() const
{
    return this->width;
}

double Figure::getDoubleFromInput(std::string label)
{
    std::cout << label << "\n";
    std::string input;
    std::getline(std::cin, input);
    try
    {
        double result = std::stod(input);
        return result;
    } catch (std::invalid_argument& ex)
    {
        std::cerr << "Invalid argument.\n";
        return -1;
    }
}

int Figure::getIntFromInput(std::string label)
{
    std::cout << label << "\n";
    std::string input;
    std::getline(std::cin, input);
    try
    {
        int result = std::stoi(input);
        return result;
    } catch (std::invalid_argument& ex)
    {
        std::cerr << "Invalid argument.\n";
        return -1;
    }
}