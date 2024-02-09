#ifndef TOOL_H
#define TOOL_H

#include<Qt3DCore>
#include "coordinatesystem.h"

class Tool: public  Qt3DCore::QEntity,public Qt3DCore::QTransform, public QMatrix4x4
{
public:
    CoordinateSystem* CoordSystem;
    Tool(Qt3DCore::QEntity *parent=nullptr) {this->Qt3DCore::QEntity::setParent(parent);
                                             CoordSystem =new CoordinateSystem(this);
                                             CoordSystem->setLength(1);
                                             this->addComponent(static_cast<Qt3DCore::QTransform*>(this));}

//    void deleteCoordSystem(){}
};



#endif // TOOL_H
