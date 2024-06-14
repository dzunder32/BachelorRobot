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
    connect(_robDraw, &RobotDraw::drawLine,this, &RobotDrawUi::drawLineWidget);

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
//    _robDraw->connectTimer();
    startDrawTimer();
//    disconnect(_robDraw->_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);
}


void RobotDrawUi::on_pushButtonDelete_clicked()
{
//    _robDraw->disconnectTimer();
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
    P1X_Str = ui->lineEdit_P1X->text();
    P1Y_Str = ui->lineEdit_P1Y->text();
    P1 = QVector3D(P1X_Str.toFloat(),P1Y_Str.toFloat(),0);
    _robDraw->AddPoint2Buffer(_robDraw->Plane2BasePoint(P1));
    _widget3d->drawPoint(_robDraw->Plane2BasePoint(P1),5,QColor(255,255,0));
}


void RobotDrawUi::on_pushButton_setP2_clicked()
{
    ui->lineEdit_P2Data->setText("P2:(" + ui->lineEdit_P2X->text()+ "; " + ui->lineEdit_P2Y->text() + ")");
    P2X_Str = ui->lineEdit_P2X->text();
    P2Y_Str = ui->lineEdit_P2Y->text();
    P1 = QVector3D(P2X_Str.toFloat(),P2Y_Str.toFloat(),0);
    _robDraw->AddPoint2Buffer(_robDraw->Plane2BasePoint(P2));
    _widget3d->drawPoint(_robDraw->Plane2BasePoint(P2),5,QColor(255,0,255));
}


void RobotDrawUi::on_pushButton_clicked()
{
    qDebug()<<_robDraw->_timer->isActive();
}

void RobotDrawUi::on_pushButton_addLine_clicked()
{
    _robDraw->AddLine2Buffer({P1,P2});
    ui->textEdit_Sequence->moveCursor(QTextCursor::End);
    ui->textEdit_Sequence->insertPlainText("\n");
    ui->textEdit_Sequence->insertPlainText("Line: Start("+P1X_Str+ "," + P1Y_Str + ")" + "End("+ P2X_Str+ "," + P2Y_Str + ")" );

}
