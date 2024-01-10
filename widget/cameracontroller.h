#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras>
#include <QDebug>
#include <QKeyEvent>
#include <QWidget>
#include <QKeyEvent>


class CameraController : public Qt3DExtras::QAbstractCameraController
{
    Q_OBJECT
public:
    explicit CameraController(Qt3DCore::QNode *parent = nullptr);
    ~CameraController();
    void moveCamera(const QAbstractCameraController::InputState &state, float dt) override;

private:

    double _x=0,_y=0,_scale=0;
    QMatrix4x4 _T1,_T2;
    Qt3DRender::QCamera *theCamera;


    void zoom(float scale);
    void shift(float x, float y);
    void rotate(float x, float y);
};

#endif // CAMERACONTROLLER_H
