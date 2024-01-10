 #ifndef POLARISTOOL_H
#define POLARISTOOL_H

#include <QObject>
#include <QQuaternion>
#include <QMatrix4x4>

#include "ToolData.h"

class PolarisTool:public QMatrix4x4, public QQuaternion, public QString
{
public:
    PolarisTool(ToolData tool);
};

#endif // POLARISTOOL_H
