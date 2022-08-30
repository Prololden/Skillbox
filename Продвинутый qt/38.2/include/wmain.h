#pragma once
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QHBoxLayout>


class wMain : public QMainWindow
{

    Q_OBJECT
public:
    wMain(QWidget *parent = nullptr);
    ~wMain();
    

private:
    QWidget *centralWidget;
    QPlainTextEdit *textedit;
    QWebEngineView *outhtml;
    QHBoxLayout *hlayot;
};