#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include<Qt3DCore>
#include <Qt3DExtras>
//#include <widget3d.h>
#include "coordinatesystem.h"
#include "stlmesh.h""

class Plane : public CoordinateSystem
{
public:
    Plane(double XSize,double YSize,Qt3DCore::QEntity *parent=nullptr);
    Qt3DCore::QEntity * upperBorderX;
    Qt3DCore::QEntity * lowerBorderX;

    Qt3DCore::QEntity * leftBorderY;
    Qt3DCore::QEntity * rightBorderY;

    // Qt3DCore::QTransform *planeToolTransform;
    STLMesh *planeMesh;
    CoordinateSystem *planeToolTransform;
    QVector3D toolPos;
    double xLimit,yLimit;

    QVector3D upperPosX;
    QVector3D lowerPosX;
    QVector3D rightPosY;
    QVector3D leftPosY;

    float offsetX_plane=0;
    float offsetY_plane=0;

    void connectPlane2Polaris();
    void updatePlanePolaris();
    QVector<QVector3D> getCornerPoints();
    void tool_setTranslation(QVector3D pos);
    QVector3D getToolTranslation();
    void adjustToolOffset(float offset);
    void setToolMatrix(QMatrix4x4 toolBase_T);
    void setToolOffset(float off1Y,float off2Y, float off1,float off2);


private:
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
    double prevAlpha=0,prevAlpha1=0;
};

#endif // PLANE_H
