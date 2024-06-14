#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include "kinematik.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <widget3d.h>
#include <plane.h>
#include "robot.h"
#include "letters.h"
// #include <iostream>
// #include <thread>
#include <chrono>
class Draw : public QObject
{
    Q_OBJECT
public:
    explicit Draw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos, Plane* plane,Widget3D *widget3d);
    bool inc_letter;
    void setTime(int time_ms){timer_draw->setInterval(time_ms);}
    void getWord(QString str);
    float xLetterDist,yLetterDist,pointThickness;
    bool isDrawing = false;
    bool simulation_isTrue=true;
public slots:
    void draw_onTimeout();
    void CreatePointsFromTxt(float size);
    void draw_TimerStop(){timer_draw->stop();}
    void draw_TimerStartNoReset(){timer_draw->start();}
    void setIncrementCounterValue(int val){IncrementCounterValue=val;CounterSet=true;}


    void StartSimulation(int);
    //    void StartRobot();

private:
    Letters *_letters;
    bool CounterSet=false, simLine_isTrue=true;
    Widget3D *_widget3d;
    Kinematik *_robotKinematik;
    Robot *_robot;
    QTimer *timer_draw;
    Plane* _plane;
    int errorCounter=0;
    int Nx,Ny;
    int lastIndexEnter,firstIndex=0;
    QVector <QString> LetterInput;
    QVector <int> currentRowIndex,LetterInputIndex;
    int prevInputLength=0;
    QElapsedTimer elapsed_timer;
    int currentIndex;
    int IncrementCounterValue;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> pointsPlane,pointsRobot,pointsBase;
    double a,b,c,l1;
    int counter=0,shiftXcounter=0,shiftYcounter=0,lineCounter=0;
    QVector3D prevLetter_lastPoint,nextLetter_firstPoint;

    QVector3D unit_planeX,unit_planeY,unit_planeZ;
    QVector3D planeX,planeY,planeZ;
    QVector <QVector <QVector2D>> points2D;
    QVector <QString> points2D_names;
    QVector<Qt3DCore::QEntity*> pointEntities;
    QVector3D letter_posPlane,letter_posRobot,letter_posBase,prev_shiftBase,prev_shiftRobot,prev_shiftPlane,save_letterPos;
    QVector <QVector <bool>> drawPoint_isTrue;
    QVector3D lastLinePoint;
    bool timerStopped=false;

    int letter;
    float letterSize;
    void robMove2Point();
    void Base2RobotPts();
    void Points2DToBase();
    void Txt2QVector2D();
    bool nextLetter;
    void moveInLine2DPoint(QVector2D point_begin, QVector2D point_end,QVector <QVector3D> &vec,QVector <bool> &draw_vec);

    QVector3D  calcPointInPlane(QVector2D point)
    {return _plane->translation()+(point.x()*planeX)+(point.y()*planeY);}

    float cartDist(QVector2D point1, QVector2D point2)
    {return qSqrt(qPow(point1.x()-point2.x(),2)+qPow(point1.y()-point2.y(),2));}

    void deleteAllPoints();
    void robot_setPoint(QVector3D position);
    void robDrawLine();

    void shiftVec2BaseAndRobot();
    void moveInLineBetweenLetters();
    QVector3D Base2RobotPoint (QVector3D point3D){return QVector3D(robotMat.inverted() * point3D);}
    QVector3D Base2PlanePoint (QVector3D point3D){return QVector3D(_plane->matrix().inverted() * point3D);}
    QVector3D Plane2BasePoint (QVector3D point3D){return QVector3D(_plane->matrix() * point3D);}
    QVector3D Plane2RobotPoint(QVector3D point3D){return Base2RobotPoint(Plane2BasePoint(point3D));}

    void getPreviousVectors();
    void shiftLetterPosPlaneX(float x);
    void shiftLetterPosPlaneY(float y);
    void getNextLetter();
    void checkPrevLetters();
    void checkRow();
    void drawingDone();
    void connectTimer();
    void connectLines(QVector3D,QVector3D);
signals:
    void sendPoint(QVector3D,float);
    void sendLine(QVector3D,QVector3D);
    void deletePoints();
    void deleteLines();
    void stopTimerDraw();
};

#endif // DRAW_H
