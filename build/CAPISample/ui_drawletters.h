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
#include <QtWidgets/QCheckBox>
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

class Ui_DrawLetters
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QSlider *robotSpeedSlider;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_Letter;
    QTextEdit *textEdit_Letter;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonDeletePoint;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Draw;
    QCheckBox *checkBox_NextLetter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DrawLetters)
    {
        if (DrawLetters->objectName().isEmpty())
            DrawLetters->setObjectName(QString::fromUtf8("DrawLetters"));
        DrawLetters->setEnabled(true);
        DrawLetters->resize(800, 600);
        centralwidget = new QWidget(DrawLetters);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(16);
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        robotSpeedSlider = new QSlider(centralwidget);
        robotSpeedSlider->setObjectName(QString::fromUtf8("robotSpeedSlider"));
        robotSpeedSlider->setFont(font);
        robotSpeedSlider->setMaximum(50);
        robotSpeedSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(robotSpeedSlider);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_Letter = new QLineEdit(centralwidget);
        lineEdit_Letter->setObjectName(QString::fromUtf8("lineEdit_Letter"));
        lineEdit_Letter->setFont(font);

        verticalLayout_2->addWidget(lineEdit_Letter);

        textEdit_Letter = new QTextEdit(centralwidget);
        textEdit_Letter->setObjectName(QString::fromUtf8("textEdit_Letter"));

        verticalLayout_2->addWidget(textEdit_Letter);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonDeletePoint = new QPushButton(centralwidget);
        buttonDeletePoint->setObjectName(QString::fromUtf8("buttonDeletePoint"));
        QFont font1;
        font1.setPointSize(14);
        buttonDeletePoint->setFont(font1);

        horizontalLayout->addWidget(buttonDeletePoint);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_Draw = new QPushButton(centralwidget);
        pushButton_Draw->setObjectName(QString::fromUtf8("pushButton_Draw"));
        pushButton_Draw->setFont(font1);

        horizontalLayout->addWidget(pushButton_Draw);

        checkBox_NextLetter = new QCheckBox(centralwidget);
        checkBox_NextLetter->setObjectName(QString::fromUtf8("checkBox_NextLetter"));
        checkBox_NextLetter->setFont(font1);

        horizontalLayout->addWidget(checkBox_NextLetter);


        verticalLayout_3->addLayout(horizontalLayout);

        DrawLetters->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DrawLetters);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
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
        lineEdit->setText(QCoreApplication::translate("DrawLetters", "RobotSpeed", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("DrawLetters", "Letter", nullptr));
        textEdit_Letter->setHtml(QCoreApplication::translate("DrawLetters", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">HALLO ICH BIN</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">DENIS WUHU</p></body></html>", nullptr));
        buttonDeletePoint->setText(QCoreApplication::translate("DrawLetters", "deletePoint", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DrawLetters", "Stop", nullptr));
        pushButton_Draw->setText(QCoreApplication::translate("DrawLetters", "Draw", nullptr));
        checkBox_NextLetter->setText(QCoreApplication::translate("DrawLetters", "Next Letter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawLetters: public Ui_DrawLetters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWLETTERS_H