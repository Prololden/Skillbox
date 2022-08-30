#include <iostream>
#include <QApplication>
#include "wmain.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto window = new wMain;
    window->show();
    
    return app.exec();
}