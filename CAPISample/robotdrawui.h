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

    void on_pushButton_setP1_clicked();

    void on_pushButton_setP2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_addLine_clicked();

private:
    Ui::RobotDrawUi *ui;
    RobotDraw *_robDraw;
    Widget3D *_widget3d;
    QThread robotThread;
    Robot *_robot;
    QVector3D P1,P2;
    QString P1X_Str,P1Y_Str,P2X_Str,P2Y_Str;
signals:
    void startDrawing();
    void stopDrawing();
public slots:
    void startDrawTimer(){_robDraw->_timer->start();}
    void stopDrawTimer(){_robDraw->_timer->stop();qDebug()<<"TimerStopped";}
    void drawLineWidget(QVector3D start,QVector3D end){_widget3d->addCylinderBetweenPoints(start,end);}
};

#endif // ROBOTDRAWUI_H
