#include "plane.h"

Plane::Plane(double XSize,double YSize,Qt3DCore::QEntity* parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    xLimit = XSize;
    yLimit = YSize;

    upperPosX = QVector3D(0,yLimit/2,0);
    lowerPosX = QVector3D(0,-yLimit/2,0);
    rightPosY = QVector3D(xLimit/2,0,0);
    leftPosY  = QVector3D(-xLimit/2,0,0);


    this->setLength(100);
    this->setNegativeAxis(false);
    _lowerCylinderX = new Qt3DExtras::QCylinderMesh;
    _upperCylinderX = new Qt3DExtras::QCylinderMesh;

    _leftCylinderY  = new Qt3DExtras::QCylinderMesh;
    _rightCylinderY = new Qt3DExtras::QCylinderMesh;

    _lowerCylinderX->setRadius(1);
    _upperCylinderX->setRadius(1);
    _leftCylinderY->setRadius(1);
    _rightCylinderY->setRadius(1);

    _materialY = new Qt3DExtras::QPhongMaterial();
    _materialY->setAmbient(QColor(255,255,0));
    _materialX = new Qt3DExtras::QPhongMaterial();
    _materialX->setAmbient(QColor(255,0,0));

    _leftTransformY  = new Qt3DCore::QTransform();
    _rightTransformY = new Qt3DCore::QTransform();
    _upperTransformX = new Qt3DCore::QTransform();
    _lowerTransformX = new Qt3DCore::QTransform();
    _upperTransformX->setRotationZ(-90);
    _lowerTransformX->setRotationZ(-90);

    _upperTransformX->setTranslation(upperPosX);
    _lowerTransformX->setTranslation(lowerPosX);
    _rightTransformY->setTranslation(rightPosY);
    _leftTransformY->setTranslation(leftPosY);

    _upperCylinderX->setLength(xLimit);
    _lowerCylinderX->setLength(xLimit);
    _rightCylinderY->setLength(yLimit);
    _leftCylinderY->setLength(yLimit);

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

QVector <QVector3D> Plane::getCornerPoints()
{
    QVector3D trans = this->translation();
    QVector <QVector3D> cornerPoints;

    QMatrix4x4 planeT;
    planeT.rotate(this->rotation());

    QVector3D xPlaneBase=QVector3D(planeT.column(0));
    QVector3D yPlaneBase=QVector3D(planeT.column(1));

    QVector3D upperLeftCorner  = -(xPlaneBase * xLimit/2) + trans + (yPlaneBase * yLimit/2);
    QVector3D upperRightCorner =  (xPlaneBase * xLimit/2) + trans + (yPlaneBase * yLimit/2);
    QVector3D lowerLeftCorner  = -(xPlaneBase * xLimit/2) + trans - (yPlaneBase * yLimit/2);
    QVector3D lowerRightCorner =  (xPlaneBase * xLimit/2) + trans - (yPlaneBase * yLimit/2);

    qDebug()<<"W"<<xPlaneBase;
    qDebug()<<upperLeftCorner;


    cornerPoints.append(upperLeftCorner);
    cornerPoints.append(upperRightCorner);
    cornerPoints.append(lowerLeftCorner);
    cornerPoints.append(lowerRightCorner);

    return cornerPoints;
//    qDebug()<<"whathtehell";
}
void Plane::connectPlane2Polaris()
{

}
