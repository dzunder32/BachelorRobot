#include "stlmesh.h"



STLMesh::STLMesh(Qt3DCore::QEntity *parent)
{
    QDir dir =QDir::currentPath();
    dir.cdUp();
    dir.cdUp();
    dir.cd("StlFiles");
    Directory=dir.path();
    Directory+=QDir::separator()/*"/BachelorRobot/StlFiles/"*/;

    this->Qt3DCore::QEntity::setParent(parent);
    Material = new Qt3DExtras::QPhongMaterial();
    Material->setDiffuse(QColor(254, 254, 254));
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    this->addComponent(static_cast<Qt3DRender::QMesh*>(this));
    this->addComponent(Material);
}

void STLMesh::setSource(QString string)
{
//    qDebug()<<Directory+string;
    this->QMesh::setSource(QUrl::fromLocalFile(Directory+string));
}
