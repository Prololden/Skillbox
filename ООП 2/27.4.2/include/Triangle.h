#ifndef TASK_27_2_TRIANGLE_H
#define TASK_27_2_TRIANGLE_H

#include "Equalsided.h"

class Triangle : public Equalsided {

public:
    Triangle();
    Triangle(double side);
    Triangle(double side, int centerX, int centerY);

    double getHeight() override;
    double getArea() override;
    double getWidth() override;
    void setSide(const double side) override;
};

#endif //TASK_27_2_TRIANGLE_H