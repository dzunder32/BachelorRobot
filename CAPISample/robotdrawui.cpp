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

void RobotDrawUi::on_pushButton_setP1_clicked()
{
    ui->lineEdit_P1Data->setText("P1:(" + ui->lineEdit_P1X->text()+ "; " + ui->lineEdit_P1Y->text() + ")");
    QVector3D planePoint = QVector3D(ui->lineEdit_P1X->text().toFloat(),ui->lineEdit_P1Y->text().toFloat(),0);
    qDebug()<<planePoint;
    _robDraw->AddPoint2Buffer(_robDraw->Plane2BasePoint(planePoint));
    _widget3d->drawPoint(_robDraw->Plane2BasePoint(planePoint),5,QColor(255,255,0));
}


void RobotDrawUi::on_pushButton_setP2_clicked()
{
    ui->lineEdit_P2Data->setText("P2:(" + ui->lineEdit_P2X->text()+ "; " + ui->lineEdit_P2Y->text() + ")");
    QVector3D planePoint = QVector3D(ui->lineEdit_P2X->text().toFloat(),ui->lineEdit_P2Y->text().toFloat(),0);
    qDebug()<<planePoint;
    _robDraw->AddPoint2Buffer(_robDraw->Plane2BasePoint(planePoint));
    _widget3d->drawPoint(_robDraw->Plane2BasePoint(planePoint),5,QColor(255,0,255));
}

