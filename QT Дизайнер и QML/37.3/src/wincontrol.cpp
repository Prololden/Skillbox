#include "wincontrol.h"


Control::Control(QWidget *parent) : QMainWindow(parent), win(nullptr)
{
    win = new Ui::MainWindow;
    win->setupUi(this);
    lcdNumber_ch = win->lcdNumber_ch;
    lcdNumber_vol = win->lcdNumber_vol;
    show();
}

Control::~Control()
{
    delete win;
}

void Control::push0()
{
    lcdNumber_ch->display(0);
}

void Control::push1()
{
    lcdNumber_ch->display(1);
}

void Control::push2()
{
    lcdNumber_ch->display(2);
}

void Control::push3()
{
    lcdNumber_ch->display(3);
}

void Control::push4()
{
    lcdNumber_ch->display(4);
}

void Control::push5()
{
    lcdNumber_ch->display(5);
}

void Control::push6()
{
    lcdNumber_ch->display(6);
}

void Control::push7()
{
    lcdNumber_ch->display(7);
}

void Control::push8()
{
    lcdNumber_ch->display(8);
}

void Control::push9()
{
    lcdNumber_ch->display(9);
}

void Control::vol_up()
{
    int vol = lcdNumber_vol->intValue();
    if(vol<volmax)
    {
        vol+=10;
        lcdNumber_vol->display(vol);
    }
}

void Control::vol_down()
{
    int vol = lcdNumber_vol->intValue();
    if(vol>volmin)
    {
        vol-=10;
        lcdNumber_vol->display(vol);
    }
}

void Control::ch_up()
{
    int ch = lcdNumber_ch->intValue();
    ++ch;
    lcdNumber_ch->display(ch);
    
}

void Control::ch_down()
{
    int ch = lcdNumber_ch->intValue();
    if(ch != 0)
    {
        --ch;
        lcdNumber_ch->display(ch);
    }
    
}