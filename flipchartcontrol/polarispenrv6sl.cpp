#include "polarispenrv6sl.h"

PolarisPenRv6sl::PolarisPenRv6sl(Qt3DCore::QEntity* parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    _tool  =new STLMesh(this);

    _tool->setSource("RV-6SL_Polaris_Stift.STL");
    _tool->Qt3DCore::QEntity::setEnabled(true);

    CoordSystem->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(this));
    CoordSystem->setTranslation(QVector3D(0,0,219));
    CoordSystem->setLength(100);
    CoordSystem->setNegativeAxis(false);

    this->QMatrix4x4::operator=(CoordSystem->matrix());
    qDebug()<<CoordSystem->matrix();
}
