/********************************************************************************
** Form generated from reading UI file 'robotcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTCONTROL_H
#define UI_ROBOTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotControl
{
public:
    QGridLayout *gridLayout;
    QPushButton *pb_stop;
    QPushButton *pb_connect;
    QPushButton *pb_servo;
    QPushButton *pb_update;
    QPlainTextEdit *plainTextEdit;
    QCheckBox *cb_updating;

    void setupUi(QWidget *RobotControl)
    {
        if (RobotControl->objectName().isEmpty())
            RobotControl->setObjectName(QString::fromUtf8("RobotControl"));
        RobotControl->resize(748, 346);
        gridLayout = new QGridLayout(RobotControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pb_stop = new QPushButton(RobotControl);
        pb_stop->setObjectName(QString::fromUtf8("pb_stop"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_stop->sizePolicy().hasHeightForWidth());
        pb_stop->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pb_stop->setFont(font);
        pb_stop->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));

        gridLayout->addWidget(pb_stop, 1, 3, 1, 1);

        pb_connect = new QPushButton(RobotControl);
        pb_connect->setObjectName(QString::fromUtf8("pb_connect"));
        sizePolicy.setHeightForWidth(pb_connect->sizePolicy().hasHeightForWidth());
        pb_connect->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_connect, 1, 0, 1, 1);

        pb_servo = new QPushButton(RobotControl);
        pb_servo->setObjectName(QString::fromUtf8("pb_servo"));
        sizePolicy.setHeightForWidth(pb_servo->sizePolicy().hasHeightForWidth());
        pb_servo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_servo, 1, 1, 1, 2);

        pb_update = new QPushButton(RobotControl);
        pb_update->setObjectName(QString::fromUtf8("pb_update"));
        sizePolicy.setHeightForWidth(pb_update->sizePolicy().hasHeightForWidth());
        pb_update->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_update, 1, 4, 1, 1);

        plainTextEdit = new QPlainTextEdit(RobotControl);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        plainTextEdit->setFont(font1);

        gridLayout->addWidget(plainTextEdit, 2, 0, 1, 6);

        cb_updating = new QCheckBox(RobotControl);
        cb_updating->setObjectName(QString::fromUtf8("cb_updating"));

        gridLayout->addWidget(cb_updating, 1, 5, 1, 1);


        retranslateUi(RobotControl);

        QMetaObject::connectSlotsByName(RobotControl);
    } // setupUi

    void retranslateUi(QWidget *RobotControl)
    {
        RobotControl->setWindowTitle(QCoreApplication::translate("RobotControl", "Form", nullptr));
        pb_stop->setText(QCoreApplication::translate("RobotControl", "stop", nullptr));
        pb_connect->setText(QCoreApplication::translate("RobotControl", "connect", nullptr));
        pb_servo->setText(QCoreApplication::translate("RobotControl", "servo on", nullptr));
        pb_update->setText(QCoreApplication::translate("RobotControl", "update position", nullptr));
        cb_updating->setText(QCoreApplication::translate("RobotControl", "direct updating", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotControl: public Ui_RobotControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTCONTROL_H
