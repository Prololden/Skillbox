#include "../include/window.h"

Window::Window(std::string title, int width, int height)
{
    this->title = title;
    this->width = width > 0 ? width : 0;
    this->height = height > 0 ? height : 0;
}

std::string Window::getTitle() const
{
    return title;
}

int Window::getWidth() const
{
    return this->width;
}

void Window::setWidth(const int newWidth)
{
    this->width = (newWidth < 1 ? 1 : newWidth);
}

int Window::getHeight() const
{
    return this->height;
}

void Window::setHeight(const int newHeight)
{
    this-> height = (newHeight < 1 ? 1 : newHeight);
}

Point Window::getPosition() const
{
    return this->position;
}

void Window::move(Point &point)
{
    position.add(point);
}