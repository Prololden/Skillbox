#ifndef TASK_27_2_SQUARE_H
#define TASK_27_2_SQUARE_H

#include "Equalsided.h"
#include "Rectangle.h"

class Square : public Equalsided {

public:
    Square();
    Square(double side);
    Square(double side, int centerX, int centerY);

    double getHeight() override;
    double getWidth() override;
    double getArea() override;
    void setSide(const double side) override;
};

#endif //TASK_27_2_SQUARE_H