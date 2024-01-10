#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include "point.h"
#include "omp.h"

class PointCloud: public Qt3DCore::QEntity,public Qt3DCore::QTransform
{
public:
    PointCloud(Qt3DCore::QEntity *parent=nullptr);
    void addCloud(QVector<QVector3D> cloud);
private:
    QVector<Qt3DCore::QEntity*> _entityPoints;

};

#endif // POINTCLOUD_H
