#include "currentsign.h"
#include "ui_currentsign.h"

CurrentSign::CurrentSign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurrentSign)
{
    ui->setupUi(this);
}

CurrentSign::~CurrentSign()
{
    delete ui;
}
