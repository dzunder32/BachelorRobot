#include "robotdraw.h"

RobotDraw::RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d)
{
    _letters = new Letters;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    _robot = robot;
    _plane = plane;
    _widget3d = widget3d;
    _timer = new QTimer;

    connect(_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);

    robotMat.rotate(90,QVector3D(0,0,1));
    robotMat.setColumn(3,QVector4D(sled_pos,1));

    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=500;

    getLetter();
}


void RobotDraw::robDraw_onTimeout()
{

        counter++;
        qDebug()<<"aight"<<counter;
        // qDebug()<<"sleep for 1 sec";
        // std::this_thread::sleep_for(std::chrono::seconds(1));

}

void RobotDraw::getLetter()
{
    currentLetter = _letters->F;
}


