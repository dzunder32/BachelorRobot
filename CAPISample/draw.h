#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include "kinematik.h"

class Draw : public QObject
{
    Q_OBJECT
public:
    explicit Draw(Kinematik *robot, QVector3D sled_pos, Qt3DCore::QTransform* plane);

    void TimerStart(int time);
    void TimerStop();
private:
    Kinematik *_robot;
    QTimer *timer;
    QMatrix4x4 robotMat;
    QVector <QVector3D> pointsRobot,pointsBase,pointsPlane;
    double a,b,c,l1;
    int counter=0;
    Qt3DCore::QTransform* _plane;
    QVector3D planeX,planeY;
    QVector <QVector2D> points2D;

    void onTimeout();

    void plane2robotPts();

    void points2D_toPlane();
};

#endif // DRAW_H
