#include "robotdraw.h"

RobotDraw::RobotDraw(Kinematik *robotKinematik, Robot *robot, QVector3D sled_pos, Plane* plane, Widget3D *widget3d)
{
    _letters        = new Letters;
    _robot          = robot;
    _plane          = plane;
    _widget3d       = widget3d;
    _l1BasePos      = sled_pos;
    _robotKinematik = robotKinematik;
    _robotKinematik->setJoints(0,0,90,0,90,0,0);

    // _timer->setInterval(1000);
    // _timer->setSingleShot(false);
    connect(_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);
    setL1(0);
    robotMat.rotate(90,QVector3D(0,0,1));
    UpdatePlanePosition();
    initLetterSize(1);
//    setTimerTime(500);
}


void RobotDraw::robDraw_onTimeout()
{
    runAgain:
//    qDebug()<<"roboSeq"<<robotSequence;
    UpdatePlanePosition();
    if(!robotSequence.isEmpty())
    {
        switch (robotSequence.takeFirst())
        {
        case POINT:
            robotDrawPoint();  break;
        case LINE:
            robotDrawLine();   break;
        case CIRCLE:
            robotDrawCircle(); break;
        case POINT_UP:
            robotdrawPointUP();break;
        }
    }
    else
    {
        if(!lastPoint_drawn)
        {
            qDebug()<<"yysas";
            // moveAboveCounter = 1;
            PointsBuffer.prepend(lastPoint+QVector3D(0,0,150));
            robotSequence.prepend(POINT);
            lastPoint_drawn = true;
            goto runAgain;
        }

        qDebug()<<"main Home";
        stopTimer_goHome();
    }
}


void RobotDraw::DrawFirstPoint()
{
    qDebug()<<"Drawing First Point";
    if (!robotSequence.isEmpty() && !dontDrawPoint){
        alreadyDrawn = false;
        alreadyDrawn_2 = false;
        moveAboveCounter=1;
        // qDebug()<<"firstRobSequence:"<<robotSequence;
        switch (robotSequence.first())
        {
        case POINT:
            if(!PointsBuffer.isEmpty()){
                QVector3D point = PointsBuffer.first();
                point.setZ(50);
                PointsBuffer.prepend(point);robotSequence.prepend(POINT);}
            break;
        case LINE:
            if(!LinesBuffer.isEmpty()){
                QVector3D point = LinesBuffer.first().first();
                point.setZ(50);
                PointsBuffer.prepend(point);robotSequence.prepend(POINT);}
            break;
        case CIRCLE:
            if(!CircleBuffer.isEmpty()){
                QVariantList circle = CircleBuffer.first();
                float        radius = circle[0].toFloat();
                QVector2D    center = circle[1].value<QVector2D>();
                QVector3D    point  = (center + QVector2D(radius,0)).toVector3D();
                point.setZ(50);
                PointsBuffer.prepend(point);robotSequence.prepend(POINT);}
            break;
        }
    }else{lastPoint_drawn = true;}
}


void RobotDraw::robotDrawPoint()
{
    if(!PointsBuffer.isEmpty())
    {
        QVector3D planePoint = PointsBuffer.takeFirst();
        if(line_isTrue){drawLine(Plane2BasePoint(startLinePoint),Plane2BasePoint(planePoint));line_isTrue = false;}
        robot_setPoint(Plane2RobotPoint(planePoint));
        lastPoint = planePoint;
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

        if(cartDistance(endLinePoint,startLinePoint) > 5 && alreadyDrawn)
        {
            LinesBuffer.prepend(line);robotSequence.prepend(LINE);
            //when distance is too big, move Tip above the plane
            moveTipAbove();/*qDebug()<<"now!";*/
            alreadyDrawn = false;
        }else
        {
            //save second Point
            if(cartDistance(endLinePoint,startLinePoint) > 5){
                robot_setPoint(Plane2RobotPoint(startLinePoint));
            }
            endLinePoint   = line[1];
            //add second Line Point to Buffer as a Point
            PointsBuffer.prepend(endLinePoint);
            robotSequence.prepend(POINT);
            line_isTrue  = true;
            alreadyDrawn = true;
            //speed up, when currently drawing a circle
            if(circlePoints_counter >= circlePoints_number)
            {changeTimerSpeed(1);}/*qDebug()<<"no speed!!"<<_timer->interval();*/
            else{circlePoints_counter++;}
        }
    }
    else{stopTimer_goHome();}
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
        float angle_range = abs(end_angle - start_angle);
        float mid_angle;
        if(start_angle < end_angle)
        {mid_angle = angle_range/2 + start_angle;}
        else
        {mid_angle = angle_range/2 + end_angle;}

        QVector2D prev_circlePt;
        prev_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
        prev_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));

        QVector2D start_circlePt;
        start_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(start_angle))));
        start_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(start_angle))));
        startLinePoint = start_circlePt;

        if(_robot->IsConnected())
        {
            if(cartDistance(endLinePoint,start_circlePt)>5 && alreadyDrawn)
            {
                qDebug()<<"were moving the tip Circle";
                CircleBuffer.prepend(currCircle);
                robotSequence.prepend(CIRCLE);
                moveTipAbove();
                // endLinePoint = start_circlePt;
                alreadyDrawn = false;
                return;
            }else
            {
                endLinePoint = prev_circlePt;
                alreadyDrawn = true;
            }
            QVector2D end_circlePt, mid_circlePt, start_circlePt;
            start_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(start_angle))));
            start_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(start_angle))));
            robotCirclePts_vec.append(start_circlePt);

            if(angle_range==360){end_angle = mid_angle; mid_angle = angle_range/4 + start_angle; drawCircle = true;}

            mid_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(mid_angle))));
            mid_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(mid_angle))));
            robotCirclePts_vec.append(mid_circlePt);

            end_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
            end_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));

            if(drawCircle){lastPoint = start_circlePt.toVector3D();}
            else{lastPoint = end_circlePt.toVector3D();}

            robotCirclePts_vec.append(end_circlePt);
            calculateL1_new(Plane2BasePoint(center.toVector3D()));
            // endLinePoint = lastPoint;

            // if(drawCircle){PointsBuffer.prepend(start_circlePt);robotSequence.prepend(POINT);}
            // PointsBuffer.prepend(end_circlePt);  robotSequence.prepend(POINT);
            // PointsBuffer.prepend(mid_circlePt);  robotSequence.prepend(POINT);
            // PointsBuffer.prepend(start_circlePt);robotSequence.prepend(POINT);

            CirclePreview(currCircle)   ;
            robot_moveCircular(robotCirclePts_vec);
            // _robotKinematik->WaitForPositionReached();
//            PointsBuffer.prepend(lastPoint);robotSequence.prepend(POINT);
        }
        else
        {
            if(end_angle > start_angle)
            {
                for (float angle = end_angle-angleStep; angle >= start_angle;angle -= angleStep)
                {
                    QVector2D circlePt;
                    circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
                    circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
                    LinesBuffer.prepend({circlePt.toVector3D(),prev_circlePt.toVector3D()});
                    robotSequence.prepend(LINE);
                    prev_circlePt = circlePt;
                }
            }else
            {
                for (float angle = end_angle+angleStep; angle <= start_angle;angle += angleStep)
                {
                    QVector2D circlePt;
                    circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
                    circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
                    LinesBuffer.prepend({circlePt.toVector3D(),prev_circlePt.toVector3D()});
                    robotSequence.prepend(LINE);
                    prev_circlePt = circlePt;
                }
            }
            lastPoint = prev_circlePt;
            // LinesBuffer.prepend({endLinePoint,prev_circlePt.toVector3D()});
            // robotSequence.prepend(LINE);
//            LinesBuffer.prepend({endLinePoint,prev_circlePt.toVector3D()});
//            robotSequence.prepend(LINE);
            initCirclePointsSpeedUp(angle_range);
        }
    }else{stopTimer_goHome();}
}


void RobotDraw::robotdrawPointUP()
{
    if(!PointsUPBuffer.isEmpty())
    {
        QVector3D planePoint = PointsUPBuffer.takeFirst();
        planePoint.setZ(50);
        moveAboveCounter=1;
        robot_setPoint(Plane2RobotPoint(planePoint));
        lastPoint = planePoint;
    }
    else {stopTimer_goHome();}
}


void RobotDraw:: robot_setPoint(QVector3D position)
{
    calculateL1_new(Robot2BasePoint(position));
    position+=QVector3D(diff_l1,0,0);

    _robotKinematik->RobotPosition::setPoint(position.x(),
                              position.y(),
                              position.z(),
                              a,b,c,l1);
    _robotKinematik->invers();

    _robotKinematik->ToolMovement(Transformations::C,-_robotKinematik->j6());

    if(_robot->IsConnected())
    {
        if(moveAboveCounter<2){_robot->UpdatePosition();}
        else                  {_robot->UpdatePositionLinear();}
        qDebug()<<"also waiting";
        _robotKinematik->WaitForPositionReached();
        qDebug()<<"done waiting";
    }

    if(moveAboveCounter<2){qDebug()<<"Doin MOV!";drawPoint_Widget(Robot2BasePoint(position),2,QColor(0,255,0));moveAboveCounter++;}
    else                  {qDebug()<<"Doin MVS!";}
//    qDebug()<<"IM OUT";
//    qDebug()<<"TimerStatus:"<<_timer->isActive();
}


void RobotDraw::robot_moveCircular(QVector <QVector2D> circlePoints)
{
    //Circle points 2 Joints
    QVector <QVector <double>> J_Vec;

    for(QVector2D point: circlePoints)
    {
        QVector3D pointRobot = Plane2RobotPoint(point.toVector3D() );
        _robotKinematik->RobotPosition::setPoint(pointRobot.x(),
                                                 pointRobot.y(),
                                                 pointRobot.z(),
                                                 a,b,c,l1     );
        _robotKinematik->invers();
        J_Vec.append({_robotKinematik->j1(),_robotKinematik->j2(),_robotKinematik->j3(),_robotKinematik->j4(),_robotKinematik->j5(),0,_robotKinematik->j7()});
    }
    // qDebug()<<"the Joints :D"<<J_Vec;
    qDebug()<<"Doin MVC/MVR";
    _robot->MoveCircularJ(J_Vec[0],J_Vec[1],J_Vec[2],l1,drawCircle);
    drawCircle = false;
}


void RobotDraw::UpdatePlanePosition()
{

    QMatrix4x4 curr_planeRobot_T =  robotMat.inverted() * _plane->matrix();
    QMatrix4x4 subtract_T = planeRobot_T - curr_planeRobot_T;
    float sum_T = 0;

    for (int i=0;i<4;i++){
        for (int k=0;k<4;k++){
            sum_T += abs(subtract_T(i,k));
        }
    }

    if(sum_T>1)
    {
        planeRobot_T = curr_planeRobot_T;
        QVector3D ew = CalculateEw(planeRobot_T * QMatrix4x4(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180).toRotationMatrix()));
        a=ew.x();
        b=ew.y();
        c=ew.z();
        calculateL1_new(_plane->translation());
    }else{}
    sum_T=0;
}



float RobotDraw::calculateAngleBetweenVectors(QVector3D vectorA, QVector3D vectorB) {
    float dotProduct = QVector3D::dotProduct(vectorA, vectorB);
    float magnitudeA = vectorA.length();
    float magnitudeB = vectorB.length();

    float angleInRadians = acos(dotProduct / (magnitudeA * magnitudeB));
    return angleInRadians * (180.0 / M_PI); // Convert radians to degrees
}


void RobotDraw::adjustRobotRangeHeigth(float height)
{
    float max_range   = 1350;
    float min_range   = 900;
    float max_height  = 1000;
    float min_height  = 0;
    float diff_height = max_height-min_height;
    float diff_range  = max_range-min_range;

    float curr_height = height - min_height;

    if(height<max_height){
        float height_percent = diff_height / curr_height;
        float curr_range = (diff_range/height_percent)+min_range;
        robotRange = curr_range;
    }else{
        qDebug()<<"point to high";
        robotRange = max_range;

    }
//    emit robotRangeChanged(robotRange);

}


void RobotDraw::calculateL1_new(QVector3D adjustPoint)
{
    QVector3D line_position_3d   = _l1BasePos;
    QVector3D plane_position_3d  = adjustPoint;
    QVector3D vec_subtraction_3d = line_position_3d - plane_position_3d;
    QVector3D line_direction_3d  = robotMat.column(0).toVector3D();
    QVector3D axisLift_3d        = QVector3D(0,0,277);
    adjustRobotRangeHeigth(Base2RobotPoint(adjustPoint).z());
    // qDebug()<<Base2RobotPoint(adjustPoint).z();
    // qDebug()<<"rangeChanged"<<robotRange;
    float     prefRob_range      = robotRange;
    float     maxRob_range       = 1400;
    QVector <QVector3D> solutionVec_3d;

    QVector3D center1_3d   = line_position_3d - (line_direction_3d*800) + axisLift_3d;
    QVector3D center2_3d   = line_position_3d + (line_direction_3d*800) + axisLift_3d;

    float     dotProduct   = QVector3D::dotProduct(vec_subtraction_3d, line_direction_3d);
    float     k            = -dotProduct/line_direction_3d.lengthSquared();
    QVector3D minDist_3d   = line_position_3d + k * line_direction_3d;
    QVector3D distPlane_3d = plane_position_3d - minDist_3d + axisLift_3d;

    QVector3D distPlaneSphere1_3d    = center1_3d - plane_position_3d;
    QVector3D distPlaneSphere2_3d    = center2_3d - plane_position_3d;

    QVector2D xzProjectionCenter_2d  = QVector2D(line_position_3d.x(), center1_3d.z());
    QVector2D xzProjectionPlane_2d   = QVector2D(plane_position_3d.x(),plane_position_3d.z());
    QVector2D xzProjection_dist_2d   = xzProjectionCenter_2d - xzProjectionPlane_2d;
//    qDebug()<<"line_position:"<<line_position_3d;
    float rectBorderY_min = line_position_3d.y() - 780;
    float rectBorderY_max = line_position_3d.y() + 780;
    float rectBorderZ_min = line_position_3d.z() - prefRob_range;
    float rectBorderZ_max = line_position_3d.z() + prefRob_range;

    bool rectCheckY = (plane_position_3d.y() >= rectBorderY_min)  && (plane_position_3d.y() <= rectBorderY_max);
    bool rectCheckZ = (plane_position_3d.z() >= rectBorderZ_min)  && (plane_position_3d.z() <= rectBorderZ_max);

    float angle1, angle2;
    bool multipleSolutions = false;

    if(distPlane_3d.length() < prefRob_range)
    {
        float alpha = acos(distPlane_3d.length()/prefRob_range);
//        qDebug()<<"alpha"<<alpha * (180.0/M_PI);

        QVector3D S1 = minDist_3d - ((prefRob_range*sin(alpha)) * line_direction_3d);
        QVector3D S2 = minDist_3d + ((prefRob_range*sin(alpha)) * line_direction_3d);

        //check wether Plane Position is in Rect
        //frontal check
        if(xzProjection_dist_2d.length()<maxRob_range){
            //side check
            if(rectCheckY && rectCheckZ){
//                qDebug()<<"plane in Rect!";
                solutionVec_3d.append(S1);
                solutionVec_3d.append(S2);
                QVector3D dist1 = S1 - plane_position_3d;
                QVector3D dist2 = S2 - plane_position_3d;

                angle1 = calculateAngleBetweenVectors(dist1,_plane->matrix().column(2).toVector3D());
                angle2 = calculateAngleBetweenVectors(dist2,_plane->matrix().column(2).toVector3D());
                multipleSolutions = true;
            }
            else{
//                qDebug()<<"side Chick bad!";
//                qDebug()<<rectCheckY<<rectCheckZ;
//                qDebug()<<"plane not in Rect...check Spheres";

                if(distPlaneSphere1_3d.length()<maxRob_range){
//                    qDebug()<<"in Sphere1";
                   solutionVec_3d.append(S2);
                }
                else if(distPlaneSphere2_3d.length()<maxRob_range){
//                    qDebug()<<"in Sphere2";
                    solutionVec_3d.append(S1);
                }
                else{qDebug()<<"plane not reachable!";}
            }
        }
        else{
//            qDebug()<<"plane not reachable, frontCheck not good";
        }
    }
    else{
//        qDebug()<<"min Distance 2 Plane!";
        solutionVec_3d.append(minDist_3d);
    }

    for(QVector3D &vec:solutionVec_3d){
//        qDebug()<<"solution:"<<vec;
        if(vec.y() > rectBorderY_max){
            vec.setY(line_position_3d.y()+780);
        }else if( vec.y() < rectBorderY_min){
            vec.setY(line_position_3d.y()-780);}
    }

    if(solutionVec_3d.isEmpty()){
        qDebug()<<"no solutions";return;}
    //when having 2 solutions for L1 -> check which one is behind the plane!
    if(multipleSolutions && angle1 > angle2)
        solutionVec_3d.removeFirst();

    QVector3D solution_3d = solutionVec_3d.first();

    float new_l1 = solution_3d.y() - line_position_3d.y();
    setL1(new_l1);
}


void RobotDraw::setL1(double val)
{
    // qDebug()<<"newL1:"<<val;
    diff_l1 = prev_l1 - val;
    l1=val;
    robotPosition = _l1BasePos + QVector3D(0,l1,0);
    robotMat.setColumn(3,QVector4D(robotPosition,1));
    prev_l1=l1;
}


void RobotDraw::moveTipAbove()
{
    QVector3D prev_linePt = endLinePoint;
    QVector3D next_linePt = startLinePoint;
    qDebug()<<"start:"<<startLinePoint<<"end:"<<endLinePoint;
    qDebug()<<"moving tip above";
    prev_linePt.setZ(50);next_linePt.setZ(50);
    PointsBuffer.prepend(next_linePt);robotSequence.prepend(POINT);
    PointsBuffer.prepend(prev_linePt);robotSequence.prepend(POINT);
    moveAboveCounter = 0;
}


void RobotDraw::CirclePreview(QVariantList circleList)
{
    float     radius      = circleList[0].toFloat();
    QVector2D center      = circleList[1].value<QVector2D>();
    QVector2D angleLimits = circleList[2].value<QVector2D>();

    float    start_angle  = angleLimits[0];
    float    end_angle    = angleLimits[1];

    QVector2D prev_circlePt;
    prev_circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(end_angle))));
    prev_circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(end_angle))));

    if(end_angle>start_angle)
    {
        for (float angle = end_angle - angleStep; angle >= start_angle; angle -= angleStep)
        {
            QVector2D circlePt;
            circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
            circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
            emit drawLine(Plane2BasePoint(circlePt),Plane2BasePoint(prev_circlePt));
            prev_circlePt = circlePt;
        }
    }else
    {
        for (float angle = end_angle + angleStep; angle <= start_angle; angle += angleStep)
        {
            QVector2D circlePt;
            circlePt.setX(center.x() + (radius * qCos(qDegreesToRadians(angle))));
            circlePt.setY(center.y() + (radius * qSin(qDegreesToRadians(angle))));
            emit drawLine(Plane2BasePoint(circlePt),Plane2BasePoint(prev_circlePt));
            prev_circlePt = circlePt;
        }
    }
    // if(!LinesBuffer.isEmpty()){
    // QVector3D lastPoint_temp = LinesBuffer.last().last();
    //     drawLine(Plane2BasePoint(prev_circlePt),Plane2BasePoint(lastPoint_temp));}
//    if(!LinesBuffer.isEmpty()){
//    QVector3D lastPoint_temp = LinesBuffer.last().last();
//        drawLine(Plane2BasePoint(prev_circlePt),Plane2BasePoint(lastPoint_temp));}
}


void RobotDraw::initCirclePointsSpeedUp(float angle_range){
    circlePoints_number = qRound(angle_range/angleStep);
    circlePoints_counter = 0;
    changeTimerSpeed(0.1);
}


void RobotDraw::initLetterSize(float sizeFactor)
{
    qDebug()<<"init"<<QThread::currentThreadId();
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
            qDebug()<<"plane is Full!"<<shiftVector;
            qDebug()<<"whatString:"<<letter_Str.at(i);
            break;
        }
        else{
            getLetterData(letter_Str.at(i));
        }
    }

}


void RobotDraw::getLetterData(QChar char_letter)
{

    if(char_letter == ' ' && shiftVector.x() <_plane->xLimit/2 - xBoxSize)
    {
        gotoNextBox();
    }
    else if(char_letter == '\n')
    {
        shiftVector.setX(_plane->xLimit/2);
        gotoNextBox();
    }
    else
    {
        currentLetter = _letters->getLetterVec(char_letter);
        qDebug()<<"CURRlETTER"<<currentLetter[0][0].value<int>();

        if(currentLetter[0][0].value<int>()==-1)
        {
            qDebug()<<"no Letter found";
        }
        else
        {
            _letters->shiftLetter(currentLetter,shiftVector);
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
    bool x_inPlane =  (shiftVector.x() >= -_plane->xLimit/2 + xSpace) && (shiftVector.x() <= _plane->xLimit/2-xBoxSize);
    bool y_inPlane =  (shiftVector.y() >= -_plane->yLimit/2) && (shiftVector.y()<=_plane->yLimit/2 - yBoxSize + ySpace + 1);
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
    PointsBuffer.append(planePoint);robotSequence.append(POINT);
}


void RobotDraw::AddPointUP2Buffer(QVector3D planePoint)
{
    PointsUPBuffer.append(planePoint);robotSequence.append(POINT_UP);
}


void RobotDraw::AddLine2Buffer(QVector3D planeLine1, QVector3D planeLine2)
{
    LinesBuffer.append({planeLine1,planeLine2});robotSequence.append(LINE);
    emit drawLine(Plane2BasePoint(planeLine1),Plane2BasePoint(planeLine2));
}


void RobotDraw::AddCircle2Buffer(QVariantList circleList)
{
    CirclePreview(circleList);
    CircleBuffer.append(circleList);robotSequence.append(CIRCLE);
}


void RobotDraw::stopTimer_goHome()
{
    stopDrawTimer();
    dontDrawPoint = false;
    lastPoint_drawn = false;
    while(_timer->isActive()){}/* {qDebug()<<"inWhile!";}*/
    _robotKinematik->setJoints(0,0,90,0,90,0,0);
    qDebug()<<"imHome";
    if(_robot->IsConnected()) {_robot->UpdatePosition();}
}



