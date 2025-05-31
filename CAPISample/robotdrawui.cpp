#include "robotdrawui.h"
#include "ui_robotdrawui.h"

RobotDrawUi::RobotDrawUi(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane,Widget3D *widget3d,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RobotDrawUi)
{
    ui->setupUi(this);
    _widget3d = widget3d;
    _robot = robot;
    _plane = plane;
    _robDraw = new RobotDraw(robotKinematik,_robot,sled_pos,plane,widget3d);
    _robDraw->moveToThread(&robotThread);
    qDebug()<<"robotdrawui thread"<< QThread::currentThreadId();

    connect(&robotThread,  &QThread::finished, _robDraw,&QObject::deleteLater);
//    connect(_robDraw, &RobotDraw::startTimer,this, &RobotDrawUi::startDrawTimer);
//    connect(_robDraw, &RobotDraw::stopTimer,this, &RobotDrawUi::stopDrawTimer);
    connect(_robDraw, &RobotDraw::drawLine,_widget3d, &Widget3D::addCylinderBetweenPoints);
//    connect(_robDraw, &RobotDraw::drawPoint_Widget,this, &RobotDrawUi::widgetDrawPoint);
    connect(_robDraw, &RobotDraw::drawPoint_Widget,_widget3d, &Widget3D::drawPoint);
//    connect(_robDraw, &RobotDraw::changeTimerSpeed,this, &RobotDrawUi::increaseTimerSpeed);
    connect(this,&RobotDrawUi::startDrawing,_robDraw,&RobotDraw::startDrawTimer);
    connect(this,&RobotDrawUi::stopDrawing,_robDraw,&RobotDraw::stopDrawTimer);
    connect(this,&RobotDrawUi::changeSpeed,_robDraw,&RobotDraw::setTimerTime);

    mouseFilter = new MousePositionFilter(ui->graphicsView->viewport());
    ui->graphicsView->viewport()->installEventFilter(mouseFilter);

    connect(mouseFilter, &MousePositionFilter::mousePressed,
            this, &RobotDrawUi::onMousePressed);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    connect(_robDraw,&RobotDraw::clearGW,this,&RobotDrawUi::removeAllItems);
    _robDraw->setTimerTime(500);
    robotThread.start();
}

RobotDrawUi::~RobotDrawUi()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}


void RobotDrawUi::planeRegistration()
{
    _robDraw->AddPointUP2Buffer(QVector3D(0,300,10));
    _robDraw->AddPoint2Buffer(QVector3D(0,300,0));
    _robDraw->AddPointUP2Buffer(QVector3D(0,300,10));

    _robDraw->AddPointUP2Buffer(QVector3D(100,300,10));
    _robDraw->AddPoint2Buffer(QVector3D(100,300,0));
    _robDraw->AddPointUP2Buffer(QVector3D(100,300,10));

}



void RobotDrawUi::on_pushButtonStart_clicked()
{
    // _robDraw->robotRange = ui->lineEdit_Range->text().toDouble();
    if(preview_isDrawn){
        _widget3d->deleteAllLines();
        _widget3d->deleteAllPoints();
        preview_isDrawn = false;
    }

    emit startDrawing();
//    _robDraw->setTimerTime(ui->timerSpeedSlider->value());
    _robDraw->UpdatePlanePosition();
    // _robDraw->robotRange = ui->lineEdit_3->text().toDouble();
}


void RobotDrawUi::on_pushButtonStop_clicked()
{
    emit stopDrawing();
    qDebug()<<"TimerStopped";
}


void RobotDrawUi::on_timerSpeedSlider_sliderMoved(int position)
{
    emit changeSpeed(position);
    qDebug()<<position;
}



void RobotDrawUi::on_pushButton_addLine_clicked()
{

    getP1fromStr();
    P2X_Str = ui->lineEdit_P2X->text();
    P2Y_Str = ui->lineEdit_P2Y->text();
    P2 = QVector2D(P2X_Str.toFloat(),P2Y_Str.toFloat());

    _robDraw->AddLine2Buffer(P1,P2);
     _widget3d->addCylinderBetweenPoints(P1.toVector3D(),P2.toVector3D());
    _robDraw->dontDrawPoint = false;
     preview_isDrawn = true;
    // _widget3d->drawPoint(P2,5,QColor(0,255,255));
}

void RobotDrawUi::on_pushButton_addP1_clicked()
{
     getP1fromStr();
    _robDraw->AddPoint2Buffer(P1.toVector3D());
    _robDraw->AddPoint2Buffer(P1.toVector3D()+QVector3D(0,0,50));
    // _widget3d->drawPoint(P1,5,QColor(255,0,255));
}
void RobotDrawUi::getP1fromStr()
{
    P1X_Str = ui->lineEdit_P1X->text();
    P1Y_Str = ui->lineEdit_P1Y->text();
    P1 = QVector2D(P1X_Str.toFloat(),P1Y_Str.toFloat());
}


void RobotDrawUi::on_pushButton_addCircle_clicked()
{
    QVariantList circleList;
    float radius = ui->lineEdit_Radius->text().toFloat();
    circleList.append(radius);
    getP1fromStr();
    circleList.append(P1);
    circleList.append(QVector2D(0,360));
    _robDraw->AddLine2Buffer(QVector3D(P1.x()+radius,P1.y(),0),QVector3D(P1.x()+radius,P1.y(),0));
    _robDraw->AddCircle2Buffer(circleList);
    _robDraw->dontDrawPoint = false;
    preview_isDrawn = true;
}


void RobotDrawUi::on_pushButton_draw_clicked()
{
    _widget3d->deleteAllLines();
    _widget3d->deleteAllPoints();
    _robDraw->resetShiftVector();
    _robDraw->clearBuffers();
    QString textInput = ui->textEdit_textInput->toPlainText();
    qDebug()<<textInput;
    _robDraw->constructLetters(textInput);
    preview_isDrawn = true;
    _robDraw->dontDrawPoint = false;
    _robDraw->UpdatePlanePosition();
    removeAllItems();
}


void RobotDrawUi::on_spinBox_letterSize_valueChanged(int arg1)
{
    _robDraw->initLetterSize(float(arg1)/10);
    setFontSizeForAllAndFutureText(arg1);
}

void RobotDrawUi::setFontSizeForAllAndFutureText( qreal pointSize) {
    // 1. Bestehenden Text formatieren
    QTextCursor allCursor = ui->textEdit_textInput->textCursor();
    allCursor.select(QTextCursor::Document);

    QTextCharFormat format;
    format.setFontPointSize(pointSize);
    allCursor.mergeCharFormat(format);

    // 2. Format für zukünftigen Text setzen
    QTextCursor cursor = ui->textEdit_textInput->textCursor();
    format = cursor.charFormat();  // bestehendes Format holen
    format.setFontPointSize(pointSize);
    cursor.setCharFormat(format);
    ui->textEdit_textInput->setTextCursor(cursor);
}

void RobotDrawUi::on_horizontalSlider_x_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_x->value()){
        _plane->tool_setTranslation(_plane->getToolTranslation() + QVector3D(50,0,0));
    }else{
        _plane->tool_setTranslation(_plane->getToolTranslation() - QVector3D(50,0,0));
    }
    _robDraw->UpdatePlanePosition();

}


void RobotDrawUi::on_horizontalSlider_y_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_y->value()){
        _plane->setTranslation(_plane->translation() + QVector3D(0,50,0));
    }else{
        _plane->setTranslation(_plane->translation() - QVector3D(0,50,0));
    }

    _robDraw->UpdatePlanePosition();

}


void RobotDrawUi::on_horizontalSlider_z_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_z->value()){
        _plane->setTranslation(_plane->translation() + QVector3D(0,0,50));
    }else{
        _plane->setTranslation(_plane->translation() - QVector3D(0,0,50));
    }

    _robDraw->UpdatePlanePosition();
}




void RobotDrawUi::on_horizontalSlider_xRot_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_xRot->value()){
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),10));
    }else{
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),-10));
    }
    _robDraw->UpdatePlanePosition();

}


void RobotDrawUi::on_horizontalSlider_yRot_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_yRot->value()){
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),10));
    }else{
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),-10));
    }
    _robDraw->UpdatePlanePosition();

}


void RobotDrawUi::on_horizontalSlider_zRot_sliderMoved(int position)
{
    if(position>ui->horizontalSlider_zRot->value()){
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),10));
    }else{
        _plane->setRotation(_plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),-10));
    }
    _robDraw->UpdatePlanePosition();

}


void RobotDrawUi::on_spinBox_dist_valueChanged(int arg1)
{
    qDebug()<<arg1;
    _plane->adjustToolOffset(float(arg1));
}


void RobotDrawUi::onMousePressed(QPoint globalPos)
{
        // Convert global position to local coordinates
        localPos = ui->graphicsView->mapFromGlobal(globalPos);
        scaleItems();
        gViewSize = ui->graphicsView->size();
        qDebug() << "Clicked at global position:" << globalPos;
        qDebug() << "Clicked at local position:" << localPos;

        drawGWBackground();
        adjustGWSliders();
        QPointF mid_localPos(gViewSize.width()/2,gViewSize.height()/2);
        QPointF curr_GWPos = localPos-mid_localPos;
        addPressedPoint(curr_GWPos.x(),curr_GWPos.y());
        preview_isDrawn = true;
}

void RobotDrawUi::scaleItems()
{
    float multi_x = ui->graphicsView->size().width() / gViewSize.width();
    float multi_y = ui->graphicsView->size().height() / gViewSize.height();

    for(auto i:points)
    {
        i->setX(i->x()*multi_x);
        i->setY(i->y()*multi_y);
    }
    if(!lines.isEmpty())
    {
        for (const auto& pair : lines) {
            QGraphicsLineItem* item = pair.first;
            QLineF line = pair.second;

            // Access start and end points
            QPointF startPoint = line.p1();
            QPointF endPoint = line.p2();

            // Manipulate the line
            line.setP1(QPointF(startPoint.x()*multi_x,startPoint.y()*multi_y)); // Set new start point
            line.setP2(QPointF(endPoint.x()*multi_x,endPoint.y()*multi_y)); // Set new end point

            // Update the graphics item
            item->setLine(line);
        }
    }
}


void RobotDrawUi::addLine(const QPointF &start, const QPointF &end)
{
    QLineF line(start, end);
    QGraphicsLineItem* lineItem = new QGraphicsLineItem();
    lineItem->setLine(line);
    scene->addItem(lineItem);

    // Store both the item and the original line
    lines.append(QPair<QGraphicsLineItem*, QLineF>(lineItem, line));
}

void RobotDrawUi::addPoint(qreal x, qreal y)
{
    QBrush brush(Qt::red);
    QPen pen(Qt::black);
    QRectF rect(-5, -5, 10, 10);
    QGraphicsEllipseItem* pointItem = scene->addEllipse(rect, pen, brush);
    pointItem->setPos(x, y);
    points.append(pointItem);
}
bool RobotDrawUi::circleInsidePlane(QPointF point,float radius)
{
    float border_X = gViewSize.width()/2;
    float border_Y = gViewSize.height()/2;

    if(point.x()+radius>border_X || point.y()+radius>border_Y || point.x()-radius<-border_X ||point.y()-radius<-border_Y)
    {
        return false;
    }else{
        return true;
    }

}
void RobotDrawUi::addCircle(qreal x, qreal y)
{
    float plane_multiX = _plane->xLimit/gViewSize.width();
    float plane_multiY = _plane->yLimit/gViewSize.height();
    // QBrush brush(Qt::red);
    QBrush brush(Qt::transparent);

    QPen pen(Qt::black);
    QRectF rect(-5, -5, 10, 10);
    QGraphicsEllipseItem* pointItem = scene->addEllipse(rect, pen, brush);
    pointItem->setPos(x, y);
    circle_points.append(pointItem);

    if(circle_points.length() % 2 == 0)
    {
        QPointF prev_point = circle_points[circle_points.length()-2]->pos();
        QPointF dist_vec = prev_point-pointItem->pos();
        float radius_gw = qSqrt(qPow(dist_vec.x(),2)+qPow(dist_vec.y(),2));
        float radius_plane = qSqrt(qPow(dist_vec.x()*plane_multiX,2)+qPow(dist_vec.y()*plane_multiY,2));
        if (circleInsidePlane(prev_point,radius_gw))
        {
            QPainterPath path;
            path.addEllipse(QRectF(-radius_gw, -radius_gw, radius_gw * 2, radius_gw * 2));

            // Create a QGraphicsPathItem for our circle
            QGraphicsPathItem* circleItem = scene->addPath(path, pen, brush);

            // Set the position of the circle
            circleItem->setPos(prev_point.x(),prev_point.y());

            QVector2D pre_point2D(prev_point.x()*plane_multiX,-prev_point.y()*plane_multiY);
            // Store the item
            circles.append(circleItem);
            QVariantList circleVariant;
            circleVariant<<radius_plane<<pre_point2D<<QVector2D(0,360);
            // _robDraw->AddLine2Buffer(QVector3D(pre_point2D.x()+radius_plane,pre_point2D.y(),0),QVector3D(pre_point2D.x()+radius_plane,pre_point2D.y(),0));
            _robDraw->AddCircle2Buffer(circleVariant);
        }
    }
}

void RobotDrawUi::addPressedPoint(qreal x, qreal y)
{
    addPoint(x,y);
    float plane_multiX = _plane->xLimit/gViewSize.width();
    float plane_multiY = _plane->yLimit/gViewSize.height();


    if(ui->checkBox_circle->isChecked()&& !liftTip_isTrue)
    {
        addCircle(x,y);
    }
    else if(points.length()>1 && !liftTip_isTrue)
    {
        if(point_isDrawn){
            _robDraw->removeLastPoint();
            _robDraw->removeLastPointUP();
            _robDraw->removeLastPoint();

            point_isDrawn = false;
        }
        QPointF linePt1 = points[points.length()-2]->pos();
        QPointF linePt2(x,y);
        addLine(linePt1,linePt2);
        QVector3D lineVec1 = QVector3D(qRound(linePt1.x()*plane_multiX),qRound(-linePt1.y()*plane_multiY),0);
        QVector3D lineVec2 = QVector3D(qRound(linePt2.x()*plane_multiX),qRound(-linePt2.y()*plane_multiY),0);
        _robDraw->AddLine2Buffer(lineVec1,lineVec2);
        }else
    {
        _robDraw->AddPointUP2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,0));
        _robDraw->AddPoint2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,0));
        _robDraw->AddPoint2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,50));
        point_isDrawn = true;
    }
}


void RobotDrawUi::drawGWBackground()
{
    float y_max = gViewSize.height();
    float x_max = gViewSize.width();

    addLine(QPointF(0, 0), QPointF(x_max/2-5,0 ));
    addLine(QPointF(0, 0), QPointF(-x_max/2+5,0));
    addLine(QPointF(0, 0), QPointF(0,y_max/2-5 ));
    addLine(QPointF(0, 0), QPointF(0,-y_max/2+5));
}


void RobotDrawUi::removeAllItems()
{
    // Remove all items from the scene
    while (!scene->items().isEmpty()) {
        QGraphicsItem* item = scene->items().first();
        scene->removeItem(item);
        delete item;
    }
    // Clear the lists
    lines.clear();
    points.clear();
    circles.clear();
    circle_points.clear();
    // Ensure the scene is updated
    ui->graphicsView->viewport()->update();
    drawGWBackground();
}

void RobotDrawUi::adjustGWSliders()
{
    int max_horizont = ui->graphicsView->horizontalScrollBar()->maximum();
    int min_horizont = ui->graphicsView->horizontalScrollBar()->minimum();
    int range = max_horizont-min_horizont;
    ui->graphicsView->horizontalScrollBar()->setValue(min_horizont + int(range/2)-12);
    int max_vertical = ui->graphicsView->verticalScrollBar()->maximum();
    int min_vertical = ui->graphicsView->verticalScrollBar()->minimum();
    int range_vertical = max_vertical-min_vertical;
    ui->graphicsView->verticalScrollBar()->setValue(min_vertical  + int(range_vertical/2)-12);

}



void RobotDrawUi::on_pushButton_lift_clicked()
{
    if(liftTip_isTrue){
        liftTip_isTrue = false;
        ui->pushButton_lift->setText("lift Tip");
    }else{
        liftTip_isTrue = true;
        ui->pushButton_lift->setText("lower Tip");
    }
}



void RobotDrawUi::on_spinBox_xRot_valueChanged(int arg1)
{
    _plane->setToolOffset(0,ui->spinBox_yRot->value(),0,arg1);
}

void RobotDrawUi::on_spinBox_yRot_valueChanged(int arg1)
{
    _plane->setToolOffset(0,arg1,0,ui->spinBox_xRot->value());
}
