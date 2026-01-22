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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_lift;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox_circle;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *textEdit_textInput;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_12;
    QSpinBox *spinBox_letterSize;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_draw;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Point;
    QRadioButton *radioButton_Line;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBox_x1;
    QLineEdit *lineEdit_9;
    QDoubleSpinBox *doubleSpinBox_y1;
    QLineEdit *lineEdit_19;
    QDoubleSpinBox *doubleSpinBox_x2;
    QLineEdit *lineEdit_20;
    QDoubleSpinBox *doubleSpinBox_y2;
    QPushButton *pushButton_drawLinePoint;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox_XMid;
    QLineEdit *lineEdit_3;
    QDoubleSpinBox *doubleSpinBox_YMid;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_21;
    QDoubleSpinBox *doubleSpinBox_radius;
    QPushButton *pushButton_drawCircle;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_15;
    QSpinBox *spinBox_dist;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QSpinBox *spinBox_yRot;
    QSpinBox *spinBox_xRot;
    QPushButton *pushButton_testY;
    QPushButton *pushButton_testX;
    QPushButton *pushButton_testDistance;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QSlider *timerSpeedSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButton;
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
        RobotDrawUi->resize(610, 581);
        centralwidget = new QWidget(RobotDrawUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_10 = new QHBoxLayout(tab);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_6);

        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_8->addWidget(graphicsView);


        horizontalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton_lift = new QPushButton(tab);
        pushButton_lift->setObjectName(QString::fromUtf8("pushButton_lift"));

        verticalLayout_5->addWidget(pushButton_lift);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        checkBox_circle = new QCheckBox(tab);
        checkBox_circle->setObjectName(QString::fromUtf8("checkBox_circle"));

        verticalLayout_5->addWidget(checkBox_circle);


        horizontalLayout_10->addLayout(verticalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_5 = new QHBoxLayout(tab_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_9->addLayout(horizontalLayout_9);

        textEdit_textInput = new QTextEdit(tab_4);
        textEdit_textInput->setObjectName(QString::fromUtf8("textEdit_textInput"));
        QFont font;
        font.setPointSize(25);
        textEdit_textInput->setFont(font);
        textEdit_textInput->setStyleSheet(QString::fromUtf8("background-color: white;         /* Hintergrundfarbe anpassen */\n"
"    border: 0.5px solid black;         /* Gleicher Rahmen wie dein Widget */\n"
"    border-radius: 0px;              /* Ecken eckig lassen */\n"
"    padding: 4px;                    /* Innenabstand anpassen */\n"
"    selection-background-color: #BBDDFF; /* Auswahlfarbe angleichen */\n"
"\n"
""));

        verticalLayout_9->addWidget(textEdit_textInput);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setMinimumSize(QSize(0, 50));
        horizontalLayout_12 = new QHBoxLayout(groupBox_5);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        spinBox_letterSize = new QSpinBox(groupBox_5);
        spinBox_letterSize->setObjectName(QString::fromUtf8("spinBox_letterSize"));
        spinBox_letterSize->setMinimum(1);
        spinBox_letterSize->setValue(10);

        horizontalLayout_12->addWidget(spinBox_letterSize);


        verticalLayout_4->addWidget(groupBox_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        pushButton_draw = new QPushButton(tab_4);
        pushButton_draw->setObjectName(QString::fromUtf8("pushButton_draw"));

        verticalLayout_4->addWidget(pushButton_draw);


        horizontalLayout_5->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_Point = new QRadioButton(groupBox);
        radioButton_Point->setObjectName(QString::fromUtf8("radioButton_Point"));

        horizontalLayout->addWidget(radioButton_Point);

        radioButton_Line = new QRadioButton(groupBox);
        radioButton_Line->setObjectName(QString::fromUtf8("radioButton_Line"));

        horizontalLayout->addWidget(radioButton_Line);


        verticalLayout_3->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        doubleSpinBox_x1 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_x1->setObjectName(QString::fromUtf8("doubleSpinBox_x1"));
        doubleSpinBox_x1->setDecimals(2);
        doubleSpinBox_x1->setMinimum(-200.000000000000000);
        doubleSpinBox_x1->setMaximum(200.000000000000000);
        doubleSpinBox_x1->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_x1, 0, 1, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_9, 0, 2, 1, 1);

        doubleSpinBox_y1 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_y1->setObjectName(QString::fromUtf8("doubleSpinBox_y1"));
        doubleSpinBox_y1->setMinimum(-300.000000000000000);
        doubleSpinBox_y1->setMaximum(300.300000000000011);

        gridLayout->addWidget(doubleSpinBox_y1, 0, 3, 1, 1);

        lineEdit_19 = new QLineEdit(groupBox);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        sizePolicy1.setHeightForWidth(lineEdit_19->sizePolicy().hasHeightForWidth());
        lineEdit_19->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_19, 1, 0, 1, 1);

        doubleSpinBox_x2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_x2->setObjectName(QString::fromUtf8("doubleSpinBox_x2"));
        doubleSpinBox_x2->setMinimum(-200.000000000000000);
        doubleSpinBox_x2->setMaximum(200.000000000000000);

        gridLayout->addWidget(doubleSpinBox_x2, 1, 1, 1, 1);

        lineEdit_20 = new QLineEdit(groupBox);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        sizePolicy1.setHeightForWidth(lineEdit_20->sizePolicy().hasHeightForWidth());
        lineEdit_20->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_20, 1, 2, 1, 1);

        doubleSpinBox_y2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_y2->setObjectName(QString::fromUtf8("doubleSpinBox_y2"));
        doubleSpinBox_y2->setMinimum(-300.000000000000000);
        doubleSpinBox_y2->setMaximum(300.000000000000000);

        gridLayout->addWidget(doubleSpinBox_y2, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        horizontalLayout_8->addWidget(groupBox);

        pushButton_drawLinePoint = new QPushButton(tab_2);
        pushButton_drawLinePoint->setObjectName(QString::fromUtf8("pushButton_drawLinePoint"));
        sizePolicy1.setHeightForWidth(pushButton_drawLinePoint->sizePolicy().hasHeightForWidth());
        pushButton_drawLinePoint->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(pushButton_drawLinePoint);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_2);

        doubleSpinBox_XMid = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_XMid->setObjectName(QString::fromUtf8("doubleSpinBox_XMid"));
        doubleSpinBox_XMid->setMinimum(-200.000000000000000);
        doubleSpinBox_XMid->setMaximum(200.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_XMid);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_3);

        doubleSpinBox_YMid = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_YMid->setObjectName(QString::fromUtf8("doubleSpinBox_YMid"));
        doubleSpinBox_YMid->setMinimum(-300.000000000000000);
        doubleSpinBox_YMid->setMaximum(300.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_YMid);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit_21 = new QLineEdit(groupBox_2);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_21->sizePolicy().hasHeightForWidth());
        lineEdit_21->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(lineEdit_21);

        doubleSpinBox_radius = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_radius->setObjectName(QString::fromUtf8("doubleSpinBox_radius"));

        horizontalLayout_13->addWidget(doubleSpinBox_radius);


        verticalLayout_6->addLayout(horizontalLayout_13);


        horizontalLayout_11->addWidget(groupBox_2);

        pushButton_drawCircle = new QPushButton(tab_2);
        pushButton_drawCircle->setObjectName(QString::fromUtf8("pushButton_drawCircle"));
        sizePolicy1.setHeightForWidth(pushButton_drawCircle->sizePolicy().hasHeightForWidth());
        pushButton_drawCircle->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(pushButton_drawCircle);


        verticalLayout_7->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_4 = new QHBoxLayout(tab_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_15 = new QLineEdit(groupBox_3);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        sizePolicy1.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit_15);

        spinBox_dist = new QSpinBox(groupBox_3);
        spinBox_dist->setObjectName(QString::fromUtf8("spinBox_dist"));
        sizePolicy2.setHeightForWidth(spinBox_dist->sizePolicy().hasHeightForWidth());
        spinBox_dist->setSizePolicy(sizePolicy2);
        spinBox_dist->setMinimum(-99);
        spinBox_dist->setValue(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_dist);

        lineEdit_16 = new QLineEdit(groupBox_3);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        sizePolicy1.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_16);

        lineEdit_17 = new QLineEdit(groupBox_3);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        sizePolicy1.setHeightForWidth(lineEdit_17->sizePolicy().hasHeightForWidth());
        lineEdit_17->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_17);

        spinBox_yRot = new QSpinBox(groupBox_3);
        spinBox_yRot->setObjectName(QString::fromUtf8("spinBox_yRot"));
        sizePolicy2.setHeightForWidth(spinBox_yRot->sizePolicy().hasHeightForWidth());
        spinBox_yRot->setSizePolicy(sizePolicy2);
        spinBox_yRot->setMinimum(-99);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_yRot);

        spinBox_xRot = new QSpinBox(groupBox_3);
        spinBox_xRot->setObjectName(QString::fromUtf8("spinBox_xRot"));
        sizePolicy2.setHeightForWidth(spinBox_xRot->sizePolicy().hasHeightForWidth());
        spinBox_xRot->setSizePolicy(sizePolicy2);
        spinBox_xRot->setMinimum(-99);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_xRot);

        pushButton_testY = new QPushButton(groupBox_3);
        pushButton_testY->setObjectName(QString::fromUtf8("pushButton_testY"));

        formLayout->setWidget(4, QFormLayout::LabelRole, pushButton_testY);

        pushButton_testX = new QPushButton(groupBox_3);
        pushButton_testX->setObjectName(QString::fromUtf8("pushButton_testX"));

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton_testX);

        pushButton_testDistance = new QPushButton(groupBox_3);
        pushButton_testDistance->setObjectName(QString::fromUtf8("pushButton_testDistance"));

        formLayout->setWidget(3, QFormLayout::LabelRole, pushButton_testDistance);


        horizontalLayout_4->addWidget(groupBox_3);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        timerSpeedSlider = new QSlider(groupBox_4);
        timerSpeedSlider->setObjectName(QString::fromUtf8("timerSpeedSlider"));
        timerSpeedSlider->setMinimum(4);
        timerSpeedSlider->setMaximum(1000);
        timerSpeedSlider->setValue(101);
        timerSpeedSlider->setSliderPosition(101);
        timerSpeedSlider->setOrientation(Qt::Horizontal);
        timerSpeedSlider->setInvertedAppearance(true);
        timerSpeedSlider->setInvertedControls(false);

        verticalLayout->addWidget(timerSpeedSlider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_10->addWidget(groupBox_4);

        radioButton = new QRadioButton(tab_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_10->addWidget(radioButton);


        horizontalLayout_4->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_3->addWidget(pushButtonStop);


        verticalLayout_2->addLayout(horizontalLayout_3);

        RobotDrawUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotDrawUi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 610, 21));
        RobotDrawUi->setMenuBar(menubar);
        statusbar = new QStatusBar(RobotDrawUi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RobotDrawUi->setStatusBar(statusbar);
        toolBar = new QToolBar(RobotDrawUi);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        RobotDrawUi->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(RobotDrawUi);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(RobotDrawUi);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDrawUi)
    {
        RobotDrawUi->setWindowTitle(QCoreApplication::translate("RobotDrawUi", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        tab->setToolTip(QCoreApplication::translate("RobotDrawUi", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("RobotDrawUi", "Flipchart", nullptr));
        pushButton_lift->setText(QCoreApplication::translate("RobotDrawUi", "Lift Tip", nullptr));
        checkBox_circle->setText(QCoreApplication::translate("RobotDrawUi", "Draw Circle", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RobotDrawUi", "Click Drawing", nullptr));
        label_5->setText(QCoreApplication::translate("RobotDrawUi", "Flipchart", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("RobotDrawUi", "Lettersize:", nullptr));
        pushButton_draw->setText(QCoreApplication::translate("RobotDrawUi", "Draw Text", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("RobotDrawUi", "Text Drawing", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RobotDrawUi", "Line / Point Definition", nullptr));
        radioButton_Point->setText(QCoreApplication::translate("RobotDrawUi", "Point", nullptr));
        radioButton_Line->setText(QCoreApplication::translate("RobotDrawUi", "Line", nullptr));
        lineEdit->setText(QCoreApplication::translate("RobotDrawUi", "X1 (mm)", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("RobotDrawUi", "Y1 (mm)", nullptr));
        lineEdit_19->setText(QCoreApplication::translate("RobotDrawUi", "X2 (mm)", nullptr));
        lineEdit_20->setText(QCoreApplication::translate("RobotDrawUi", "Y2 (mm)", nullptr));
        pushButton_drawLinePoint->setText(QCoreApplication::translate("RobotDrawUi", "Draw", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RobotDrawUi", "Circle", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RobotDrawUi", "X (mm)", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("RobotDrawUi", "Y (mm)", nullptr));
        lineEdit_21->setText(QCoreApplication::translate("RobotDrawUi", "Radius (mm)", nullptr));
        pushButton_drawCircle->setText(QCoreApplication::translate("RobotDrawUi", "Draw ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RobotDrawUi", "Manual Input", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("RobotDrawUi", "Plane Adjustment", nullptr));
        lineEdit_15->setText(QCoreApplication::translate("RobotDrawUi", "Tool Distance [mm]", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("RobotDrawUi", "Rot X-Axis [\302\260]", nullptr));
        lineEdit_17->setText(QCoreApplication::translate("RobotDrawUi", "Rot Y-Axis [\302\260]", nullptr));
        pushButton_testY->setText(QCoreApplication::translate("RobotDrawUi", "Test Rot X-Axis", nullptr));
        pushButton_testX->setText(QCoreApplication::translate("RobotDrawUi", "Test Rot Y-Axis", nullptr));
        pushButton_testDistance->setText(QCoreApplication::translate("RobotDrawUi", "Test Tool Distance", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("RobotDrawUi", "Simulation Speed", nullptr));
        label->setText(QCoreApplication::translate("RobotDrawUi", "Slow", nullptr));
        label_2->setText(QCoreApplication::translate("RobotDrawUi", "Fast", nullptr));
        radioButton->setText(QCoreApplication::translate("RobotDrawUi", "display Measurement Volume", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("RobotDrawUi", "Setup", nullptr));
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
