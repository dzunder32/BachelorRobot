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
    QTimer *_timer;
    void setTimerTime(int time_ms){_timer->setInterval(time_ms);}
    void robot_moveHome();
    void UpdatePointsBuffer(QVector<QVector3D> pts);
    void AddPoint2Buffer(QVector3D pt){PointsBuffer.append(pt);robotSequence.append(1);}
    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return Base2RobotPoint(Plane2BasePoint(point3D));}
private:
    Letters *_letters;
    Widget3D *_widget3d;
    Kinematik *_robotKinematik;
    Robot *_robot;
    Plane* _plane;

    int counter=0;
    double a,b,c,l1;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> currentLetter;
    QVector<QVector3D> cornerPoints;
    QVector<QVector3D> PointsBuffer;
    QList <int> robotSequence;



    void runDraw();
    void getLetter();

    void robDraw_onTimeout();
    void robot_setPoint(QVector3D position);


    void robot_drawLine(QVector<QVector3D> linePTs);
public slots:

signals:
    void stopTimer();
    void startTimer();

};

#endif // ROBOTDRAW_H
