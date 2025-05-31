/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *MovementMethod;
    QWidget *JointTab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_Joint1;
    QLabel *label_Joint2;
    QLabel *label_Joint3;
    QLabel *label_Joint4;
    QLabel *label_Joint5;
    QLabel *label_Joint6;
    QLabel *label_Joint7;
    QGridLayout *gridLayout_7;
    QPushButton *PB_J1_plus;
    QPushButton *PB_J3_plus;
    QPushButton *PB_J3_minus;
    QPushButton *PB_J2_plus;
    QPushButton *PB_J6_minus;
    QSlider *SliderJ5;
    QSlider *SliderJ1;
    QPushButton *PB_J2_minus;
    QPushButton *PB_J5_plus;
    QPushButton *PB_J1_minus;
    QSlider *SliderJ4;
    QPushButton *PB_J4_plus;
    QPushButton *PB_J5_minus;
    QPushButton *PB_J4_minus;
    QSlider *SliderJ3;
    QSlider *SliderJ2;
    QPushButton *PB_J6_plus;
    QSlider *SliderJ6;
    QPushButton *PB_J7_plus;
    QPushButton *PB_J7_minus;
    QSlider *SliderJ7;
    QWidget *BaseTab;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_BaseX;
    QLabel *label_BaseY;
    QLabel *label_BaseZ;
    QLabel *label_BaseA;
    QLabel *label_BaseB;
    QLabel *label_BaseC;
    QLabel *label_BaseL1;
    QGridLayout *gridLayout;
    QPushButton *PB_BaseX_minus;
    QPushButton *PB_BaseY_plus;
    QSpacerItem *horizontalSpacer_4;
    QSlider *Slider_BaseY;
    QPushButton *PB_BaseB_plus;
    QPushButton *PB_BaseZ_plus;
    QSlider *Slider_BaseC;
    QSlider *Slider_BaseZ;
    QPushButton *PB_BaseY_minus;
    QPushButton *PB_BaseC_minus;
    QSlider *Slider_BaseX;
    QPushButton *PB_BaseA_minus;
    QPushButton *PB_BaseB_minus;
    QPushButton *PB_BaseC_plus;
    QPushButton *PB_BaseZ_minus;
    QPushButton *PB_BaseA_plus;
    QPushButton *PB_BaseX_plus;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *PB_BaseL1_plus;
    QPushButton *PB_BaseL1_minus;
    QSlider *Slider_BaseL1;
    QWidget *ToolTab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_ToolX;
    QLabel *label_ToolY;
    QLabel *label_ToolZ;
    QLabel *label_ToolA;
    QLabel *label_ToolB;
    QLabel *label_ToolC;
    QGridLayout *gridLayout_3;
    QPushButton *PB_ToolX_minus;
    QPushButton *PB_ToolB_plus;
    QPushButton *PB_ToolZ_plus;
    QPushButton *PB_ToolY_minus;
    QPushButton *PB_ToolC_minus;
    QPushButton *PB_ToolA_minus;
    QPushButton *PB_ToolB_minus;
    QPushButton *PB_ToolY_plus;
    QPushButton *PB_ToolC_plus;
    QPushButton *PB_ToolZ_minus;
    QPushButton *PB_ToolA_plus;
    QPushButton *PB_ToolX_plus;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QDoubleSpinBox *SB_Increment;
    QPushButton *PB_Phome;
    QFrame *frame_Values;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_J1;
    QLabel *label_J2;
    QLabel *label_J3;
    QLabel *label_J4;
    QLabel *label_J5;
    QLabel *label_J6;
    QLabel *label_J7;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *sb_j1;
    QDoubleSpinBox *sb_j2;
    QDoubleSpinBox *sb_j3;
    QDoubleSpinBox *sb_j4;
    QDoubleSpinBox *sb_j5;
    QDoubleSpinBox *sb_j6;
    QDoubleSpinBox *sb_j7;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *sb_x;
    QDoubleSpinBox *sb_y;
    QDoubleSpinBox *sb_z;
    QDoubleSpinBox *sb_a;
    QDoubleSpinBox *sb_b;
    QDoubleSpinBox *sb_c;
    QDoubleSpinBox *sb_l1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_X;
    QLabel *label_Y;
    QLabel *label_Z;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_C;
    QLabel *label_L1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *cb_Flg1;
    QLabel *label_Konfig;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox_Flg2;
    QLabel *label_FL2;

    void setupUi(QWidget *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        ControlPanel->resize(555, 342);
        gridLayout_2 = new QGridLayout(ControlPanel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        MovementMethod = new QTabWidget(ControlPanel);
        MovementMethod->setObjectName(QString::fromUtf8("MovementMethod"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MovementMethod->sizePolicy().hasHeightForWidth());
        MovementMethod->setSizePolicy(sizePolicy);
        MovementMethod->setMinimumSize(QSize(200, 261));
        MovementMethod->setMaximumSize(QSize(16777215, 261));
        JointTab = new QWidget();
        JointTab->setObjectName(QString::fromUtf8("JointTab"));
        gridLayout_4 = new QGridLayout(JointTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_Joint1 = new QLabel(JointTab);
        label_Joint1->setObjectName(QString::fromUtf8("label_Joint1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Joint1->sizePolicy().hasHeightForWidth());
        label_Joint1->setSizePolicy(sizePolicy1);
        label_Joint1->setMinimumSize(QSize(20, 20));
        label_Joint1->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint1);

        label_Joint2 = new QLabel(JointTab);
        label_Joint2->setObjectName(QString::fromUtf8("label_Joint2"));
        sizePolicy1.setHeightForWidth(label_Joint2->sizePolicy().hasHeightForWidth());
        label_Joint2->setSizePolicy(sizePolicy1);
        label_Joint2->setMinimumSize(QSize(20, 20));
        label_Joint2->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint2);

        label_Joint3 = new QLabel(JointTab);
        label_Joint3->setObjectName(QString::fromUtf8("label_Joint3"));
        sizePolicy1.setHeightForWidth(label_Joint3->sizePolicy().hasHeightForWidth());
        label_Joint3->setSizePolicy(sizePolicy1);
        label_Joint3->setMinimumSize(QSize(20, 20));
        label_Joint3->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint3);

        label_Joint4 = new QLabel(JointTab);
        label_Joint4->setObjectName(QString::fromUtf8("label_Joint4"));
        sizePolicy1.setHeightForWidth(label_Joint4->sizePolicy().hasHeightForWidth());
        label_Joint4->setSizePolicy(sizePolicy1);
        label_Joint4->setMinimumSize(QSize(20, 20));
        label_Joint4->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint4);

        label_Joint5 = new QLabel(JointTab);
        label_Joint5->setObjectName(QString::fromUtf8("label_Joint5"));
        sizePolicy1.setHeightForWidth(label_Joint5->sizePolicy().hasHeightForWidth());
        label_Joint5->setSizePolicy(sizePolicy1);
        label_Joint5->setMinimumSize(QSize(20, 20));
        label_Joint5->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint5);

        label_Joint6 = new QLabel(JointTab);
        label_Joint6->setObjectName(QString::fromUtf8("label_Joint6"));
        sizePolicy1.setHeightForWidth(label_Joint6->sizePolicy().hasHeightForWidth());
        label_Joint6->setSizePolicy(sizePolicy1);
        label_Joint6->setMinimumSize(QSize(20, 20));
        label_Joint6->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint6);

        label_Joint7 = new QLabel(JointTab);
        label_Joint7->setObjectName(QString::fromUtf8("label_Joint7"));
        sizePolicy1.setHeightForWidth(label_Joint7->sizePolicy().hasHeightForWidth());
        label_Joint7->setSizePolicy(sizePolicy1);
        label_Joint7->setMinimumSize(QSize(20, 20));
        label_Joint7->setMaximumSize(QSize(20, 20));

        verticalLayout_10->addWidget(label_Joint7);


        gridLayout_4->addLayout(verticalLayout_10, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_7->setContentsMargins(-1, -1, 0, -1);
        PB_J1_plus = new QPushButton(JointTab);
        PB_J1_plus->setObjectName(QString::fromUtf8("PB_J1_plus"));
        sizePolicy1.setHeightForWidth(PB_J1_plus->sizePolicy().hasHeightForWidth());
        PB_J1_plus->setSizePolicy(sizePolicy1);
        PB_J1_plus->setMinimumSize(QSize(0, 0));
        PB_J1_plus->setMaximumSize(QSize(25, 16777215));
        PB_J1_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J1_plus, 0, 0, 1, 1);

        PB_J3_plus = new QPushButton(JointTab);
        PB_J3_plus->setObjectName(QString::fromUtf8("PB_J3_plus"));
        sizePolicy1.setHeightForWidth(PB_J3_plus->sizePolicy().hasHeightForWidth());
        PB_J3_plus->setSizePolicy(sizePolicy1);
        PB_J3_plus->setMinimumSize(QSize(0, 0));
        PB_J3_plus->setMaximumSize(QSize(25, 16777215));
        PB_J3_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J3_plus, 2, 0, 1, 1);

        PB_J3_minus = new QPushButton(JointTab);
        PB_J3_minus->setObjectName(QString::fromUtf8("PB_J3_minus"));
        sizePolicy1.setHeightForWidth(PB_J3_minus->sizePolicy().hasHeightForWidth());
        PB_J3_minus->setSizePolicy(sizePolicy1);
        PB_J3_minus->setMinimumSize(QSize(0, 0));
        PB_J3_minus->setMaximumSize(QSize(25, 16777215));
        PB_J3_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J3_minus, 2, 1, 1, 1);

        PB_J2_plus = new QPushButton(JointTab);
        PB_J2_plus->setObjectName(QString::fromUtf8("PB_J2_plus"));
        sizePolicy1.setHeightForWidth(PB_J2_plus->sizePolicy().hasHeightForWidth());
        PB_J2_plus->setSizePolicy(sizePolicy1);
        PB_J2_plus->setMinimumSize(QSize(0, 0));
        PB_J2_plus->setMaximumSize(QSize(25, 16777215));
        PB_J2_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J2_plus, 1, 0, 1, 1);

        PB_J6_minus = new QPushButton(JointTab);
        PB_J6_minus->setObjectName(QString::fromUtf8("PB_J6_minus"));
        sizePolicy1.setHeightForWidth(PB_J6_minus->sizePolicy().hasHeightForWidth());
        PB_J6_minus->setSizePolicy(sizePolicy1);
        PB_J6_minus->setMinimumSize(QSize(0, 0));
        PB_J6_minus->setMaximumSize(QSize(25, 16777215));
        PB_J6_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J6_minus, 5, 1, 1, 1);

        SliderJ5 = new QSlider(JointTab);
        SliderJ5->setObjectName(QString::fromUtf8("SliderJ5"));
        SliderJ5->setMinimumSize(QSize(0, 20));
        SliderJ5->setMaximumSize(QSize(16777215, 20));
        SliderJ5->setMinimum(-120);
        SliderJ5->setMaximum(120);
        SliderJ5->setPageStep(0);
        SliderJ5->setTracking(true);
        SliderJ5->setOrientation(Qt::Horizontal);
        SliderJ5->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ5, 4, 2, 1, 1);

        SliderJ1 = new QSlider(JointTab);
        SliderJ1->setObjectName(QString::fromUtf8("SliderJ1"));
        SliderJ1->setMinimumSize(QSize(0, 20));
        SliderJ1->setMaximumSize(QSize(16777215, 20));
        SliderJ1->setMinimum(-240);
        SliderJ1->setMaximum(240);
        SliderJ1->setPageStep(0);
        SliderJ1->setTracking(true);
        SliderJ1->setOrientation(Qt::Horizontal);
        SliderJ1->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ1, 0, 2, 1, 1);

        PB_J2_minus = new QPushButton(JointTab);
        PB_J2_minus->setObjectName(QString::fromUtf8("PB_J2_minus"));
        sizePolicy1.setHeightForWidth(PB_J2_minus->sizePolicy().hasHeightForWidth());
        PB_J2_minus->setSizePolicy(sizePolicy1);
        PB_J2_minus->setMinimumSize(QSize(0, 0));
        PB_J2_minus->setMaximumSize(QSize(25, 16777215));
        PB_J2_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J2_minus, 1, 1, 1, 1);

        PB_J5_plus = new QPushButton(JointTab);
        PB_J5_plus->setObjectName(QString::fromUtf8("PB_J5_plus"));
        sizePolicy1.setHeightForWidth(PB_J5_plus->sizePolicy().hasHeightForWidth());
        PB_J5_plus->setSizePolicy(sizePolicy1);
        PB_J5_plus->setMinimumSize(QSize(0, 0));
        PB_J5_plus->setMaximumSize(QSize(25, 16777215));
        PB_J5_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J5_plus, 4, 0, 1, 1);

        PB_J1_minus = new QPushButton(JointTab);
        PB_J1_minus->setObjectName(QString::fromUtf8("PB_J1_minus"));
        sizePolicy1.setHeightForWidth(PB_J1_minus->sizePolicy().hasHeightForWidth());
        PB_J1_minus->setSizePolicy(sizePolicy1);
        PB_J1_minus->setMinimumSize(QSize(0, 0));
        PB_J1_minus->setMaximumSize(QSize(25, 16777215));
        PB_J1_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J1_minus, 0, 1, 1, 1);

        SliderJ4 = new QSlider(JointTab);
        SliderJ4->setObjectName(QString::fromUtf8("SliderJ4"));
        SliderJ4->setMinimumSize(QSize(0, 20));
        SliderJ4->setMaximumSize(QSize(16777215, 20));
        SliderJ4->setMinimum(-200);
        SliderJ4->setMaximum(200);
        SliderJ4->setPageStep(0);
        SliderJ4->setTracking(true);
        SliderJ4->setOrientation(Qt::Horizontal);
        SliderJ4->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ4, 3, 2, 1, 1);

        PB_J4_plus = new QPushButton(JointTab);
        PB_J4_plus->setObjectName(QString::fromUtf8("PB_J4_plus"));
        sizePolicy1.setHeightForWidth(PB_J4_plus->sizePolicy().hasHeightForWidth());
        PB_J4_plus->setSizePolicy(sizePolicy1);
        PB_J4_plus->setMinimumSize(QSize(0, 0));
        PB_J4_plus->setMaximumSize(QSize(25, 16777215));
        PB_J4_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J4_plus, 3, 0, 1, 1);

        PB_J5_minus = new QPushButton(JointTab);
        PB_J5_minus->setObjectName(QString::fromUtf8("PB_J5_minus"));
        sizePolicy1.setHeightForWidth(PB_J5_minus->sizePolicy().hasHeightForWidth());
        PB_J5_minus->setSizePolicy(sizePolicy1);
        PB_J5_minus->setMinimumSize(QSize(0, 0));
        PB_J5_minus->setMaximumSize(QSize(25, 16777215));
        PB_J5_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J5_minus, 4, 1, 1, 1);

        PB_J4_minus = new QPushButton(JointTab);
        PB_J4_minus->setObjectName(QString::fromUtf8("PB_J4_minus"));
        sizePolicy1.setHeightForWidth(PB_J4_minus->sizePolicy().hasHeightForWidth());
        PB_J4_minus->setSizePolicy(sizePolicy1);
        PB_J4_minus->setMinimumSize(QSize(0, 0));
        PB_J4_minus->setMaximumSize(QSize(25, 16777215));
        PB_J4_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J4_minus, 3, 1, 1, 1);

        SliderJ3 = new QSlider(JointTab);
        SliderJ3->setObjectName(QString::fromUtf8("SliderJ3"));
        SliderJ3->setMinimumSize(QSize(0, 20));
        SliderJ3->setMaximumSize(QSize(16777215, 20));
        SliderJ3->setMaximum(164);
        SliderJ3->setPageStep(0);
        SliderJ3->setTracking(true);
        SliderJ3->setOrientation(Qt::Horizontal);
        SliderJ3->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ3, 2, 2, 1, 1);

        SliderJ2 = new QSlider(JointTab);
        SliderJ2->setObjectName(QString::fromUtf8("SliderJ2"));
        SliderJ2->setMinimumSize(QSize(0, 20));
        SliderJ2->setMaximumSize(QSize(16777215, 20));
        SliderJ2->setMinimum(-120);
        SliderJ2->setMaximum(120);
        SliderJ2->setSingleStep(1);
        SliderJ2->setPageStep(0);
        SliderJ2->setTracking(true);
        SliderJ2->setOrientation(Qt::Horizontal);
        SliderJ2->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ2, 1, 2, 1, 1);

        PB_J6_plus = new QPushButton(JointTab);
        PB_J6_plus->setObjectName(QString::fromUtf8("PB_J6_plus"));
        sizePolicy1.setHeightForWidth(PB_J6_plus->sizePolicy().hasHeightForWidth());
        PB_J6_plus->setSizePolicy(sizePolicy1);
        PB_J6_plus->setMinimumSize(QSize(0, 0));
        PB_J6_plus->setMaximumSize(QSize(25, 16777215));
        PB_J6_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J6_plus, 5, 0, 1, 1);

        SliderJ6 = new QSlider(JointTab);
        SliderJ6->setObjectName(QString::fromUtf8("SliderJ6"));
        SliderJ6->setMinimumSize(QSize(0, 20));
        SliderJ6->setMaximumSize(QSize(16777215, 20));
        SliderJ6->setMinimum(-360);
        SliderJ6->setMaximum(360);
        SliderJ6->setPageStep(0);
        SliderJ6->setValue(0);
        SliderJ6->setTracking(true);
        SliderJ6->setOrientation(Qt::Horizontal);
        SliderJ6->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ6, 5, 2, 1, 1);

        PB_J7_plus = new QPushButton(JointTab);
        PB_J7_plus->setObjectName(QString::fromUtf8("PB_J7_plus"));
        sizePolicy1.setHeightForWidth(PB_J7_plus->sizePolicy().hasHeightForWidth());
        PB_J7_plus->setSizePolicy(sizePolicy1);
        PB_J7_plus->setMinimumSize(QSize(0, 0));
        PB_J7_plus->setMaximumSize(QSize(25, 16777215));
        PB_J7_plus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J7_plus, 6, 0, 1, 1);

        PB_J7_minus = new QPushButton(JointTab);
        PB_J7_minus->setObjectName(QString::fromUtf8("PB_J7_minus"));
        sizePolicy1.setHeightForWidth(PB_J7_minus->sizePolicy().hasHeightForWidth());
        PB_J7_minus->setSizePolicy(sizePolicy1);
        PB_J7_minus->setMinimumSize(QSize(0, 0));
        PB_J7_minus->setMaximumSize(QSize(25, 16777215));
        PB_J7_minus->setAutoRepeat(true);

        gridLayout_7->addWidget(PB_J7_minus, 6, 1, 1, 1);

        SliderJ7 = new QSlider(JointTab);
        SliderJ7->setObjectName(QString::fromUtf8("SliderJ7"));
        SliderJ7->setMinimumSize(QSize(0, 20));
        SliderJ7->setMaximumSize(QSize(16777215, 20));
        SliderJ7->setMinimum(-800);
        SliderJ7->setMaximum(800);
        SliderJ7->setPageStep(0);
        SliderJ7->setValue(0);
        SliderJ7->setTracking(true);
        SliderJ7->setOrientation(Qt::Horizontal);
        SliderJ7->setTickPosition(QSlider::NoTicks);

        gridLayout_7->addWidget(SliderJ7, 6, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_7, 0, 1, 1, 1);

        MovementMethod->addTab(JointTab, QString());
        BaseTab = new QWidget();
        BaseTab->setObjectName(QString::fromUtf8("BaseTab"));
        horizontalLayout_4 = new QHBoxLayout(BaseTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_BaseX = new QLabel(BaseTab);
        label_BaseX->setObjectName(QString::fromUtf8("label_BaseX"));
        sizePolicy1.setHeightForWidth(label_BaseX->sizePolicy().hasHeightForWidth());
        label_BaseX->setSizePolicy(sizePolicy1);
        label_BaseX->setMinimumSize(QSize(20, 20));
        label_BaseX->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseX);

        label_BaseY = new QLabel(BaseTab);
        label_BaseY->setObjectName(QString::fromUtf8("label_BaseY"));
        sizePolicy1.setHeightForWidth(label_BaseY->sizePolicy().hasHeightForWidth());
        label_BaseY->setSizePolicy(sizePolicy1);
        label_BaseY->setMinimumSize(QSize(20, 20));
        label_BaseY->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseY);

        label_BaseZ = new QLabel(BaseTab);
        label_BaseZ->setObjectName(QString::fromUtf8("label_BaseZ"));
        sizePolicy1.setHeightForWidth(label_BaseZ->sizePolicy().hasHeightForWidth());
        label_BaseZ->setSizePolicy(sizePolicy1);
        label_BaseZ->setMinimumSize(QSize(20, 20));
        label_BaseZ->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseZ);

        label_BaseA = new QLabel(BaseTab);
        label_BaseA->setObjectName(QString::fromUtf8("label_BaseA"));
        sizePolicy1.setHeightForWidth(label_BaseA->sizePolicy().hasHeightForWidth());
        label_BaseA->setSizePolicy(sizePolicy1);
        label_BaseA->setMinimumSize(QSize(20, 20));
        label_BaseA->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseA);

        label_BaseB = new QLabel(BaseTab);
        label_BaseB->setObjectName(QString::fromUtf8("label_BaseB"));
        sizePolicy1.setHeightForWidth(label_BaseB->sizePolicy().hasHeightForWidth());
        label_BaseB->setSizePolicy(sizePolicy1);
        label_BaseB->setMinimumSize(QSize(20, 20));
        label_BaseB->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseB);

        label_BaseC = new QLabel(BaseTab);
        label_BaseC->setObjectName(QString::fromUtf8("label_BaseC"));
        sizePolicy1.setHeightForWidth(label_BaseC->sizePolicy().hasHeightForWidth());
        label_BaseC->setSizePolicy(sizePolicy1);
        label_BaseC->setMinimumSize(QSize(20, 20));
        label_BaseC->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseC);

        label_BaseL1 = new QLabel(BaseTab);
        label_BaseL1->setObjectName(QString::fromUtf8("label_BaseL1"));
        sizePolicy1.setHeightForWidth(label_BaseL1->sizePolicy().hasHeightForWidth());
        label_BaseL1->setSizePolicy(sizePolicy1);
        label_BaseL1->setMinimumSize(QSize(20, 20));
        label_BaseL1->setMaximumSize(QSize(20, 20));

        verticalLayout_14->addWidget(label_BaseL1);


        horizontalLayout_4->addLayout(verticalLayout_14);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PB_BaseX_minus = new QPushButton(BaseTab);
        PB_BaseX_minus->setObjectName(QString::fromUtf8("PB_BaseX_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseX_minus->sizePolicy().hasHeightForWidth());
        PB_BaseX_minus->setSizePolicy(sizePolicy1);
        PB_BaseX_minus->setMinimumSize(QSize(0, 0));
        PB_BaseX_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseX_minus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseX_minus, 0, 1, 1, 1);

        PB_BaseY_plus = new QPushButton(BaseTab);
        PB_BaseY_plus->setObjectName(QString::fromUtf8("PB_BaseY_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseY_plus->sizePolicy().hasHeightForWidth());
        PB_BaseY_plus->setSizePolicy(sizePolicy1);
        PB_BaseY_plus->setMinimumSize(QSize(0, 0));
        PB_BaseY_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseY_plus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseY_plus, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        Slider_BaseY = new QSlider(BaseTab);
        Slider_BaseY->setObjectName(QString::fromUtf8("Slider_BaseY"));
        Slider_BaseY->setMinimumSize(QSize(0, 20));
        Slider_BaseY->setMaximumSize(QSize(16777215, 20));
        Slider_BaseY->setMinimum(-1000);
        Slider_BaseY->setMaximum(1000);
        Slider_BaseY->setPageStep(0);
        Slider_BaseY->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Slider_BaseY, 1, 2, 1, 1);

        PB_BaseB_plus = new QPushButton(BaseTab);
        PB_BaseB_plus->setObjectName(QString::fromUtf8("PB_BaseB_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseB_plus->sizePolicy().hasHeightForWidth());
        PB_BaseB_plus->setSizePolicy(sizePolicy1);
        PB_BaseB_plus->setMinimumSize(QSize(0, 20));
        PB_BaseB_plus->setMaximumSize(QSize(25, 11111111));
        PB_BaseB_plus->setAutoRepeat(true);
        PB_BaseB_plus->setAutoRepeatDelay(100);
        PB_BaseB_plus->setAutoRepeatInterval(25);

        gridLayout->addWidget(PB_BaseB_plus, 4, 0, 1, 1);

        PB_BaseZ_plus = new QPushButton(BaseTab);
        PB_BaseZ_plus->setObjectName(QString::fromUtf8("PB_BaseZ_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseZ_plus->sizePolicy().hasHeightForWidth());
        PB_BaseZ_plus->setSizePolicy(sizePolicy1);
        PB_BaseZ_plus->setMinimumSize(QSize(0, 0));
        PB_BaseZ_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseZ_plus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseZ_plus, 2, 0, 1, 1);

        Slider_BaseC = new QSlider(BaseTab);
        Slider_BaseC->setObjectName(QString::fromUtf8("Slider_BaseC"));
        Slider_BaseC->setMinimumSize(QSize(0, 20));
        Slider_BaseC->setMaximumSize(QSize(16777215, 20));
        Slider_BaseC->setMinimum(-180);
        Slider_BaseC->setMaximum(180);
        Slider_BaseC->setPageStep(0);
        Slider_BaseC->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Slider_BaseC, 5, 2, 1, 1);

        Slider_BaseZ = new QSlider(BaseTab);
        Slider_BaseZ->setObjectName(QString::fromUtf8("Slider_BaseZ"));
        Slider_BaseZ->setMinimumSize(QSize(0, 20));
        Slider_BaseZ->setMaximumSize(QSize(16777215, 20));
        Slider_BaseZ->setMinimum(-1000);
        Slider_BaseZ->setMaximum(1000);
        Slider_BaseZ->setPageStep(0);
        Slider_BaseZ->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Slider_BaseZ, 2, 2, 1, 1);

        PB_BaseY_minus = new QPushButton(BaseTab);
        PB_BaseY_minus->setObjectName(QString::fromUtf8("PB_BaseY_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseY_minus->sizePolicy().hasHeightForWidth());
        PB_BaseY_minus->setSizePolicy(sizePolicy1);
        PB_BaseY_minus->setMinimumSize(QSize(0, 0));
        PB_BaseY_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseY_minus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseY_minus, 1, 1, 1, 1);

        PB_BaseC_minus = new QPushButton(BaseTab);
        PB_BaseC_minus->setObjectName(QString::fromUtf8("PB_BaseC_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseC_minus->sizePolicy().hasHeightForWidth());
        PB_BaseC_minus->setSizePolicy(sizePolicy1);
        PB_BaseC_minus->setMinimumSize(QSize(0, 0));
        PB_BaseC_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseC_minus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseC_minus, 5, 1, 1, 1);

        Slider_BaseX = new QSlider(BaseTab);
        Slider_BaseX->setObjectName(QString::fromUtf8("Slider_BaseX"));
        Slider_BaseX->setMinimumSize(QSize(0, 20));
        Slider_BaseX->setMaximumSize(QSize(16777215, 20));
        Slider_BaseX->setMinimum(-1000);
        Slider_BaseX->setMaximum(1000);
        Slider_BaseX->setPageStep(0);
        Slider_BaseX->setValue(335);
        Slider_BaseX->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Slider_BaseX, 0, 2, 1, 1);

        PB_BaseA_minus = new QPushButton(BaseTab);
        PB_BaseA_minus->setObjectName(QString::fromUtf8("PB_BaseA_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseA_minus->sizePolicy().hasHeightForWidth());
        PB_BaseA_minus->setSizePolicy(sizePolicy1);
        PB_BaseA_minus->setMinimumSize(QSize(0, 20));
        PB_BaseA_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseA_minus->setAutoRepeat(true);
        PB_BaseA_minus->setAutoRepeatDelay(100);
        PB_BaseA_minus->setAutoRepeatInterval(25);

        gridLayout->addWidget(PB_BaseA_minus, 3, 1, 1, 1);

        PB_BaseB_minus = new QPushButton(BaseTab);
        PB_BaseB_minus->setObjectName(QString::fromUtf8("PB_BaseB_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseB_minus->sizePolicy().hasHeightForWidth());
        PB_BaseB_minus->setSizePolicy(sizePolicy1);
        PB_BaseB_minus->setMinimumSize(QSize(0, 20));
        PB_BaseB_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseB_minus->setAutoRepeat(true);
        PB_BaseB_minus->setAutoRepeatDelay(100);
        PB_BaseB_minus->setAutoRepeatInterval(25);

        gridLayout->addWidget(PB_BaseB_minus, 4, 1, 1, 1);

        PB_BaseC_plus = new QPushButton(BaseTab);
        PB_BaseC_plus->setObjectName(QString::fromUtf8("PB_BaseC_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseC_plus->sizePolicy().hasHeightForWidth());
        PB_BaseC_plus->setSizePolicy(sizePolicy1);
        PB_BaseC_plus->setMinimumSize(QSize(0, 0));
        PB_BaseC_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseC_plus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseC_plus, 5, 0, 1, 1);

        PB_BaseZ_minus = new QPushButton(BaseTab);
        PB_BaseZ_minus->setObjectName(QString::fromUtf8("PB_BaseZ_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseZ_minus->sizePolicy().hasHeightForWidth());
        PB_BaseZ_minus->setSizePolicy(sizePolicy1);
        PB_BaseZ_minus->setMinimumSize(QSize(0, 0));
        PB_BaseZ_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseZ_minus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseZ_minus, 2, 1, 1, 1);

        PB_BaseA_plus = new QPushButton(BaseTab);
        PB_BaseA_plus->setObjectName(QString::fromUtf8("PB_BaseA_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseA_plus->sizePolicy().hasHeightForWidth());
        PB_BaseA_plus->setSizePolicy(sizePolicy1);
        PB_BaseA_plus->setMinimumSize(QSize(0, 20));
        PB_BaseA_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseA_plus->setAutoRepeat(true);
        PB_BaseA_plus->setAutoRepeatDelay(100);
        PB_BaseA_plus->setAutoRepeatInterval(25);

        gridLayout->addWidget(PB_BaseA_plus, 3, 0, 1, 1);

        PB_BaseX_plus = new QPushButton(BaseTab);
        PB_BaseX_plus->setObjectName(QString::fromUtf8("PB_BaseX_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseX_plus->sizePolicy().hasHeightForWidth());
        PB_BaseX_plus->setSizePolicy(sizePolicy1);
        PB_BaseX_plus->setMinimumSize(QSize(0, 0));
        PB_BaseX_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseX_plus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseX_plus, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        PB_BaseL1_plus = new QPushButton(BaseTab);
        PB_BaseL1_plus->setObjectName(QString::fromUtf8("PB_BaseL1_plus"));
        sizePolicy1.setHeightForWidth(PB_BaseL1_plus->sizePolicy().hasHeightForWidth());
        PB_BaseL1_plus->setSizePolicy(sizePolicy1);
        PB_BaseL1_plus->setMinimumSize(QSize(0, 0));
        PB_BaseL1_plus->setMaximumSize(QSize(25, 16777215));
        PB_BaseL1_plus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseL1_plus, 6, 0, 1, 1);

        PB_BaseL1_minus = new QPushButton(BaseTab);
        PB_BaseL1_minus->setObjectName(QString::fromUtf8("PB_BaseL1_minus"));
        sizePolicy1.setHeightForWidth(PB_BaseL1_minus->sizePolicy().hasHeightForWidth());
        PB_BaseL1_minus->setSizePolicy(sizePolicy1);
        PB_BaseL1_minus->setMinimumSize(QSize(0, 0));
        PB_BaseL1_minus->setMaximumSize(QSize(25, 16777215));
        PB_BaseL1_minus->setAutoRepeat(true);

        gridLayout->addWidget(PB_BaseL1_minus, 6, 1, 1, 1);

        Slider_BaseL1 = new QSlider(BaseTab);
        Slider_BaseL1->setObjectName(QString::fromUtf8("Slider_BaseL1"));
        Slider_BaseL1->setMinimumSize(QSize(0, 20));
        Slider_BaseL1->setMaximumSize(QSize(16777215, 20));
        Slider_BaseL1->setMinimum(-800);
        Slider_BaseL1->setMaximum(800);
        Slider_BaseL1->setPageStep(0);
        Slider_BaseL1->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Slider_BaseL1, 6, 2, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        MovementMethod->addTab(BaseTab, QString());
        ToolTab = new QWidget();
        ToolTab->setObjectName(QString::fromUtf8("ToolTab"));
        horizontalLayout_5 = new QHBoxLayout(ToolTab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_ToolX = new QLabel(ToolTab);
        label_ToolX->setObjectName(QString::fromUtf8("label_ToolX"));
        sizePolicy1.setHeightForWidth(label_ToolX->sizePolicy().hasHeightForWidth());
        label_ToolX->setSizePolicy(sizePolicy1);
        label_ToolX->setMinimumSize(QSize(20, 20));
        label_ToolX->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolX);

        label_ToolY = new QLabel(ToolTab);
        label_ToolY->setObjectName(QString::fromUtf8("label_ToolY"));
        sizePolicy1.setHeightForWidth(label_ToolY->sizePolicy().hasHeightForWidth());
        label_ToolY->setSizePolicy(sizePolicy1);
        label_ToolY->setMinimumSize(QSize(20, 20));
        label_ToolY->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolY);

        label_ToolZ = new QLabel(ToolTab);
        label_ToolZ->setObjectName(QString::fromUtf8("label_ToolZ"));
        sizePolicy1.setHeightForWidth(label_ToolZ->sizePolicy().hasHeightForWidth());
        label_ToolZ->setSizePolicy(sizePolicy1);
        label_ToolZ->setMinimumSize(QSize(20, 20));
        label_ToolZ->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolZ);

        label_ToolA = new QLabel(ToolTab);
        label_ToolA->setObjectName(QString::fromUtf8("label_ToolA"));
        sizePolicy1.setHeightForWidth(label_ToolA->sizePolicy().hasHeightForWidth());
        label_ToolA->setSizePolicy(sizePolicy1);
        label_ToolA->setMinimumSize(QSize(20, 20));
        label_ToolA->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolA);

        label_ToolB = new QLabel(ToolTab);
        label_ToolB->setObjectName(QString::fromUtf8("label_ToolB"));
        sizePolicy1.setHeightForWidth(label_ToolB->sizePolicy().hasHeightForWidth());
        label_ToolB->setSizePolicy(sizePolicy1);
        label_ToolB->setMinimumSize(QSize(20, 20));
        label_ToolB->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolB);

        label_ToolC = new QLabel(ToolTab);
        label_ToolC->setObjectName(QString::fromUtf8("label_ToolC"));
        sizePolicy1.setHeightForWidth(label_ToolC->sizePolicy().hasHeightForWidth());
        label_ToolC->setSizePolicy(sizePolicy1);
        label_ToolC->setMinimumSize(QSize(20, 20));
        label_ToolC->setMaximumSize(QSize(20, 20));

        verticalLayout_15->addWidget(label_ToolC);


        horizontalLayout_5->addLayout(verticalLayout_15);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        PB_ToolX_minus = new QPushButton(ToolTab);
        PB_ToolX_minus->setObjectName(QString::fromUtf8("PB_ToolX_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolX_minus->sizePolicy().hasHeightForWidth());
        PB_ToolX_minus->setSizePolicy(sizePolicy1);
        PB_ToolX_minus->setMinimumSize(QSize(0, 0));
        PB_ToolX_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolX_minus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolX_minus, 0, 1, 1, 1);

        PB_ToolB_plus = new QPushButton(ToolTab);
        PB_ToolB_plus->setObjectName(QString::fromUtf8("PB_ToolB_plus"));
        sizePolicy1.setHeightForWidth(PB_ToolB_plus->sizePolicy().hasHeightForWidth());
        PB_ToolB_plus->setSizePolicy(sizePolicy1);
        PB_ToolB_plus->setMinimumSize(QSize(0, 20));
        PB_ToolB_plus->setMaximumSize(QSize(100, 11111111));
        PB_ToolB_plus->setAutoRepeat(true);
        PB_ToolB_plus->setAutoRepeatDelay(100);
        PB_ToolB_plus->setAutoRepeatInterval(25);

        gridLayout_3->addWidget(PB_ToolB_plus, 4, 0, 1, 1);

        PB_ToolZ_plus = new QPushButton(ToolTab);
        PB_ToolZ_plus->setObjectName(QString::fromUtf8("PB_ToolZ_plus"));
        sizePolicy1.setHeightForWidth(PB_ToolZ_plus->sizePolicy().hasHeightForWidth());
        PB_ToolZ_plus->setSizePolicy(sizePolicy1);
        PB_ToolZ_plus->setMinimumSize(QSize(0, 0));
        PB_ToolZ_plus->setMaximumSize(QSize(100, 16777215));
        PB_ToolZ_plus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolZ_plus, 2, 0, 1, 1);

        PB_ToolY_minus = new QPushButton(ToolTab);
        PB_ToolY_minus->setObjectName(QString::fromUtf8("PB_ToolY_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolY_minus->sizePolicy().hasHeightForWidth());
        PB_ToolY_minus->setSizePolicy(sizePolicy1);
        PB_ToolY_minus->setMinimumSize(QSize(0, 0));
        PB_ToolY_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolY_minus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolY_minus, 1, 1, 1, 1);

        PB_ToolC_minus = new QPushButton(ToolTab);
        PB_ToolC_minus->setObjectName(QString::fromUtf8("PB_ToolC_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolC_minus->sizePolicy().hasHeightForWidth());
        PB_ToolC_minus->setSizePolicy(sizePolicy1);
        PB_ToolC_minus->setMinimumSize(QSize(0, 0));
        PB_ToolC_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolC_minus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolC_minus, 5, 1, 1, 1);

        PB_ToolA_minus = new QPushButton(ToolTab);
        PB_ToolA_minus->setObjectName(QString::fromUtf8("PB_ToolA_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolA_minus->sizePolicy().hasHeightForWidth());
        PB_ToolA_minus->setSizePolicy(sizePolicy1);
        PB_ToolA_minus->setMinimumSize(QSize(0, 20));
        PB_ToolA_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolA_minus->setAutoRepeat(true);
        PB_ToolA_minus->setAutoRepeatDelay(100);
        PB_ToolA_minus->setAutoRepeatInterval(25);

        gridLayout_3->addWidget(PB_ToolA_minus, 3, 1, 1, 1);

        PB_ToolB_minus = new QPushButton(ToolTab);
        PB_ToolB_minus->setObjectName(QString::fromUtf8("PB_ToolB_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolB_minus->sizePolicy().hasHeightForWidth());
        PB_ToolB_minus->setSizePolicy(sizePolicy1);
        PB_ToolB_minus->setMinimumSize(QSize(0, 20));
        PB_ToolB_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolB_minus->setAutoRepeat(true);
        PB_ToolB_minus->setAutoRepeatDelay(100);
        PB_ToolB_minus->setAutoRepeatInterval(25);

        gridLayout_3->addWidget(PB_ToolB_minus, 4, 1, 1, 1);

        PB_ToolY_plus = new QPushButton(ToolTab);
        PB_ToolY_plus->setObjectName(QString::fromUtf8("PB_ToolY_plus"));
        sizePolicy1.setHeightForWidth(PB_ToolY_plus->sizePolicy().hasHeightForWidth());
        PB_ToolY_plus->setSizePolicy(sizePolicy1);
        PB_ToolY_plus->setMinimumSize(QSize(0, 0));
        PB_ToolY_plus->setMaximumSize(QSize(100, 16777215));
        PB_ToolY_plus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolY_plus, 1, 0, 1, 1);

        PB_ToolC_plus = new QPushButton(ToolTab);
        PB_ToolC_plus->setObjectName(QString::fromUtf8("PB_ToolC_plus"));
        sizePolicy1.setHeightForWidth(PB_ToolC_plus->sizePolicy().hasHeightForWidth());
        PB_ToolC_plus->setSizePolicy(sizePolicy1);
        PB_ToolC_plus->setMinimumSize(QSize(0, 0));
        PB_ToolC_plus->setMaximumSize(QSize(100, 16777215));
        PB_ToolC_plus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolC_plus, 5, 0, 1, 1);

        PB_ToolZ_minus = new QPushButton(ToolTab);
        PB_ToolZ_minus->setObjectName(QString::fromUtf8("PB_ToolZ_minus"));
        sizePolicy1.setHeightForWidth(PB_ToolZ_minus->sizePolicy().hasHeightForWidth());
        PB_ToolZ_minus->setSizePolicy(sizePolicy1);
        PB_ToolZ_minus->setMinimumSize(QSize(0, 0));
        PB_ToolZ_minus->setMaximumSize(QSize(100, 16777215));
        PB_ToolZ_minus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolZ_minus, 2, 1, 1, 1);

        PB_ToolA_plus = new QPushButton(ToolTab);
        PB_ToolA_plus->setObjectName(QString::fromUtf8("PB_ToolA_plus"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PB_ToolA_plus->sizePolicy().hasHeightForWidth());
        PB_ToolA_plus->setSizePolicy(sizePolicy2);
        PB_ToolA_plus->setMinimumSize(QSize(0, 20));
        PB_ToolA_plus->setMaximumSize(QSize(100, 16777215));
        PB_ToolA_plus->setAutoRepeat(true);
        PB_ToolA_plus->setAutoRepeatDelay(100);
        PB_ToolA_plus->setAutoRepeatInterval(25);

        gridLayout_3->addWidget(PB_ToolA_plus, 3, 0, 1, 1);

        PB_ToolX_plus = new QPushButton(ToolTab);
        PB_ToolX_plus->setObjectName(QString::fromUtf8("PB_ToolX_plus"));
        sizePolicy1.setHeightForWidth(PB_ToolX_plus->sizePolicy().hasHeightForWidth());
        PB_ToolX_plus->setSizePolicy(sizePolicy1);
        PB_ToolX_plus->setMinimumSize(QSize(0, 0));
        PB_ToolX_plus->setMaximumSize(QSize(100, 16777215));
        PB_ToolX_plus->setAutoRepeat(true);

        gridLayout_3->addWidget(PB_ToolX_plus, 0, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_3);

        MovementMethod->addTab(ToolTab, QString());

        verticalLayout_6->addWidget(MovementMethod);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(ControlPanel);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(label);

        SB_Increment = new QDoubleSpinBox(ControlPanel);
        SB_Increment->setObjectName(QString::fromUtf8("SB_Increment"));
        sizePolicy3.setHeightForWidth(SB_Increment->sizePolicy().hasHeightForWidth());
        SB_Increment->setSizePolicy(sizePolicy3);
        SB_Increment->setMinimum(0.500000000000000);
        SB_Increment->setMaximum(10.000000000000000);
        SB_Increment->setSingleStep(0.500000000000000);
        SB_Increment->setValue(1.000000000000000);

        horizontalLayout_8->addWidget(SB_Increment);

        PB_Phome = new QPushButton(ControlPanel);
        PB_Phome->setObjectName(QString::fromUtf8("PB_Phome"));
        sizePolicy3.setHeightForWidth(PB_Phome->sizePolicy().hasHeightForWidth());
        PB_Phome->setSizePolicy(sizePolicy3);
        PB_Phome->setMinimumSize(QSize(0, 25));
        PB_Phome->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(PB_Phome);


        verticalLayout_6->addLayout(horizontalLayout_8);


        gridLayout_2->addLayout(verticalLayout_6, 0, 0, 1, 1);

        frame_Values = new QFrame(ControlPanel);
        frame_Values->setObjectName(QString::fromUtf8("frame_Values"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_Values->sizePolicy().hasHeightForWidth());
        frame_Values->setSizePolicy(sizePolicy4);
        frame_Values->setMinimumSize(QSize(191, 287));
        frame_Values->setMaximumSize(QSize(16777215, 16777215));
        frame_Values->setFrameShape(QFrame::StyledPanel);
        frame_Values->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_Values);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_J1 = new QLabel(frame_Values);
        label_J1->setObjectName(QString::fromUtf8("label_J1"));
        sizePolicy3.setHeightForWidth(label_J1->sizePolicy().hasHeightForWidth());
        label_J1->setSizePolicy(sizePolicy3);
        label_J1->setMinimumSize(QSize(20, 20));
        label_J1->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J1);

        label_J2 = new QLabel(frame_Values);
        label_J2->setObjectName(QString::fromUtf8("label_J2"));
        sizePolicy3.setHeightForWidth(label_J2->sizePolicy().hasHeightForWidth());
        label_J2->setSizePolicy(sizePolicy3);
        label_J2->setMinimumSize(QSize(20, 20));
        label_J2->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J2);

        label_J3 = new QLabel(frame_Values);
        label_J3->setObjectName(QString::fromUtf8("label_J3"));
        sizePolicy3.setHeightForWidth(label_J3->sizePolicy().hasHeightForWidth());
        label_J3->setSizePolicy(sizePolicy3);
        label_J3->setMinimumSize(QSize(20, 20));
        label_J3->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J3);

        label_J4 = new QLabel(frame_Values);
        label_J4->setObjectName(QString::fromUtf8("label_J4"));
        sizePolicy3.setHeightForWidth(label_J4->sizePolicy().hasHeightForWidth());
        label_J4->setSizePolicy(sizePolicy3);
        label_J4->setMinimumSize(QSize(20, 20));
        label_J4->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J4);

        label_J5 = new QLabel(frame_Values);
        label_J5->setObjectName(QString::fromUtf8("label_J5"));
        sizePolicy3.setHeightForWidth(label_J5->sizePolicy().hasHeightForWidth());
        label_J5->setSizePolicy(sizePolicy3);
        label_J5->setMinimumSize(QSize(20, 20));
        label_J5->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J5);

        label_J6 = new QLabel(frame_Values);
        label_J6->setObjectName(QString::fromUtf8("label_J6"));
        sizePolicy3.setHeightForWidth(label_J6->sizePolicy().hasHeightForWidth());
        label_J6->setSizePolicy(sizePolicy3);
        label_J6->setMinimumSize(QSize(20, 20));
        label_J6->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J6);

        label_J7 = new QLabel(frame_Values);
        label_J7->setObjectName(QString::fromUtf8("label_J7"));
        sizePolicy3.setHeightForWidth(label_J7->sizePolicy().hasHeightForWidth());
        label_J7->setSizePolicy(sizePolicy3);
        label_J7->setMinimumSize(QSize(20, 20));
        label_J7->setMaximumSize(QSize(20, 20));

        verticalLayout_3->addWidget(label_J7);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sb_j1 = new QDoubleSpinBox(frame_Values);
        sb_j1->setObjectName(QString::fromUtf8("sb_j1"));
        sizePolicy4.setHeightForWidth(sb_j1->sizePolicy().hasHeightForWidth());
        sb_j1->setSizePolicy(sizePolicy4);
        sb_j1->setMinimumSize(QSize(70, 30));
        sb_j1->setMaximumSize(QSize(50, 16777215));
        sb_j1->setReadOnly(false);
        sb_j1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j1->setDecimals(3);
        sb_j1->setMinimum(-240.000000000000000);
        sb_j1->setMaximum(240.000000000000000);

        verticalLayout->addWidget(sb_j1);

        sb_j2 = new QDoubleSpinBox(frame_Values);
        sb_j2->setObjectName(QString::fromUtf8("sb_j2"));
        sizePolicy4.setHeightForWidth(sb_j2->sizePolicy().hasHeightForWidth());
        sb_j2->setSizePolicy(sizePolicy4);
        sb_j2->setMinimumSize(QSize(70, 30));
        sb_j2->setMaximumSize(QSize(50, 16777215));
        sb_j2->setReadOnly(false);
        sb_j2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j2->setDecimals(3);
        sb_j2->setMinimum(-120.000000000000000);
        sb_j2->setValue(0.000000000000000);

        verticalLayout->addWidget(sb_j2);

        sb_j3 = new QDoubleSpinBox(frame_Values);
        sb_j3->setObjectName(QString::fromUtf8("sb_j3"));
        sizePolicy4.setHeightForWidth(sb_j3->sizePolicy().hasHeightForWidth());
        sb_j3->setSizePolicy(sizePolicy4);
        sb_j3->setMinimumSize(QSize(70, 30));
        sb_j3->setMaximumSize(QSize(50, 16777215));
        sb_j3->setReadOnly(false);
        sb_j3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j3->setDecimals(3);

        verticalLayout->addWidget(sb_j3);

        sb_j4 = new QDoubleSpinBox(frame_Values);
        sb_j4->setObjectName(QString::fromUtf8("sb_j4"));
        sizePolicy4.setHeightForWidth(sb_j4->sizePolicy().hasHeightForWidth());
        sb_j4->setSizePolicy(sizePolicy4);
        sb_j4->setMinimumSize(QSize(70, 30));
        sb_j4->setMaximumSize(QSize(50, 16777215));
        sb_j4->setReadOnly(false);
        sb_j4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j4->setDecimals(3);
        sb_j4->setMinimum(-200.000000000000000);
        sb_j4->setValue(0.000000000000000);

        verticalLayout->addWidget(sb_j4);

        sb_j5 = new QDoubleSpinBox(frame_Values);
        sb_j5->setObjectName(QString::fromUtf8("sb_j5"));
        sizePolicy4.setHeightForWidth(sb_j5->sizePolicy().hasHeightForWidth());
        sb_j5->setSizePolicy(sizePolicy4);
        sb_j5->setMinimumSize(QSize(70, 30));
        sb_j5->setMaximumSize(QSize(50, 16777215));
        sb_j5->setReadOnly(false);
        sb_j5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j5->setDecimals(3);
        sb_j5->setMinimum(-120.000000000000000);
        sb_j5->setValue(0.000000000000000);

        verticalLayout->addWidget(sb_j5);

        sb_j6 = new QDoubleSpinBox(frame_Values);
        sb_j6->setObjectName(QString::fromUtf8("sb_j6"));
        sizePolicy4.setHeightForWidth(sb_j6->sizePolicy().hasHeightForWidth());
        sb_j6->setSizePolicy(sizePolicy4);
        sb_j6->setMinimumSize(QSize(70, 30));
        sb_j6->setMaximumSize(QSize(50, 16777215));
        sb_j6->setReadOnly(false);
        sb_j6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j6->setDecimals(3);
        sb_j6->setMinimum(-360.000000000000000);
        sb_j6->setValue(0.000000000000000);

        verticalLayout->addWidget(sb_j6);

        sb_j7 = new QDoubleSpinBox(frame_Values);
        sb_j7->setObjectName(QString::fromUtf8("sb_j7"));
        sizePolicy4.setHeightForWidth(sb_j7->sizePolicy().hasHeightForWidth());
        sb_j7->setSizePolicy(sizePolicy4);
        sb_j7->setMinimumSize(QSize(70, 30));
        sb_j7->setMaximumSize(QSize(50, 16777215));
        sb_j7->setReadOnly(false);
        sb_j7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_j7->setDecimals(3);
        sb_j7->setMinimum(-800.000000000000000);
        sb_j7->setMaximum(800.000000000000000);
        sb_j7->setValue(0.000000000000000);

        verticalLayout->addWidget(sb_j7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sb_x = new QDoubleSpinBox(frame_Values);
        sb_x->setObjectName(QString::fromUtf8("sb_x"));
        sizePolicy4.setHeightForWidth(sb_x->sizePolicy().hasHeightForWidth());
        sb_x->setSizePolicy(sizePolicy4);
        sb_x->setMinimumSize(QSize(70, 30));
        sb_x->setMaximumSize(QSize(50, 16777215));
        sb_x->setReadOnly(false);
        sb_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_x->setDecimals(3);
        sb_x->setMinimum(-2000.000000000000000);
        sb_x->setMaximum(2000.000000000000000);

        verticalLayout_2->addWidget(sb_x);

        sb_y = new QDoubleSpinBox(frame_Values);
        sb_y->setObjectName(QString::fromUtf8("sb_y"));
        sizePolicy4.setHeightForWidth(sb_y->sizePolicy().hasHeightForWidth());
        sb_y->setSizePolicy(sizePolicy4);
        sb_y->setMinimumSize(QSize(70, 30));
        sb_y->setMaximumSize(QSize(50, 16777215));
        sb_y->setReadOnly(false);
        sb_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_y->setDecimals(3);
        sb_y->setMinimum(-1000.000000000000000);
        sb_y->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(sb_y);

        sb_z = new QDoubleSpinBox(frame_Values);
        sb_z->setObjectName(QString::fromUtf8("sb_z"));
        sizePolicy4.setHeightForWidth(sb_z->sizePolicy().hasHeightForWidth());
        sb_z->setSizePolicy(sizePolicy4);
        sb_z->setMinimumSize(QSize(70, 30));
        sb_z->setMaximumSize(QSize(50, 16777215));
        sb_z->setReadOnly(false);
        sb_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_z->setDecimals(3);
        sb_z->setMinimum(-1000.000000000000000);
        sb_z->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(sb_z);

        sb_a = new QDoubleSpinBox(frame_Values);
        sb_a->setObjectName(QString::fromUtf8("sb_a"));
        sizePolicy4.setHeightForWidth(sb_a->sizePolicy().hasHeightForWidth());
        sb_a->setSizePolicy(sizePolicy4);
        sb_a->setMinimumSize(QSize(70, 30));
        sb_a->setMaximumSize(QSize(50, 16777215));
        sb_a->setReadOnly(false);
        sb_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_a->setDecimals(3);
        sb_a->setMinimum(-1000.000000000000000);
        sb_a->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(sb_a);

        sb_b = new QDoubleSpinBox(frame_Values);
        sb_b->setObjectName(QString::fromUtf8("sb_b"));
        sizePolicy4.setHeightForWidth(sb_b->sizePolicy().hasHeightForWidth());
        sb_b->setSizePolicy(sizePolicy4);
        sb_b->setMinimumSize(QSize(70, 30));
        sb_b->setMaximumSize(QSize(50, 16777215));
        sb_b->setReadOnly(false);
        sb_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_b->setDecimals(3);
        sb_b->setMinimum(-1000.000000000000000);
        sb_b->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(sb_b);

        sb_c = new QDoubleSpinBox(frame_Values);
        sb_c->setObjectName(QString::fromUtf8("sb_c"));
        sizePolicy4.setHeightForWidth(sb_c->sizePolicy().hasHeightForWidth());
        sb_c->setSizePolicy(sizePolicy4);
        sb_c->setMinimumSize(QSize(70, 30));
        sb_c->setMaximumSize(QSize(50, 16777215));
        sb_c->setReadOnly(false);
        sb_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_c->setDecimals(3);
        sb_c->setMinimum(-1000.000000000000000);
        sb_c->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(sb_c);

        sb_l1 = new QDoubleSpinBox(frame_Values);
        sb_l1->setObjectName(QString::fromUtf8("sb_l1"));
        sizePolicy4.setHeightForWidth(sb_l1->sizePolicy().hasHeightForWidth());
        sb_l1->setSizePolicy(sizePolicy4);
        sb_l1->setMinimumSize(QSize(70, 30));
        sb_l1->setMaximumSize(QSize(50, 16777215));
        sb_l1->setReadOnly(false);
        sb_l1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sb_l1->setDecimals(3);
        sb_l1->setMinimum(-800.000000000000000);
        sb_l1->setMaximum(800.000000000000000);

        verticalLayout_2->addWidget(sb_l1);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_X = new QLabel(frame_Values);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        sizePolicy3.setHeightForWidth(label_X->sizePolicy().hasHeightForWidth());
        label_X->setSizePolicy(sizePolicy3);
        label_X->setMinimumSize(QSize(20, 20));
        label_X->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_X);

        label_Y = new QLabel(frame_Values);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        sizePolicy3.setHeightForWidth(label_Y->sizePolicy().hasHeightForWidth());
        label_Y->setSizePolicy(sizePolicy3);
        label_Y->setMinimumSize(QSize(20, 20));
        label_Y->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_Y);

        label_Z = new QLabel(frame_Values);
        label_Z->setObjectName(QString::fromUtf8("label_Z"));
        sizePolicy3.setHeightForWidth(label_Z->sizePolicy().hasHeightForWidth());
        label_Z->setSizePolicy(sizePolicy3);
        label_Z->setMinimumSize(QSize(20, 20));
        label_Z->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_Z);

        label_A = new QLabel(frame_Values);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        sizePolicy3.setHeightForWidth(label_A->sizePolicy().hasHeightForWidth());
        label_A->setSizePolicy(sizePolicy3);
        label_A->setMinimumSize(QSize(20, 20));
        label_A->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_A);

        label_B = new QLabel(frame_Values);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        sizePolicy3.setHeightForWidth(label_B->sizePolicy().hasHeightForWidth());
        label_B->setSizePolicy(sizePolicy3);
        label_B->setMinimumSize(QSize(20, 20));
        label_B->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_B);

        label_C = new QLabel(frame_Values);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        sizePolicy3.setHeightForWidth(label_C->sizePolicy().hasHeightForWidth());
        label_C->setSizePolicy(sizePolicy3);
        label_C->setMinimumSize(QSize(20, 20));
        label_C->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_C);

        label_L1 = new QLabel(frame_Values);
        label_L1->setObjectName(QString::fromUtf8("label_L1"));
        sizePolicy3.setHeightForWidth(label_L1->sizePolicy().hasHeightForWidth());
        label_L1->setSizePolicy(sizePolicy3);
        label_L1->setMinimumSize(QSize(20, 20));
        label_L1->setMaximumSize(QSize(20, 20));

        verticalLayout_4->addWidget(label_L1);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cb_Flg1 = new QComboBox(frame_Values);
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->addItem(QString());
        cb_Flg1->setObjectName(QString::fromUtf8("cb_Flg1"));

        horizontalLayout_2->addWidget(cb_Flg1);

        label_Konfig = new QLabel(frame_Values);
        label_Konfig->setObjectName(QString::fromUtf8("label_Konfig"));
        sizePolicy3.setHeightForWidth(label_Konfig->sizePolicy().hasHeightForWidth());
        label_Konfig->setSizePolicy(sizePolicy3);
        label_Konfig->setMinimumSize(QSize(30, 20));
        label_Konfig->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(label_Konfig);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        spinBox_Flg2 = new QSpinBox(frame_Values);
        spinBox_Flg2->setObjectName(QString::fromUtf8("spinBox_Flg2"));
        spinBox_Flg2->setFrame(true);
        spinBox_Flg2->setReadOnly(true);
        spinBox_Flg2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_19->addWidget(spinBox_Flg2);

        label_FL2 = new QLabel(frame_Values);
        label_FL2->setObjectName(QString::fromUtf8("label_FL2"));
        label_FL2->setMinimumSize(QSize(30, 20));
        label_FL2->setMaximumSize(QSize(20, 20));

        horizontalLayout_19->addWidget(label_FL2);


        verticalLayout_5->addLayout(horizontalLayout_19);


        gridLayout_2->addWidget(frame_Values, 0, 1, 1, 1);


        retranslateUi(ControlPanel);

        MovementMethod->setCurrentIndex(1);
        cb_Flg1->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QWidget *ControlPanel)
    {
        ControlPanel->setWindowTitle(QCoreApplication::translate("ControlPanel", "Form", nullptr));
        label_Joint1->setText(QCoreApplication::translate("ControlPanel", "J1", nullptr));
        label_Joint2->setText(QCoreApplication::translate("ControlPanel", "J2", nullptr));
        label_Joint3->setText(QCoreApplication::translate("ControlPanel", "J3", nullptr));
        label_Joint4->setText(QCoreApplication::translate("ControlPanel", "J4", nullptr));
        label_Joint5->setText(QCoreApplication::translate("ControlPanel", "J5", nullptr));
        label_Joint6->setText(QCoreApplication::translate("ControlPanel", "J6", nullptr));
        label_Joint7->setText(QCoreApplication::translate("ControlPanel", "J7", nullptr));
        PB_J1_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J3_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J3_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J2_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J6_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J2_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J5_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J1_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J4_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J5_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J4_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_J6_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J7_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_J7_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        MovementMethod->setTabText(MovementMethod->indexOf(JointTab), QCoreApplication::translate("ControlPanel", "Joint", nullptr));
        label_BaseX->setText(QCoreApplication::translate("ControlPanel", "X", nullptr));
        label_BaseY->setText(QCoreApplication::translate("ControlPanel", "Y", nullptr));
        label_BaseZ->setText(QCoreApplication::translate("ControlPanel", "Z", nullptr));
        label_BaseA->setText(QCoreApplication::translate("ControlPanel", "A", nullptr));
        label_BaseB->setText(QCoreApplication::translate("ControlPanel", "B", nullptr));
        label_BaseC->setText(QCoreApplication::translate("ControlPanel", "C", nullptr));
        label_BaseL1->setText(QCoreApplication::translate("ControlPanel", "L1", nullptr));
        PB_BaseX_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseY_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseB_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseZ_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseY_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseC_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseA_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseB_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseC_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseZ_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_BaseA_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseX_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseL1_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_BaseL1_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        MovementMethod->setTabText(MovementMethod->indexOf(BaseTab), QCoreApplication::translate("ControlPanel", "Base", nullptr));
        label_ToolX->setText(QCoreApplication::translate("ControlPanel", "X", nullptr));
        label_ToolY->setText(QCoreApplication::translate("ControlPanel", "Y", nullptr));
        label_ToolZ->setText(QCoreApplication::translate("ControlPanel", "Z", nullptr));
        label_ToolA->setText(QCoreApplication::translate("ControlPanel", "A", nullptr));
        label_ToolB->setText(QCoreApplication::translate("ControlPanel", "B", nullptr));
        label_ToolC->setText(QCoreApplication::translate("ControlPanel", "C", nullptr));
        PB_ToolX_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolB_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_ToolZ_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_ToolY_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolC_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolA_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolB_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolY_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_ToolC_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_ToolZ_minus->setText(QCoreApplication::translate("ControlPanel", "-", nullptr));
        PB_ToolA_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        PB_ToolX_plus->setText(QCoreApplication::translate("ControlPanel", "+", nullptr));
        MovementMethod->setTabText(MovementMethod->indexOf(ToolTab), QCoreApplication::translate("ControlPanel", "Tool", nullptr));
        label->setText(QCoreApplication::translate("ControlPanel", "+/- Increment:", nullptr));
        PB_Phome->setText(QCoreApplication::translate("ControlPanel", "Home Position", nullptr));
        label_J1->setText(QCoreApplication::translate("ControlPanel", "J1", nullptr));
        label_J2->setText(QCoreApplication::translate("ControlPanel", "J2", nullptr));
        label_J3->setText(QCoreApplication::translate("ControlPanel", "J3", nullptr));
        label_J4->setText(QCoreApplication::translate("ControlPanel", "J4", nullptr));
        label_J5->setText(QCoreApplication::translate("ControlPanel", "J5", nullptr));
        label_J6->setText(QCoreApplication::translate("ControlPanel", "J6", nullptr));
        label_J7->setText(QCoreApplication::translate("ControlPanel", "J7", nullptr));
        sb_j5->setSuffix(QString());
        label_X->setText(QCoreApplication::translate("ControlPanel", "X", nullptr));
        label_Y->setText(QCoreApplication::translate("ControlPanel", "Y", nullptr));
        label_Z->setText(QCoreApplication::translate("ControlPanel", "Z", nullptr));
        label_A->setText(QCoreApplication::translate("ControlPanel", "A", nullptr));
        label_B->setText(QCoreApplication::translate("ControlPanel", "B", nullptr));
        label_C->setText(QCoreApplication::translate("ControlPanel", "C", nullptr));
        label_L1->setText(QCoreApplication::translate("ControlPanel", "L1", nullptr));
        cb_Flg1->setItemText(0, QCoreApplication::translate("ControlPanel", "L,B,F", nullptr));
        cb_Flg1->setItemText(1, QCoreApplication::translate("ControlPanel", "L,B,N", nullptr));
        cb_Flg1->setItemText(2, QCoreApplication::translate("ControlPanel", "L,A,F", nullptr));
        cb_Flg1->setItemText(3, QCoreApplication::translate("ControlPanel", "L,A,N", nullptr));
        cb_Flg1->setItemText(4, QCoreApplication::translate("ControlPanel", "R,B,F", nullptr));
        cb_Flg1->setItemText(5, QCoreApplication::translate("ControlPanel", "R,B,N", nullptr));
        cb_Flg1->setItemText(6, QCoreApplication::translate("ControlPanel", "R,A,F", nullptr));
        cb_Flg1->setItemText(7, QCoreApplication::translate("ControlPanel", "R,A,N", nullptr));

        label_Konfig->setText(QCoreApplication::translate("ControlPanel", "Fl1", nullptr));
        label_FL2->setText(QCoreApplication::translate("ControlPanel", "FL2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
