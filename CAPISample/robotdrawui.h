#ifndef ROBOTDRAWUI_H
#define ROBOTDRAWUI_H

#include <QMainWindow>
#include "robotdraw.h"

namespace Ui {
class RobotDrawUi;
}

class RobotDrawUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotDrawUi(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d, QWidget *parent = nullptr);
    ~RobotDrawUi();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonDelete_clicked();

    void on_timerSpeedSlider_sliderMoved(int position);

private:
    Ui::RobotDrawUi *ui;
    RobotDraw *_robDraw;
    Widget3D *_widget3d;
    QThread robotThread;
    Robot *_robot;
signals:
    void startDrawing();
    void stopDrawing();
};

#endif // ROBOTDRAWUI_H
