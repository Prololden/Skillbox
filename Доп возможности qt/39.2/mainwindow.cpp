#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QRegularExpression"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->regularLine, &QLineEdit::textEdited, [this](QString currentText)
    {
        if (currentText.length() < 12)
            setIncompleteLabelRegular();
        else
        {
            QRegularExpression exp ("^\\+\\d{11}");
            if (exp.match(currentText).hasMatch())
                setOkLabelRegular();
            else
                setNokLabelRegular();
        }
    });
    connect(ui->maskedLine, &QLineEdit::textEdited, [this](QString currentText)
    {
        if (currentText.length() < 18)
            setIncompleteLabelMasked();
        else
            setOkLabelMasked();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabelRegular()
{
    ui->labelRegularStatus->setText("Ok");
    ui->labelRegularStatus->setStyleSheet("QLabel {color: green;}");
}

void MainWindow::setNokLabelRegular()
{
    ui->labelRegularStatus->setText("Nok");
    ui->labelRegularStatus->setStyleSheet("QLabel {color: red;}");
}

void MainWindow::setIncompleteLabelRegular()
{
    ui->labelRegularStatus->setText("Please enter + and all 11 digits.");
    ui->labelRegularStatus->setStyleSheet("QLabel {color: lightblue;}");
}

void MainWindow::setOkLabelMasked()
{
    ui->labelMaskedStatus->setText("Ok");
    ui->labelMaskedStatus->setStyleSheet("QLabel {color: green;}");
}

void MainWindow::setNokLabelMasked()
{
    ui->labelMaskedStatus->setText("Nok");
    ui->labelMaskedStatus->setStyleSheet("QLabel {color: red;}");
}

void MainWindow::setIncompleteLabelMasked()
{
    ui->labelMaskedStatus->setText("Please enter all 10 digits.");
    ui->labelMaskedStatus->setStyleSheet("QLabel {color: lightblue;}");
}
