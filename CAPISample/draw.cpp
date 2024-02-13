#include "draw.h"

Draw::Draw(Kinematik *robot, QVector3D sled_pos,Qt3DCore::QTransform* plane,Widget3D *widget3d)
{
    timer_draw = new QTimer;
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
    unit_planeX=QVector3D(_plane->matrix().column(0));
    unit_planeY=QVector3D(_plane->matrix().column(1));
    unit_planeZ=QVector3D(_plane->matrix().column(2));

    CreatePointsFromTxt(0.1);

    shift_vecPlane = QVector3D(10,10,0);
    shiftVec2BaseAndRobot();
    inc_letter=false;
    letter=0;
    nextLetter=false;

}

void Draw::draw_onTimeout()
{
    timer.start();

    if (counter==0 && currentIndex == 0)
        emit deletePoints();

    robot_setPoint(pointsRobot[letter][counter]+shift_vecRobot);

    if(drawPoint_isTrue[letter][counter])
        emit sendPoint(pointsBase[letter][counter]+shift_vecBase,pointThickness);

    counter+=IncrementCounterValue;

    if (counter>=pointsRobot[letter].length())
    {
        getPreviousVectors();
        nextLetter=!nextLetter;

        CreatePointsFromTxt(letterSize);

        shift_vecPlane.setX(shift_vecPlane.x()+horizontalLetterDist);
        shiftVec2BaseAndRobot();
        back:
        currentIndex++;
        if(currentIndex==LetterInputIndex.size()){
            _robot->setJoints(0,0,90,0,90,0,0);
            timer_draw->stop();
        }
        else
        {
            letter=LetterInputIndex[currentIndex];

            if(letter==-1)
            {
                shift_vecPlane.setX(shift_vecPlane.x()+horizontalLetterDist);
                goto back;
            }
            else if(letter==-2){
                shift_vecPlane.setX(10);
                shift_vecPlane.setY(shift_vecPlane.y()-verticalLetterDist);
                goto back;
            }
            shiftVec2BaseAndRobot();
            nextLetter_firstPoint = pointsBase[letter].first()+shift_vecBase;
            if(nextLetter)
            {
                letter=LetterInputIndex[currentIndex-1];
                moveInLineBetweenLetters();

            }else{counter=0;}


        }
    }
        while(timer.nsecsElapsed()<300000){}

    qint64 elapsedTime = timer.nsecsElapsed(); // Get the elapsed time in nanoseconds
//    qDebug() << "Time taken:" << elapsedTime << "ns";

}
void Draw::getPreviousVectors()
{
    prevLetter_lastPoint = pointsBase[letter].last()+shift_vecBase;
    prev_shiftBase = shift_vecBase;
    prev_shiftRobot = shift_vecRobot;
}

void Draw::moveInLineBetweenLetters()
{
//    QVector <QVector3D> temp_basePoints;
//    QVector <bool> temp_drawVec;
    QVector3D point_Plane1 = Base2PlanePoint(prevLetter_lastPoint-prev_shiftBase);
    QVector3D point_Plane2 = Base2PlanePoint(nextLetter_firstPoint-prev_shiftBase);
    qDebug()<<point_Plane1 << point_Plane2;
//    qDebug()<<
    moveInLine2DPoint(point_Plane1.toVector2D(),point_Plane2.toVector2D(),pointsBase[letter],drawPoint_isTrue[letter]);
//    qDebug()<<temp_basePoints.length();
//    for (int i=temp_basePoints.length();i>0;i--){
//        pointsBase[letter].prepend(temp_basePoints[i-1]);
//        pointsRobot[letter].prepend(Base2RobotPoint(temp_basePoints[i-1]));
//        drawPoint_isTrue[letter].prepend(false);
//        qDebug()<<i;
//    }
//    for (int i=0; i<temp_basePoint)


//    for (auto it = temp_vec.rbegin(); it != temp_vec.rend(); ++it) {
//        another_vec.prepend(*it);
//    }

}
void Draw::CreatePointsFromTxt(float size)
{
    letterSize=size;
    horizontalLetterDist=60*size;
    verticalLetterDist=100*size;
    pointThickness = 2 * size;
    IncrementCounterValue=qRound(1/size);

    planeX = unit_planeX*size;
    planeY = unit_planeY*size;
    planeZ = unit_planeZ*size;

    Txt2QVector2D();
    Points2DToBase();
    Base2RobotPts();
}

void Draw::shiftVec2BaseAndRobot()
{
    QMatrix4x4 temp_planeMat =_plane->matrix();
    QMatrix4x4 temp_robotMat = robotMat;
    temp_robotMat.setColumn(3,QVector4D(0,0,0,1));
    temp_planeMat.setColumn(3,QVector4D(0,0,0,1));
    shift_vecBase = QVector3D(temp_planeMat * shift_vecPlane);
    shift_vecRobot = QVector3D(temp_robotMat.inverted() * shift_vecBase);
}
void Draw::robot_setPoint(QVector3D position)
{
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

    for (int i =  0; i < str.length(); ++i) {
        if(str.at(i)==" "){LetterInputIndex.push_back(-1);}
        else if(str.at(i)=="\n"){LetterInputIndex.push_back(-2);}
        else{
           LetterInput.push_back(str.at(i));
           int index = points2D_names.indexOf(str.at(i));
           LetterInputIndex.push_back(index);}
    }
    currentIndex=0;
    letter=LetterInputIndex[currentIndex];
}


void Draw::setLetter(QString str)
{
    int index = points2D_names.indexOf(str);

    if (index != -1){letter = index;}
    else            {letter=0;      }
}


void Draw::Base2RobotPts()
{
    pointsRobot.clear();
    QVector <QVector3D> temp_pointsRobot;
    for (QVector <QVector3D> pointsBase_vec:pointsBase)
    {
        temp_pointsRobot.clear();
        for (auto point:pointsBase_vec){
           temp_pointsRobot.push_back(Base2RobotPoint(point));
        }
        pointsRobot.push_back(temp_pointsRobot);
    }
}



void Draw::Points2DToBase()
{
   pointsBase.clear();
   for (QVector <QVector2D> points_vec:points2D)
   {
        QVector2D prev_point = points_vec.first();
        QVector <QVector3D> temp_pointsBase;
        QVector <bool> temp_drawPoint_isTrue;
        temp_drawPoint_isTrue.push_back(true);
        points_vec.remove(0);
        for (QVector2D point:points_vec)
        {

            if(cartDist(prev_point,point)>5)
            {
                moveInLine2DPoint(prev_point,point,temp_pointsBase,temp_drawPoint_isTrue);
                temp_pointsBase.push_back(calcPointInPlane(point));
                temp_drawPoint_isTrue.push_back(true);
            }
            else
            {
                temp_pointsBase.push_back(calcPointInPlane(point));
                temp_drawPoint_isTrue.push_back(true);
            }

            prev_point = point;
        }
        drawPoint_isTrue.push_back(temp_drawPoint_isTrue);
        pointsBase.push_back(temp_pointsBase);
   }
}

void Draw::moveInLine2DPoint(QVector2D point_begin,QVector2D point_end,QVector <QVector3D> &vec,QVector <bool> &draw_vec)
{

    int i;
    int plane_dist = 20;
    for (i=1;i<plane_dist;i++)
    {
        vec.push_back(calcPointInPlane(point_begin) + (planeZ*i));
        draw_vec.push_back(false);
    }
    QVector3D point_begin_Z = vec.last();
    QVector2D vec_between = point_end-point_begin;

    for (int j=0;j<vec_between.length();j++)
    {
        vec.push_back(point_begin_Z+(vec_between.normalized().x()*planeX*j)+(vec_between.normalized().y()*planeY*j));
        draw_vec.push_back(false);
    }

    for (int k=1;k<plane_dist;k++)
    {
        vec.push_back(calcPointInPlane(point_end) + (planeZ*(i-k)));
        draw_vec.push_back(false);
    }
}


void Draw::Txt2QVector2D()
{
    points2D.clear();

    QDir dir =QDir::currentPath();
    dir.cdUp();
    dir.cdUp();
    dir.cd("LettersTxt");

    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    QFileInfoList fileInfos = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

    foreach (QFileInfo fileInfo, fileInfos)
    {

        QFile file(QString(fileInfo.absoluteFilePath()));
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
            str_list=line.split(" ");
            temp_points2D.push_back(QVector2D(str_list[0].toInt(),str_list[1].toInt()));
        }
        points2D_names.push_back(fileInfo.baseName());
        points2D.push_back(temp_points2D);
        file.close();
    }

}


