/********************************************************************************
** Form generated from reading UI file 'drawletters.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWLETTERS_H
#define UI_DRAWLETTERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawLetters
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DrawLetters)
    {
        if (DrawLetters->objectName().isEmpty())
            DrawLetters->setObjectName(QString::fromUtf8("DrawLetters"));
        DrawLetters->resize(800, 600);
        centralwidget = new QWidget(DrawLetters);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        DrawLetters->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DrawLetters);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DrawLetters->setMenuBar(menubar);
        statusbar = new QStatusBar(DrawLetters);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DrawLetters->setStatusBar(statusbar);

        retranslateUi(DrawLetters);

        QMetaObject::connectSlotsByName(DrawLetters);
    } // setupUi

    void retranslateUi(QMainWindow *DrawLetters)
    {
        DrawLetters->setWindowTitle(QCoreApplication::translate("DrawLetters", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DrawLetters", "Stop", nullptr));
        pushButton->setText(QCoreApplication::translate("DrawLetters", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawLetters: public Ui_DrawLetters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWLETTERS_H
