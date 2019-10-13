#ifndef MYPHOTOBACK_H
#define MYPHOTOBACK_H

#include <QLabel>

class myPhotoBack: public QLabel
{
    public:
        myPhotoBack(QWidget *parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());
        ~myPhotoBack();
        virtual void paintEvent(QPaintEvent * event);
};

#endif // MYPHOTOBACK_H
