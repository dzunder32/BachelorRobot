#include "draw.h"

Draw::Draw(Kinematik *robot, QVector3D sled_pos,Qt3DCore::QTransform* plane)
{
    timer = new QTimer;
    _robot = robot;
    _plane = plane;
    connect(timer, &QTimer::timeout,this, &Draw::onTimeout);

    robotMat.rotate(90,QVector3D(0,0,1));
    robotMat.setColumn(3,QVector4D(sled_pos,1));

    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=0;

    Txt2QVector2D();
//    points2D = {QVector2D(0,0),QVector2D(0,100),QVector2D(0,200)};
    points2D_toPlane();
//    pointsPlane={_plane->translation()};
    plane2robotPts();

    qDebug()<<robotMat;


}
void Draw::onTimeout()
{
    _robot->setPoint(pointsRobot[counter].x(),pointsRobot[counter].y(),pointsRobot[counter].z(),a,b,c,l1);
    _robot->ToolMovement(Transformations::Z,-199);
    counter++;
    if (counter==pointsRobot.length())
        counter=0;
}

void Draw::TimerStart(int time)
{
    timer->start(time);
}

void Draw::TimerStop()
{
    timer->stop();
}

void Draw::plane2robotPts()
{
    pointsRobot.clear();
//    qDebug()<<"Plane:"<<pointsPlane;
    for (auto point:pointsPlane){
//        pointRobot = QVector3D(robotMat.inverted() * point);
        pointsRobot.push_back(QVector3D(robotMat.inverted() * point));
    }
//    qDebug()<<"Robot:"<<pointsRobot;
}

void Draw::points2D_toPlane()
{
    planeX=QVector3D(_plane->matrix().column(0));
    planeY=QVector3D(_plane->matrix().column(1));

    for (QVector2D point:points2D){
        pointsPlane.push_back(_plane->translation()+(point.x()*planeX)+(point.y()*planeY));
    }
}
void Draw::Txt2QVector2D()
{
    for (int i=1;i<10;i++)
    {

        QFile file(QString("C:/Users/wolfd/Desktop/BachelorArbeit/LettersTxt/") +QString::number(i) + QString(".txt"));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"you fucked up!";
            return;
        }

        QTextStream in(&file);
        QString line;
        QStringList str_list;
        while (!in.atEnd())
        {
            line = in.readLine();
        //        qDebug()<<line;
            str_list=line.split(" ");
//            qDebug()<<str_list;
            points2D.push_back(QVector2D(str_list[0].toInt(),str_list[1].toInt()));
        }
//        qDebug()<<points2D;
        file.close();
    }
}
