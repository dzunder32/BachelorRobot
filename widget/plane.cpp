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

//     toolPos = QVector3D(-xLimit/2,0,10);
    toolPos = QVector3D(xLimit/2,0,10);

    //Tool as CSystem
    planeToolTransform = new CoordinateSystem(static_cast<Qt3DCore::QEntity*>(this));
    planeToolTransform->setLength(50);
    planeToolTransform->setNegativeAxis(false);
    planeToolTransform->setTranslation(toolPos);

    planeMesh= new STLMesh(this);
    planeMesh->setSource("Flipchart.stl");
    planeMesh->setTranslation(QVector3D(0,0,-10));
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
void Plane::tool_setTranslation(QVector3D pos)
{
    this->setTranslation(pos-toolPos);
    // planeToolTransform->setTranslation(pos)
}

QVector3D Plane::getToolTranslation()
{
    return this->translation() + toolPos;
}

void Plane::adjustToolOffset(float offset)
{
    toolPos.setZ(offset);
    QMatrix4x4 toolBase_T = this->matrix() * planeToolTransform->matrix();

    planeToolTransform->setTranslation(toolPos);
    this->setMatrix(toolBase_T*planeToolTransform->matrix().inverted());

    // this->setTranslation(this->translation()-this->matrix().column(2).toVector3D()*offset);
    // this->setTranslation(this->matrix()*toolPos);
}

void Plane::setToolMatrix(QMatrix4x4 toolBase_T)
{
    this->setMatrix(toolBase_T*planeToolTransform->matrix().inverted());
}

void Plane::setToolOffset(float off1Y,float off2Y,float off1,float off2)
{
    float plane_off = toolPos.z()+off1;
    adjustToolOffset(plane_off);
    float opposite = abs(off1-off2);
    float adjacent = 100;
    float alpha =  atan2(opposite,adjacent);
    if(off2>off1){}else{alpha=-alpha;}

    planeToolTransform->setRotationY(qRadiansToDegrees(alpha));
    this->setRotationX(qRadiansToDegrees(alpha));
    this->setTranslation(this->translation()+QVector3D(this->xLimit/2*sin(prevAlpha-alpha),0,0));
    prevAlpha=alpha;

    float plane_off2 = toolPos.z()+off1Y;
    adjustToolOffset(plane_off2);
    float opposite1 = abs(off1Y-off2Y);
    float adjacent1 = 100;
    float alpha1 =  atan2(opposite1,adjacent1);
    if(off2Y<off1Y){alpha1=-alpha1;}

    planeToolTransform->setRotationX(qRadiansToDegrees(alpha1));
    this->setRotationY(90-qRadiansToDegrees(alpha1));
    // this->setTranslation(this->translation()+QVector3D(this->xLimit/2*sin(prevAlpha1-alpha1),0,0));
    prevAlpha1=alpha1;
}
