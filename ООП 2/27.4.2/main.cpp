#include <iostream>

#include "include/Circle.h"
#include "include/Triangle.h"
#include "include/Square.h"



void getFigureData(Figure* f)
{
    f->printInfo();
}

void configureCheckAndDelete(Figure* f)
{
    f->configure();
    getFigureData(f);
    delete f;
    f = nullptr;
}

int main() {
    std::string cmd {" "};
    do
    {
        std::cout << "Please enter the command:\n";
        std::cout << "\t - circle\n";
        std::cout << "\t - triangle\n";
        std::cout << "\t - rectangle\n";
        std::cout << "\t - square\n";
        std::cout << "\t - break (to exit)\n";

        std::getline(std::cin, cmd);

        if (cmd == "circle")
        {
            Circle* circle = new Circle();
            configureCheckAndDelete(circle);
        }
        else if (cmd == "triangle")
        {
            Triangle* triangle = new Triangle();
            configureCheckAndDelete(triangle);
        }
        else if (cmd == "rectangle")
        {
            Rectangle* rectangle = new Rectangle();
            configureCheckAndDelete(rectangle);
        }
        else if (cmd == "square")
        {
            Square* square = new Square();
            configureCheckAndDelete(square);
        }
        else if (cmd == "break")
        {
            std::cout << "Finishing the program...\n";
        }
        else
        {
            std::cout << "Unknown command. Try again.\n";
        }
    } while (cmd != "break");
    std::cout << "Program is finished.\n";

    return 0;
}