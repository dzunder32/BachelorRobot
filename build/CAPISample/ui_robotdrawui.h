/********************************************************************************
** Form generated from reading UI file 'robotdrawui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTDRAWUI_H
#define UI_ROBOTDRAWUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDrawUi
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonDelete;
    QSlider *timerSpeedSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RobotDrawUi)
    {
        if (RobotDrawUi->objectName().isEmpty())
            RobotDrawUi->setObjectName(QString::fromUtf8("RobotDrawUi"));
        RobotDrawUi->resize(800, 600);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(180, 300, 80, 24));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(460, 300, 80, 24));
        timerSpeedSlider = new QSlider(centralwidget);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setGeometry(QRect(100, 140, 16, 160));
        timerSpeedSlider->setMinimum(1);
        timerSpeedSlider->setMaximum(400);
        timerSpeedSlider->setOrientation(Qt::Vertical);
        RobotDrawUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotDrawUi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RobotDrawUi->setMenuBar(menubar);
        statusbar = new QStatusBar(RobotDrawUi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RobotDrawUi->setStatusBar(statusbar);

        retranslateUi(RobotDrawUi);

        QMetaObject::connectSlotsByName(RobotDrawUi);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDrawUi)
    {
        RobotDrawUi->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "MainWindow", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("RobotDrawUi", "Start", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("RobotDrawUi", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDrawUi: public Ui_RobotDrawUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDRAWUI_H
