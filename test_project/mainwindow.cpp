#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "custom_paint.h"

#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    Dialog *dialog = new Dialog(this);

    custom_paint *label = new custom_paint(dialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 20, 100, 100));
    label->repaint();

    //dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    dialog->show();
    dialog->resize(this->width()/2,this->height()/2);
    dialog->move((QApplication::desktop()->width() - dialog->width())/2,(QApplication::desktop()->height() - dialog->height())/2);
}





