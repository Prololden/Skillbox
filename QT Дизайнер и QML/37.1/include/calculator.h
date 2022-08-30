#pragma once
#include <QMainWindow>
#include <QLineEdit>
#include <qstring.h>
#include "ui_calc.h"

enum class OPERATOR
{
    ADD,
    SUB,
    MULT,
    DIV
};

class Calcwindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit *_answer = nullptr;
    QLineEdit *_number_1 = nullptr;
    QLineEdit *_number_2 = nullptr;
    Ui::CalcWindow *calc = nullptr;
    void setupLineEdit(QLineEdit *answer, QLineEdit *number_1, QLineEdit *number_2);
    QString calculate(const OPERATOR& op);
public:
    
    explicit Calcwindow(QWidget *parent);
    ~Calcwindow();

public slots:
    void add();
    void sub();
    void mult();
    void div();
    
};


