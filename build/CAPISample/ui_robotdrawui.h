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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_P1X;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_P1Y;
    QPushButton *pushButton_setP1;
    QLineEdit *lineEdit_P1Data;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_P2X;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_P2Y;
    QPushButton *pushButton_setP2;
    QLineEdit *lineEdit_P2Data;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_addP1;
    QPushButton *pushButton_addLine;
    QPushButton *pushButton_addCircle;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_Radius;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_11;
    QScrollBar *horizontalScrollBar_XChange;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_10;
    QScrollBar *horizontalScrollBar_YChange;
    QLineEdit *lineEdit_5;
    QTextEdit *textEdit_Sequence;
    QSlider *timerSpeedSlider;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_History;
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
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_P1X = new QLineEdit(centralwidget);
        lineEdit_P1X->setObjectName(QString::fromUtf8("lineEdit_P1X"));

        gridLayout->addWidget(lineEdit_P1X, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        lineEdit_P1Y = new QLineEdit(centralwidget);
        lineEdit_P1Y->setObjectName(QString::fromUtf8("lineEdit_P1Y"));

        gridLayout->addWidget(lineEdit_P1Y, 0, 4, 1, 1);

        pushButton_setP1 = new QPushButton(centralwidget);
        pushButton_setP1->setObjectName(QString::fromUtf8("pushButton_setP1"));

        gridLayout->addWidget(pushButton_setP1, 0, 5, 1, 1);

        lineEdit_P1Data = new QLineEdit(centralwidget);
        lineEdit_P1Data->setObjectName(QString::fromUtf8("lineEdit_P1Data"));

        gridLayout->addWidget(lineEdit_P1Data, 0, 6, 1, 1);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 0, 1, 1);

        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 1, 1, 1, 1);

        lineEdit_P2X = new QLineEdit(centralwidget);
        lineEdit_P2X->setObjectName(QString::fromUtf8("lineEdit_P2X"));

        gridLayout->addWidget(lineEdit_P2X, 1, 2, 1, 1);

        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 1, 3, 1, 1);

        lineEdit_P2Y = new QLineEdit(centralwidget);
        lineEdit_P2Y->setObjectName(QString::fromUtf8("lineEdit_P2Y"));

        gridLayout->addWidget(lineEdit_P2Y, 1, 4, 1, 1);

        pushButton_setP2 = new QPushButton(centralwidget);
        pushButton_setP2->setObjectName(QString::fromUtf8("pushButton_setP2"));

        gridLayout->addWidget(pushButton_setP2, 1, 5, 1, 1);

        lineEdit_P2Data = new QLineEdit(centralwidget);
        lineEdit_P2Data->setObjectName(QString::fromUtf8("lineEdit_P2Data"));

        gridLayout->addWidget(lineEdit_P2Data, 1, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_addP1 = new QPushButton(centralwidget);
        pushButton_addP1->setObjectName(QString::fromUtf8("pushButton_addP1"));

        horizontalLayout->addWidget(pushButton_addP1);

        pushButton_addLine = new QPushButton(centralwidget);
        pushButton_addLine->setObjectName(QString::fromUtf8("pushButton_addLine"));

        horizontalLayout->addWidget(pushButton_addLine);

        pushButton_addCircle = new QPushButton(centralwidget);
        pushButton_addCircle->setObjectName(QString::fromUtf8("pushButton_addCircle"));

        horizontalLayout->addWidget(pushButton_addCircle);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_Radius = new QLineEdit(centralwidget);
        lineEdit_Radius->setObjectName(QString::fromUtf8("lineEdit_Radius"));

        verticalLayout->addWidget(lineEdit_Radius);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        verticalLayout_2->addWidget(lineEdit_11);

        horizontalScrollBar_XChange = new QScrollBar(centralwidget);
        horizontalScrollBar_XChange->setObjectName(QString::fromUtf8("horizontalScrollBar_XChange"));
        horizontalScrollBar_XChange->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalScrollBar_XChange);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_10 = new QLineEdit(centralwidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        verticalLayout_3->addWidget(lineEdit_10);

        horizontalScrollBar_YChange = new QScrollBar(centralwidget);
        horizontalScrollBar_YChange->setObjectName(QString::fromUtf8("horizontalScrollBar_YChange"));
        horizontalScrollBar_YChange->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar_YChange);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 3);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 2, 0, 1, 2);

        textEdit_Sequence = new QTextEdit(centralwidget);
        textEdit_Sequence->setObjectName(QString::fromUtf8("textEdit_Sequence"));

        gridLayout_2->addWidget(textEdit_Sequence, 2, 2, 2, 1);

        timerSpeedSlider = new QSlider(centralwidget);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(1000);
        timerSpeedSlider->setValue(200);
        timerSpeedSlider->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(timerSpeedSlider, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_History = new QPushButton(centralwidget);
        pushButton_History->setObjectName(QString::fromUtf8("pushButton_History"));

        horizontalLayout_3->addWidget(pushButton_History);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        horizontalLayout_3->addWidget(pushButtonDelete);


        gridLayout_2->addLayout(horizontalLayout_3, 4, 1, 1, 2);

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
        lineEdit_3->setText(QCoreApplication::translate("RobotDrawUi", "Set first Point", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        pushButton_setP1->setText(QCoreApplication::translate("RobotDrawUi", "Set P1", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("RobotDrawUi", "Set Second Point", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        pushButton_setP2->setText(QCoreApplication::translate("RobotDrawUi", "Set P2", nullptr));
        pushButton_addP1->setText(QCoreApplication::translate("RobotDrawUi", "Add P1 ", nullptr));
        pushButton_addLine->setText(QCoreApplication::translate("RobotDrawUi", "Add Line (P1,P2)", nullptr));
        pushButton_addCircle->setText(QCoreApplication::translate("RobotDrawUi", "Add Circle", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("RobotDrawUi", "Circle Radius: ", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("RobotDrawUi", "adjust X Coordinate P1", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("RobotDrawUi", "adjust Y Coordinate P1", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("RobotDrawUi", "Speed", nullptr));
        textEdit_Sequence->setHtml(QCoreApplication::translate("RobotDrawUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Robot Sequence:</p></body></html>", nullptr));
        pushButton_History->setText(QCoreApplication::translate("RobotDrawUi", "previous Sequence", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("RobotDrawUi", "Start", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("RobotDrawUi", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDrawUi: public Ui_RobotDrawUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDRAWUI_H
