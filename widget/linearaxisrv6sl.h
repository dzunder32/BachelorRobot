#ifndef LINEARAXISRV6SL_H
#define LINEARAXISRV6SL_H

#include <QObject>
#include "linearaxis.h"
#include "stlmesh.h"
#include "coordinatesystem.h"
class LinearAxisRV6SL: public LinearAxis
{
public:
    LinearAxisRV6SL(Qt3DCore::QEntity* parent=nullptr);
    void showAxes(Qt3DCore::QEntity* Ent1, Qt3DCore::QEntity* Ent2);
    void getSledPosition();
//    QVector3D sled_position;
    QVector3D rotate_vector(QVector3D, QMatrix3x3);
    void set_sled_position(QMatrix3x3 rotationMatrix);
private:
    CoordinateSystem *substructure_CSystem;
    CoordinateSystem *axis_CSystem;
    CoordinateSystem *sled_CSystem;

    STLMesh *_axis;
    STLMesh *_sled;
    STLMesh *_substructure;
    STLMesh *_tableTop;
    QVector3D currentTrans;


    void sled_pos_inBase();
};

#endif // LINEARAXISRV6SL_H
