#pragma once
#include <QMainWindow>
#include <QtWidgets/QLCDNumber>
#include "ui_control.h"

class Control : public QMainWindow
{
    Q_OBJECT
    
    QLCDNumber *lcdNumber_vol;
    QLCDNumber *lcdNumber_ch;
    const int volmax = 100;
    const int volmin = 0;
    Ui::MainWindow *win;
public:
    explicit Control(QWidget *parent);
    ~Control();
public slots:
    void push1();
    void push2();
    void push3();
    void push4();
    void push5();
    void push6();
    void push7();
    void push8();
    void push9();
    void push0();
    void vol_up();
    void vol_down();
    void ch_up();
    void ch_down();

};