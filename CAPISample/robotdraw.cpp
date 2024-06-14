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
//    connectTimer();

    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=-20;
    robotMat.setColumn(3,QVector4D((sled_pos+QVector3D(0,l1,0)),1));
    robotMat.rotate(90,QVector3D(0,0,1));

    getLetter();

//    QVector <QVector3D> test = {_plane->translation()+QVector3D(100,100,0),_plane->translation()+QVector3D(100,-100,0)};
//    LinesBuffer.append(test);
//    robotSequence.append(2);

//    PointsBuffer = _plane->getCornerPoints();
}


void RobotDraw::robDraw_onTimeout()
{


    if(counter<=robotSequence.length()-1)
    {
        switch (robotSequence[counter])
        {
        case 1:
            qDebug()<<PointsBuffer;
            if(!PointsBuffer.isEmpty())
            {
                    QVector3D basePoint = PointsBuffer.takeFirst();
                    robot_setPoint(Base2RobotPoint(basePoint));
            }else{stopTimer();robot_moveHome();}

            break;
        case 2:
            if(!LinesBuffer.isEmpty()){
                auto line = LinesBuffer.takeFirst();
                QVector3D basePoint = line[0];
                robot_setPoint(Base2RobotPoint(basePoint));
                PointsBuffer.prepend(line[1]);
                robotSequence.prepend(1);
                drawLine(line[0],line[1]);
            }else{stopTimer();robot_moveHome();}

            break;
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
        _widget3d->deleteAllLines();
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

//void RobotDraw::robot_drawLine(QVector <QVector3D> linePts)
//{

//    drawLine(start,end);
//    qDebug()<<"second PT";
////    std::this_thread::sleep_for(std::chrono::seconds(1));

////    startTimer();
//}

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



