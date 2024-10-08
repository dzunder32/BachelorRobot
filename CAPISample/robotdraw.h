#ifndef ROBOTDRAW_H
#define ROBOTDRAW_H

#include <QObject>
#include "kinematik.h"
#include <widget3d.h>
#include <plane.h>
#include "robot.h"
#include "letters.h"
#include <QVariant>
#include <QtMath>
#include <QMatrix4x4>
#include <QVector4D>

#define POINT    1
#define LINE     2
#define CIRCLE   3
#define POINT_UP 4

class RobotDraw : public QObject
{
      Q_OBJECT
public:
    RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d);
    QTimer *_timer = new QTimer(this);

    bool dontDrawPoint = false;
    int prev_timerTime;
    int toolTipDistance = 0;
    double robotRange = 1000;

    void stopTimer_goHome();
    void AddPoint2Buffer  (QVector3D planePoint);
    void AddLine2Buffer   (QVector3D linePlane1, QVector3D linePlane2);
    void AddCircle2Buffer (QVariantList circleList);
    void AddPointUP2Buffer(QVector3D planePoint);
    void robDraw_onTimeout();
    void constructLetters (QString letter_Str);
    void resetShiftVector ();
    void initLetterSize   (float sizeFactor);
    void drawGrid();
    void clearBuffers(){CircleBuffer.clear();PointsBuffer.clear();LinesBuffer.clear();robotSequence.clear();line_isTrue=false;}
    void UpdatePlanePosition();
    void removeLastPoint(){qDebug()<<"here man";robotSequence.removeLast();PointsBuffer.removeLast();}
    void removeLastPointUP(){qDebug()<<"here man";robotSequence.removeLast();PointsUPBuffer.removeLast();}

private:
    Letters   *_letters;
    Widget3D  *_widget3d;
    Kinematik *_robotKinematik;
    Robot     *_robot;
    Plane     *_plane;

    bool  line_isTrue      = false;
    bool  plane_isFull     = false;
    bool  drawCircle       = false;
    bool  alreadyDrawn     = false;
    bool  alreadyDrawn_2   = false;
    bool  lastPoint_drawn  = false;

    int   moveAboveCounter = 2;
    int circlePoints_counter;
    int last_timerTime;

    float angleStep        = 10;
    float xBoxSize,yBoxSize,xSpace,ySpace;
    float circlePoints_number;

    double prev_l1=0,diff_l1=0;
    double a,b,c,l1;


    QVector2D shiftVector;
    QVector3D startLinePoint, endLinePoint;
    QVector3D robotPosition;
    QVector3D lastPoint;
    QVector3D _l1BasePos;

    QMatrix4x4 robotMat,planeRobot_T;

    QVector <QVector <QVector3D>> LinesBuffer;
    QVector<QVector3D> PointsBuffer,PointsUPBuffer;
    QVector <QVariantList> CircleBuffer;
    QVector <QVariantList> currentLetter;
    QList <int> robotSequence;

    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return QVector3D((robotMat.inverted() * _plane->matrix()) * point3D);}
    QVector3D Robot2BasePoint (QVector3D point3D){return QVector3D(robotMat * point3D);}

    double cartDistance(QVector3D V1,QVector3D V2){QVector3D V_diff=V2-V1;return V_diff.length();}
    bool shiftVec_inPlane();
    void robot_setPoint(QVector3D position);
    void robotDrawCircle();
    void robotDrawPoint();
    void robotDrawLine();

    void addLetter2Buffer();
    void getLetterData(QChar char_letter);
    void gotoNextBox();
    void moveTipAbove();

    void robot_moveCircular(QVector<QVector2D> circlePoints);
    void initCirclePointsSpeedUp(float range);
    void setL1(double val);
    float calculateAngleBetweenVectors(QVector3D vectorA, QVector3D vectorB);
    void  calculateL1_new(QVector3D adjustPoint);
    void  checkPlane();
    void  CirclePreview(QVariantList circleList);
    void DrawFirstPoint();
    void adjustRobotRangeHeigth(float height);

    void robotdrawPointUP();
public slots:
    void startDrawTimer(){DrawFirstPoint();_timer->start();}
    void stopDrawTimer(){_timer->stop();dontDrawPoint = true;emit clearGW();}
    void setTimerTime(int ms){_timer->setInterval(ms);last_timerTime = ms;}
    void changeTimerSpeed(float factor){_timer->setInterval(last_timerTime * factor);}

signals:
//    void changeTimerSpeed(float factor);
    void drawLine(QVector3D start,QVector3D end);
    void drawPoint_Widget(QVector3D point , float thickness, QColor color);
    void robotRangeChanged(float);
    void clearGW();
};

#endif // ROBOTDRAW_H
