#ifndef STLMESH_H
#define STLMESH_H

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>

class STLMesh: public Qt3DCore::QEntity,public Qt3DRender::QMesh,public Qt3DCore::QTransform
{
public:
    STLMesh(Qt3DCore::QEntity *parent=nullptr);
    Qt3DExtras::QPhongMaterial *Material;
    QString Directory;
    void setSource(QString string);
};

#endif // STLMESH_H
