#ifndef CURRENTSIGN_H
#define CURRENTSIGN_H

#include <QDialog>

namespace Ui {
class CurrentSign;
}

class CurrentSign : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentSign(QWidget *parent = 0);
    ~CurrentSign();

private:
    Ui::CurrentSign *ui;
};

#endif // CURRENTSIGN_H
