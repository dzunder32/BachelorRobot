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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDrawUi
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_P1X;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_P2Y;
    QLineEdit *lineEdit_P1Y;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_setP2;
    QLineEdit *lineEdit_P2X;
    QPushButton *pushButton_setP1;
    QLineEdit *lineEdit_P1Data;
    QLineEdit *lineEdit_P2Data;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_addP1;
    QPushButton *pushButton_addLine;
    QPushButton *pushButton_addCircle;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_draw;
    QLineEdit *lineEdit_Radius;
    QSpinBox *spinBox_letterSize;
    QRadioButton *radioButton_grid;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_5;
    QSlider *timerSpeedSlider;
    QTextEdit *textEdit_Sequence;
    QTextEdit *textEdit_textInput;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider_xRot;
    QSlider *horizontalSlider_yRot;
    QSlider *horizontalSlider_zRot;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_x;
    QSlider *horizontalSlider_y;
    QSlider *horizontalSlider_z;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_History;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *RobotDrawUi)
    {
        if (RobotDrawUi->objectName().isEmpty())
            RobotDrawUi->setObjectName(QString::fromUtf8("RobotDrawUi"));
        RobotDrawUi->resize(800, 600);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_P1X = new QLineEdit(centralwidget);
        lineEdit_P1X->setObjectName(QString::fromUtf8("lineEdit_P1X"));

        gridLayout->addWidget(lineEdit_P1X, 0, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_P2Y = new QLineEdit(centralwidget);
        lineEdit_P2Y->setObjectName(QString::fromUtf8("lineEdit_P2Y"));

        gridLayout->addWidget(lineEdit_P2Y, 1, 4, 1, 1);

        lineEdit_P1Y = new QLineEdit(centralwidget);
        lineEdit_P1Y->setObjectName(QString::fromUtf8("lineEdit_P1Y"));

        gridLayout->addWidget(lineEdit_P1Y, 0, 4, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 0, 1, 1);

        pushButton_setP2 = new QPushButton(centralwidget);
        pushButton_setP2->setObjectName(QString::fromUtf8("pushButton_setP2"));

        gridLayout->addWidget(pushButton_setP2, 1, 5, 1, 1);

        lineEdit_P2X = new QLineEdit(centralwidget);
        lineEdit_P2X->setObjectName(QString::fromUtf8("lineEdit_P2X"));

        gridLayout->addWidget(lineEdit_P2X, 1, 2, 1, 1);

        pushButton_setP1 = new QPushButton(centralwidget);
        pushButton_setP1->setObjectName(QString::fromUtf8("pushButton_setP1"));

        gridLayout->addWidget(pushButton_setP1, 0, 5, 1, 1);

        lineEdit_P1Data = new QLineEdit(centralwidget);
        lineEdit_P1Data->setObjectName(QString::fromUtf8("lineEdit_P1Data"));

        gridLayout->addWidget(lineEdit_P1Data, 0, 6, 1, 1);

        lineEdit_P2Data = new QLineEdit(centralwidget);
        lineEdit_P2Data->setObjectName(QString::fromUtf8("lineEdit_P2Data"));

        gridLayout->addWidget(lineEdit_P2Data, 1, 6, 1, 1);

        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

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

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_2->addWidget(lineEdit_6, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout_2->addWidget(lineEdit_7, 0, 1, 1, 1);

        pushButton_draw = new QPushButton(centralwidget);
        pushButton_draw->setObjectName(QString::fromUtf8("pushButton_draw"));

        gridLayout_2->addWidget(pushButton_draw, 0, 2, 1, 1);

        lineEdit_Radius = new QLineEdit(centralwidget);
        lineEdit_Radius->setObjectName(QString::fromUtf8("lineEdit_Radius"));

        gridLayout_2->addWidget(lineEdit_Radius, 1, 0, 1, 1);

        spinBox_letterSize = new QSpinBox(centralwidget);
        spinBox_letterSize->setObjectName(QString::fromUtf8("spinBox_letterSize"));
        spinBox_letterSize->setMinimum(1);

        gridLayout_2->addWidget(spinBox_letterSize, 1, 1, 1, 1);

        radioButton_grid = new QRadioButton(centralwidget);
        radioButton_grid->setObjectName(QString::fromUtf8("radioButton_grid"));

        gridLayout_2->addWidget(radioButton_grid, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);

        timerSpeedSlider = new QSlider(centralwidget);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(1000);
        timerSpeedSlider->setValue(500);
        timerSpeedSlider->setSliderPosition(500);
        timerSpeedSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(timerSpeedSlider);


        horizontalLayout_2->addLayout(verticalLayout_2);

        textEdit_Sequence = new QTextEdit(centralwidget);
        textEdit_Sequence->setObjectName(QString::fromUtf8("textEdit_Sequence"));

        horizontalLayout_2->addWidget(textEdit_Sequence);

        textEdit_textInput = new QTextEdit(centralwidget);
        textEdit_textInput->setObjectName(QString::fromUtf8("textEdit_textInput"));

        horizontalLayout_2->addWidget(textEdit_textInput);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSlider_xRot = new QSlider(centralwidget);
        horizontalSlider_xRot->setObjectName(QString::fromUtf8("horizontalSlider_xRot"));
        horizontalSlider_xRot->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_xRot);

        horizontalSlider_yRot = new QSlider(centralwidget);
        horizontalSlider_yRot->setObjectName(QString::fromUtf8("horizontalSlider_yRot"));
        horizontalSlider_yRot->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_yRot);

        horizontalSlider_zRot = new QSlider(centralwidget);
        horizontalSlider_zRot->setObjectName(QString::fromUtf8("horizontalSlider_zRot"));
        horizontalSlider_zRot->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_zRot);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSlider_x = new QSlider(centralwidget);
        horizontalSlider_x->setObjectName(QString::fromUtf8("horizontalSlider_x"));
        horizontalSlider_x->setMinimum(-99);
        horizontalSlider_x->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_x);

        horizontalSlider_y = new QSlider(centralwidget);
        horizontalSlider_y->setObjectName(QString::fromUtf8("horizontalSlider_y"));
        horizontalSlider_y->setMinimum(-99);
        horizontalSlider_y->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_y);

        horizontalSlider_z = new QSlider(centralwidget);
        horizontalSlider_z->setObjectName(QString::fromUtf8("horizontalSlider_z"));
        horizontalSlider_z->setMinimum(-99);
        horizontalSlider_z->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_z);


        verticalLayout_3->addLayout(verticalLayout);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout_3->addWidget(spinBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_History = new QPushButton(centralwidget);
        pushButton_History->setObjectName(QString::fromUtf8("pushButton_History"));

        horizontalLayout_3->addWidget(pushButton_History);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_3->addWidget(pushButtonStop);


        verticalLayout_3->addLayout(horizontalLayout_3);

        RobotDrawUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotDrawUi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        RobotDrawUi->setMenuBar(menubar);
        statusbar = new QStatusBar(RobotDrawUi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RobotDrawUi->setStatusBar(statusbar);
        toolBar = new QToolBar(RobotDrawUi);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        RobotDrawUi->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(RobotDrawUi);

        QMetaObject::connectSlotsByName(RobotDrawUi);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDrawUi)
    {
        RobotDrawUi->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("RobotDrawUi", "Set first Point", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("RobotDrawUi", "X Coordinate", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("RobotDrawUi", "Set Second Point", nullptr));
        pushButton_setP2->setText(QCoreApplication::translate("RobotDrawUi", "Set P2", nullptr));
        pushButton_setP1->setText(QCoreApplication::translate("RobotDrawUi", "Set P1", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("RobotDrawUi", "Y Coordinate", nullptr));
        pushButton_addP1->setText(QCoreApplication::translate("RobotDrawUi", "Add P1 ", nullptr));
        pushButton_addLine->setText(QCoreApplication::translate("RobotDrawUi", "Add Line (P1,P2)", nullptr));
        pushButton_addCircle->setText(QCoreApplication::translate("RobotDrawUi", "Add Circle", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("RobotDrawUi", "Circle Radius: ", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("RobotDrawUi", "LetterSize", nullptr));
        pushButton_draw->setText(QCoreApplication::translate("RobotDrawUi", "Draw Text", nullptr));
        radioButton_grid->setText(QCoreApplication::translate("RobotDrawUi", "Draw Grid", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("RobotDrawUi", "Speed", nullptr));
        textEdit_Sequence->setHtml(QCoreApplication::translate("RobotDrawUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">Robot Sequence:</span></p></body></html>", nullptr));
        pushButton_History->setText(QCoreApplication::translate("RobotDrawUi", "previous Sequence", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("RobotDrawUi", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("RobotDrawUi", "Stop", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDrawUi: public Ui_RobotDrawUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDRAWUI_H
