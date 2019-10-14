#include "custom_paint.h"

#include <QPainter>
#include <QColor>
#include <QPoint>

custom_paint::custom_paint(QWidget *parent, Qt::WindowFlags f):QLabel(parent,f)
{
    flag = 0;
}

void custom_paint::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(flag)
    {
        painter.setPen(QColor(0xff,0,0));
        painter.drawEllipse(QPoint(100,100),100,100);
        flag = 0;
    }
    else
    {
        painter.setPen(QColor(0,0xff,0));
        painter.drawEllipse(QPoint(10,10),10,10);
        flag = 1;
    }


}

