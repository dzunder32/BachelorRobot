#include "drawletters.h"
#include "ui_drawletters.h"

DrawLetters::DrawLetters(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane,Widget3D *widget3d, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawLetters)
{
    ui->setupUi(this);

    _widget3d = widget3d;
    _robot = robot;
    _draw = new Draw(robotKinematik,_robot,sled_pos,plane,widget3d);
    _draw->moveToThread(&robotThread);

    connect(&robotThread,  &QThread::finished, _draw,&QObject::deleteLater);
    connect(_draw, &Draw::sendPoint,this, &DrawLetters::drawPointWidget);
    connect(_draw, &Draw::deletePoints,this, &DrawLetters::deletePointWidget);
//    connect(ui->checkBox_NextLetter,&QCheckBox::stateChanged,_draw,&Draw::inc_letter_changeState);
//    connect(ui->spinBox_robotSpeed,&QSpinBox::valueChanged,_draw,&Draw::RobotSpeedChanged);
//    connect(ui->pushButton_Draw,&QPushButton::clicked,this,&DrawLetters::spinBox_valueChanged);
    connect(ui->pushButton_Draw,&QPushButton::clicked,this,&DrawLetters::pB_draw_clicked);
    connect(_draw,&Draw::stopTimerDraw,this,&DrawLetters::stopTimer);
    robotThread.start();
    pbStop=true;
}

DrawLetters::~DrawLetters()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}

void DrawLetters::pB_draw_clicked()
{
    if(ui->checkBox->isChecked())
        _draw->setIncrementCounterValue(ui->spinBox_spacePoints->value());

    _draw->CreatePointsFromTxt(float(ui->spinBox_LetterSize->value())/10);
    _draw->getWord(ui->textEdit_Letter->toPlainText());
    _draw->isDrawing = true;
//    if(!_robot->IsConnected()){
        _draw->StartSimulation(ui->robotSpeedSlider->value());
//    }else
//    {
//        _draw->StartRobot();
//    }
}

void DrawLetters::on_pushButton_2_clicked()
{
    if(pbStop){
        _draw->draw_TimerStop();
    }else{
        _draw->StartSimulation(ui->robotSpeedSlider->value());
    }
    pbStop=!pbStop;

}
void DrawLetters::stopTimer()
{
    _draw->draw_TimerStop();
    qDebug()<<"timerStopped";
}

void DrawLetters::on_buttonDeletePoint_clicked()
{
    _widget3d->deleteAllPoints();

}

void DrawLetters::drawPointWidget(QVector3D point,float thickness)
{
    _widget3d->drawPoint(point,thickness,QColor(255,255,255));
}
void DrawLetters::deletePointWidget()
{
    _widget3d->deleteAllPoints();
}


void DrawLetters::on_spinBox_LetterSize_valueChanged(int arg1)
{
    ui->textEdit_Letter->selectAll(); // Select all text
    ui->textEdit_Letter->setFontPointSize(arg1+9);
//    _draw->CreatePointsFromTxt(float(arg1)/10);
}

void DrawLetters::on_robotSpeedSlider_valueChanged(int value)
{
    _draw->setTime(value);

}



void DrawLetters::on_checkBox_2_clicked()
{
    _draw->simulation_isTrue = ui->checkBox_2->isChecked();
    qDebug()<<_draw->simulation_isTrue;
}

