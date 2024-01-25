#ifndef PENHOLDER_H
#define PENHOLDER_H
#include "tool.h"
#include "stlmesh.h"
#include <QObject>

class PenHolder : public Tool
{
public:
    PenHolder(Qt3DCore::QEntity* parent=nullptr);

private:
    STLMesh* _tool;
};

#endif // PENHOLDER_H
