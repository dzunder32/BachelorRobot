#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include<Qt3DCore>
#include <Qt3DExtras>
#include <widget3d.h>
#include "coordinatesystem.h"


class Plane : public CoordinateSystem
{
public:
    Plane(double XSize,double YSize,Widget3D *widget3d,Qt3DCore::QEntity *parent=nullptr);
    Qt3DCore::QEntity * upperBorderX;
    Qt3DCore::QEntity * lowerBorderX;

    Qt3DCore::QEntity * leftBorderY;
    Qt3DCore::QEntity * rightBorderY;


private:
    double _xLimit,_yLimit;
    Widget3D *_widget;
    Qt3DExtras::QCylinderMesh *_upperCylinderX;
    Qt3DExtras::QCylinderMesh *_lowerCylinderX;
    Qt3DExtras::QCylinderMesh *_leftCylinderY;
    Qt3DExtras::QCylinderMesh *_rightCylinderY;

    Qt3DExtras::QPhongMaterial *_materialX;
    Qt3DExtras::QPhongMaterial *_materialY;
    Qt3DCore::QTransform * _upperTransformX;
    Qt3DCore::QTransform * _lowerTransformX;
    Qt3DCore::QTransform *_leftTransformY;
    Qt3DCore::QTransform *_rightTransformY;



    void DrawPlaneLimits();

};

#endif // PLANE_H
