#include "robot.h"

Robot::Robot(QString ip, int port)
{
    _ip=ip;
    _port=port;

    _connect=false;
    _emergencyStop=false;
    DirectUpdating=false;

    connect(this,  &QThread::finished, this,&QObject::deleteLater);

//    qDebug()<<"roboThread"<< QThread::currentThreadId();
}

void Robot::ConnectKinematik(RobotPosition* pos)
{
    _position=pos;
    connect(pos,&RobotPosition::j1Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j2Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j3Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j4Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j5Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j6Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::j7Changed,this,&Robot::_positionChanged);
    connect(pos,&RobotPosition::jointsChanged,this,&Robot::_positionChanged);

    connect(pos,&Kinematik::updateRobot,this,&Robot::UpdatePosition);
    connect(pos,&Kinematik::updateRobotFromUi,this,&Robot::UpdatePositionFromUi);

}


void Robot::_positionChanged()
{
    _connetedRobotChangePosition=true;
//    qDebug()<<_position->getTransformationMatrix();
//    qDebug()<<"roboThread3"<< QThread::currentThreadId();

}

void Robot::UpdatePosition()
{
    MoveToPosition(_position);
    Write("USR:PositionChanged");
}

void Robot::UpdatePositionLinear()
{
    MoveToPositionLinear(_position);
    Write("USR:PositionChanged");
}

void Robot::UpdatePositionFromUi()
{
    if(DirectUpdating)
    {
        MoveToPosition(_position);
        Write("USR:PositionChanged");
    }
}

void Robot::MoveToPosition(Position* pos)
{
    Write("1;1;EXECJ81=("+QString::number(pos->j1())+","
                         +QString::number(pos->j2())+","
                         +QString::number(pos->j3())+","
                         +QString::number(pos->j4())+","
                         +QString::number(pos->j5())+","
                         +QString::number(pos->j6())+","
                         +QString::number(pos->j7())+")");
    Write("1;1;EXECMOV J81");
}

void Robot::MoveToPositionLinear(Position* pos)
{
    Write("1;1;EXECJ81=("+QString::number(pos->j1())+","
                         +QString::number(pos->j2())+","
                         +QString::number(pos->j3())+","
                         +QString::number(pos->j4())+","
                         +QString::number(pos->j5())+","
                         +QString::number(pos->j6())+","
                         +QString::number(pos->j7())+")");
    Write("1;1;EXECMVS J81");
}

void Robot::MoveInCircle(QVector3D P1,QVector3D P2,QVector3D P3,double ew1, double ew2, double ew3, double l1)
{
    Write("1;1;EXECP1=(" +QString::number(P1.x())+","
                         +QString::number(P1.y())+","
                         +QString::number(P1.z())+","
                         +QString::number(ew1)+","
                         +QString::number(ew2)+","
                         +QString::number(ew3)+","
                         +QString::number(l1)+")");

    Write("1;1;EXECP2=(" +QString::number(P2.x())+","
                         +QString::number(P2.y())+","
                         +QString::number(P2.z())+","
                         +QString::number(ew1)+","
                         +QString::number(ew2)+","
                         +QString::number(ew3)+","
                         +QString::number(l1)+")");

    Write("1;1;EXECP3=(" +QString::number(P3.x())+","
                         +QString::number(P3.y())+","
                         +QString::number(P3.z())+","
                         +QString::number(ew1)+","
                         +QString::number(ew2)+","
                         +QString::number(ew3)+","
                         +QString::number(l1)+")");

    Write("1;1;EXECMVR P1,P2,P3");
    Write("USR:PositionChanged");

}

void Robot::MoveInCircleJ(QVector <double> joints1,QVector <double> joints2,QVector <double> joints3,double joint7)
{
    Write("1;1;EXECJ1=(" +QString::number(joints1.at(0))+","
                         +QString::number(joints1.at(1))+","
                         +QString::number(joints1.at(2))+","
                         +QString::number(joints1.at(3))+","
                         +QString::number(joints1.at(4))+","
                         +QString::number(joints1.at(5))+","
                         +QString::number(joint7)+")");

    Write("1;1;EXECJ2=(" +QString::number(joints2.at(0))+","
                         +QString::number(joints2.at(1))+","
                         +QString::number(joints2.at(2))+","
                         +QString::number(joints2.at(3))+","
                         +QString::number(joints2.at(4))+","
                         +QString::number(joints2.at(5))+","
                         +QString::number(joint7)+")");

    Write("1;1;EXECJ3=(" +QString::number(joints3.at(0))+","
                         +QString::number(joints3.at(1))+","
                         +QString::number(joints3.at(2))+","
                         +QString::number(joints3.at(3))+","
                         +QString::number(joints3.at(4))+","
                         +QString::number(joints3.at(5))+","
                         +QString::number(joint7)+")");

    Write("1;1;EXECMVR J1,J2,J3");
    Write("USR:PositionChanged");

}


void Robot::Connect()
{
    this->start();
}

void Robot::Disconnect()
{
    _connect=false;
}

void Robot::Write(QString command)
{
    _commandList.append(command);
}

void Robot::ServoOn(bool on)
{
    if(on)
        Write("1;1;SRVON");
    else
        Write("1;1;SRVOFF");
}

void Robot::EmergencyStop()
{
    _emergencyStop=true;
}

void Robot::run()
{
    qDebug()<<"lets Go!";
    qDebug()<<QThread::currentThreadId();
    _socket = new QTcpSocket;

    _socket->connectToHost(_ip,_port,QIODevice::ReadWrite);
    if( !_socket->waitForConnected(5000) )
    {
        _socket->disconnectFromHost();
        _connect = false;
        return;
    }
    _connect=true;
    pause(100);
    writeToRobot("1;1;CNTLON");
    pause(100);

    Write("1;1;EXECACCEL 10");
    Write("1;1;OVRD=5");

    getPosition();
    getJoints();

    forever
    {
//        qDebug()<<"im in forever!";
//        qDebug()<<QThread::currentThreadId();
        if(_connect)
        {

            if(_emergencyStop)
            {
                stopRobot();
            }

            if(!isRunning())
            {
                if(!_commandList.isEmpty())
                {
                    QString command = _commandList.takeFirst();
                    writeToRobot(command);
                }
            }
        }
        else
        {
            _socket->disconnectFromHost();
            _emergencyStop=false;
        }
    }
}

bool Robot::isRunning()
{
    QString command = "1;1;VALM_RUN";
    _socket->write((command + "\r\n").toLocal8Bit());
    if(_socket->waitForReadyRead(-1))
    {
        QString answer=_socket->readAll().remove(0,10);
        if(answer=="0")
        {
            running(false);
            return false;
        }
        else
        {
            running(true);
            return true;
        }
    }
    else
    {
        return true;
    }
}

void Robot::getJoints()
{
    Write("1;1;JPOSF");
}

void Robot::getPosition()
{
    Write("1;1;PPOSF");
}

void Robot::writeToRobot(QString command)
{

    if(command.startsWith("USR:"))
    {
        _alternativeCommand(command);
        alternativeCommand(command);
    }
    else
    {
        QByteArray command_temp = (command+"\r\n").toLocal8Bit();
        _socket->write(command_temp);
        qDebug()<<command;
        emit robotCommand(command);
        readFromRobot(command);
    }
}

void Robot::readFromRobot(QString command)
{
    QString answer = "";

    while(answer == "")
    {
        if(_socket->waitForReadyRead(-1) )
            answer = _socket->readAll();
    }
    emit robotAnswer(answer);
    if(answer.startsWith("QoK"))
    {
        answer.remove(0,3);
    }
    if(command=="1;1;SRVON")
    {
        pause(5000);
    }
    if(answer.startsWith("QeR") | answer.startsWith("Qer"))
    {

    }
    if(answer.startsWith("J1;") )
    {
        float j1 = answer.section(';', 1, 1).toDouble();
        float j2 = answer.section(';', 3, 3).toDouble();
        float j3 = answer.section(';', 5, 5).toDouble();
        float j4 = answer.section(';', 7, 7).toDouble();
        float j5 = answer.section(';', 9, 9).toDouble();
        float j6 = answer.section(';',11,11).toDouble();
        float j7 = answer.section(';',13,13).toDouble();
        if(_position!=nullptr)
        {
            _position->setJoints(j1,j2,j3,j4,j5,j6,j7);
            _position->updateView();
        }
    }
}

void Robot::stopRobot()
{
    QString answer = "EMERGENCYSTOP: ";
    QString command = "1;1;STOP";
    _socket->write((command + "\r\n").toLocal8Bit());
    if(_socket->waitForReadyRead(-1))
    {
        answer.append(_socket->readAll());
    }
    _emergencyStop = false;

    emit robotCommand(command)
            ;
    emit robotAnswer(answer);
}

void Robot::pause(int ms)
{

    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed()<ms)
    {

    }
}

void Robot::_alternativeCommand(QString command)
{
    command.remove(0,4);
    if(command=="PositionChanged")
    {
        qDebug()<<"position"<<_position;
        if(_position!=nullptr){
            qDebug()<<"reached the position!";
            _position->Reached();}
        _connetedRobotChangePosition=false;
    }
}
