#include "robotcontrol.h"
#include "ui_robotcontrol.h"

RobotControl::RobotControl(Robot* robot,QWidget *parent) :
    SubWindow(parent),
    ui(new Ui::RobotControl)
{
    ui->setupUi(this);
    _disable(true);
    _robot=robot;
    connect(_robot,&Robot::robotAnswer,this,&RobotControl::TextOutput);
    connect(_robot,&Robot::robotCommand,this,&RobotControl::TextOutput);
    connect(_robot,&Robot::alternativeCommand,this,&RobotControl::TextOutput);

    connect(ui->pb_connect,&QPushButton::clicked,this,&RobotControl::_connectClicked);
    connect(ui->pb_servo,&QPushButton::clicked,this,&RobotControl::_servoClicked);
    connect(ui->pb_stop,&QPushButton::clicked,this,&RobotControl::_stopClicked);
    connect(ui->pb_update,&QPushButton::clicked,this,&RobotControl::_update);
    connect(ui->cb_updating,&QCheckBox::toggled,this,&RobotControl::_directUpdate);
}

RobotControl::~RobotControl()
{
    delete ui;
}

void RobotControl::TextOutput(QString text)
{
    ui->plainTextEdit->appendPlainText(text);
}

void RobotControl::_connectClicked()
{
    if(ui->pb_connect->text()=="connect"){
        _robot->Connect();
        ui->pb_connect->setText("disconnect");
        _disable(false);
    }
    else{
        _robot->Disconnect();
        ui->pb_connect->setText("connect");
        _disable(true);
    }
}

void RobotControl::_servoClicked()
{
    if(ui->pb_servo->text()=="servo on"){
        _robot->ServoOn(true);
        ui->pb_servo->setText("servo off");
    }
    else{
        _robot->ServoOn(false);
        ui->pb_servo->setText("servo on");
    }
}

void RobotControl::_stopClicked()
{
    _robot->EmergencyStop();
}

void RobotControl::_update()
{
    _robot->UpdatePosition();
}

void RobotControl::_directUpdate(bool checked)
{
    _robot->DirectUpdating=checked;
}

void RobotControl::_disable(bool disable)
{
    ui->pb_servo->setDisabled(disable);
    ui->pb_stop->setDisabled(disable);
    ui->pb_update->setDisabled(disable);
    ui->cb_updating->setDisabled(disable);
}
