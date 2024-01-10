#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>

class Point: public Qt3DCore::QEntity,public Qt3DCore::QTransform,public Qt3DExtras::QSphereMesh
{
public:
    Point(Qt3DCore::QEntity *parent=nullptr);
    Qt3DExtras::QPhongMaterial* Material;
};

#endif // POINT_H
