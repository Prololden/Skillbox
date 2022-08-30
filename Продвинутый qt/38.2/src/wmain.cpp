#include "wmain.h"
#include <iostream>
#include <QTextDocument>

wMain::wMain(QWidget *parent) : QMainWindow(parent)
{
    resize(1000, 1000);
    centralWidget = new QWidget(this);
    
    
    hlayot = new QHBoxLayout(centralWidget);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    textedit = new QPlainTextEdit(centralWidget);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(textedit->sizePolicy().hasHeightForWidth());
    textedit->setSizePolicy(sizePolicy);
    
    hlayot->addWidget(textedit);

    outhtml = new QWebEngineView(centralWidget);
    sizePolicy.setHeightForWidth(outhtml->sizePolicy().hasHeightForWidth());
    outhtml->setSizePolicy(sizePolicy);
    
    hlayot->addWidget(outhtml);

    setCentralWidget(centralWidget);

    QObject::connect(textedit, &QPlainTextEdit::textChanged, [=](){
         outhtml->setHtml(textedit->toPlainText());
    });
}

wMain::~wMain()
{
    delete outhtml;
    delete textedit;
    delete hlayot;
    delete centralWidget;
}