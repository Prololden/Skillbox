#include <iostream>
#include <QApplication>
#include "wincontrol.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    std::unique_ptr<Control>  control  = std::make_unique<Control>(nullptr);
    control->setFixedSize(240, 680);

    return app.exec();
}