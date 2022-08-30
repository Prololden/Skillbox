#ifndef TASK_26_3_MONITOR_H
#define TASK_26_3_MONITOR_H

#include <iostream>
#include "window.h"
#include "point.h"

class Monitor {

private:
    int width {0};
    int height{0};
    Window* window{nullptr};
public:
    Monitor(){};
    Monitor(int w, int h);
    ~Monitor();


    void setWidth(const int newWidth);


    void setHeight(const int newHeight);


    int getWidth() const;


    int getHeight() const;


    void display() const;


    void createWindow(std::string title, int width, int height);


    Window* getWindow();


    void moveWindow(Point& p);
};

#endif //TASK_26_3_MONITOR_H