#ifndef LINEARAXISRV6SL_H
#define LINEARAXISRV6SL_H

#include <QObject>
#include "linearaxis.h"
#include "stlmesh.h"
#include "dialog.h"
class LinearAxisRV6SL: public LinearAxis
{
public:
    LinearAxisRV6SL(Qt3DCore::QEntity* parent=nullptr);
//    void passDialog(Dialog*);
private:
    STLMesh *_axis;
    STLMesh *_sled;
    STLMesh *_substructure;
    QVector3D currentTrans;


public slots:
    void adjustPosX(int value);
    void adjustPosY(int value);
};

#endif // LINEARAXISRV6SL_H
