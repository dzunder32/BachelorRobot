#include "robotdraw.h"



RobotDraw::RobotDraw(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane, Widget3D *widget3d)
{
    _letters = new Letters;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    _robot = robot;
    _plane = plane;
    _widget3d = widget3d;
    _l1BasePos = sled_pos;
    _timer = new QTimer;
    connect(_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);

    // QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    // a=ew.x();
    // b=ew.y();
    // c=ew.z();
    // l1=-250;

    // robotPosition = sled_pos+QVector3D(0,l1,0);
    // robotMat.setColumn(3,QVector4D(robotPosition,1));
    setL1(0);
    robotMat.rotate(90,QVector3D(0,0,1));

    rotation_plane = _plane->matrix();
    rotation_plane.setColumn(3,QVector4D(0,0,0,1));

    initLetterSize(1);
}

void RobotDraw::PlanePositionChanged()
{
     QVector3D ew = CalculateEw(_plane->matrix()*QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();

}
void RobotDraw::CalculateL1()
{
    QVector3D dist_vec = _plane->translation()-robotPosition;
    double preffered_distance = 500;
    double sqrt_arg = pow(preffered_distance,2) - pow(dist_vec.x(),2) -pow(dist_vec.z(),2);

    if(abs(sqrt_arg)< 0.001)
        sqrt_arg=1;

    if(sqrt_arg<0){
        qDebug()<<"negative sqrt argument! CalculateL1()";
        return;
    }
    double new_l1 = sqrt(sqrt_arg)-dist_vec.y();
}
void RobotDraw::setL1(double val)
{
    l1=val;
    robotPosition = _l1BasePos + QVector3D(0,l1,0);
    robotMat.setColumn(3,QVector4D(robotPosition,1));


}

void RobotDraw::robDraw_onTimeout()
{
//    qDebug()<<robotSequence;

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
            // qDebug()<<CircleBuffer;
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
//        qDebug()<<"Point";
        QVector3D basePoint = PointsBuffer.takeFirst();
        robot_setPoint(Base2RobotPoint(basePoint));
        if(moveAboveCounter<2){drawPoint_Widget(basePoint,2,QColor(0,255,0));moveAboveCounter++;}
       // else{drawPoint_Widget(basePoint,2,QColor(255,0,0));}
        if(line_isTrue){drawLine(startLinePoint,basePoint);line_isTrue = false;}
    }
    else {stopTimer_goHome();}
}

void RobotDraw::robotDrawLine()
{
    if(!LinesBuffer.isEmpty())
    {
        QVector <QVector3D> line = LinesBuffer.takeFirst();
        //save first Point
        startLinePoint = line[0];
        //check wether the distance between endPoint of current Line is bigger than 5
        if(cartDistance(endLinePoint,startLinePoint)>5 && alreadyDrawn)
        {
            LinesBuffer.prepend(line);robotSequence.prepend(LINE);
            //when distance is too big, move Tip above the plane
            moveTipAbove();qDebug()<<"now!";
            alreadyDrawn = false;
        }
        else{
            //save second Point
            endLinePoint   = line[1];
            robot_setPoint(Base2RobotPoint(startLinePoint));
            //add second Line Point to Buffer as a Point
            PointsBuffer.prepend(endLinePoint);
            robotSequence.prepend(POINT);
            line_isTrue  = true;
            alreadyDrawn = true;
            //speed up, when currently drawing a circle
            if(circlePoints_counter>=circlePoints_number)
            {changeTimerSpeed(1);qDebug()<<"no speed!!"<<_timer->interval();}
            else{circlePoints_counter++;}
        }
    }else{stopTimer_goHome();}
}

void RobotDraw::moveTipAbove()
{
    QVector3D prev_linePt = endLinePoint;
    QVector3D next_linePt = startLinePoint;

    QVector3D liftVecPlane = QVector3D(0,0,50);
    QVector3D liftVecBase = rotation_plane *liftVecPlane;

    QVector3D lifted_prevPoint = prev_linePt + liftVecBase;
    QVector3D lifted_nextPoint = next_linePt + liftVecBase;

    PointsBuffer.prepend(lifted_nextPoint);
    robotSequence.prepend(POINT);

    PointsBuffer.prepend(lifted_prevPoint);
    robotSequence.prepend(POINT);
    moveAboveCounter = 0;
}

void RobotDraw::robotDrawCircle()
{

    if(!CircleBuffer.isEmpty())
    {
        QVariantList currCircle = CircleBuffer.takeFirst();
        QVector <QVector2D> robotCirclePts_vec;
        float radius = currCircle[0].toFloat();
        QVector2D center = currCircle[1].value<QVector2D>();
        QVector2D angleLimits = currCircle[2].value<QVector2D>();

        float start_angle  = angleLimits[0];
        float end_angle   = angleLimits[1];
        float angle_range = end_angle - start_angle;
        float mid_angle   = angle_range/2 + start_angle;

        QVector2D prev_circlePt;
        prev_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
        prev_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));

        if(_robot->IsConnected())
        {
            QVector2D end_circlePt, mid_circlePt, start_circlePt;
            start_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(start_angle))));
            start_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(start_angle))));
            robotCirclePts_vec.append(start_circlePt);

            if(angle_range==360){end_angle = mid_angle; mid_angle = angle_range/4 + start_angle;}

            mid_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(mid_angle))));
            mid_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(mid_angle))));
            robotCirclePts_vec.append(mid_circlePt);

            end_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
            end_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));
            robotCirclePts_vec.append(end_circlePt);

            robot_moveInCircle(robotCirclePts_vec);

            for (QVector2D vec2d:robotCirclePts_vec)
            {
                qDebug()<<Plane2BasePoint(vec2d.toVector3D());
                PointsBuffer.prepend(Plane2BasePoint(vec2d.toVector3D()));robotSequence.prepend(POINT);
//              drawPoint_Widget(Plane2BasePoint(Plane2BasePoint(vec2d.toVector3D())),2,QColor(255,0,0));
            }
        }
        else
        {
            for (float angle = end_angle-angleStep; angle >start_angle;angle-=angleStep)
            {
                QVector2D circlePt;
                circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
                circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
                LinesBuffer.prepend({Plane2BasePoint(circlePt.toVector3D()),Plane2BasePoint(prev_circlePt.toVector3D())});
                robotSequence.prepend(LINE);
                prev_circlePt = circlePt;
            }
            LinesBuffer.prepend({endLinePoint,Plane2BasePoint(prev_circlePt.toVector3D())});
            robotSequence.prepend(LINE);
            initCirclePointsSpeedUp(angle_range);
        }
    }else{stopTimer_goHome();}

}

void RobotDraw::initCirclePointsSpeedUp(float angle_range){
    circlePoints_number = qRound(angle_range/angleStep);
    circlePoints_counter = 0;
    changeTimerSpeed(0.1);
    qDebug()<<"superSonicSpeed"<<_timer->interval();
}
void RobotDraw::initLetterSize(float sizeFactor)
{
    _letters->changeLetterSize(sizeFactor);

    xSpace = _letters->LetterSizeX *0.1;
    ySpace = _letters->LetterSizeY *0.1;
    xBoxSize = _letters->LetterSizeX * 1.2;
    yBoxSize = _letters->LetterSizeY * 1.2;

    resetShiftVector();
}

void RobotDraw::drawGrid()
{
    double Nx = qRound(_plane->xLimit/xBoxSize);
    double Ny = qRound(_plane->yLimit/yBoxSize);
    qDebug()<<"Nx:"<<Nx<<"Ny:"<<Ny;
    qDebug()<<"max Letters: "<< Nx*Ny;

    for (float yi = _plane->yLimit/2-yBoxSize; yi>=-_plane->yLimit/2+yBoxSize;yi-=yBoxSize)
    {AddLine2Buffer(QVector2D(-_plane->xLimit/2,yi),QVector2D(_plane->xLimit/2,yi));}

    for(float xi =-_plane->xLimit/2+xBoxSize; xi<=_plane->xLimit/2-xBoxSize;xi+=xBoxSize)
    {AddLine2Buffer(QVector2D(xi,-_plane->yLimit/2),QVector2D(xi,_plane->yLimit/2));}
}

void RobotDraw::constructLetters(QString letter_Str)
{
    for (int i =  0; i < letter_Str.length(); ++i)
    {
        if(!shiftVec_inPlane())
        {
            //            plane_isFull = false;
            qDebug()<<"plane is Full!"<<shiftVector;
            qDebug()<<"whatString:"<<letter_Str.at(i);
            break;
        }
        else{
            getLetterData(letter_Str.at(i));
            qDebug()<<"getData!";
        }
    }
}

void RobotDraw::getLetterData(QChar char_letter)
{

    if(char_letter == ' ' && shiftVector.x() <_plane->xLimit/2 - xBoxSize)
    {
        // shiftVector+=QVector2D(_letters->LetterSizeX,0);
        gotoNextBox();
    }
    else if(char_letter == '\n')
    {
        shiftVector.setX(_plane->xLimit/2);
        // shiftVector-=QVector2D(0,_letters->LetterSizeY);
        gotoNextBox();
    }
    else
    {
        qDebug()<<"im in Letter Man!";
        currentLetter = _letters->getLetterVec(char_letter);

        _letters->shiftLetter(currentLetter,shiftVector);

        if(currentLetter[0][0]=="no Letter found")
        {
            qDebug()<<"no Letter found";
        }
        else
        {
            addLetter2Buffer();
            gotoNextBox();
        }
    }
}

void RobotDraw::gotoNextBox()
{

   shiftVector+=QVector2D(xBoxSize,0);
    if(shiftVector.x()>_plane->xLimit/2-xBoxSize)
    {
        shiftVector.setX(-_plane->xLimit/2 + xSpace);
        shiftVector-=QVector2D(0,yBoxSize);
    }
}

void RobotDraw::resetShiftVector()
{
    shiftVector.setX(-_plane->xLimit/2 + xSpace);
    shiftVector.setY( _plane->yLimit/2 - yBoxSize + ySpace);
    qDebug()<<shiftVector;
}
bool RobotDraw::shiftVec_inPlane()
{
    qDebug()<<"shift"<<shiftVector;

    bool x_inPlane =  (shiftVector.x() >= -_plane->xLimit/2 + xSpace) && (shiftVector.x() <= _plane->xLimit/2-xBoxSize);
    bool y_inPlane =  (shiftVector.y() >= -_plane->yLimit/2) && (shiftVector.y()<=_plane->yLimit/2 - yBoxSize + ySpace + 1);

    qDebug()<<"left Limit:"<<-_plane->xLimit/2 + xSpace;
    qDebug()<<"right Limit"<<_plane->xLimit/2;
    qDebug()<<"lower Limit "<<-_plane->yLimit/2<<(shiftVector.y() >= -_plane->yLimit/2);
    qDebug()<<"upper Limit"<<_plane->yLimit/2 - yBoxSize+ ySpace<< (shiftVector.y()<=_plane->yLimit/2 - yBoxSize + ySpace + 1);

    qDebug()<<"xOut"<<x_inPlane;
    qDebug()<<"yOut"<<y_inPlane;

    return (y_inPlane);
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
    qDebug()<<"Base1:"<<lineBasePt1<<"Plane1:"<<linePlane1;
    qDebug()<<"Base2:"<<lineBasePt2<<"Plane2:"<<linePlane2;
    LinesBuffer.append({lineBasePt1,lineBasePt2});
//    drawPoint_Widget(lineBasePt1,2,QColor(0,255,0));
//    drawPoint_Widget(lineBasePt2,2,QColor(0,255,0));
    drawLine(lineBasePt1,lineBasePt2);
    robotSequence.append(LINE);
}
void RobotDraw::AddCircle2Buffer(QVariantList circleList)
{
    CircleBuffer.append(circleList);
    robotSequence.append(CIRCLE);
}


void RobotDraw::safeCurrentSequence()
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
//    _robotKinematik->RobotPosition::setPoint(position.x(),
//                                             position.y(),
//                                             position.z(),
//                                             a,b,c,l1);
//    _robotKinematik->ToolMovement(Transformations::Z,-199);

    if(_robot->IsConnected())
    {
        _robot->UpdatePosition();
        _robotKinematik->WaitForPositionReached();
    }

}

void RobotDraw::robot_moveInCircle(QVector <QVector2D> circlePoints)
{

    QVector <QVector <double>> J_Vec;

    for(QVector2D point: circlePoints)
    {
        QVector3D pointRobot = Plane2RobotPoint(point.toVector3D());
        _robotKinematik->RobotPosition::setPoint(pointRobot.x(),
                                  pointRobot.y(),
                                  pointRobot.z(),
                                  a,b,c,l1);
        QMatrix4x4 pointT = _robotKinematik->getTransformationMatrix()*MatrixTranslationZ(199);

//        _robotKinematik->ToolMovement(Transformations::Z,-199);
        J_Vec.append({_robotKinematik->j1(),_robotKinematik->j2(),_robotKinematik->j3(),_robotKinematik->j4(),_robotKinematik->j5(),_robotKinematik->j6(),_robotKinematik->j7()});
    }
    qDebug()<<"the Joints :D"<<J_Vec;
}


void RobotDraw::UpdatePointsBuffer(QVector <QVector3D> pts)
{
    PointsBuffer = pts;
    for(auto i:pts){robotSequence.append(1);}
}

void RobotDraw::stopTimer_goHome()
{
    stopTimer();
    while(_timer->isActive()) {/*qDebug()<<"inWhile!";*/}
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    qDebug()<<"imHome";
    if(_robot->IsConnected()) {_robot->UpdatePosition();}
}



