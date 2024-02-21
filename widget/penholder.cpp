#include "penholder.h"

PenHolder::PenHolder(Qt3DCore::QEntity* parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    _tool  = new STLMesh(this);

    _tool->setSource("StiftHalter.STL");
    _tool->Qt3DCore::QEntity::setEnabled(true);
    _tool->setRotationX(90);
    CoordSystem->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(this));
    CoordSystem->setTranslation(QVector3D(0,0,198));
//    CoordSystem->setTranslation(QVector3D(-94.5,0,178));
//    CoordSystem->setMatrix(QMatrix4x4(0 ,cos(-7.3*M_PI/180) ,-sin(-7.3*M_PI/180),-94.5,
//                            -1,0       ,0      ,0    ,
//                            0 ,sin(-7.3*M_PI/180),cos(-7.3*M_PI/180),178  ,
//                            0 ,0       ,0      ,1    ));
    CoordSystem->setLength(10);
    CoordSystem->setNegativeAxis(false);

    this->QMatrix4x4::operator=(CoordSystem->matrix());
}
