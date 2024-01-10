#include "point.h"

Point::Point(Qt3DCore::QEntity *parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    Material = new Qt3DExtras::QPhongMaterial();
    Material->setDiffuse(QColor(254, 254, 254));

    this->setRadius(5);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    this->addComponent(static_cast<Qt3DExtras::QSphereMesh*>(this));
    this->addComponent(Material);


}
