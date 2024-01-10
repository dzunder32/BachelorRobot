#ifndef RV6SLKINEMATIK_H
#define RV6SLKINEMATIK_H

#include <QObject>
#include <math.h>
#include <QtMath>
#include <Qt3DCore>
#include <QMatrix4x4>
#include "kinematik.h"

class Rv6slKinematik: public Kinematik
{
    Q_OBJECT
public:
    Rv6slKinematik(QVector<Qt3DCore::QTransform*>* joints=nullptr);
    void invers() override;
    void direct() override;
    void updateView() override;

};

#endif // RV6SLKINEMATIK_H
