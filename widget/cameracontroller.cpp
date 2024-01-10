#include "cameracontroller.h"

CameraController::CameraController(Qt3DCore::QNode *parent)
    : QAbstractCameraController(parent)
{
}

CameraController::~CameraController()
{
}

void CameraController::moveCamera(const QAbstractCameraController::InputState &state, float dt)
{
    theCamera=camera();

    if (theCamera == nullptr)
        return;
    zoom(state.tzAxisValue *linearSpeed()*dt);
    if(state.rightMouseButtonActive)
        shift(-state.rxAxisValue*linearSpeed()*dt,state.ryAxisValue*linearSpeed()*dt);
    if(state.leftMouseButtonActive)
        rotate(state.rxAxisValue*lookSpeed()*dt,state.ryAxisValue*lookSpeed()*dt);

}


void CameraController::zoom(float scale)
{
    _scale+=scale*3;
    camera()->translate(QVector3D(0, 0, scale*3));
}

void CameraController::shift(float x,float y)
{
    x*=-3;
    y*=3;
    _x+=x;
    _y+=y;
    camera()->translate(QVector3D(x, y, 0), Qt3DRender::QCamera::CameraTranslationOption::TranslateViewCenter);
}

void CameraController::rotate(float x, float y)
{
    QMatrix4x4 Tx,Ty;
    Ty.rotate(y*0.5, QVector3D(1,0,0)); //horizontal rotation
    Tx.rotate(x*0.5, QVector3D(0,0,1));  //z rotation

    QVector4D Pos(_x, _y,_scale,1);
    camera()->translate(-Pos.toVector3D(), Qt3DRender::QCamera::CameraTranslationOption::TranslateViewCenter);
    camera()->rotateAboutViewCenter(QQuaternion::fromRotationMatrix(_T1.toGenericMatrix<3,3>()));
    camera()->rotateAboutViewCenter(QQuaternion::fromRotationMatrix(Ty.toGenericMatrix<3,3>()));
    camera()->rotateAboutViewCenter(QQuaternion::fromRotationMatrix(_T2.toGenericMatrix<3,3>()));
    camera()->rotateAboutViewCenter(QQuaternion::fromRotationMatrix(Tx.toGenericMatrix<3,3>()));
    camera()->translate(Pos.toVector3D(), Qt3DRender::QCamera::CameraTranslationOption::TranslateViewCenter);

    _T1.rotate(-x*0.5, QVector3D(0,0,1));
    _T2.rotate(x*0.5, QVector3D(0,0,1));
}
