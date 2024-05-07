#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include "kinematik.h"
#include <QThread>
#include <QTcpSocket>
#include <QElapsedTimer>

class Robot:public QThread
{
    Q_OBJECT
private:

    void run() override;
    QTcpSocket *_socket;
    QString _ip;
    int _port;
    bool _connect;
    bool _writecheck;
    bool _emergencyStop;

    QStringList _commandList;
    RobotPosition* _position=nullptr;
    bool _connetedRobotChangePosition=false;

    void readFromRobot(QString);
    void writeToRobot(QString);
    void stopRobot();
    void pause(int);
    void getPosition();
    void getJoints();
    bool isRunning();
    void _alternativeCommand(QString);

private slots:
    void _positionChanged();

public slots:
    void UpdatePosition();
    void Write(QString);
    void Connect();
    bool IsConnected(){return _connect;}
    void Stop(){_emergencyStop=true;}
    void Disconnect();
    void ServoOn(bool);
    void EmergencyStop();
    void UpdatePositionFromUi();

public:
    bool DirectUpdating;
    Robot(QString ip,int port);
    void ConnectKinematik(RobotPosition *pos);
    void MoveToPosition(Position* pos);
    void MoveInLine(double P1, double P2, double P3, double a, double b, double c, double l1);
signals:
    void robotAnswer(QString);
    void robotCommand(QString);
    void alternativeCommand(QString);
    void running(bool);
};

#endif // ROBOT_H
