#include "../include/monitor.h"

Monitor::Monitor(int w, int h)
{
    this->width = (w < 1 ? 1 : w);
    this->height = (h < 1 ? 1 : h);
}

void Monitor::setWidth(const int newWidth)
{
    if (newWidth <= 0)
    {
        std::cerr << "Bad width (width <= 0)\n";
    }
    else
    {
        width = newWidth;
    }
}

void Monitor::setHeight(const int newHeight)
{
    if (newHeight <= 0)
    {
        std::cerr << "Bad height (height <= 0)\n";
    }
    else
    {
        height = newHeight;
    }
}

int Monitor::getWidth() const
{
    return width;
}

int Monitor::getHeight() const
{
    return height;
}

void Monitor::display() const
{
    if (window != nullptr)
    {
        int windowStartX = window->getPosition().getX();
        int windowEndX = windowStartX + window->getWidth();
        int windowStartY = window->getPosition().getY();
        int windowEndY = windowStartY + window->getHeight();
        std::cout << "----------------------------------------\n";

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (i >= windowStartY && i < windowEndY && j >= windowStartX && j < windowEndX)
                {
                    std::cout << 1;
                }
                else
                {
                    std::cout << 0;
                }
            }
            std::cout << "\n";
        }
        std::cout << "----------------------------------------\n";
    }
    else
    {
        std::cerr << "There are no windows. Create at least one to use display cmd.\n";
    }
}

void Monitor::createWindow(std::string title, int width, int height)
{
    window = new Window("Test window", width, height);
    std::cout << "\t - Window \"" << window->getTitle() << "\" is created.\n";
}

Monitor::~Monitor()
{
    if (window != nullptr)
    {
        delete window;
        window = nullptr;
    }
}

Window *Monitor::getWindow()
{
    return window;
}

void Monitor::moveWindow(Point& p)
{
    if (window == nullptr)
    {
        std::cerr << "Please create window at first.\n";
        return;
    }
    else
    {
        if ((window->getPosition().getX() + p.getX()) >= width ||
            (window->getPosition().getY() + p.getY()) >= height ||
            (window->getPosition().getX() + p.getX()) < 0 ||
            (window->getPosition().getY() + p.getY()) < 0)
        {
            std::cerr << "New window position is out of the monitor dimensions.\n";
        }
        else
        {
            window->move(p);
        }
    }

}