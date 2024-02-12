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

class Draw : public QObject
{
    Q_OBJECT
public:
    explicit Draw(Kinematik *robot, QVector3D sled_pos, Qt3DCore::QTransform* plane,Widget3D *widget3d);
    bool inc_letter;
    void setTime(int time_ms){timer_draw->setInterval(time_ms);}
    void getWord(QString str);
    float horizontalLetterDist,verticalLetterDist,pointThickness;

public slots:
    void draw_onTimeout();
    void setLetter(QString str);
    void CreatePointsFromTxt(float size);
    void draw_TimerStart(){timer_draw->start();}
    void draw_TimerStop(){timer_draw->stop();}


private:
    Widget3D *_widget3d;
    Kinematik *_robot;
    QTimer *timer_draw;
    QVector <QString> LetterInput;
    QVector <int> LetterInputIndex;
    int currentIndex;
    int IncrementCounterValue;
    QMatrix4x4 robotMat;
    QVector <QVector <QVector3D>> pointsPlane,pointsRobot;
    double a,b,c,l1;
    int counter=0;
    QVector3D prevLetter_lastPoint,nextLetter_firstPoint;
    Qt3DCore::QTransform* _plane;
    QVector3D unit_planeX,unit_planeY,unit_planeZ;
    QVector3D planeX,planeY,planeZ;
    QVector <QVector <QVector2D>> points2D;
    QVector <QString> points2D_names;
    QVector<Qt3DCore::QEntity*> pointEntities;
    QVector3D shift_vecPlane,shift_vecRobot,shift_vecBase;
    QVector <QVector <bool>> drawPoint_isTrue;
    int letter;


    void plane2robotPts();
    void points2D_ToBase();
    void Txt2QVector2D();

    void moveInLine2DPoint(QVector2D point_begin, QVector2D point_end,QVector <QVector3D> &vec,QVector <bool> &draw_vec);

    QVector3D calcPointInPlane(QVector2D point)
    {return _plane->translation()+(point.x()*planeX)+(point.y()*planeY);}

    float cartDist(QVector2D point1, QVector2D point2)
    {return qSqrt(qPow(point1.x()-point2.x(),2)+qPow(point1.y()-point2.y(),2));}

    void deleteAllPoints();
    void robot_setPoint(QVector3D position);

    void shiftVec2BaseAndRobot();
    void moveInLineBetweenLetters();
signals:
    void sendPoint(QVector3D,float);
    void deletePoints();
    void stopTimerDraw();
};

#endif // DRAW_H
