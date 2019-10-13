#include "myphotoback.h"
#include <QPainter>

myPhotoBack::myPhotoBack(QWidget *parent, Qt::WindowFlags f):QLabel(parent,f)
{

}


myPhotoBack::~myPhotoBack()
{

}

void myPhotoBack::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QPixmap pixmap(":/sign_image/Invango/bg_ avatar3.png");
    painter.drawPixmap(0,0,100,100,pixmap);
}



