/********************************************************************************
** Form generated from reading UI file 'drawwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWINDOW_H
#define UI_DRAWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DrawWindow)
    {
        if (DrawWindow->objectName().isEmpty())
            DrawWindow->setObjectName(QString::fromUtf8("DrawWindow"));
        DrawWindow->resize(800, 600);
        centralwidget = new QWidget(DrawWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 270, 80, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 270, 80, 24));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(280, 120, 113, 24));
        DrawWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DrawWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DrawWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DrawWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DrawWindow->setStatusBar(statusbar);

        retranslateUi(DrawWindow);

        QMetaObject::connectSlotsByName(DrawWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DrawWindow)
    {
        DrawWindow->setWindowTitle(QCoreApplication::translate("DrawWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("DrawWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DrawWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawWindow: public Ui_DrawWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWINDOW_H
