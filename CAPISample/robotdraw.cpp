#include "robotdraw.h"



RobotDraw::RobotDraw(Kinematik *robotKinematik, Robot *robot, QVector3D sled_pos, Plane* plane, Widget3D *widget3d)
{
    _timer          = new QTimer;
    _letters        = new Letters;
    _robot          = robot;
    _plane          = plane;
    _widget3d       = widget3d;
    _l1BasePos      = sled_pos;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);

    connect(_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);

    setL1(0);
    robotMat.rotate(90,QVector3D(0,0,1));
    initLetterSize(1);
}

void RobotDraw::PlanePositionChanged()
{
    planeCounter=0;
    UpdatePlanePosition();
    //You Imbecile!
}

void RobotDraw::UpdatePlanePosition()
{
//    rotation_plane = _plane->matrix();
//    rotation_plane.setColumn(3,QVector4D(0,0,0,1));
    planeRobot_T = robotMat.inverted() * _plane->matrix();
    QVector3D ew = CalculateEw(robotMat.inverted() * _plane->matrix() *QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180).toRotationMatrix()));
    a=ew.x();
    b=ew.y();
    c=ew.z();
    calculateL1_new();
}

float RobotDraw::calculateAngleBetweenVectors(QVector3D vectorA, QVector3D vectorB) {
    float dotProduct = QVector3D::dotProduct(vectorA, vectorB);
    float magnitudeA = vectorA.length();
    float magnitudeB = vectorB.length();

    float angleInRadians = acos(dotProduct / (magnitudeA * magnitudeB));
    return angleInRadians * (180.0 / M_PI); // Convert radians to degrees
}

void RobotDraw::calculateL1_new()
{
    QVector3D line_position_3d   = _l1BasePos;
    QVector3D plane_position_3d  = _plane->translation();
    QVector3D vec_subtraction_3d = line_position_3d - plane_position_3d;
    QVector3D line_direction_3d  = robotMat.column(0).toVector3D();
    QVector3D axisLift_3d        = QVector3D(0,0,277);
    QVector3D nextRobPos_3d;
    float     prefRob_range      = 1000;
    float     maxRob_range       = 1400;
    QVector <QVector3D> solutionVec_3d;

    QVector3D center1_3d      = line_position_3d - (line_direction_3d*800) + axisLift_3d;
    QVector3D center2_3d      = line_position_3d + (line_direction_3d*800) + axisLift_3d;

//    qDebug() << "direction:" << line_direction_3d;

    float     dotProduct   = QVector3D::dotProduct(vec_subtraction_3d, line_direction_3d);
    float     k            = -dotProduct/line_direction_3d.lengthSquared();
    QVector3D minDist_3d   = line_position_3d + k * line_direction_3d;
    QVector3D distPlane_3d = plane_position_3d - minDist_3d + axisLift_3d;
    QVector3D distPlaneSphere1_3d    = center1_3d - plane_position_3d;
    QVector3D distPlaneSphere2_3d    = center2_3d - plane_position_3d;

    QVector2D xzProjectionCenter_2d  = QVector2D(line_position_3d.x(), center1_3d.z());
    QVector2D xzProjectionPlane_2d   = QVector2D(plane_position_3d.x(),plane_position_3d.z());
    QVector2D xzProjection_dist_2d   = xzProjectionCenter_2d - xzProjectionPlane_2d;
    qDebug()<<"line_position:"<<line_position_3d;
    float rectBorderY_min = line_position_3d.y() - 800;
    float rectBorderY_max = line_position_3d.y() + 800;
    float rectBorderZ_min = line_position_3d.z() - prefRob_range;
    float rectBorderZ_max = line_position_3d.z() + prefRob_range;

    bool rectCheckY = (plane_position_3d.y() >= rectBorderY_min)  && (plane_position_3d.y() <= rectBorderY_max);
    bool rectCheckZ = (plane_position_3d.z() >= rectBorderZ_min)  && (plane_position_3d.z() <= rectBorderZ_max);

    float angle1, angle2;
    bool multipleSolutions = false;

    qDebug() << "distance Plane minDist:" << distPlane_3d.length();

//    PointsBuffer.append(minDist_3d);robotSequence.append(POINT);

    if(distPlane_3d.length() < prefRob_range)
    {
        float alpha = acos(distPlane_3d.length()/prefRob_range);
//        qDebug()<<"alpha"<<alpha * (180.0/M_PI);

        QVector3D S1 = minDist_3d - ((prefRob_range*sin(alpha)) * line_direction_3d);
        QVector3D S2 = minDist_3d + ((prefRob_range*sin(alpha)) * line_direction_3d);

//        qDebug()<<"minDist_3d"<<minDist_3d<<"S1:"<<S1;
//        qDebug()<<"S2:"<<S2;
        //check wether Plane Position is in Rect
        //frontal check
        if(xzProjection_dist_2d.length()<maxRob_range){
            //side check
            if(rectCheckY && rectCheckZ){
                qDebug()<<"plane in Rect!";
                solutionVec_3d.append(S1);
                solutionVec_3d.append(S2);
                QVector3D dist1 = S1 - plane_position_3d;
                QVector3D dist2 = S2 - plane_position_3d;

                angle1 = calculateAngleBetweenVectors(dist1,_plane->matrix().column(2).toVector3D());
                angle2 = calculateAngleBetweenVectors(dist2,_plane->matrix().column(2).toVector3D());
                multipleSolutions = true;
                qDebug()<<"angle1"<<calculateAngleBetweenVectors(dist1,_plane->matrix().column(2).toVector3D());
                qDebug()<<"angle2"<<calculateAngleBetweenVectors(dist2,_plane->matrix().column(2).toVector3D());
            }
            else{
                qDebug()<<"side Chick bad!";
                qDebug()<<rectCheckY<<rectCheckZ;
                qDebug()<<"plane not in Rect...check Spheres";

                if(distPlaneSphere1_3d.length()<maxRob_range){
                    qDebug()<<"in Sphere1";
                   solutionVec_3d.append(S2);
                }
                else if(distPlaneSphere2_3d.length()<maxRob_range){
                    qDebug()<<"in Sphere2";
                    solutionVec_3d.append(S1);
                }
                else{qDebug()<<"plane not reachable!";}
            }
        }
        else{
            qDebug()<<"plane not reachable, frontCheck not good";
        }
    }
    else{
        qDebug()<<"min Distance 2 Plane!";
        solutionVec_3d.append(minDist_3d);
    }

    for(QVector3D &vec:solutionVec_3d){
        qDebug()<<"solution:"<<vec;
        if(vec.y() > rectBorderY_max){
            vec.setY(line_position_3d.y()+800);
        }else if( vec.y() < rectBorderY_min){
            vec.setY(line_position_3d.y()-800);}
            // if(vec.y() > rectBorderY_max || vec.y() < rectBorderY_min){
        //     solutionVec_3d.remove(solutionVec_3d.indexOf(vec));
        //     qDebug()<<"delete that ass";multipleSolutions = false;}

        if(planeCounter < 5){
            PointsBuffer.prepend(Base2PlanePoint(vec));robotSequence.prepend(POINT);}
    }

    if(solutionVec_3d.isEmpty()){
        qDebug()<<"no solutions";return;}
    //when having 2 solutions for L1 -> check which one is behind the plane!
    if(multipleSolutions && angle1 > angle2)
        solutionVec_3d.removeFirst();

    QVector3D solution_3d = solutionVec_3d.first();
    QVector <QVector3D> plane_cornerPts_vec3d = _plane->getCornerPoints();
    //check wether plane corner points are inside robot range

    if(planeCounter < 5){
        for (QVector3D pt_3d:plane_cornerPts_vec3d){
            PointsBuffer.prepend(Base2PlanePoint(pt_3d));robotSequence.prepend(POINT);
        }
    }

    float new_l1 = solution_3d.y() - line_position_3d.y();
    setL1(new_l1);

//    qDebug()<<"new L1"<<new_l1;
//    if(pt_inRange){
//        qDebug()<<"ALL cornerPTs !in! range";
//    }else{
//        qDebug()<<"One or More cornerPT not in range";
//    }
    if(planeCounter < 5){
        PointsBuffer.prepend(Base2PlanePoint(plane_position_3d));robotSequence.prepend(POINT);}
    // QVector3D robotPosition
    // drawPoint_Widget(QVector3D(0,0,100),10,QColor(255,255,255));
}


void RobotDraw::setL1(double val)
{
    qDebug()<<"newL1:"<<val;
    l1=val;
    robotPosition = _l1BasePos + QVector3D(0,l1,0);
    robotMat.setColumn(3,QVector4D(robotPosition,1));
}

void RobotDraw::robDraw_onTimeout()
{
//    qDebug()<<"roboSeq"<<robotSequence;

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
        qDebug()<<"main Home";
        stopTimer_goHome();
    }
}
void RobotDraw::checkPlane()
{
    if(planeCounter < 5 && !_robotKinematik->ePointReachable){
        qDebug()<<planeCounter<<" -->Point not Reachable!!";
        stopTimer_goHome();
    }
    planeCounter++;
}

void RobotDraw::robotDrawPoint()
{

    if(!PointsBuffer.isEmpty())
    {
        QVector3D planePoint = PointsBuffer.takeFirst();
        robot_setPoint(Plane2RobotPoint(planePoint));
        checkPlane();

        if(moveAboveCounter<2){drawPoint_Widget(Plane2BasePoint(planePoint),2,QColor(0,255,0));moveAboveCounter++;}
        // else{drawPoint_Widget(basePoint,10,QColor(255,0,0));}

        if(line_isTrue){drawLine(Plane2BasePoint(startLinePoint),Plane2BasePoint(planePoint));line_isTrue = false;}
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
            moveTipAbove();/*qDebug()<<"now!";*/
            alreadyDrawn = false;
        }
        else{
            //save second Point
            endLinePoint   = line[1];
            robot_setPoint(Plane2RobotPoint(startLinePoint));
            //add second Line Point to Buffer as a Point
            PointsBuffer.prepend(endLinePoint);
            robotSequence.prepend(POINT);
            line_isTrue  = true;
            alreadyDrawn = true;
            //speed up, when currently drawing a circle
            if(circlePoints_counter >= circlePoints_number)
            {changeTimerSpeed(1);/*qDebug()<<"no speed!!"<<_timer->interval();*/}
            else{circlePoints_counter++;}
        }
    }else{stopTimer_goHome();}
}

void RobotDraw::moveTipAbove()
{

    QVector3D prev_linePt = endLinePoint;
    QVector3D next_linePt = startLinePoint;
//    QVector3D liftVecPlane = QVector3D(0,0,50);
//    QVector3D liftVecBase = rotation_plane *liftVecPlane;
//    QVector3D lifted_prevPoint = prev_linePt + liftVecBase;
//    QVector3D lifted_nextPoint = next_linePt + liftVecBase;
//  QVector3D lifted_prevPoint = prev_linePt + liftVecPlane;
    prev_linePt.setZ(50);next_linePt.setZ(50);
//    QVector3D lifted_nextPoint = next_linePt + liftVecPlane;
    PointsBuffer.prepend(next_linePt);robotSequence.prepend(POINT);
    PointsBuffer.prepend(prev_linePt);robotSequence.prepend(POINT);
    moveAboveCounter = 0;

}

void RobotDraw::CirclePreview(QVariantList circleList)
{
    float     radius      = circleList[0].toFloat();
    QVector2D center      = circleList[1].value<QVector2D>();
    QVector2D angleLimits = circleList[2].value<QVector2D>();

    qDebug()<<"leggo!";
    qDebug()<<"radius:"<<radius;
    qDebug()<<"center:"<<center;
    qDebug()<<"lims:"<<angleLimits;

    float    start_angle  = angleLimits[0];
    float    end_angle    = angleLimits[1];

    QVector2D prev_circlePt;
    prev_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
    prev_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));

    qDebug()<<"prev_CirclePt1"<<Plane2BasePoint(prev_circlePt);
    int cnt = 0;

    for (float angle = end_angle - angleStep; angle > start_angle;angle -= angleStep)
    {
        QVector2D circlePt;
        circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
        circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
        emit drawLine(Plane2BasePoint(circlePt),Plane2BasePoint(prev_circlePt));
        prev_circlePt = circlePt;
        cnt++;
    }
    QVector3D lastPoint = LinesBuffer.last().last();
    drawLine(Plane2BasePoint(prev_circlePt),Plane2BasePoint(lastPoint));
    qDebug()<<"prev_CirclePt2"<<Plane2BasePoint(prev_circlePt);
    qDebug()<<cnt;
    qDebug()<<"circle drawn!";

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
//                qDebug()<<Plane2BasePoint(vec2d.toVector3D());
                PointsBuffer.prepend(vec2d.toVector3D());robotSequence.prepend(POINT);
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
                LinesBuffer.prepend({circlePt.toVector3D(),prev_circlePt.toVector3D()});
                robotSequence.prepend(LINE);
                prev_circlePt = circlePt;
            }
            LinesBuffer.prepend({endLinePoint,prev_circlePt.toVector3D()});
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
    {AddLine2Buffer(QVector3D(-_plane->xLimit/2,yi,0),QVector3D(_plane->xLimit/2,yi,0));}

    for(float xi =-_plane->xLimit/2+xBoxSize; xi<=_plane->xLimit/2-xBoxSize;xi+=xBoxSize)
    {AddLine2Buffer(QVector3D(xi,-_plane->yLimit/2,0),QVector3D(xi,_plane->yLimit/2,0));}
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

//    qDebug()<<"left Limit:"<<-_plane->xLimit/2 + xSpace;
//    qDebug()<<"right Limit"<<_plane->xLimit/2;
//    qDebug()<<"lower Limit "<<-_plane->yLimit/2<<(shiftVector.y() >= -_plane->yLimit/2);
//    qDebug()<<"upper Limit"<<_plane->yLimit/2 - yBoxSize+ ySpace<< (shiftVector.y()<=_plane->yLimit/2 - yBoxSize + ySpace + 1);

//    qDebug()<<"xOut"<<x_inPlane;
//    qDebug()<<"yOut"<<y_inPlane;

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
            AddLine2Buffer(startLine.toVector3D(),endLine.toVector3D());
            qDebug()<<"line";
        }
        if(list.takeFirst()==CIRCLE)
        {
            AddCircle2Buffer(list);
            qDebug()<<"Circle";
        }
    }
}


void RobotDraw::AddPoint2Buffer(QVector3D planePoint)
{
//    QVector3D basePoint = Plane2BasePoint(pointPlane.toVector3D());

    PointsBuffer.append(planePoint);
//    drawPoint_Widget(Plane2BasePoint(planePoint),2,QColor(0,255,0));
    robotSequence.append(POINT);
}

void RobotDraw::AddLine2Buffer(QVector3D planeLine1, QVector3D planeLine2)
{
//    QVector3D lineBasePt1=Plane2BasePoint(linePlane1.toVector3D());
//    QVector3D lineBasePt2=Plane2BasePoint(linePlane2.toVector3D());
//    qDebug()<<"Base1:"<<lineBasePt1<<"Plane1:"<<linePlane1;
//    qDebug()<<"Base2:"<<lineBasePt2<<"Plane2:"<<linePlane2;
    LinesBuffer.append({planeLine1,planeLine2});
//    drawPoint_Widget(lineBasePt1,2,QColor(0,255,0));
//    drawPoint_Widget(lineBasePt2,2,QColor(0,255,0));
    emit drawLine(Plane2BasePoint(planeLine1),Plane2BasePoint(planeLine2));
    robotSequence.append(LINE);
}
void RobotDraw::AddCircle2Buffer(QVariantList circleList)
{
    CirclePreview(circleList);
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

    if(_robot->IsConnected())
    {_robot->UpdatePosition(); _robotKinematik->WaitForPositionReached();}
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
        QMatrix4x4 pointT   = _robotKinematik->getTransformationMatrix();
        QVector3D  position = pointT.column(3).toVector3D();

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
    emit stopTimer();
    while(_timer->isActive())/* {qDebug()<<"inWhile!";}*/
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    qDebug()<<"imHome";
    if(_robot->IsConnected()) {_robot->UpdatePosition();}
}



