#ifndef LINEARAXIS_H
#define LINEARAXIS_H

#include<Qt3DCore>

class LinearAxis: public Qt3DCore::QEntity,public Qt3DCore::QTransform
{
public:
    Qt3DCore::QTransform* Joint7;
    QVector2D Limits;
    Qt3DCore::QEntity* Sled;
    QVector3D sled_position;

};

#endif // LINEARAXIS_H
