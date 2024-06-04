#include "draw.h"

Draw::Draw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane,Widget3D *widget3d)
{
     timer_draw = new QTimer;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    _robot = robot;
    _plane = plane;
    _widget3d = widget3d;
    
    connect(timer_draw, &QTimer::timeout,this, &Draw::draw_onTimeout);

    robotMat.rotate(90,QVector3D(0,0,1));
    robotMat.setColumn(3,QVector4D(sled_pos,1));
//    /*qDebug()*/<<robotMat;

    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=500;
    unit_planeX = QVector3D(_plane->matrix().column(0));
    unit_planeY = QVector3D(_plane->matrix().column(1));
    unit_planeZ = QVector3D(_plane->matrix().column(2));

    letter=0;
    nextLetter=false;



}
void Draw::StartSimulation(int time_ms)
{
    timer_draw->start(time_ms);
}
void Draw::draw_onTimeout()
{

    if(counter >= 0 && counter<pointsRobot[letter].length()){
        robMove2Point();
        errorCounter = 0;
    }else
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        qDebug()<<counter;
        qDebug()<<pointsRobot[letter].length();
        errorCounter++;
        qDebug()<<errorCounter;
    }
}
void Draw::StartRobot()
{
    qDebug()<<isDrawing;
    qDebug()<<"counter"<<counter;
    while(isDrawing)
    {
        qDebug()<<"before Timeout";
        draw_onTimeout();
        qDebug()<<"after Timeout;";

    }
}

void Draw::robMove2Point()
{
    if (counter==0 && currentIndex == 0)
        emit deletePoints();

    // qDebug()<<"counter:"<<counter;
//    pointsRobot[letter][counter];
    robot_setPoint(pointsRobot[letter][counter]+letter_posRobot-QVector3D(l1,0,0));


    if(drawPoint_isTrue[letter][counter])
        emit sendPoint(pointsBase[letter][counter]+letter_posBase,pointThickness);

    counter+=IncrementCounterValue;

    if (counter>=pointsRobot[letter].length())
        getNextLetter();
}

void Draw::getNextLetter()
{
    getPreviousVectors();
    shiftLetterPosPlaneX(xLetterDist);
    back:
    currentIndex++;

    if(currentIndex==/*currentRowIndex.length()*/LetterInputIndex.length()){
        drawingDone();
    }
    else
    {
        letter=LetterInputIndex[currentIndex];
        // letter=currentRowIndex[currentIndex];

        if(letter==-1)
        {
            shiftLetterPosPlaneX(xLetterDist);
            shiftXcounter++;
            goto back;
        }
        else if(letter==-2){
            letter_posPlane.setX(10);
            shiftLetterPosPlaneY(yLetterDist);
            shiftYcounter++;
            goto back;
        }
        nextLetter_firstPoint = pointsBase[letter].first()+letter_posBase;
        nextLetter = !nextLetter;
        if(nextLetter){
            currentIndex--;
            letter=LetterInputIndex[currentIndex-shiftXcounter-shiftYcounter];
            moveInLineBetweenLetters();
            shiftXcounter=0;
            shiftYcounter=0;
        }
        else{
            counter=0;
            CreatePointsFromTxt(letterSize);
            letter_posPlane=save_letterPos;
            shiftVec2BaseAndRobot();
        }
    }
}


void Draw::drawingDone()
{
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
//    if(!_robot->IsConnected()){
        emit stopTimerDraw();
        qDebug()<<"sleep for 1 sec";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        qDebug()<<"done";
//    }else{
        if(_robot->IsConnected())
        {
        _robot->UpdatePosition();
        isDrawing=false;
        }
//    }
}



void Draw::shiftLetterPosPlaneX(float x)
{
    letter_posPlane+=QVector3D(x,0,0);
    shiftVec2BaseAndRobot();
}
void Draw::shiftLetterPosPlaneY(float y)
{
    letter_posPlane-=QVector3D(0,y,0);
    shiftVec2BaseAndRobot();
}
void Draw::getPreviousVectors()
{
    prevLetter_lastPoint = pointsBase[letter].last()+letter_posBase;
    prev_shiftBase  = letter_posBase;
    prev_shiftRobot = letter_posRobot;
    prev_shiftPlane = letter_posPlane;
}

void Draw::moveInLineBetweenLetters()
{
    QVector3D basePoint1;
    save_letterPos = letter_posPlane;
    letter_posPlane = prev_shiftPlane;
    shiftVec2BaseAndRobot();

    QVector3D point_Plane1 = Base2PlanePoint(prevLetter_lastPoint)-prev_shiftPlane;
    QVector3D point_Plane2 = Base2PlanePoint(nextLetter_firstPoint)-prev_shiftPlane;
    QVector3D vec_between = point_Plane2-point_Plane1;
    QVector3D planeOffset = QVector3D(0,0,20*letterSize);

    if(simulation_isTrue)
    {
        qDebug()<<"imTrue";
        for (int heigth; heigth < 20; heigth++){
            point_Plane1+=QVector3D(0,0,letterSize);
            basePoint1 = Plane2BasePoint(point_Plane1);
            pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
            pointsBase[letter].push_back(basePoint1);
            drawPoint_isTrue[letter].push_back(false);
        }

        for(float len = 0; len<vec_between.length(); len+=letterSize)
        {
            point_Plane1+=vec_between.normalized()*letterSize;
            basePoint1 = Plane2BasePoint(point_Plane1);
            pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
            pointsBase[letter].push_back(basePoint1);
            drawPoint_isTrue[letter].push_back(false);
        }

        for(int heigth = 20;heigth>0;heigth--)
        {
            point_Plane1-=QVector3D(0,0,letterSize);
            basePoint1 = Plane2BasePoint(point_Plane1);
            pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
            pointsBase[letter].push_back(basePoint1);
            drawPoint_isTrue[letter].push_back(false);
        }

    }
    else
    {

        qDebug()<<"imFalse";
        point_Plane1+=planeOffset;
        basePoint1 = Plane2BasePoint(point_Plane1);
        pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
        pointsBase[letter].push_back(basePoint1);
        drawPoint_isTrue[letter].push_back(false);


//        point_Plane1+=vec_between.normalized()*letterSize;

        point_Plane1+=vec_between;
        basePoint1 = Plane2BasePoint(point_Plane1);
        pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
        pointsBase[letter].push_back(basePoint1);
        drawPoint_isTrue[letter].push_back(false);

        point_Plane1-=planeOffset;
        basePoint1 = Plane2BasePoint(point_Plane1);
        pointsRobot[letter].push_back(Base2RobotPoint(basePoint1));
        pointsBase[letter].push_back(basePoint1);
        drawPoint_isTrue[letter].push_back(false);
    }

}


void Draw::CreatePointsFromTxt(float size)
{
    letterSize=size;
    xLetterDist = 60*size;
    yLetterDist = 100*size;
    pointThickness = 2 * size;
    if(!CounterSet)
        IncrementCounterValue=qRound(1/size)+5;


    // IncrementCounterValue=10;

    planeX = unit_planeX*size;
    planeY = unit_planeY*size;
    planeZ = unit_planeZ*size;

    Nx = _plane->xLimit/xLetterDist;
    Ny = _plane->yLimit/yLetterDist;

    letter_posPlane = QVector3D(10, (Ny-1)*yLetterDist, 0);
    shiftVec2BaseAndRobot();

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
    letter_posBase = QVector3D(temp_planeMat * letter_posPlane);
    letter_posRobot = QVector3D(temp_robotMat.inverted() * letter_posBase);
}
void Draw::robot_setPoint(QVector3D position)
{
    _robotKinematik->setPoint(position.x(),
                     position.y(),
                     position.z(),
                     a,b,c,l1);


    _robotKinematik->ToolMovement(Transformations::Z,-199);

//Mathafacka
    if(_robot->IsConnected())
    {
        _robot->UpdatePosition();
        _robotKinematik->WaitForPositionReached();
    }

}

void Draw::getWord(QString str)
{
    LetterInput.clear();
    LetterInputIndex.clear();
    currentRowIndex.clear();

    nextLetter=false;

//    letter_posPlane = QVector3D(10,10,0);

    checkAgain:
    for (int i =  0; i < str.length(); ++i) {

        if((str.at(i)==" " || str.at(i)=="\n") && i==0)
        {
            if(str.at(0)==" ")
                shiftLetterPosPlaneX(xLetterDist);
            else
                shiftLetterPosPlaneY(yLetterDist);
            str.remove(0,1);
            goto checkAgain;
        }

        if(str.at(i)==" "){LetterInputIndex.push_back(-1);}

        else if(str.at(i)=="\n"){LetterInputIndex.push_back(-2);}

        else{
           LetterInput.push_back(str.at(i));
           int index = points2D_names.indexOf(str.at(i));
           LetterInputIndex.push_back(index);
        }
        // if(i % Nx == 0){checkRow();}
    }

    // checkRow();
    currentIndex=0;
    counter=0;
   // letter=LetterInputIndex[currentIndex];
    qDebug()<<"LetterInputIndex"<<LetterInputIndex;
    letter=LetterInputIndex[currentIndex];

    qDebug()<<"letter:"<<LetterInput;
}


void Draw::checkRow()
{
    QVector <int> EndRowIndex,SpaceIndex,RowDistance,temp_Index;
    int index=0;
    for (int i:LetterInputIndex){
        if(i==-2)
            EndRowIndex.push_back(index);
        index++;
        if(i==-1)
            SpaceIndex.push_back(index);
    }
    EndRowIndex.push_back(LetterInputIndex.length());
    qDebug()<<"EndRowIndex"<<EndRowIndex;

    temp_Index=EndRowIndex;
    temp_Index.prepend(0);
    temp_Index.removeLast();
    qDebug()<<"tempIndex"<<temp_Index;
    int index2=0;
    for (int i=0;i<EndRowIndex.length();i++)
    {
        RowDistance.push_back(EndRowIndex[i]-temp_Index[i]);
    }

    for(int dist:RowDistance)
    {
        if(dist>Nx){

        }
    }
    qDebug()<<RowDistance;
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

            if(cartDist(prev_point,point)>8)
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

//void Draw::moveInLine2DPoint_Sim()

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


