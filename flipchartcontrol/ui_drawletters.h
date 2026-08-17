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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
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
    QFormLayout *formLayout;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox_LetterSize;
    QLineEdit *lineEdit;
    QSlider *robotSpeedSlider;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;
    QSpinBox *spinBox_spacePoints;
    QCheckBox *checkBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_Letter;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonDeletePoint;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Draw;
    QHBoxLayout *horizontalLayout_3;
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
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QFont font;
        font.setPointSize(16);
        lineEdit_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit_2);

        spinBox_LetterSize = new QSpinBox(centralwidget);
        spinBox_LetterSize->setObjectName(QString::fromUtf8("spinBox_LetterSize"));
        spinBox_LetterSize->setFont(font);
        spinBox_LetterSize->setMinimum(1);
        spinBox_LetterSize->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::LabelRole, spinBox_LetterSize);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        robotSpeedSlider = new QSlider(centralwidget);
        robotSpeedSlider->setObjectName(QString::fromUtf8("robotSpeedSlider"));
        robotSpeedSlider->setFont(font);
        robotSpeedSlider->setMinimum(1);
        robotSpeedSlider->setMaximum(50);
        robotSpeedSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, robotSpeedSlider);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_3);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox);

        spinBox_spacePoints = new QSpinBox(centralwidget);
        spinBox_spacePoints->setObjectName(QString::fromUtf8("spinBox_spacePoints"));
        spinBox_spacePoints->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_spacePoints);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, checkBox_2);


        horizontalLayout_2->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit_Letter = new QTextEdit(centralwidget);
        textEdit_Letter->setObjectName(QString::fromUtf8("textEdit_Letter"));
        textEdit_Letter->setFont(font);

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


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);

        DrawLetters->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DrawLetters);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        lineEdit_2->setText(QCoreApplication::translate("DrawLetters", "LetterSize", nullptr));
        lineEdit->setText(QCoreApplication::translate("DrawLetters", "RobotSpeed", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("DrawLetters", "Space between Points ", nullptr));
        checkBox->setText(QCoreApplication::translate("DrawLetters", "Set Space to Slider Value", nullptr));
        checkBox_2->setText(QCoreApplication::translate("DrawLetters", "CheckBox", nullptr));
        textEdit_Letter->setHtml(QCoreApplication::translate("DrawLetters", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">HALLO ICH BIN</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">DENIS WUHU</span></p></body></html>", nullptr));
        buttonDeletePoint->setText(QCoreApplication::translate("DrawLetters", "deletePoint", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DrawLetters", "Start Stop", nullptr));
        pushButton_Draw->setText(QCoreApplication::translate("DrawLetters", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawLetters: public Ui_DrawLetters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWLETTERS_H
