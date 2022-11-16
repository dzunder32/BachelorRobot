#include "polaristool.h"

PolarisTool::PolarisTool(ToolData tool)
{
    this->QQuaternion::operator=( QQuaternion(tool.transform.q0,
                              tool.transform.qx,
                              tool.transform.qy,
                              tool.transform.qz));
    this->QQuaternion::normalize();


    this->QMatrix4x4::operator=(QMatrix4x4(this->QQuaternion::toRotationMatrix()));
    this->operator()(0,3) = tool.transform.tx;
    this->operator()(1,3) = tool.transform.ty;
    this->operator()(2,3) = tool.transform.tz;

    this->QString::operator=( QString::number(tool.transform.toolHandle));
}
