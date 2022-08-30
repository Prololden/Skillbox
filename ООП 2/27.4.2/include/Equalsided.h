#ifndef TASK_27_2_EQUALSIDED_H
#define TASK_27_2_EQUALSIDED_H

#include "Figure.h"

class Equalsided : public Figure {

protected:
    Equalsided(){};
    const double MINIMAL_SIDE = 0.1;
    double side {MINIMAL_SIDE};
    virtual double getHeight() = 0;
    virtual double getWidth() = 0;
    virtual void setSide(const double side) = 0;

    void printInfo() override;
    void configure() override;

public:
    double getSide() const;
};

#endif //TASK_27_2_EQUALSIDED_H