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
#define L1CHANGE 4

class RobotDraw : public QObject
{
      Q_OBJECT
public:
    RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d);
    QTimer *_timer = new QTimer(this);
    int prev_timerTime;
    int toolTipDistance = 0;

    // int planeCounter = 0;

    //    void setTimerTime(int time_ms){_timer->setInterval(time_ms);}
    void stopTimer_goHome();

    void AddPoint2Buffer   (QVector3D planePoint);
    void AddLine2Buffer    (QVector3D linePlane1, QVector3D linePlane2);
    void AddCircle2Buffer  (QVariantList circleList);
    void AddL1Adjust2Buffer(QVector3D vec){robotSequence.append(L1CHANGE);L1Buffer.append(vec);}

    void robDraw_onTimeout ();
    void safeCurrentSequence();
    void setPreviousSequence();
    void constructLetters  (QString letter_Str);
    void resetShiftVector();
    void initLetterSize(float sizeFactor);
    void drawGrid();
    void clearBuffers(){CircleBuffer.clear();PointsBuffer.clear();LinesBuffer.clear();robotSequence.clear();line_isTrue=false;}
    // void PlanePositionChanged();
    void UpdatePlanePosition();

private:
    Letters   *_letters;
    Widget3D  *_widget3d;
    Kinematik *_robotKinematik;
    Robot     *_robot;
    Plane     *_plane;
    QVector3D _l1BasePos;
    int   moveAboveCounter = 2;
    bool  line_isTrue      = false;
    bool  plane_isFull     = false;
    bool  drawCircle       = false;
    bool  alreadyDrawn     = false;
    bool  lastPoint_drawn  = false;
    float angleStep        = 10;

    QVector3D lastPoint;

    QVector <QVector <QVector3D>> LinesBuffer, LinesBuffer_hist;
    QVector3D startLinePoint, endLinePoint;
    double a,b,c,l1;
    QMatrix4x4 robotMat;
    QVector<QVector3D> cornerPoints;
    QVector<QVector3D> PointsBuffer, PointsBuffer_hist, L1Buffer;
    QList <int> robotSequence, robotSequence_hist;
    QVector <QVariantList> CircleBuffer,CircleBuffer_hist;
    QVector <QVariantList> currentLetter;
    QVector2D shiftVector;
    float xBoxSize,yBoxSize,xSpace,ySpace;
    QMatrix4x4 rotation_plane;
    QMatrix4x4 planeRobot_T;
    float circlePoints_number;
    int circlePoints_counter;
    QVector3D robotPosition;
    int last_timerTime;

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
    void robotAdjustL1();

    void addLetter2Buffer();
    void getLetterData(QChar char_letter);


    void gotoNextBox();
    void moveTipAbove();
    // void robot_moveInArc(QVector<QVector2D> circlePoints);
    void robot_moveCircular(QVector<QVector2D> circlePoints);
    void initCirclePointsSpeedUp(float range);
    void setL1(double val);
//    void CalculateL1();
    float calculateAngleBetweenVectors(QVector3D vectorA, QVector3D vectorB);
    void  calculateL1_new();
    void  checkPlane();
    void  CirclePreview(QVariantList circleList);
public slots:
    void startDrawTimer(){_timer->start();alreadyDrawn=false;moveAboveCounter=1;}
    void stopDrawTimer(){_timer->stop();}
    void setTimerTime(int ms){_timer->setInterval(ms);last_timerTime = ms;}
    void changeTimerSpeed(float factor){_timer->setInterval(last_timerTime * factor);}

signals:
//    void changeTimerSpeed(float factor);
    void drawLine(QVector3D start,QVector3D end);
    void drawPoint_Widget(QVector3D point , float thickness, QColor color);

};

#endif // ROBOTDRAW_H
