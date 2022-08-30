#include <iostream>
#include <memory>
#include <QApplication>
#include "calculator.h"


int main(int argc, char ** argv)
{
    
    QApplication app(argc, argv);
    std::unique_ptr<Calcwindow> window = std::make_unique<Calcwindow>(nullptr);
   // Calcwindow window(nullptr);
      
    return app.exec();
}