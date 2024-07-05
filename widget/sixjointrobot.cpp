#include "sixjointrobot.h"

void SixJointRobot::initialize()
{
    ToolEntity      =new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(Joint5));
    _emptyTool      =new Tool (ToolEntity);
    setNoTool();
    this->addComponent(this);

    this->append(Joint1);
    this->append(Joint2);
    this->append(Joint3);
    this->append(Joint4);
    this->append(Joint5);
    this->append(RobotTool);

    Joints.append(Joint1);
    Joints.append(Joint2);
    Joints.append(Joint3);
    Joints.append(Joint4);
    Joints.append(Joint5);
}

QMatrix4x4 SixJointRobot::getTransformationMatrix()
{
    QMatrix4x4 transMatrix;
    transMatrix.setToIdentity();
    foreach (Qt3DCore::QTransform* val, Joints) {
        transMatrix=transMatrix*val->matrix();
    }
    transMatrix*=transTool->matrix();
    transMatrix*=RobotTool->matrix();
    transMatrix+=static_cast<QMatrix4x4>(*currentTool);//
    transMatrix*=currentTool->CoordSystem->matrix();
    return transMatrix;
}

QMatrix4x4 SixJointRobot::getPositionMatrix()
{
    return this->matrix();
}


void SixJointRobot::addTool(Tool *tool)
{
    tool->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(ToolEntity));
    _emptyTool->Qt3DCore::QEntity::setEnabled(false);
    this->removeLast();
    RobotTool=tool;
    this->append(RobotTool);
    currentTool=tool;
}

void SixJointRobot::setNoTool()
{
    RobotTool=_emptyTool;
    _emptyTool->CoordSystem->setLength(100);
    _emptyTool->CoordSystem->setNegativeAxis(false);
}

void SixJointRobot:: addLinearAxis(LinearAxis *axis)
{
    axis->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(this));
    _baseCoordSystem->Qt3DCore::QEntity::setParent(axis->Sled);
    QMatrix4x4 rot;
    rot.rotate(-90,1,0,0);
    rot.rotate(90,0,0,1);
    _baseCoordSystem->setMatrix(rot);
    axis->setRotationX(90);

    this->append(axis->Joint7);
    _axis=axis;
}

void SixJointRobot::removeLinearAxis()
{
    _baseCoordSystem->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(this));
    QMatrix4x4 rot;
    rot.setToIdentity();
    _baseCoordSystem->setMatrix(rot);
    this->removeLast();
    _axis->~LinearAxis();

}

Qt3DCore::QTransform* SixJointRobot::getBaseKoordinateSystemPosition()
{
    return static_cast<Qt3DCore::QTransform*>(currentTool->CoordSystem);
}
