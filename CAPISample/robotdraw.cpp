#include "robotdraw.h"



RobotDraw::RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d)
{
    _letters = new Letters;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    _robot = robot;
    _plane = plane;
    _widget3d = widget3d;
    _timer = new QTimer;
    connect(_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);

    QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    l1=-20;

    robotMat.setColumn(3,QVector4D((sled_pos+QVector3D(0,l1,0)),1));
    robotMat.rotate(90,QVector3D(0,0,1));

    setTimerTime(500);

    initLetterSize(0.5);
}


void RobotDraw::robDraw_onTimeout()
{
    qDebug()<<robotSequence;

    if(!robotSequence.isEmpty())
    {
        switch (robotSequence.takeFirst())
        {
        case POINT:
            robotDrawPoint();
        break;

        case LINE:
            robotDrawLine();
            break;

        case CIRCLE:
            qDebug()<<CircleBuffer;
            robotDrawCircle();
            break;
        }
    }
    else
    {
        stopTimer_goHome();
    }
}

void RobotDraw::robotDrawPoint()
{


    if(!PointsBuffer.isEmpty())
    {
        qDebug()<<"Point";
        QVector3D basePoint = PointsBuffer.takeFirst();
        robot_setPoint(Base2RobotPoint(basePoint));
        drawPoint_Widget( basePoint,1,QColor(0,255,0));
        if(line_isTrue)
        {
            drawLine(firstLinePoint,basePoint);
            line_isTrue = false;
        }
    }else
    {
        stopTimer_goHome();
    }
}

void RobotDraw::robotDrawLine()
{
    if(!LinesBuffer.isEmpty())
    {
        qDebug()<<"Line";
        auto line = LinesBuffer.takeFirst();
        //save first Point
        firstLinePoint = line[0];
        robot_setPoint(Base2RobotPoint(firstLinePoint));
        //add second Line Point to Buffer as a Point
        PointsBuffer.prepend(line[1]);
        robotSequence.prepend(1);
        line_isTrue = true;
    }else
    {
        stopTimer_goHome();
    }
}

void RobotDraw::robotDrawCircle()
{

    QVariantList currCircle = CircleBuffer.takeFirst();

    float radius = currCircle[0].toFloat();
    QVector2D center = currCircle[1].value<QVector2D>();
    QVector2D angleLimits = currCircle[2].value<QVector2D>();

    float prev_angle= angleLimits[1];

    QVector2D prev_circlePt;
    prev_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(prev_angle))));
    prev_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(prev_angle))));


    for (float angle = angleLimits[1]-10; angle >angleLimits[0];angle-=10)
    {
        QVector2D circlePt;
        circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
        circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));

        if(_robot->IsConnected())
        {
            drawPoint_Widget(Plane2BasePoint(circlePt.toVector3D()),1,QColor(255,0,0));
        }else
        {
            LinesBuffer.prepend({Plane2BasePoint(circlePt.toVector3D()),Plane2BasePoint(prev_circlePt.toVector3D())});
            robotSequence.prepend(LINE);
            prev_circlePt = circlePt;
        }
    }
}

void RobotDraw::constructLetters(QString letter_Str)
{
    for (int i =  0; i < letter_Str.length(); ++i)
    {
        getLetterData(letter_Str.at(i));
    }
}

void RobotDraw::initLetterSize(float sizeFactor)
{

    shiftVector.setX(-_plane->xLimit/2);
    shiftVector.setY( _plane->yLimit/2 - _letters->LetterSizeY);
    //    _letters->changeLetterSize(currentLetter,1);
    _letters->changeLetterSize(0.5);
}

void RobotDraw::getLetterData(QChar char_letter)
{
    currentLetter = _letters->getLetterVec(char_letter);

    _letters->shiftLetter(currentLetter,shiftVector);

    if(currentLetter[0][0]=="no Letter found")
    {
        qDebug()<<"you fucked up";
    }
    else
    {
        addLetter2Buffer();
        shiftVector+=QVector2D(_letters->LetterSizeX,0);
    }
}

void RobotDraw::addLetter2Buffer()
{
    for (QVariantList list:currentLetter)
    {
        if(list.first()==LINE)
        {
            QVector2D startLine = list[1].value<QVector2D>();
            QVector2D endLine   = list[2].value<QVector2D>();
            AddLine2Buffer(startLine,endLine);
            qDebug()<<"line";
        }
        if(list.takeFirst()==CIRCLE)
        {
            AddCircle2Buffer(list);
            qDebug()<<"Circle";
        }
    }
}


void RobotDraw::AddPoint2Buffer(QVector2D pointPlane)
{
    QVector3D basePoint = Plane2BasePoint(pointPlane.toVector3D());
    PointsBuffer.append(basePoint);
    drawPoint_Widget(basePoint,2,QColor(0,255,0));
    robotSequence.append(POINT);
}

void RobotDraw::AddLine2Buffer(QVector2D linePlane1, QVector2D linePlane2)
{
    QVector3D lineBasePt1=Plane2BasePoint(linePlane1.toVector3D());
    QVector3D lineBasePt2=Plane2BasePoint(linePlane2.toVector3D());
    LinesBuffer.append({lineBasePt1,lineBasePt2});
    drawPoint_Widget(lineBasePt1,2,QColor(0,255,0));
    drawPoint_Widget(lineBasePt2,2,QColor(0,255,0));
    robotSequence.append(LINE);
}
void RobotDraw::AddCircle2Buffer(QVariantList circleList)
{
    CircleBuffer.append(circleList);
    robotSequence.append(CIRCLE);
}

void RobotDraw::RobotDraw::safeCurrentSequence()
{
    PointsBuffer_hist  = PointsBuffer; LinesBuffer_hist   = LinesBuffer;
    CircleBuffer_hist  = CircleBuffer; robotSequence_hist = robotSequence;
}

void RobotDraw::setPreviousSequence()
{
    PointsBuffer  = PointsBuffer_hist;
    LinesBuffer   = LinesBuffer_hist;
    CircleBuffer  = CircleBuffer_hist;
    robotSequence = robotSequence_hist;
}


void RobotDraw::robot_setPoint(QVector3D position)
{
    _robotKinematik->setPoint(position.x(),
                              position.y(),
                              position.z(),
                              a,b,c,l1);

    _robotKinematik->ToolMovement(Transformations::Z,-199);

    if(_robot->IsConnected())
    {
        _robot->UpdatePosition();
        _robotKinematik->WaitForPositionReached();
    }

}


void RobotDraw::UpdatePointsBuffer(QVector <QVector3D> pts)
{
    PointsBuffer = pts;
    for(auto i:pts){robotSequence.append(1);}
}

void RobotDraw::stopTimer_goHome()
{
    stopTimer();
    while(_timer->isActive()) {qDebug()<<"inWhile!";}
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    qDebug()<<"imHome";
    if(_robot->IsConnected()) {_robot->UpdatePosition();}
}



