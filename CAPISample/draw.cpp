#include "draw.h"

Draw::Draw(Kinematik *robot, QVector3D sled_pos,Qt3DCore::QTransform* plane,Widget3D *widget3d)
{
    timer_draw = new QTimer;
    timer_moveBack   = new QTimer;
    _robot = robot;
    _robot->setJoints(0,0,90,0,90,0,0);
    _plane = plane;
    _widget3d = widget3d;

    connect(timer_draw, &QTimer::timeout,this, &Draw::draw_onTimeout);

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
    shiftVec2BaseAndRobot();
    inc_letter=false;
    letter=0;
    qDebug()<<"points2D_names size"<<points2D_names.size();
//    getWord("MA");
}

void Draw::draw_onTimeout()
{
    if (counter==0 && currentIndex == 0)
        emit deletePoints();

    robot_setPoint(pointsRobot[letter][counter]+shift_vecRobot);

    if(drawPoint_isTrue[letter][counter])
        emit sendPoint(pointsPlane[letter][counter]+shift_vecBase);

    counter++;

    if (counter==pointsRobot[letter].length())
    {
        counter=0;
        back:
        currentIndex++;
        if(currentIndex==LetterInputIndex.size()){
            timer_draw->stop();
        }else{
            letter=LetterInputIndex[currentIndex];
            if(letter==-1){
                shift_vecPlane.setX(shift_vecPlane.x()+60);
                goto back;
            }
            shift_vecPlane.setX(shift_vecPlane.x()+60);
            shiftVec2BaseAndRobot();
        }

        if(inc_letter && letter<points2D_names.size()-1)
        {
           letter++;
        }
        else if(letter==points2D_names.size()-1)
        {
           letter=0;
        }

        _robot->setJoints(0,0,90,0,90,0,0);

    }
}

void Draw::shiftVec2BaseAndRobot()
{
    QMatrix4x4 temp_planeMat =_plane->matrix();
    QMatrix4x4 temp_robotMat = robotMat;
    temp_robotMat.setColumn(3,QVector4D(0,0,0,1));
    temp_planeMat.setColumn(3,QVector4D(0,0,0,1));
    shift_vecBase = QVector3D(temp_planeMat * shift_vecPlane);

    shift_vecRobot = QVector3D(temp_robotMat.inverted() * shift_vecBase);
    qDebug()<<shift_vecRobot;
}
void Draw::robot_setPoint(QVector3D position)
{
//    _robot->setPoint(position.x()+shift_vecRobot.x(),
//                     position.y()+shift_vecRobot.y(),
//                     position.z()+shift_vecRobot.z(),
//                     a,b,c,l1);
    _robot->setPoint(position.x(),
                     position.y(),
                     position.z(),
                     a,b,c,l1);

    _robot->ToolMovement(Transformations::Z,-199);
}
void Draw::getWord(QString str)
{
    LetterInput.clear();
    LetterInputIndex.clear();
    shift_vecPlane = QVector3D(10,10,0);
    shiftVec2BaseAndRobot();

    int length = str.length();

    for (int i =  0; i < length; ++i) {
        // Access each character using the index
//        QChar letter = str.at(i);
        if(str.at(i)==" "){
           LetterInputIndex.push_back(-1);
        }else{
           LetterInput.push_back(str.at(i));
           int index = points2D_names.indexOf(str.at(i));
           LetterInputIndex.push_back(index);
        }
        // Now you have access to the single letter
    }
    qDebug()<<LetterInput;
    qDebug()<<LetterInputIndex;
    currentIndex=0;
    letter=LetterInputIndex[currentIndex];
}
void Draw::drawWord()
{
    for (QString oneLetter:LetterInput)
    {

    }
}

void Draw::setLetter(QString str)
{

    int index = points2D_names.indexOf(str);
    if (index != -1) {
        qDebug() << "First occurrence of B is at position" << index;
        letter = index;
    } else {
        letter=0;
        qDebug() << "Value B not found in vector.";
    }
}

void Draw::setTime(int time_ms)
{
    current_time = time_ms;
    timer_draw->setInterval(current_time);
    timer_moveBack->setInterval(current_time);
}
void Draw::draw_TimerStart(/*int time*/)
{
//    timer_draw->setInterval(current_time);
    timer_draw->start();
}

void Draw::draw_TimerStop()
{
    timer_draw->stop();
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
{return qSqrt(qPow(point1.x()-point2.x(),2)+qPow(point1.y()-point2.y(),2));}

void Draw::points2D_toPlane()
{
   for (QVector <QVector2D> points_vec:points2D)
   {
        QVector2D prev_point=points_vec.first();
        QVector <QVector3D> temp_pointsPlane;
        QVector <bool> temp_drawPoint_isTrue;
        temp_drawPoint_isTrue.push_back(true);
        points_vec.remove(0);
        for (QVector2D point:points_vec)
        {

            if(cartDist(prev_point,point)>5)
            {
                drawLine(prev_point,point,temp_pointsPlane,temp_drawPoint_isTrue);
                temp_pointsPlane.push_back(calcPointInPlane(point));
                temp_drawPoint_isTrue.push_back(true);
            }
            else
            {
                temp_pointsPlane.push_back(calcPointInPlane(point));
                temp_drawPoint_isTrue.push_back(true);
            }

            prev_point = point;
        }
        drawPoint_isTrue.push_back(temp_drawPoint_isTrue);
        pointsPlane.push_back(temp_pointsPlane);
   }
}

QVector3D Draw::calcPointInPlane(QVector2D point)
{
    return _plane->translation()+(point.x()*planeX)+(point.y()*planeY);
}

void Draw::drawLine(QVector2D point_begin,QVector2D point_end,QVector <QVector3D> &vec,QVector <bool> &draw_vec)
{
    int i;
    int plane_dist = 20;
    for (i=1;i<plane_dist;i++)
    {
        vec.push_back(calcPointInPlane(point_begin)+(planeZ*i));
        draw_vec.push_back(false);
    }
    QVector3D point_begin_Z = calcPointInPlane(point_begin)+(planeZ*i);
    QVector2D vec_between = point_end-point_begin;

    for (int j=0;j<vec_between.length();j++)
    {
        vec.push_back(point_begin_Z+(vec_between.normalized().x()*planeX*j)+(vec_between.normalized().y()*planeY*j));
        draw_vec.push_back(false);
    }

    for (int k=1;k<plane_dist;k++)
    {
        vec.push_back(calcPointInPlane(point_end)+(planeZ*i)-(planeZ*k));
        draw_vec.push_back(false);
    }
}


void Draw::Txt2QVector2D()
{
    QDir dir =QDir::currentPath();
    dir.cdUp();
    dir.cdUp();
    dir.cd("LettersTxt");
    qDebug()<<"directory:"<<dir;

    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    QFileInfoList fileInfos = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

    foreach (QFileInfo fileInfo, fileInfos)
    {
        qDebug() << "Found text file:" << fileInfo.baseName();

//    findTxtFiles(dir.path());

//    for (int i=1;i<40;i++)
//    {
        QFile file(QString(fileInfo.absoluteFilePath()));
//        qDebug()<<fileInfo.absoluteFilePath();
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
        points2D_names.push_back(fileInfo.baseName());
        points2D.push_back(temp_points2D);
//        qDebug()<<points2D;
        file.close();
    }
//    }
    qDebug()<<points2D_names;
    qDebug()<<"points";
    qDebug()<<points2D[34].mid(1,10);
    qDebug()<<"secnd_vec";
    qDebug()<<points2D[35].mid(1,10);

}



void Draw::inc_letter_changeState(){
    inc_letter=!inc_letter;
}
QString Draw::getLetterName()
{
    return points2D_names[letter];
}
void Draw::RobotSpeedChanged(int time_ms)
{
    current_time=time_ms;
}

