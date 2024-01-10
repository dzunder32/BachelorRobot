#ifndef RV4FL_H
#define RV4FL_H

#include <QDir>
#include "sixjointrobot.h"

class RV4FL : public SixJointRobot
{
public:
    RV4FL();
private:
    void RV4FLMesh();
};

#endif // RV4FL_H
