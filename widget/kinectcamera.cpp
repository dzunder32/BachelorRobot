#include "kinectcamera.h"

KinectCamera::KinectCamera(Qt3DCore::QEntity* parent)
{
    //ToolType=Visualisation::camera;;
    this->Qt3DCore::QEntity::setParent(parent);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    _tool  = new STLMesh(this);

    _tool->setSource("StiftHalterUndKamera.STL");
    _tool->Qt3DCore::QEntity::setEnabled(true);

    CoordSystem->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(this));
    CoordSystem->setTranslation(QVector3D(-94.5,0,178));
//    CoordSystem->setMatrix(QMatrix4x4(0 ,cos(-7.3*M_PI/180) ,-sin(-7.3*M_PI/180),-94.5,
//                            -1,0       ,0      ,0    ,
//                            0 ,sin(-7.3*M_PI/180),cos(-7.3*M_PI/180),178  ,
//                            0 ,0       ,0      ,1    ));
    CoordSystem->setLength(100);
    CoordSystem->setNegativeAxis(false);

    this->QMatrix4x4::operator=(CoordSystem->matrix());
}

void KinectCamera::connectWithRecording(Qt3DCore::QEntity *stlMesh)
{
    stlMesh->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(CoordSystem));
}



