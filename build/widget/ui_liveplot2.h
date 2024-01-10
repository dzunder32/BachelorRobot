/********************************************************************************
** Form generated from reading UI file 'liveplot2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVEPLOT2_H
#define UI_LIVEPLOT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LivePlot2
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ClearButton;
    QPushButton *DataButton;
    QGridLayout *gridLayout;
    QCustomPlot *plot_5;
    QCustomPlot *plot_3;
    QCustomPlot *plot_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *numDataEdit;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LivePlot2)
    {
        if (LivePlot2->objectName().isEmpty())
            LivePlot2->setObjectName(QString::fromUtf8("LivePlot2"));
        LivePlot2->resize(800, 600);
        centralwidget = new QWidget(LivePlot2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClearButton->sizePolicy().hasHeightForWidth());
        ClearButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ClearButton);

        DataButton = new QPushButton(centralwidget);
        DataButton->setObjectName(QString::fromUtf8("DataButton"));
        sizePolicy.setHeightForWidth(DataButton->sizePolicy().hasHeightForWidth());
        DataButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(DataButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plot_5 = new QCustomPlot(centralwidget);
        plot_5->setObjectName(QString::fromUtf8("plot_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plot_5->sizePolicy().hasHeightForWidth());
        plot_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot_5, 0, 1, 1, 1);

        plot_3 = new QCustomPlot(centralwidget);
        plot_3->setObjectName(QString::fromUtf8("plot_3"));
        sizePolicy1.setHeightForWidth(plot_3->sizePolicy().hasHeightForWidth());
        plot_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot_3, 0, 0, 1, 1);

        plot_4 = new QCustomPlot(centralwidget);
        plot_4->setObjectName(QString::fromUtf8("plot_4"));
        sizePolicy1.setHeightForWidth(plot_4->sizePolicy().hasHeightForWidth());
        plot_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot_4, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        numDataEdit = new QLineEdit(centralwidget);
        numDataEdit->setObjectName(QString::fromUtf8("numDataEdit"));
        sizePolicy.setHeightForWidth(numDataEdit->sizePolicy().hasHeightForWidth());
        numDataEdit->setSizePolicy(sizePolicy);
        numDataEdit->setMaximumSize(QSize(16777215, 16777215));
        numDataEdit->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(14);
        numDataEdit->setFont(font);
        numDataEdit->setLayoutDirection(Qt::LeftToRight);
        numDataEdit->setMaxLength(32769);
        numDataEdit->setAlignment(Qt::AlignCenter);
        numDataEdit->setDragEnabled(true);

        horizontalLayout_2->addWidget(numDataEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        LivePlot2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LivePlot2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LivePlot2->setMenuBar(menubar);
        statusbar = new QStatusBar(LivePlot2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LivePlot2->setStatusBar(statusbar);

        retranslateUi(LivePlot2);

        QMetaObject::connectSlotsByName(LivePlot2);
    } // setupUi

    void retranslateUi(QMainWindow *LivePlot2)
    {
        LivePlot2->setWindowTitle(QCoreApplication::translate("LivePlot2", "MainWindow", nullptr));
        ClearButton->setText(QCoreApplication::translate("LivePlot2", "Clear", nullptr));
        DataButton->setText(QCoreApplication::translate("LivePlot2", "Export data to txt-File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LivePlot2: public Ui_LivePlot2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVEPLOT2_H
