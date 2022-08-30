#include "wmain.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>
#include <iostream>

WMain::WMain(QWidget *parent) : QMainWindow(parent)
{
    m_centalWidget = new QWidget(this);

    m_vlayout = new QVBoxLayout(m_centalWidget);
    m_imageLael = new QLabel("image...");
    m_imageLael->setMinimumSize(500, 500);
    m_vlayout->addWidget(m_imageLael);

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setMinimum(0);
    m_slider->setMaximum(10);
    m_slider->setPageStep(1);
    m_vlayout->addWidget(m_slider);

    m_button = new QPushButton("Open image");
    m_vlayout->addWidget(m_button);

    QObject::connect(m_button, &QPushButton::clicked, this, &WMain::openfile);
    QObject::connect(m_slider, &QSlider::valueChanged, this, &WMain::blurmove);

    setCentralWidget(m_centalWidget);
}

QImage WMain::blurImage(QImage source, int blurRadius)
{
    if (source.isNull())
        return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}

void WMain::openfile()
{
    auto filename = QFileDialog::getOpenFileName(this, tr("open file"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty())
        return;
    m_pixmapimage = new QPixmap(filename);
    m_imageLael->setPixmap(m_pixmapimage->scaled(m_imageLael->width(), m_imageLael->height(), Qt::KeepAspectRatio));
}

void WMain::blurmove(int newvalue)
{
    if (m_pixmapimage == nullptr)
        return;
    m_imageLael->setPixmap(QPixmap::fromImage(blurImage(m_pixmapimage->toImage(), newvalue).scaled(m_imageLael->width(), m_imageLael->height(), Qt::KeepAspectRatio)));
}

WMain::~WMain()
{
    delete m_imageLael;
    delete m_slider;
    delete m_button;
    delete m_vlayout;
    delete m_pixmapimage;
    delete m_centalWidget;
}