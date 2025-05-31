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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDrawUi
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_lift;
    QCheckBox *checkBox_circle;
    QGraphicsView *graphicsView;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_textInput;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_7;
    QSpinBox *spinBox_letterSize;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_draw;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *line_7;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_P1X;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_P2X;
    QPushButton *pushButton_addP1;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_P1Y;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_addLine;
    QLineEdit *lineEdit_P2Y;
    QFrame *line_8;
    QFrame *line_2;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_Radius;
    QPushButton *pushButton_addCircle;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_5;
    QSlider *timerSpeedSlider;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_12;
    QSlider *horizontalSlider_x;
    QSlider *horizontalSlider_xRot;
    QLineEdit *lineEdit_13;
    QSlider *horizontalSlider_y;
    QSlider *horizontalSlider_yRot;
    QLineEdit *lineEdit_11;
    QSlider *horizontalSlider_z;
    QSlider *horizontalSlider_zRot;
    QLineEdit *lineEdit_18;
    QFrame *line_4;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_3;
    QFrame *line_3;
    QLineEdit *lineEdit_15;
    QSpinBox *spinBox_dist;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QSpinBox *spinBox_xRot;
    QSpinBox *spinBox_yRot;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *RobotDrawUi)
    {
        if (RobotDrawUi->objectName().isEmpty())
            RobotDrawUi->setObjectName(QString::fromUtf8("RobotDrawUi"));
        RobotDrawUi->resize(637, 453);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_11 = new QVBoxLayout(tab);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_lift = new QPushButton(tab);
        pushButton_lift->setObjectName(QString::fromUtf8("pushButton_lift"));

        horizontalLayout_6->addWidget(pushButton_lift);

        checkBox_circle = new QCheckBox(tab);
        checkBox_circle->setObjectName(QString::fromUtf8("checkBox_circle"));

        horizontalLayout_6->addWidget(checkBox_circle);


        verticalLayout_11->addLayout(horizontalLayout_6);

        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_11->addWidget(graphicsView);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEdit_textInput = new QTextEdit(tab_4);
        textEdit_textInput->setObjectName(QString::fromUtf8("textEdit_textInput"));

        verticalLayout_4->addWidget(textEdit_textInput);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_5->addWidget(lineEdit_7);

        spinBox_letterSize = new QSpinBox(tab_4);
        spinBox_letterSize->setObjectName(QString::fromUtf8("spinBox_letterSize"));
        spinBox_letterSize->setMinimum(1);
        spinBox_letterSize->setValue(10);

        horizontalLayout_5->addWidget(spinBox_letterSize);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton_draw = new QPushButton(tab_4);
        pushButton_draw->setObjectName(QString::fromUtf8("pushButton_draw"));

        horizontalLayout_5->addWidget(pushButton_draw);


        verticalLayout_4->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        line_7 = new QFrame(tab_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 0, 1, 1);

        lineEdit_P1X = new QLineEdit(tab_2);
        lineEdit_P1X->setObjectName(QString::fromUtf8("lineEdit_P1X"));

        gridLayout->addWidget(lineEdit_P1X, 2, 1, 1, 1);

        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 0, 1, 1);

        lineEdit_P2X = new QLineEdit(tab_2);
        lineEdit_P2X->setObjectName(QString::fromUtf8("lineEdit_P2X"));

        gridLayout->addWidget(lineEdit_P2X, 3, 1, 1, 1);

        pushButton_addP1 = new QPushButton(tab_2);
        pushButton_addP1->setObjectName(QString::fromUtf8("pushButton_addP1"));

        gridLayout->addWidget(pushButton_addP1, 2, 4, 1, 1);

        lineEdit_9 = new QLineEdit(tab_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 1, 3, 1, 1);

        lineEdit_P1Y = new QLineEdit(tab_2);
        lineEdit_P1Y->setObjectName(QString::fromUtf8("lineEdit_P1Y"));

        gridLayout->addWidget(lineEdit_P1Y, 2, 3, 1, 1);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 0, 1, 2);

        pushButton_addLine = new QPushButton(tab_2);
        pushButton_addLine->setObjectName(QString::fromUtf8("pushButton_addLine"));

        gridLayout->addWidget(pushButton_addLine, 3, 4, 1, 1);

        lineEdit_P2Y = new QLineEdit(tab_2);
        lineEdit_P2Y->setObjectName(QString::fromUtf8("lineEdit_P2Y"));

        gridLayout->addWidget(lineEdit_P2Y, 3, 3, 1, 1);

        line_8 = new QFrame(tab_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 1, 2, 3, 1);

        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 4);


        horizontalLayout->addLayout(gridLayout);

        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);

        lineEdit_Radius = new QLineEdit(tab_2);
        lineEdit_Radius->setObjectName(QString::fromUtf8("lineEdit_Radius"));

        horizontalLayout_7->addWidget(lineEdit_Radius);

        pushButton_addCircle = new QPushButton(tab_2);
        pushButton_addCircle->setObjectName(QString::fromUtf8("pushButton_addCircle"));

        horizontalLayout_7->addWidget(pushButton_addCircle);


        verticalLayout_2->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout = new QVBoxLayout(tab_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        QFont font;
        font.setBold(true);
        lineEdit_5->setFont(font);

        horizontalLayout_4->addWidget(lineEdit_5);

        timerSpeedSlider = new QSlider(tab_3);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(1000);
        timerSpeedSlider->setValue(500);
        timerSpeedSlider->setSliderPosition(500);
        timerSpeedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(timerSpeedSlider);


        verticalLayout->addLayout(horizontalLayout_4);

        line_6 = new QFrame(tab_3);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout_2->addWidget(lineEdit_10, 0, 1, 1, 1);

        lineEdit_14 = new QLineEdit(tab_3);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        gridLayout_2->addWidget(lineEdit_14, 0, 2, 1, 1);

        lineEdit_12 = new QLineEdit(tab_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        gridLayout_2->addWidget(lineEdit_12, 1, 0, 1, 1);

        horizontalSlider_x = new QSlider(tab_3);
        horizontalSlider_x->setObjectName(QString::fromUtf8("horizontalSlider_x"));
        horizontalSlider_x->setMinimum(-99);
        horizontalSlider_x->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_x, 1, 1, 1, 1);

        horizontalSlider_xRot = new QSlider(tab_3);
        horizontalSlider_xRot->setObjectName(QString::fromUtf8("horizontalSlider_xRot"));
        horizontalSlider_xRot->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_xRot, 1, 2, 1, 1);

        lineEdit_13 = new QLineEdit(tab_3);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        gridLayout_2->addWidget(lineEdit_13, 2, 0, 1, 1);

        horizontalSlider_y = new QSlider(tab_3);
        horizontalSlider_y->setObjectName(QString::fromUtf8("horizontalSlider_y"));
        horizontalSlider_y->setMinimum(-99);
        horizontalSlider_y->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_y, 2, 1, 1, 1);

        horizontalSlider_yRot = new QSlider(tab_3);
        horizontalSlider_yRot->setObjectName(QString::fromUtf8("horizontalSlider_yRot"));
        horizontalSlider_yRot->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_yRot, 2, 2, 1, 1);

        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout_2->addWidget(lineEdit_11, 3, 0, 1, 1);

        horizontalSlider_z = new QSlider(tab_3);
        horizontalSlider_z->setObjectName(QString::fromUtf8("horizontalSlider_z"));
        horizontalSlider_z->setMinimum(-99);
        horizontalSlider_z->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_z, 3, 1, 1, 1);

        horizontalSlider_zRot = new QSlider(tab_3);
        horizontalSlider_zRot->setObjectName(QString::fromUtf8("horizontalSlider_zRot"));
        horizontalSlider_zRot->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_zRot, 3, 2, 1, 1);

        lineEdit_18 = new QLineEdit(tab_3);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setFont(font);

        gridLayout_2->addWidget(lineEdit_18, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        line_4 = new QFrame(tab_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit_3);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::SpanningRole, line_3);

        lineEdit_15 = new QLineEdit(tab_3);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_15);

        spinBox_dist = new QSpinBox(tab_3);
        spinBox_dist->setObjectName(QString::fromUtf8("spinBox_dist"));
        spinBox_dist->setMinimum(-99);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_dist);

        lineEdit_16 = new QLineEdit(tab_3);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_16);

        lineEdit_17 = new QLineEdit(tab_3);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lineEdit_17);

        spinBox_xRot = new QSpinBox(tab_3);
        spinBox_xRot->setObjectName(QString::fromUtf8("spinBox_xRot"));
        spinBox_xRot->setMinimum(-99);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_xRot);

        spinBox_yRot = new QSpinBox(tab_3);
        spinBox_yRot->setObjectName(QString::fromUtf8("spinBox_yRot"));
        spinBox_yRot->setMinimum(-99);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_yRot);


        horizontalLayout_2->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_5->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_3->addWidget(pushButtonStop);


        verticalLayout_5->addLayout(horizontalLayout_3);

        RobotDrawUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotDrawUi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 637, 21));
        RobotDrawUi->setMenuBar(menubar);
        statusbar = new QStatusBar(RobotDrawUi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RobotDrawUi->setStatusBar(statusbar);
        toolBar = new QToolBar(RobotDrawUi);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        RobotDrawUi->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(RobotDrawUi);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(RobotDrawUi);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDrawUi)
    {
        RobotDrawUi->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        tab->setToolTip(QCoreApplication::translate("RobotDrawUi", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_lift->setText(QCoreApplication::translate("RobotDrawUi", "Lift Tip", nullptr));
        checkBox_circle->setText(QCoreApplication::translate("RobotDrawUi", "Draw Circle", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RobotDrawUi", "Mouse Drawing", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("RobotDrawUi", "LetterSize", nullptr));
        pushButton_draw->setText(QCoreApplication::translate("RobotDrawUi", "Draw Text", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("RobotDrawUi", "Letter Drawing", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("RobotDrawUi", "P1", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("RobotDrawUi", "P2", nullptr));
        pushButton_addP1->setText(QCoreApplication::translate("RobotDrawUi", "Draw P1 ", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("RobotDrawUi", "Y", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "Draw point or line between P1 and P2", nullptr));
        pushButton_addLine->setText(QCoreApplication::translate("RobotDrawUi", "Draw Line", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("RobotDrawUi", "Circle Radius: ", nullptr));
        pushButton_addCircle->setText(QCoreApplication::translate("RobotDrawUi", "Draw Circle", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RobotDrawUi", "Manual Drawing", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("RobotDrawUi", "Robot speed ", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("RobotDrawUi", "Translation", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("RobotDrawUi", "Rotation", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("RobotDrawUi", "X", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("RobotDrawUi", "Y", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("RobotDrawUi", "Z", nullptr));
        lineEdit_18->setText(QCoreApplication::translate("RobotDrawUi", "Plane Pose", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("RobotDrawUi", "Plane Registration", nullptr));
        lineEdit_15->setText(QCoreApplication::translate("RobotDrawUi", "Tool Offset", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("RobotDrawUi", "Rotation xAxis", nullptr));
        lineEdit_17->setText(QCoreApplication::translate("RobotDrawUi", "Rotation yAxis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("RobotDrawUi", "Simulation", nullptr));
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
