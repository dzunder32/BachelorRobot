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

    void on_pushButton_addLine_clicked();

    void on_pushButton_addP1_clicked();

    // void on_pushButton_addP2_clicked();

    void on_pushButton_History_clicked();

    void widgetDrawPoint(QVector3D point , float thickness, QColor color){_widget3d->drawPoint(point,thickness,color);}

    void on_pushButton_addCircle_clicked();


    void on_pushButton_draw_clicked();

    void on_spinBox_letterSize_valueChanged(int arg1);

    void on_horizontalSlider_x_sliderMoved(int position);

    void on_horizontalSlider_y_sliderMoved(int position);

    void on_horizontalSlider_z_sliderMoved(int position);

    void on_horizontalSlider_r_sliderMoved(int position);

private:
    Ui::RobotDrawUi *ui;
    RobotDraw *_robDraw;
    Widget3D *_widget3d;
    QThread robotThread;
    Robot *_robot;
    Plane *_plane;
    QVector2D P1,P2;
    QString P1X_Str,P1Y_Str,P2X_Str,P2Y_Str;
    QString historyText;
    bool preview_isDrawn = false;
    void insertRobotSequenceText(QString str);
    void initBuffers();
    void setTimerSpeed(int time_ms);
    void increaseTimerSpeed(float factor);
signals:
    void startDrawing();
    void stopDrawing();
public slots:
    void startDrawTimer();
    void stopDrawTimer();
    void drawLineWidget(QVector3D start,QVector3D end){_widget3d->addCylinderBetweenPoints(start,end);}
};

#endif // ROBOTDRAWUI_H
