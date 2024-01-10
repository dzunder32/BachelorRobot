#ifndef SIXJOINTROBOT_H
#define SIXJOINTROBOT_H

#include<QVector>
#include<Qt3DCore>

#include "tool.h"
#include "coordinatesystem.h"
#include "linearaxis.h"
#include "stlmesh.h"

class SixJointRobot: public Qt3DCore::QEntity,public Qt3DCore::QTransform, public QVector<Qt3DCore::QTransform*>
{
public:  
    void initialize();
    CoordinateSystem *_baseCoordSystem;
    Tool* _emptyTool;
    Tool* currentTool;

    STLMesh* Base;
    STLMesh* Joint1;
    STLMesh* Joint2;
    STLMesh* Joint3;
    STLMesh* Joint4;
    STLMesh* Joint5;
    Qt3DCore::QEntity* ToolEntity;
    Qt3DCore::QTransform* transTool;
    Qt3DCore::QTransform* RobotTool;
    QVector<Qt3DCore::QTransform*> Joints;

    LinearAxis* _axis;

    void addTool(Tool *tool);
    void setNoTool();
    void addLinearAxis(LinearAxis *axis);
    void removeLinearAxis();
    QMatrix4x4 getTransformationMatrix();
    QMatrix4x4 getPositionMatrix();
    Qt3DCore::QTransform* getBaseKoordinateSystemPosition();
};

#endif // SIXJOINTROBOT_H

