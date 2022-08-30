#include <iostream>
#include <QApplication>
#include "wmain.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    WMain win;
    win.show();

    return app.exec();
}