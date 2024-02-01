#include "draw.h"

Draw::Draw(Kinematik *robot, QVector3D sled_pos,Qt3DCore::QTransform* plane,Widget3D *widget3d)
{
    timer = new QTimer;
    _robot = robot;
    _plane = plane;
    _widget3d = widget3d;
    connect(timer, &QTimer::timeout,this, &Draw::onTimeout);
    robotMat.rotate(90,QVector3D(0,0,1));
    robotMat.setColumn(3,QVector4D(sled_pos,1));
    qDebug()<<robotMat;
    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=0;
    planeX=QVector3D(_plane->matrix().column(0));
    planeY=QVector3D(_plane->matrix().column(1));
    planeZ=QVector3D(_plane->matrix().column(2));


    Txt2QVector2D();
    points2D_toPlane();
    plane2robotPts();
    shift_vecPlane = QVector3D(10,10,0);

    QMatrix4x4 temp_planeMat =_plane->matrix();
    QMatrix4x4 temp_robotMat = robotMat;
    temp_robotMat.setColumn(3,QVector4D(0,0,0,1));
    temp_planeMat.setColumn(3,QVector4D(0,0,0,1));
    shift_vecBase = QVector3D(temp_planeMat * shift_vecPlane);
//    qDebug()<< robotMat.normalMatrix();
//    robotMat.setColumn(3,QVector4D(0,0,0,1));

    shift_vecRobot = QVector3D(temp_robotMat.inverted() * shift_vecBase);
    qDebug()<<shift_vecRobot;
//    robotMat.setColumn(3,QVector4D(sled_pos,1));

}

void Draw::onTimeout()
{
    _robot->setPoint(pointsRobot[letter][counter].x()+shift_vecRobot.x(),pointsRobot[letter][counter].y()+shift_vecRobot.y(),pointsRobot[letter][counter].z()+shift_vecRobot.z(),a,b,c,l1);
    _robot->ToolMovement(Transformations::Z,-199);

//    if(counter % 3 == 0)
    emit sendPoint(pointsPlane[letter][counter]+shift_vecBase);
    counter++;


    if (counter==pointsRobot[letter].length())
    {
        counter=0;
        TimerStop();
    }
}

void Draw::setLetter(int num)
{
    letter = num;
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
    QVector <QVector3D> temp_pointsRobot;
    for (QVector <QVector3D> pointsPlane_vec:pointsPlane)
    {
        temp_pointsRobot.clear();
        for (auto point:pointsPlane_vec){
            temp_pointsRobot.push_back(QVector3D(robotMat.inverted() * point));
        }
        pointsRobot.push_back(temp_pointsRobot);
    }
}

float Draw::cartDist(QVector2D point1,QVector2D point2)
{

   return qSqrt(qPow(point1.x()-point2.x(),2)+qPow(point1.y()-point2.y(),2));
}

void Draw::points2D_toPlane()
{
   for (QVector <QVector2D> points_vec:points2D)
   {
        QVector2D prev_point=points_vec.first();
        QVector <QVector3D> temp_pointsPlane;
//        qDebug()<<"First:"<<prev_point;
        points2D.remove(0);
        for (QVector2D point:points_vec)
        {

            if(cartDist(prev_point,point)>2)
            {
//                qDebug()<<"prev_point"<<prev_point<<" "<<point<<"cartDist"<<cartDist(prev_point,point);
                drawLine(prev_point,point,temp_pointsPlane);
            }
            else
            {
                temp_pointsPlane.push_back(calcPointInPlane(point));
            }

            prev_point = point;
        }
        pointsPlane.push_back(temp_pointsPlane);
   }
}

QVector3D Draw::calcPointInPlane(QVector2D point)
{
    return _plane->translation()+(point.x()*planeX)+(point.y()*planeY);
}

void Draw::drawLine(QVector2D point_begin,QVector2D point_end,QVector <QVector3D> &vec)
{
    int i;
    for (i=0;i<20;i++)
    {
        vec.push_back(calcPointInPlane(point_begin)+(planeZ*i));
    }
    QVector3D point_begin_Z = calcPointInPlane(point_begin)+(planeZ*i);
    QVector2D vec_between = point_end-point_begin;

    for (int j=0;j<vec_between.length();j++)
    {
        vec.push_back(point_begin_Z+(vec_between.normalized().x()*planeX*j)+(vec_between.normalized().y()*planeY*j));
    }

    for (int k=0;k<20;k++)
    {
        vec.push_back(calcPointInPlane(point_end)+(planeZ*i)-(planeZ*k));
    }
}


void Draw::Txt2QVector2D()
{
    for (int i=1;i<40;i++)
    {
        QFile file(QString("C:/Users/wolfd/Desktop/BachelorArbeit/LettersTxt/") + QString::number(i) + QString(".txt"));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"you fucked up!";
            return;
        }

        QTextStream in(&file);
        QString line;
        QStringList str_list;
        QVector <QVector2D> temp_points2D;
        while (!in.atEnd())
        {
            line = in.readLine();
        //        qDebug()<<line;
            str_list=line.split(" ");
//            qDebug()<<str_list;
            temp_points2D.push_back(QVector2D(str_list[0].toInt(),str_list[1].toInt()));
        }
        points2D.push_back(temp_points2D);
//        qDebug()<<points2D;
        file.close();
    }
}


