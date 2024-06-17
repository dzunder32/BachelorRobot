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
    void AddPoint2Buffer(QVector3D pointBase){PointsBuffer.append(pointBase);robotSequence.append(1);}
    void AddLine2Buffer(QVector <QVector3D> lineBase){LinesBuffer.append(lineBase);robotSequence.append(2);}
    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return Base2RobotPoint(Plane2BasePoint(point3D));}
    void robDraw_onTimeout();
    void safeCurrentSequence();
    void setPreviousSequence();
private:
    Letters *_letters;
    Widget3D *_widget3d;
    Kinematik *_robotKinematik;
    Robot *_robot;
    Plane* _plane;

    bool line_isTrue = false;
    QVector3D firstLinePoint;
    double a,b,c,l1;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> currentLetter;
    QVector<QVector3D> cornerPoints;
    QVector<QVector3D> PointsBuffer, PointsBuffer_hist;
    QVector <QVector <QVector3D>> LinesBuffer, LinesBuffer_hist;
    QList <int> robotSequence, robotSequence_hist;

    void getLetter();

    void robot_setPoint(QVector3D position);


public slots:

signals:
    void stopTimer();
    void startTimer();
    void drawLine(QVector3D start,QVector3D end);

};

#endif // ROBOTDRAW_H
