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

    void TimerStart(int time);
    void TimerStop();
public slots:
    void setLetter(int num);
private:
    Widget3D *_widget3d;
    Kinematik *_robot;
    QTimer *timer;
    QMatrix4x4 robotMat;
//    QVector <QVector3D> /*pointsRobot,*/pointsBase/*,pointsPlane*/;
    QVector <QVector <QVector3D>> pointsPlane,pointsRobot;
    double a,b,c,l1;
    int counter=0;
    Qt3DCore::QTransform* _plane;
    QVector3D planeX,planeY,planeZ;
    QVector <QVector <QVector2D>> points2D;
    QVector<Qt3DCore::QEntity*> pointEntities;
    QVector3D shift_vecPlane,shift_vecRobot,shift_vecBase;
    int letter;
    void onTimeout();

    void plane2robotPts();

    void points2D_toPlane();
    void Txt2QVector2D();
    float cartDist(QVector2D point1, QVector2D point2);
    void drawLine(QVector2D point_begin, QVector2D point_end,QVector <QVector3D> &vec);
    QVector3D calcPointInPlane(QVector2D point);
    void drawPoint(QVector3D position, float size, QColor color);
//    void drawPoint(QVector3D position, float size, QColor color);
    void deleteAllPoints();
signals:
    void sendPoint(QVector3D);
    void deletePoints();
};

#endif // DRAW_H
