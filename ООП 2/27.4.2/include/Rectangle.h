#ifndef TASK_27_2_RECTANGLE_H
#define TASK_27_2_RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure{
protected:
    const double MINIMAL_SIDE = 0.1;
    double width {MINIMAL_SIDE};
    double height {MINIMAL_SIDE};

public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(double width, double height, int centerX, int centerY);

    double getArea() override;
    void configure() override;
    void printInfo() override;

    void setWidth(const double width);
    void setHeight(const double height);
};

#endif //TASK_27_2_RECTANGLE_H