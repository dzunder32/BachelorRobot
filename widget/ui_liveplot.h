/********************************************************************************
** Form generated from reading UI file 'liveplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVEPLOT_H
#define UI_LIVEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LivePlot
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ClearButton;
    QPushButton *DataButton;
    QGridLayout *gridLayout;
    QCustomPlot *plot_1;
    QCustomPlot *plot_2;
    QCustomPlot *plot;
    QVBoxLayout *verticalLayout;
    QLineEdit *numDataEdit;

    void setupUi(QMainWindow *LivePlot)
    {
        if (LivePlot->objectName().isEmpty())
            LivePlot->setObjectName(QString::fromUtf8("LivePlot"));
        LivePlot->setWindowModality(Qt::NonModal);
        LivePlot->resize(589, 559);
        centralwidget = new QWidget(LivePlot);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plot_1 = new QCustomPlot(centralwidget);
        plot_1->setObjectName(QString::fromUtf8("plot_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plot_1->sizePolicy().hasHeightForWidth());
        plot_1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot_1, 1, 0, 1, 1);

        plot_2 = new QCustomPlot(centralwidget);
        plot_2->setObjectName(QString::fromUtf8("plot_2"));
        sizePolicy1.setHeightForWidth(plot_2->sizePolicy().hasHeightForWidth());
        plot_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot_2, 0, 1, 1, 1);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        sizePolicy1.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        numDataEdit = new QLineEdit(centralwidget);
        numDataEdit->setObjectName(QString::fromUtf8("numDataEdit"));
        QFont font;
        font.setPointSize(14);
        numDataEdit->setFont(font);

        verticalLayout->addWidget(numDataEdit);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        LivePlot->setCentralWidget(centralwidget);

        retranslateUi(LivePlot);

        QMetaObject::connectSlotsByName(LivePlot);
    } // setupUi

    void retranslateUi(QMainWindow *LivePlot)
    {
        LivePlot->setWindowTitle(QCoreApplication::translate("LivePlot", "MainWindow", nullptr));
        ClearButton->setText(QCoreApplication::translate("LivePlot", "Clear", nullptr));
        DataButton->setText(QCoreApplication::translate("LivePlot", "Export data to txt-File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LivePlot: public Ui_LivePlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVEPLOT_H
