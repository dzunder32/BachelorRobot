#ifndef RV4FLKINEMATIK_H
#define RV4FLKINEMATIK_H

#include <QObject>
#include <QMatrix4x4>
#include <math.h>
#include "kinematik.h"

class Rv4flKinematik:public Kinematik
{
    Q_OBJECT
public:
    Rv4flKinematik(QVector<Qt3DCore::QTransform*>* joints=nullptr);
    void invers() override;
    void direct() override;
    void updateView() override;

};

#endif // RV4FLKINEMATIK_H
