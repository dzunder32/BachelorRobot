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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *textEdit_Sequence;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_lift;
    QCheckBox *checkBox_circle;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *lineEdit_7;
    QSpinBox *spinBox_letterSize;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pushButton_draw;
    QCheckBox *checkBox_grid;
    QTextEdit *textEdit_textInput;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_P1X;
    QLineEdit *lineEdit_P2X;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_P1Y;
    QLineEdit *lineEdit_P2Y;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_setP1;
    QPushButton *pushButton_setP2;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_addP1;
    QPushButton *pushButton_addLine;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_Radius;
    QPushButton *pushButton_addCircle;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_History;
    QPushButton *pushButton_Registrate;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_dist;
    QSlider *horizontalSlider_xRot;
    QSlider *horizontalSlider_yRot;
    QSlider *horizontalSlider_zRot;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_Range;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_11;
    QVBoxLayout *verticalLayout;
    QSlider *timerSpeedSlider;
    QSlider *horizontalSlider_x;
    QSlider *horizontalSlider_y;
    QSlider *horizontalSlider_z;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *RobotDrawUi)
    {
        if (RobotDrawUi->objectName().isEmpty())
            RobotDrawUi->setObjectName(QString::fromUtf8("RobotDrawUi"));
        RobotDrawUi->resize(600, 566);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_14 = new QVBoxLayout(centralwidget);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        textEdit_Sequence = new QTextEdit(centralwidget);
        textEdit_Sequence->setObjectName(QString::fromUtf8("textEdit_Sequence"));

        horizontalLayout_9->addWidget(textEdit_Sequence);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        lineEdit_10 = new QLineEdit(centralwidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        QFont font;
        font.setPointSize(9);
        lineEdit_10->setFont(font);

        verticalLayout_11->addWidget(lineEdit_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_lift = new QPushButton(centralwidget);
        pushButton_lift->setObjectName(QString::fromUtf8("pushButton_lift"));

        horizontalLayout_6->addWidget(pushButton_lift);

        checkBox_circle = new QCheckBox(centralwidget);
        checkBox_circle->setObjectName(QString::fromUtf8("checkBox_circle"));

        horizontalLayout_6->addWidget(checkBox_circle);


        verticalLayout_11->addLayout(horizontalLayout_6);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_11->addWidget(graphicsView);


        horizontalLayout_9->addLayout(verticalLayout_11);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_10->addWidget(lineEdit_7);

        spinBox_letterSize = new QSpinBox(centralwidget);
        spinBox_letterSize->setObjectName(QString::fromUtf8("spinBox_letterSize"));
        spinBox_letterSize->setMinimum(1);

        verticalLayout_10->addWidget(spinBox_letterSize);


        horizontalLayout_7->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        pushButton_draw = new QPushButton(centralwidget);
        pushButton_draw->setObjectName(QString::fromUtf8("pushButton_draw"));

        verticalLayout_12->addWidget(pushButton_draw);

        checkBox_grid = new QCheckBox(centralwidget);
        checkBox_grid->setObjectName(QString::fromUtf8("checkBox_grid"));

        verticalLayout_12->addWidget(checkBox_grid);


        horizontalLayout_7->addLayout(verticalLayout_12);


        verticalLayout_13->addLayout(horizontalLayout_7);

        textEdit_textInput = new QTextEdit(centralwidget);
        textEdit_textInput->setObjectName(QString::fromUtf8("textEdit_textInput"));

        verticalLayout_13->addWidget(textEdit_textInput);


        horizontalLayout_9->addLayout(verticalLayout_13);


        verticalLayout_14->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_P1X = new QLineEdit(centralwidget);
        lineEdit_P1X->setObjectName(QString::fromUtf8("lineEdit_P1X"));

        verticalLayout_4->addWidget(lineEdit_P1X);

        lineEdit_P2X = new QLineEdit(centralwidget);
        lineEdit_P2X->setObjectName(QString::fromUtf8("lineEdit_P2X"));

        verticalLayout_4->addWidget(lineEdit_P2X);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        verticalLayout_5->addWidget(lineEdit_9);

        lineEdit_P1Y = new QLineEdit(centralwidget);
        lineEdit_P1Y->setObjectName(QString::fromUtf8("lineEdit_P1Y"));

        verticalLayout_5->addWidget(lineEdit_P1Y);

        lineEdit_P2Y = new QLineEdit(centralwidget);
        lineEdit_P2Y->setObjectName(QString::fromUtf8("lineEdit_P2Y"));

        verticalLayout_5->addWidget(lineEdit_P2Y);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_6->addWidget(lineEdit_3);

        pushButton_setP1 = new QPushButton(centralwidget);
        pushButton_setP1->setObjectName(QString::fromUtf8("pushButton_setP1"));

        verticalLayout_6->addWidget(pushButton_setP1);

        pushButton_setP2 = new QPushButton(centralwidget);
        pushButton_setP2->setObjectName(QString::fromUtf8("pushButton_setP2"));

        verticalLayout_6->addWidget(pushButton_setP2);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_3);

        pushButton_addP1 = new QPushButton(centralwidget);
        pushButton_addP1->setObjectName(QString::fromUtf8("pushButton_addP1"));

        verticalLayout_7->addWidget(pushButton_addP1);

        pushButton_addLine = new QPushButton(centralwidget);
        pushButton_addLine->setObjectName(QString::fromUtf8("pushButton_addLine"));

        verticalLayout_7->addWidget(pushButton_addLine);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_5->addWidget(lineEdit_6);

        lineEdit_Radius = new QLineEdit(centralwidget);
        lineEdit_Radius->setObjectName(QString::fromUtf8("lineEdit_Radius"));

        horizontalLayout_5->addWidget(lineEdit_Radius);

        pushButton_addCircle = new QPushButton(centralwidget);
        pushButton_addCircle->setObjectName(QString::fromUtf8("pushButton_addCircle"));

        horizontalLayout_5->addWidget(pushButton_addCircle);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_History = new QPushButton(centralwidget);
        pushButton_History->setObjectName(QString::fromUtf8("pushButton_History"));

        horizontalLayout_3->addWidget(pushButton_History);

        pushButton_Registrate = new QPushButton(centralwidget);
        pushButton_Registrate->setObjectName(QString::fromUtf8("pushButton_Registrate"));

        horizontalLayout_3->addWidget(pushButton_Registrate);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_3->addWidget(pushButtonStop);


        verticalLayout_8->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBox_dist = new QSpinBox(centralwidget);
        spinBox_dist->setObjectName(QString::fromUtf8("spinBox_dist"));
        spinBox_dist->setMinimum(-99);

        horizontalLayout_4->addWidget(spinBox_dist);

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

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        lineEdit_Range = new QLineEdit(centralwidget);
        lineEdit_Range->setObjectName(QString::fromUtf8("lineEdit_Range"));

        horizontalLayout_4->addWidget(lineEdit_Range);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);

        lineEdit_12 = new QLineEdit(centralwidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        verticalLayout_2->addWidget(lineEdit_12);

        lineEdit_13 = new QLineEdit(centralwidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        verticalLayout_2->addWidget(lineEdit_13);

        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        verticalLayout_2->addWidget(lineEdit_11);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        timerSpeedSlider = new QSlider(centralwidget);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(1000);
        timerSpeedSlider->setValue(500);
        timerSpeedSlider->setSliderPosition(500);
        timerSpeedSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(timerSpeedSlider);

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


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_9->addLayout(verticalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_9);


        verticalLayout_14->addLayout(horizontalLayout_8);

        RobotDrawUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotDrawUi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
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
        textEdit_Sequence->setHtml(QCoreApplication::translate("RobotDrawUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Robot Sequence:</p></body></html>", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("RobotDrawUi", "Mouse Drawing", nullptr));
        pushButton_lift->setText(QCoreApplication::translate("RobotDrawUi", "Lift Tip", nullptr));
        checkBox_circle->setText(QCoreApplication::translate("RobotDrawUi", "Draw Circle", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("RobotDrawUi", "LetterSize", nullptr));
        pushButton_draw->setText(QCoreApplication::translate("RobotDrawUi", "Draw Text", nullptr));
        checkBox_grid->setText(QCoreApplication::translate("RobotDrawUi", "CheckBox", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("RobotDrawUi", "Y", nullptr));
        pushButton_setP1->setText(QCoreApplication::translate("RobotDrawUi", "Set P1", nullptr));
        pushButton_setP2->setText(QCoreApplication::translate("RobotDrawUi", "Set P2", nullptr));
        pushButton_addP1->setText(QCoreApplication::translate("RobotDrawUi", "Add P1 ", nullptr));
        pushButton_addLine->setText(QCoreApplication::translate("RobotDrawUi", "Add Line", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("RobotDrawUi", "Circle Radius: ", nullptr));
        pushButton_addCircle->setText(QCoreApplication::translate("RobotDrawUi", "Add Circle", nullptr));
        pushButton_History->setText(QCoreApplication::translate("RobotDrawUi", "PushButton", nullptr));
        pushButton_Registrate->setText(QCoreApplication::translate("RobotDrawUi", "Registrate", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("RobotDrawUi", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("RobotDrawUi", "Stop", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "0,0", nullptr));
        lineEdit_Range->setText(QCoreApplication::translate("RobotDrawUi", "0,0", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("RobotDrawUi", "Speed", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("RobotDrawUi", "x", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("RobotDrawUi", "Y", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("RobotDrawUi", "z", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDrawUi: public Ui_RobotDrawUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDRAWUI_H
