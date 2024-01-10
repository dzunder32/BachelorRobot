#include "rv6sl.h"

RV6SL::RV6SL()
{


    _baseCoordSystem=new CoordinateSystem(this);
    Base            =new STLMesh(_baseCoordSystem);
    Joint1          =new STLMesh(Base);
    Joint2          =new STLMesh(Joint1);
    Joint3          =new STLMesh(Joint2);
    Joint4          =new STLMesh(Joint3);
    _arm            =new STLMesh(Joint4);
    Joint5          =new STLMesh(_arm);

    initialize();

    RV6SLMesh();
}


void RV6SL::RV6SLMesh()
{

    _baseCoordSystem->setLength(1000);


    QMatrix4x4 base;
    base.rotate(90,1,0,0);
    base.rotate(90,0,1,0);
    Base->setSource("RV-6S_BASE.STL");
    Base->Qt3DCore::QEntity::setEnabled(true);
    Base->setMatrix(base);

    Joint1->setSource("RV-6S_SHOULDER.STL");
    Joint1->setTranslation(QVector3D(0,277,0));
    Joint1->Qt3DCore::QEntity::setEnabled(true);

    Joint2->setSource("RV-6SL_NO1ARM.STL");
    Joint2->setTranslation(QVector3D(114.5,73,85));
    Joint2->Qt3DCore::QEntity::setEnabled(true);

    Joint3->setSource("RV-6S_ELBO.STL");
    Joint3->setTranslation(QVector3D(-8,380,0));
    Joint3->Qt3DCore::QEntity::setEnabled(true);

    Joint4->setSource("RV-6SL_JOINT_ARM.STL");
    Joint4->setTranslation(QVector3D(-106.5,100,83.5));
    Joint4->Qt3DCore::QEntity::setEnabled(true);

    _arm->setSource("RV-6S_NO2ARM.STL");
    _arm->setTranslation(QVector3D(0,0,126.5));
    _arm->setRotationX(90);
    _arm->Qt3DCore::QEntity::setEnabled(true);

    Joint5->setSource("RV-6S_WRIST.STL");
    Joint5->setTranslation(QVector3D(47,215,0));
    Joint5->Qt3DCore::QEntity::setEnabled(true);

    transTool= new Qt3DCore::QTransform() ;
    QMatrix4x4 tool;
    tool.rotate(-90,1,0,0);
    tool.rotate(-90,0,0,1);
    transTool->setMatrix(tool);
    ToolEntity->addComponent(transTool);
    transTool->setTranslation(QVector3D(-47,85,0));
}

