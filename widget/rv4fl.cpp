#include "rv4fl.h"

RV4FL::RV4FL()
{
    _baseCoordSystem=new CoordinateSystem(this);
    Base            =new STLMesh(_baseCoordSystem);
    Joint1          =new STLMesh(Base);
    Joint2          =new STLMesh(Joint1);
    Joint3          =new STLMesh(Joint2);
    Joint4          =new STLMesh(Joint3);
    Joint5          =new STLMesh(Joint4);

    initialize();

    RV4FLMesh();
}


void RV4FL::RV4FLMesh()
{
    _baseCoordSystem->setLength(1000);

    QMatrix4x4 base;
    base.rotate(90,1,0,0);
    base.rotate(180,0,1,0);
    Base->setSource("RV-4F_BASE_01.STL");
    Base->Qt3DCore::QEntity::setEnabled(true);
    Base->setMatrix(base);

    Joint1->setSource("RV-4FL_SHOLDER_02.STL");
    Joint1->setTranslation(QVector3D(0,350,0));
    Joint1->Qt3DCore::QEntity::setEnabled(true);

    Joint2->setSource("RV-4FL_NO1ARM_03.STL");
    Joint2->Qt3DCore::QEntity::setEnabled(true);

    Joint3->setSource("RV-4F_ELBOW_04.STL");
    Joint3->setTranslation(QVector3D(0,310,0));
    Joint3->Qt3DCore::QEntity::setEnabled(true);

    Joint4->setSource("RV-4FL_NO2ARM_05.STL");
    Joint4->setTranslation(QVector3D(-335,50,0));
    Joint4->Qt3DCore::QEntity::setEnabled(true);

    Joint5->setSource("RV-4F_WRIST_06.STL");
    Joint5->Qt3DCore::QEntity::setEnabled(true);

    transTool= new Qt3DCore::QTransform() ;
    QMatrix4x4 tool;
    tool.rotate(-90,0,1,0);
    tool.rotate(-90,0,0,1);
    transTool->setMatrix(tool);
    ToolEntity->addComponent(transTool);
    transTool->setTranslation(QVector3D(-85,0,0));
}



