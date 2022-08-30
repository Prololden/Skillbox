#include "calculator.h"



void Calcwindow::setupLineEdit(QLineEdit *answer, QLineEdit *number_1, QLineEdit *number_2)
{
    _answer = answer;
    _number_1 = number_1;
    _number_2 = number_2;
}

Calcwindow::Calcwindow(QWidget *parent) : QMainWindow(parent)
{
    calc = new Ui::CalcWindow;
    calc->setupUi(this);
    setupLineEdit(calc->answer, calc->number_1, calc->number_2);
    show();
}

Calcwindow::~Calcwindow()
{
    delete calc;
}

QString Calcwindow::calculate(const OPERATOR& op)
{
    bool ok_num1;
    qlonglong num1 = _number_1->text().toLongLong(&ok_num1);
    bool ok_num2;
    qlonglong num2 = _number_2->text().toLongLong(&ok_num2);
    QString answer;

    if(ok_num1 && ok_num2)
    {
        switch (op)
        {
        case OPERATOR::ADD :
            answer =  QString::number(num1 + num2);
            break;
        case OPERATOR::SUB :
            answer =  QString::number(num1 - num2);
            break;
        case OPERATOR::MULT :
            answer =  QString::number(num1 * num2);
            break;
        case OPERATOR::DIV :
            if(num2 == 0)
            {
                answer = "Error";
                break;
            }
            answer =  QString::number(num1 / num2);
            break;
        
        default:
            answer = "0";
            break;
        }
        
    }
    else
    {
        answer = "Error";
    }  
    return answer;
}

void Calcwindow::add()
{
     _answer->setText("= " + calculate(OPERATOR::ADD));
}

void Calcwindow::sub()
{
    _answer->setText("= " + calculate(OPERATOR::SUB));
}

void Calcwindow::mult()
{
    _answer->setText("= " + calculate(OPERATOR::MULT));
}

void Calcwindow::div()
{
    _answer->setText("= " + calculate(OPERATOR::DIV));
}