#ifndef KINECTCAMERA_H
#define KINECTCAMERA_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "tool.h"
#include "stlmesh.h"

class KinectCamera: public Tool
{
public:
    KinectCamera(Qt3DCore::QEntity* parent=nullptr);
    void  connectWithRecording(Qt3DCore::QEntity *stlMesh);

private:
    STLMesh* _tool;

};



#endif // KINECTCAMERA_H
