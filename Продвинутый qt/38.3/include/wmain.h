#pragma once
#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QImage>

class WMain : public QMainWindow
{
    Q_OBJECT
    QWidget *m_centalWidget = nullptr;
    QLabel *m_imageLael = nullptr;
    QSlider *m_slider = nullptr;
    QPushButton *m_button = nullptr;
    QVBoxLayout *m_vlayout = nullptr;
    QPixmap *m_pixmapimage = nullptr;
public:
   explicit WMain(QWidget *parent = nullptr);
   WMain(const WMain& other) = delete;
   WMain& operator=(const WMain& other) = delete;
    ~WMain();

public slots:
    void openfile();
    void blurmove(int newvalue);

private:
    QImage blurImage(QImage source, int blurRadius);

};