#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <Qt3DExtras/QText2DEntity>

class CoordinateSystem: public Qt3DCore::QEntity,public Qt3DCore::QTransform
{
public:
    CoordinateSystem(Qt3DCore::QEntity* parent=nullptr);

    void setLength(float length);
    void thinOut(float factor);
    void setText(const QString& text);
    void setTextProperties(const QFont& font, float height, const QColor& color);
    void setCoordLabel(QString string,char axis);
    Qt3DCore::QEntity * AxisZ;
    Qt3DCore::QEntity * AxisX;
    Qt3DCore::QEntity * AxisY;

    void setNegativeAxis(bool enabeld);

private:
    Qt3DExtras::QCylinderMesh *_cylinder;
    Qt3DCore::QEntity * _arrowheadAxisZ;
    Qt3DCore::QEntity * _arrowheadAxisX;
    Qt3DCore::QEntity * _arrowheadAxisY;
    Qt3DExtras::QConeMesh* _arrowhead;
    Qt3DCore::QTransform *_arrowheadTransform;
    Qt3DCore::QTransform *_cylinderTransformX;
    Qt3DCore::QTransform *_cylinderTransformY;
    Qt3DCore::QTransform *_cylinderTransformZ;
    Qt3DExtras::QPhongMaterial *_materialX;
    Qt3DExtras::QPhongMaterial *_materialY;
    Qt3DExtras::QPhongMaterial *_materialZ;
    Qt3DExtras::QText2DEntity *_textLabel,*_textLabel1;
    float textOffset = 10;
    float _length=100;
    bool _negativeAxis=true;



};

#endif // COORDINATESYSTEM_H
