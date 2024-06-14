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

//    PointsBuffer = _plane->getCornerPoints();
}


void RobotDraw::robDraw_onTimeout()
{
    QVector <QVector3D> test = {_plane->translation()+QVector3D(100,100,0),_plane->translation()+QVector3D(100,-100,0)};
    robot_drawLine(test);

    if(counter<=robotSequence.length()-1)
    {
        switch (robotSequence[counter])
        {
        case 1:
            QVector3D basePoint = PointsBuffer[counter];
            robot_setPoint(Base2RobotPoint(basePoint));
            break;
//        case 2:
//            // statements_2;
//            break;
//        case 3:
//            break;
//        default:
//            qDebug()<<"no valid Value";
//            break;
        }
        qDebug()<<counter;

        counter++;
    }
    else
    {
        emit stopTimer();

        while(_timer->isActive())
        {
            qDebug()<<"inWhile!";
        }
        _widget3d->deleteAllPoints();
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

void RobotDraw::robot_drawLine(QVector <QVector3D> linePts)
{
    QVector3D start = linePts[0];
    QVector3D end   = linePts[1];

    robot_setPoint(Base2RobotPoint(start));
    qDebug()<<"first PT";
    stopTimer();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    robot_setPoint(Base2RobotPoint(end));
    qDebug()<<"second PT";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    startTimer();
}

void RobotDraw::UpdatePointsBuffer(QVector <QVector3D> pts)
{
    PointsBuffer = pts;
    for(auto i:pts){
        robotSequence.append(1);
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



