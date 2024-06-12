#include "robotdrawui.h"
#include "ui_robotdrawui.h"

RobotDrawUi::RobotDrawUi(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane,Widget3D *widget3d,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RobotDrawUi)
{
    ui->setupUi(this);
    _widget3d = widget3d;
    _robot = robot;
    _robDraw = new RobotDraw(robotKinematik,_robot,sled_pos,plane,widget3d);
    _robDraw->moveToThread(&robotThread);

    connect(&robotThread,  &QThread::finished, _robDraw,&QObject::deleteLater);
    connect(_robDraw, &RobotDraw::startTimer,this, &RobotDrawUi::startDrawTimer);
    connect(_robDraw, &RobotDraw::stopTimer,this, &RobotDrawUi::stopDrawTimer);

    robotThread.start();
}

RobotDrawUi::~RobotDrawUi()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}

void RobotDrawUi::on_pushButtonStart_clicked()
{
    startDrawTimer();

}


void RobotDrawUi::on_pushButtonDelete_clicked()
{

    stopDrawTimer();

}


void RobotDrawUi::on_timerSpeedSlider_sliderMoved(int position)
{
    _robDraw->setTimerTime(position);
    qDebug()<<position;
}
