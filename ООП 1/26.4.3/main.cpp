#include <iostream>
#include "include/monitor.h"

int getIntFromCin(std::string message)
{
    std::cout << message;
    std::string buff;
    std::getline(std::cin, buff);
    int value {0};
    try
    {
        value = std::stoi(buff);
    } catch (std::invalid_argument& exp) {
        std::cerr << "Invalid argument.\n";
    }
    return value;
}

int main()
{
    std::cout << "Window simulation is started.\n";
    std::cout << "\t - Initialization.\n";
    Monitor monitor(80, 50);
    monitor.createWindow("Test window", 10, 10);
    std::cout << "\t - Ready.\n";
    std::cout << "-----------------\n";

    std::string cmd;
    do
    {
        std::cout << "Please enter the command (move, resize, display, close): ";
        std::getline(std::cin, cmd);
        if (cmd == "move")
        {
            std::cout << "\t - Current window position is " <<
                      monitor.getWindow()->getPosition().getX() << " : " <<
                      monitor.getWindow()->getPosition().getY() << "\n";

            int vectorX = getIntFromCin("Please set X value for move vector: ");
            int vectorY = getIntFromCin("Please set Y value for move vector: ");
            std::cout << "\t - Move vector is " << vectorX << " : " << vectorY << "\n";

            Point *p = new Point (vectorX, vectorY);
            monitor.moveWindow(*p);
            delete p;
            p = nullptr;

            std::cout << "\t - New window position is " <<
                      monitor.getWindow()->getPosition().getX() << " : " <<
                      monitor.getWindow()->getPosition().getY() << "\n";

        }
        else if (cmd == "resize")
        {
            std::cout << "\t - Current window size is " <<
                      monitor.getWindow()->getWidth() << " x " <<
                      monitor.getWindow()->getHeight() << "\n";

            int newWidth = getIntFromCin("Please enter new width: ");
            int newHeight = getIntFromCin("Please enter new height: ");
            std::cout << "\t - Your input is " << newWidth << " x " << newHeight << "\n";

            monitor.getWindow()->setWidth(newWidth);
            monitor.getWindow()->setHeight(newHeight);
            std::cout << "\t - New window size is " <<
                      monitor.getWindow()->getWidth() << " x " <<
                      monitor.getWindow()->getHeight() << "\n";
        }
        else if (cmd == "display")
        {
            monitor.display();
        }

    } while (cmd != "close");

    std::cout << "\t - Window is closed.\n";
    std::cout << "\t - Program is finished.\n";

    return 0;
}