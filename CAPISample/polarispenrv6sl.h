#ifndef POLARISPENRV6SL_H
#define POLARISPENRV6SL_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "tool.h"
#include "stlmesh.h"

class PolarisPenRv6sl: public Tool
{
public:
    PolarisPenRv6sl(Qt3DCore::QEntity* parent=nullptr);

private:
    STLMesh* _tool;
};

#endif // POLARISPENRV6SL_H
