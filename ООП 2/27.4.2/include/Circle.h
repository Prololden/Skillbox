#ifndef TASK_27_2_CIRCLE_H
#define TASK_27_2_CIRCLE_H

#include "Figure.h"

class Circle : public Figure {

private:
    const double MINIMAL_RADIUS = 0.1;
    double radius;

public:
    Circle();
    Circle(double radius);
    Circle(double radius, int centerX, int centerY);

    double getArea() override;
    void printInfo() override;
    void configure() override;

    double getRadius() const;
    void setRadius(const double radius);
};

#endif //TASK_27_2_CIRCLE_H