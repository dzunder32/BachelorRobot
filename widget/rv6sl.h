#ifndef RV6SL_H
#define RV6SL_H

#include <QDir>
#include "stlmesh.h"
#include "sixjointrobot.h"
#include "tool.h"
#include "coordinatesystem.h"
#include "linearaxis.h"

class RV6SL :public SixJointRobot
{
public:
    RV6SL();

private:
    void RV6SLMesh();

    STLMesh* _arm;
};

#endif // RV6SL_H
