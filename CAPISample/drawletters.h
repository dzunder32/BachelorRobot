#ifndef DRAWLETTERS_H
#define DRAWLETTERS_H

#include <QMainWindow>
//#include "kinematik.h"
#include "windows.h"
#include "draw.h"
namespace Ui {
class DrawLetters;
}

class DrawLetters : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawLetters(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d, QWidget *parent = nullptr);
    ~DrawLetters();


public slots:

    void drawPointWidget(QVector3D point,float thickness);
    void deletePointWidget();
    void deleteLineWidget();
    void stopTimer();
    void drawLineWidget(QVector3D startPoint, QVector3D endPoint);
private slots:
//    void on_pushButton_Draw_clicked();
    void on_pushButton_2_clicked();
    void on_buttonDeletePoint_clicked();
//    void spinBox_valueChanged();
    void pB_draw_clicked();
    void on_spinBox_LetterSize_valueChanged(int arg1);

    void on_robotSpeedSlider_valueChanged(int value);


    void on_checkBox_2_clicked();

private:
    Ui::DrawLetters *ui;
    Draw *_draw;
    Widget3D *_widget3d;
    // Kinematik *_robotKin;
    QThread robotThread;
    Robot *_robot;
    bool pbStop;

};

#endif // DRAWLETTERS_H
