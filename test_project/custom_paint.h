#ifndef CUSTOM_PAINT_H
#define CUSTOM_PAINT_H

#include <QLabel>

class custom_paint : public QLabel
{
public:
    custom_paint(QWidget *parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());

    virtual void paintEvent(QPaintEvent *);

    int flag;
};
#endif // CUSTOM_PAINT_H
