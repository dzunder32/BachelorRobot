#include "drawletters.h"
#include "ui_drawletters.h"

DrawLetters::DrawLetters(Kinematik *robot, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawLetters)
{
    ui->setupUi(this);
    _robot=robot;
//    _robot->moveToThread(&robotThread);
    this->moveToThread(&robotThread);
    connect(&robotThread,  &QThread::finished, _robot,&QObject::deleteLater);
    timer=new QTimer;
//    timer->moveToThread(&robotThread);
    connect(timer, &QTimer::timeout,this, &DrawLetters::onTimeout);
//    connect(&robotThread, &QThread::started, _robot, &Kinematik::startTimer);
    connect(this, &DrawLetters::passPosition, _robot, &Kinematik::setPoint);
    robotThread.start();
    a=0;
    b=0;
    c=0;
    l1=0;

    for (int i = 700;i<=1000; i+=1 ){
        pointsBase.push_back(QVector3D(0,0,i));
    }

//    pointsBase.push_back(QVector3D(0,0,600));
//    pointsBase.push_back(QVector3D(0,0,750));
//    pointsBase.push_back(QVector3D(0,0,800));


    robotMat.rotate(90,QVector3D(0,0,1));

}

DrawLetters::~DrawLetters()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}

void DrawLetters::setPoints(QVector<QVector3D> pts)
{
    pointsBase=pts;
}

void DrawLetters::setSledPos(QVector3D pos)
{
    sled_pos=pos;
    robotMat.setColumn(3,QVector4D(sled_pos,1));
    qDebug()<<"DrawLetters:"<<robotMat;
    for (auto& point:pointsBase){
        point+=sled_pos;
    }
    qDebug()<<"pointsBase:"<<pointsBase;
    pointsBase2Robot(pointsBase);
}

void DrawLetters::pointsBase2Robot(QVector <QVector3D> points_vec)
{
    pointsRobot.clear();
    for (auto point:points_vec){
        pointRobot = QVector3D(robotMat.inverted() * point);
        pointsRobot.push_back(pointRobot);
    }
    qDebug()<<"pointsRobot:"<<pointsRobot;
    qDebug()<<"len:"<<pointsRobot.length();
}

void DrawLetters::on_pushButton_clicked()
{
    timer->start(10);
}

void DrawLetters::onTimeout()
{

    emit passPosition(pointsRobot[counter].x(),pointsRobot[counter].y(),pointsRobot[counter].z(),a,b,c,l1);
    counter++;
    if (counter==pointsRobot.length())
        counter=0;
}


void DrawLetters::on_pushButton_2_clicked()
{
    timer->stop();
}

void DrawLetters::getPlane(Qt3DCore::QTransform *plane)
{
    trans_plane=plane;
    qDebug()<<trans_plane->translation();
    qDebug()<<trans_plane->matrix();
    qDebug()<<"x:"<<QVector3D(trans_plane->matrix().column(0));
    qDebug()<<"y:"<<QVector3D(trans_plane->matrix().column(1));

}
