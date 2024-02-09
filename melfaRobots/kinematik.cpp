#include "kinematik.h"


void Kinematik::setTool(QMatrix4x4 tool)
{
    _toolTransformationMatrix = tool;
}

void Kinematik::ToolMovement(Transformations::ToolMovement movementDirection, double inc)
{
    QMatrix4x4 toolMovement;
    switch (movementDirection)
    {
    case 0: toolMovement=MatrixTranslationX(inc);break;
    case 1: toolMovement=MatrixTranslationY(inc);break;
    case 2: toolMovement=MatrixTranslationZ(inc);break;
    case 3: toolMovement=MatrixRotationX(inc);break;
    case 4: toolMovement=MatrixRotationY(inc);break;
    case 5: toolMovement=MatrixRotationZ(inc);break;
    default:toolMovement.setToIdentity();
    }
    QMatrix4x4 t=getTransformationMatrix()*toolMovement;
//    qDebug()<<t;
    setTransformationMatrix(t);
}

