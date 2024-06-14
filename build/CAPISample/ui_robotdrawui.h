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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDrawUi
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_5;
    QSlider *timerSpeedSlider;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_3;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_P1X;
    QLineEdit *lineEdit_P1Y;
    QPushButton *pushButton_setP1;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_4;
    QFormLayout *formLayout_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_P2X;
    QLineEdit *lineEdit_P2Y;
    QPushButton *pushButton_setP2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_P1Data;
    QLineEdit *lineEdit_P2Data;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_addP1;
    QPushButton *pushButton_addP2;
    QPushButton *pushButton_addLine;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RobotDrawUi)
    {
        if (RobotDrawUi->objectName().isEmpty())
            RobotDrawUi->setObjectName(QString::fromUtf8("RobotDrawUi"));
        RobotDrawUi->resize(800, 600);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        timerSpeedSlider = new QSlider(centralwidget);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(400);
        timerSpeedSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(timerSpeedSlider);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_P1X = new QLineEdit(centralwidget);
        lineEdit_P1X->setObjectName(QString::fromUtf8("lineEdit_P1X"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_P1X);

        lineEdit_P1Y = new QLineEdit(centralwidget);
        lineEdit_P1Y->setObjectName(QString::fromUtf8("lineEdit_P1Y"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_P1Y);


        verticalLayout_2->addLayout(formLayout);

        pushButton_setP1 = new QPushButton(centralwidget);
        pushButton_setP1->setObjectName(QString::fromUtf8("pushButton_setP1"));

        verticalLayout_2->addWidget(pushButton_setP1);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEdit_6);

        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_7);

        lineEdit_P2X = new QLineEdit(centralwidget);
        lineEdit_P2X->setObjectName(QString::fromUtf8("lineEdit_P2X"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lineEdit_P2X);

        lineEdit_P2Y = new QLineEdit(centralwidget);
        lineEdit_P2Y->setObjectName(QString::fromUtf8("lineEdit_P2Y"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_P2Y);


        verticalLayout_3->addLayout(formLayout_2);

        pushButton_setP2 = new QPushButton(centralwidget);
        pushButton_setP2->setObjectName(QString::fromUtf8("pushButton_setP2"));

        verticalLayout_3->addWidget(pushButton_setP2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_P1Data = new QLineEdit(centralwidget);
        lineEdit_P1Data->setObjectName(QString::fromUtf8("lineEdit_P1Data"));

        horizontalLayout_2->addWidget(lineEdit_P1Data);

        lineEdit_P2Data = new QLineEdit(centralwidget);
        lineEdit_P2Data->setObjectName(QString::fromUtf8("lineEdit_P2Data"));

        horizontalLayout_2->addWidget(lineEdit_P2Data);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_addP1 = new QPushButton(centralwidget);
        pushButton_addP1->setObjectName(QString::fromUtf8("pushButton_addP1"));

        horizontalLayout_4->addWidget(pushButton_addP1);

        pushButton_addP2 = new QPushButton(centralwidget);
        pushButton_addP2->setObjectName(QString::fromUtf8("pushButton_addP2"));

        horizontalLayout_4->addWidget(pushButton_addP2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        pushButton_addLine = new QPushButton(centralwidget);
        pushButton_addLine->setObjectName(QString::fromUtf8("pushButton_addLine"));

        verticalLayout_5->addWidget(pushButton_addLine);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout->addWidget(pushButtonStart);

        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        horizontalLayout->addWidget(pushButtonDelete);


        horizontalLayout_5->addLayout(horizontalLayout);

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
        lineEdit_5->setText(QCoreApplication::translate("RobotDrawUi", "Speed", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("RobotDrawUi", "Set first Point", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        pushButton_setP1->setText(QCoreApplication::translate("RobotDrawUi", "Set P1", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("RobotDrawUi", "Set Second Point", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        pushButton_setP2->setText(QCoreApplication::translate("RobotDrawUi", "Set P2", nullptr));
        pushButton_addP1->setText(QCoreApplication::translate("RobotDrawUi", "Add P1 ", nullptr));
        pushButton_addP2->setText(QCoreApplication::translate("RobotDrawUi", "Add P2 ", nullptr));
        pushButton_addLine->setText(QCoreApplication::translate("RobotDrawUi", "Add Line", nullptr));
        textEdit->setHtml(QCoreApplication::translate("RobotDrawUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Robot Sequence:</p></body></html>", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("RobotDrawUi", "Start", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("RobotDrawUi", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDrawUi: public Ui_RobotDrawUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDRAWUI_H
