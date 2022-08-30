#ifndef TASK_26_3_WINDOW_H
#define TASK_26_3_WINDOW_H

#include <iostream>
#include "point.h"

class Window {

private:
    Point position{Point()};
    int width{0};
    int height{0};
    std::string title{"No name"};

public:
    Window(){};
    Window(std::string title, int width, int height);


    std::string getTitle() const;


    int getWidth() const;


    void setWidth(const int newWidth);


    int getHeight() const;


    void setHeight(const int newHeight);


    Point getPosition() const;


    void move(Point& point);
};

#endif //TASK_26_3_WINDOW_H