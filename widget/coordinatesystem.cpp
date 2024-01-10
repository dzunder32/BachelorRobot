#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(Qt3DCore::QEntity* parent) :Qt3DCore::QEntity(parent)
{
    //Transform=new Qt3DCore::QTransform();
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));

    _cylinder =new Qt3DExtras::QCylinderMesh;
    _arrowhead=new Qt3DExtras::QConeMesh();
    _arrowhead->setTopRadius(0);
    _arrowhead->setHasBottomEndcap(true);
    _arrowhead->setHasTopEndcap(true);

    _materialZ =new Qt3DExtras::QPhongMaterial();
    _materialZ->setAmbient(QColor(0,0,255));
    _materialY =new Qt3DExtras::QPhongMaterial();
    _materialY->setAmbient(QColor(255,255,0));
    _materialX =new Qt3DExtras::QPhongMaterial();
    _materialX->setAmbient(QColor(255,0,0));

    _arrowheadTransform = new Qt3DCore::QTransform();
    _cylinderTransformX = new Qt3DCore::QTransform();
    _cylinderTransformY = new Qt3DCore::QTransform();
    _cylinderTransformZ = new Qt3DCore::QTransform();
    _cylinderTransformZ->setRotationX(90);
    _cylinderTransformX->setRotationZ(-90);

    AxisZ = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    AxisZ->addComponent(_cylinder);
    AxisZ->addComponent(_cylinderTransformZ);
    AxisZ->addComponent(_materialZ);
    AxisZ->setEnabled(true);

    _arrowheadAxisZ =new Qt3DCore::QEntity(AxisZ);
    _arrowheadAxisZ->addComponent(_arrowhead);
    _arrowheadAxisZ->addComponent(_arrowheadTransform);
    _arrowheadAxisZ->addComponent(_materialZ);
    _arrowheadAxisZ->setEnabled(true);

    AxisX = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    AxisX->addComponent(_cylinder);
    AxisX->addComponent(_cylinderTransformX);
    AxisX->addComponent(_materialX);
    AxisX->setEnabled(true);

    _arrowheadAxisX =new Qt3DCore::QEntity(AxisX);
    _arrowheadAxisX->addComponent(_arrowhead);
    _arrowheadAxisX->addComponent(_arrowheadTransform);
    _arrowheadAxisX->addComponent(_materialX);
    _arrowheadAxisX->setEnabled(true);

    AxisY = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    AxisY->addComponent(_cylinder);
    AxisY->addComponent(_cylinderTransformY);
    AxisY->addComponent(_materialY);
    AxisY->setEnabled(true);

    _arrowheadAxisY =new Qt3DCore::QEntity(AxisY);
    _arrowheadAxisY->addComponent(_arrowhead);
    _arrowheadAxisY->addComponent(_arrowheadTransform);
    _arrowheadAxisY->addComponent(_materialY);
    _arrowheadAxisY->setEnabled(true);

}

void CoordinateSystem::setLength(float length)
{
    _cylinder->setLength(length);
    _cylinder->setRadius(pow(length,1.0/4.0)/2);
    _arrowheadTransform->setTranslation(QVector3D(0,length/2,0));
    _arrowhead->setBottomRadius(pow(length,1.0/4.0)*2);
    _arrowhead->setLength(_arrowhead->bottomRadius()*2);
}

void CoordinateSystem::setNegativeAxis(bool enabeld)
{
    if (enabeld!=_negativeAxis)
    {
        float length=_cylinder->length()/2;
        if (!enabeld)
        {
            _cylinderTransformZ->setTranslation(QVector3D(0,0,length));
            _cylinderTransformX->setTranslation(QVector3D(length,0,0));
            _cylinderTransformY->setTranslation(QVector3D(0,length,0));
        }
        else
        {
            _cylinderTransformY->setTranslation(QVector3D(0,0,-length));
            _cylinderTransformX->setTranslation(QVector3D(-length,0,0));
            _cylinderTransformZ->setTranslation(QVector3D(0,-length,0));
        }
    }
    enabeld=_negativeAxis;

}



