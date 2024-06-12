#ifndef ROBOTDRAW_H
#define ROBOTDRAW_H

#include <QObject>
#include "kinematik.h"
#include <widget3d.h>
#include <plane.h>
#include "robot.h"
#include "letters.h"
#include <chrono>

class RobotDraw : public QObject
{
      Q_OBJECT
public:
    RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d);
    void setTimerTime(int time_ms){_timer->setInterval(time_ms);}
private:
    Letters *_letters;
    Widget3D *_widget3d;
    Kinematik *_robotKinematik;
    Robot *_robot;
    Plane* _plane;
    QTimer *_timer;
    int counter=0;
    double a,b,c,l1;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> currentLetter;

    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return Base2RobotPoint(Plane2BasePoint(point3D));}




    void runDraw();
    void getLetter();

    void robDraw_onTimeout();
    void robot_setPoint(QVector3D position);
public slots:
    void startTimer(){_timer->start();}
    void stopTimer(){_timer->stop();counter=0;}

};

#endif // ROBOTDRAW_H
