#include "plane.h"

Plane::Plane(double XSize,double YSize,Widget3D *widget3d,Qt3DCore::QEntity* parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    _xLimit = XSize;
    _yLimit = YSize;
    this->setLength(100);
    this->setNegativeAxis(false);
    _widget = widget3d;
    _lowerCylinderX =new Qt3DExtras::QCylinderMesh;
    _upperCylinderX =new Qt3DExtras::QCylinderMesh;

    _leftCylinderY =new Qt3DExtras::QCylinderMesh;
    _rightCylinderY =new Qt3DExtras::QCylinderMesh;

    _lowerCylinderX->setRadius(1);
    _upperCylinderX->setRadius(1);
    _leftCylinderY->setRadius(1);
    _rightCylinderY->setRadius(1);

    _materialY =new Qt3DExtras::QPhongMaterial();
    _materialY->setAmbient(QColor(255,255,0));
    _materialX =new Qt3DExtras::QPhongMaterial();
    _materialX->setAmbient(QColor(255,0,0));

    _leftTransformY = new Qt3DCore::QTransform();
    _rightTransformY = new Qt3DCore::QTransform();
    _upperTransformX = new Qt3DCore::QTransform();
    _lowerTransformX = new Qt3DCore::QTransform();
    _upperTransformX->setRotationZ(-90);
    _lowerTransformX->setRotationZ(-90);

    _upperTransformX->setTranslation(QVector3D(_xLimit/2,_yLimit,0));
    _lowerTransformX->setTranslation(QVector3D(_xLimit/2,-_yLimit,0));
    _rightTransformY->setTranslation(QVector3D(_xLimit,0,0));
    _leftTransformY->setTranslation(QVector3D(0,0,0));

    _upperCylinderX->setLength(_xLimit);
    _lowerCylinderX->setLength(_xLimit);
    _rightCylinderY->setLength(_yLimit*2);
    _leftCylinderY->setLength(_yLimit*2);

    upperBorderX = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    upperBorderX->addComponent(_upperCylinderX);
    upperBorderX->addComponent(_upperTransformX);
    upperBorderX->addComponent(_materialX);
    upperBorderX->setEnabled(true);

    lowerBorderX = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    lowerBorderX->addComponent(_lowerCylinderX);
    lowerBorderX->addComponent(_lowerTransformX);
    lowerBorderX->addComponent(_materialX);
    lowerBorderX->setEnabled(true);

    rightBorderY = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    rightBorderY->addComponent(_rightCylinderY);
    rightBorderY->addComponent(_rightTransformY);
    rightBorderY->addComponent(_materialY);
    rightBorderY->setEnabled(true);

    leftBorderY = new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    leftBorderY->addComponent(_leftCylinderY);
    leftBorderY->addComponent(_leftTransformY);
    leftBorderY->addComponent(_materialY);
    leftBorderY->setEnabled(true);



}

void Plane::DrawPlaneLimits()
{

}
