#ifndef ROBOTDRAW_H
#define ROBOTDRAW_H

#include <QObject>
#include "kinematik.h"
#include <widget3d.h>
#include <plane.h>
#include "robot.h"
#include "letters.h"
#include <chrono>
#include <QVariant>
#include <QtMath>

#define POINT 1
#define LINE 2
#define CIRCLE 3

class RobotDraw : public QObject
{
      Q_OBJECT
public:
    RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d);
    QTimer *_timer;
    void setTimerTime(int time_ms){_timer->setInterval(time_ms);}
    void stopTimer_goHome();
    void UpdatePointsBuffer(QVector<QVector3D> pts);
    void AddPoint2Buffer(QVector3D pointPlane){PointsBuffer.append(Plane2BasePoint(pointPlane));robotSequence.append(POINT);}
    void AddLine2Buffer(QVector <QVector3D> linePlane){LinesBuffer.append(linePlane);robotSequence.append(LINE);}
    void AddLine2Circle(QVariantList circleList){CircleBuffer.append(circleList);robotSequence.append(CIRCLE);}
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
    bool simulation_isTrue = true;
    QVector3D firstLinePoint;
    double a,b,c,l1;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> currentLetter;
    QVector<QVector3D> cornerPoints;
    QVector<QVector3D> PointsBuffer, PointsBuffer_hist;
    QVector <QVector <QVector3D>> LinesBuffer, LinesBuffer_hist;
    QList <int> robotSequence, robotSequence_hist;
    QVector <QVariantList> CircleBuffer;



    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return Base2RobotPoint(Plane2BasePoint(point3D));}

    void robot_setPoint(QVector3D position);



    void robotDrawCircle();
    void robotDrawPoint();
    void robotDrawLine();
public slots:

signals:
    void stopTimer();
    void startTimer();
    void drawLine(QVector3D start,QVector3D end);
    void drawPoint_Widget(QVector3D point , float thickness, QColor color);

};

#endif // ROBOTDRAW_H
