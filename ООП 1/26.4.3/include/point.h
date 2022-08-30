#ifndef TASK_26_3_POINT_H
#define TASK_26_3_POINT_H

class Point {

private:
    int x {0};
    int y {0};

public:
    Point(){};
    Point(int x, int y);


    void setX(const int newX);


    void setY(const int newY);


    void setPoint(const int newX, const int newY);


    int getX() const;


    int getY() const;


    void add(Point& p);
};

#endif //TASK_26_3_POINT_H