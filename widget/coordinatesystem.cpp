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

    //For Label



    // _textLabel = new Qt3DExtras::QText2DEntity(static_cast<Qt3DCore::QEntity*>(this));
    // _textLabel1 = new Qt3DExtras::QText2DEntity(static_cast<Qt3DCore::QEntity*>(this));
    // // auto *material = new Qt3DExtras::QPhongMaterial();
    // // material.setTra
    // // material->setTwoSided(true);
    // // _textLabel->addComponent(material);
    // _textLabel->setFont(QFont("Arial"));
    // _textLabel->setHeight(_length/8);
    // _textLabel->setWidth(_length/4);
    // _textLabel->setColor(Qt::yellow);
    // _textLabel1->setFont(QFont("Arial"));
    // _textLabel1->setHeight(_length/8);
    // _textLabel1->setWidth(_length/8);
    // _textLabel1->setColor(Qt::yellow);
    // // _textLabel1=_textLabel;
    // auto *textTransform  = new Qt3DCore::QTransform(_textLabel);
    // auto *textTransform1 = new Qt3DCore::QTransform(_textLabel1);

    // textTransform->setScale(1.0f);
    // textTransform->setTranslation(QVector3D(-25,-25,100));
    // //-----------------------------------------------------(    X,   Y,     Z) rot in zxy
    // // textTransform->setRotation(QQuaternion::fromEulerAngles(45.0f, 0.0f, 45.0f));
    // // textTransform->setRotationX(90);
    // // textTransform->setRotationZ(45);
    // textTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),-45));
    // textTransform1->setScale(1.0f);
    // textTransform1->setTranslation(QVector3D(0,0,0));
    // textTransform1->setRotation(QQuaternion::fromEulerAngles(-90.0f,180.0f,0.0f));
    // // textTransform->setRotationX(90);    // Position above the origin

    // _textLabel->addComponent(textTransform);
    // _textLabel1->addComponent(textTransform1);

    // setText("Coordinate System");

}
void CoordinateSystem::setCoordLabel(QString string,char axis)
{

    _textLabel = new Qt3DExtras::QText2DEntity(static_cast<Qt3DCore::QEntity*>(this));
    _textLabel1 = new Qt3DExtras::QText2DEntity(static_cast<Qt3DCore::QEntity*>(this));
    // auto *material = new Qt3DExtras::QPhongMaterial();
    // material.setTra
    // material->setTwoSided(true);
    // _textLabel->addComponent(material);
    _textLabel->setFont(QFont("Arial"));
    _textLabel->setHeight(_length/4);
    _textLabel->setWidth(_length/1.5);
    _textLabel->setColor(Qt::yellow);
    _textLabel1->setFont(QFont("Arial"));
    _textLabel1->setHeight(_length/4);
    _textLabel1->setWidth(_length);
    _textLabel1->setColor(Qt::yellow);
    // _textLabel1=_textLabel;
    auto *textTransform  = new Qt3DCore::QTransform(_textLabel);
    auto *textTransform1 = new Qt3DCore::QTransform(_textLabel1);

    float width45=_textLabel->width()/2*(qPow(2,0.5)/2);
    float coord_offset=_length/20;
    textTransform->setScale(1.0f);
    switch(axis)
    {
    case 'Z':
        textTransform->setTranslation(QVector3D(-width45-coord_offset,width45-coord_offset,_length/2));
        textTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),-45));
        textTransform1->setScale(1.0f);
        textTransform1->setTranslation(QVector3D(width45+coord_offset,-width45+coord_offset,_length/2));
        textTransform1->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),135));
        break;
    case 'X':
        textTransform->setTranslation(QVector3D(_length/2,width45/*+coord_offset*/,width45/*+coord_offset*/));
        textTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),45));
        textTransform->setTranslation(QVector3D(0,0,0));
        textTransform1->setScale(1.0f);

        textTransform1->setTranslation(QVector3D(_length/2,-width45/*-coord_offset*/,-width45/*-coord_offset*/));
        textTransform1->setTranslation(QVector3D(0,0,0));
        textTransform1->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),235));
        break;
    }

    // textTransform->setTranslation(QVector3D(0,0,0));
    // textTransform->setTranslation(QVector3D(-_textLabel->width()/2*(qPow(2,0.5)/2)-_length/10,_textLabel->width()/2*(qPow(2,0.5)/2)-_length/10,_length/2));
    //-----------------------------------------------------(    X,   Y,     Z) rot in zxy
    // textTransform->setRotation(QQuaternion::fromEulerAngles(45.0f, 0.0f, 45.0f));
    // textTransform->setRotationX(90);
    // textTransform->setRotationZ(45);
    // textTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),-90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),-45));
    // textTransform1->setScale(1.0f);
    // textTransform1->setTranslation(QVector3D(_textLabel->width()/2*(qPow(2,0.5)/2)+_length/10,-_textLabel->width()/2*(qPow(2,0.5)/2)+_length/10,_length/2));
    // textTransform1->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),90) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),135));
    // textTransform->setRotationX(90);    // Position above the origin

    _textLabel->addComponent(textTransform);
    _textLabel1->addComponent(textTransform1);

    setText(string);
}
void CoordinateSystem::setLength(float length)
{
    _cylinder->setLength(length);
    _cylinder->setRadius(pow(length,1.0/4.0)/2);
    _arrowheadTransform->setTranslation(QVector3D(0,length/2,0));
    _arrowhead->setBottomRadius(pow(length,1.0/4.0)*2);
    _arrowhead->setLength(_arrowhead->bottomRadius()*2);
    _length=length;
}

void CoordinateSystem::thinOut(float factor)
{
    _arrowhead->setBottomRadius(pow(_cylinder->length(),1.0/4.0)*2*factor);
    _arrowhead->setLength(_arrowhead->bottomRadius()*2*factor);
    _cylinder->setRadius((pow(_cylinder->length(),1.0/4.0)/2)*factor);

}

void CoordinateSystem::setText(const QString& text)
{
    _textLabel->setText(text);
    _textLabel1->setText(text);
}

void CoordinateSystem::setTextProperties(const QFont& font, float height, const QColor& color)
{
    _textLabel->setFont(font);
    _textLabel->setHeight(height);
    _textLabel->setWidth(100); // Adjust width based on text length if needed
    _textLabel->setColor(color);
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

            //  _textLabel->setTranslation(QVector3D(0, 0, textOffset));
            // _textLabel->set
        }
        else
        {
            _cylinderTransformY->setTranslation(QVector3D(0,0,-length));
            _cylinderTransformX->setTranslation(QVector3D(-length,0,0));
            _cylinderTransformZ->setTranslation(QVector3D(0,-length,0));

            // _textLabel->setTranslation(QVector3D(0, 0, -textOffset));
        }
    }
    enabeld=_negativeAxis;

}



