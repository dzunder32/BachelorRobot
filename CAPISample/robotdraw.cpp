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




    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=-20;
    robotMat.setColumn(3,QVector4D((sled_pos+QVector3D(0,l1,0)),1));
    robotMat.rotate(90,QVector3D(0,0,1));

    getLetter();

    cornerPoints = _plane->getCornerPoints();
}


void RobotDraw::robDraw_onTimeout()
{

    if(counter<=cornerPoints.length()-1)
    {
        qDebug()<<counter;
        QVector3D basePoint = cornerPoints[counter];
        robot_setPoint(Base2RobotPoint(basePoint));
        counter++;
    }
    else
    {
        emit stopTimer();

        while(_timer->isActive())
        {
            qDebug()<<"inWhile!";
        }

        robot_moveHome();
        counter=0;
    }
    qDebug()<<counter;


}

void RobotDraw::getLetter()
{
    currentLetter = _letters->F;
}

void RobotDraw::robot_setPoint(QVector3D position)
{
    _robotKinematik->setPoint(position.x(),
                              position.y(),
                              position.z(),
                              a,b,c,l1);


    _robotKinematik->ToolMovement(Transformations::Z,-199);

    if(_robot->IsConnected())
    {
        _robot->UpdatePosition();
        _robotKinematik->WaitForPositionReached();
    }

}



void RobotDraw::robot_moveHome()
{
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    qDebug()<<"imHome";

    if(_robot->IsConnected())
    {
        _robot->UpdatePosition();
        //        isDrawing=false;
    }
    //    }
}



