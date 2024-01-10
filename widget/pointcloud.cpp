#include "pointcloud.h"

PointCloud::PointCloud(Qt3DCore::QEntity* parent) :Qt3DCore::QEntity(parent)
{
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
}

void PointCloud::addCloud(QVector<QVector3D> cloud)
{
    Qt3DExtras::QPhongMaterial* material=new Qt3DExtras::QPhongMaterial() ;
    Qt3DExtras::QSphereMesh* sphere=new Qt3DExtras::QSphereMesh();
    sphere->setRadius(2);
    material->setDiffuse(QColor(254, 254, 254));
    int i=0;

    foreach (QVector3D val, cloud)
    {
        if(!(val.x()==0 & val.y()==0 & val.z()==0))
        {
            Qt3DCore::QEntity* point=new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
            Qt3DCore::QTransform* transform= new Qt3DCore::QTransform();
            _entityPoints.append(point);
            point->addComponent(transform);
            point->addComponent(sphere);
            point->addComponent(material);
            transform->setTranslation(val);
        }
        i++;
        if (i==10000)
        {
            QTimer *timer = new QTimer;
            timer->start(100);
        }
    }
    qDebug()<<"Ready "<<i;
}

