/********************************************************************************
** Form generated from reading UI file 'currentsign.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTSIGN_H
#define UI_CURRENTSIGN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CurrentSign
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CurrentSign)
    {
        if (CurrentSign->objectName().isEmpty())
            CurrentSign->setObjectName(QString::fromUtf8("CurrentSign"));
        CurrentSign->resize(1080, 580);
        CurrentSign->setStyleSheet(QString::fromUtf8("border-image: url(:/sign_image/Invango/bg_ avatar1 .png);"));
        verticalLayout = new QVBoxLayout(CurrentSign);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 139, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(CurrentSign);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/sign_image/Invango/bg_ avatar2.png);"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label = new QLabel(CurrentSign);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 14);
        horizontalLayout->setStretch(1, 25);
        horizontalLayout->setStretch(2, 6);
        horizontalLayout->setStretch(3, 35);
        horizontalLayout->setStretch(4, 14);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 139, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 15);
        verticalLayout->setStretch(1, 28);
        verticalLayout->setStretch(2, 15);

        retranslateUi(CurrentSign);

        QMetaObject::connectSlotsByName(CurrentSign);
    } // setupUi

    void retranslateUi(QDialog *CurrentSign)
    {
        CurrentSign->setWindowTitle(QApplication::translate("CurrentSign", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label->setText(QApplication::translate("CurrentSign", "<html><head/><body><p><span style=\" font-size:36pt;\">\350\260\242\346\230\245\350\212\261         01888</span></p><p><span style=\" font-size:36pt;\">\344\272\272\345\212\233\350\265\204\346\272\220\351\203\250</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CurrentSign: public Ui_CurrentSign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTSIGN_H
