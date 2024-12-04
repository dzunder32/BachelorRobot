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
    connect(_widget3d, &Widget3D::sendAngle,this, &RobotDrawUi::displayAngleReference);

//    connect(_robDraw, &RobotDraw::changeTimerSpeed,this, &RobotDrawUi::increaseTimerSpeed);
    connect(this,&RobotDrawUi::startDrawing,_robDraw,&RobotDraw::startDrawTimer);
    connect(this,&RobotDrawUi::stopDrawing,_robDraw,&RobotDraw::stopDrawTimer);
    connect(this,&RobotDrawUi::changeSpeed,_robDraw,&RobotDraw::setTimerTime);
    connect(_robDraw, &RobotDraw::robotRangeChanged,this, &RobotDrawUi::adjustRobotRange);

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

void RobotDrawUi::displayAngleReference(float angle)
{
    QTextCursor cursor = ui->textEdit_Sequence->textCursor();

    // Move cursor to the beginning of the document
    cursor.movePosition(QTextCursor::Start);

    // Select the first line
    cursor.select(QTextCursor::LineUnderCursor);

    // Remove the selected text (first line)
    cursor.removeSelectedText();
    qDebug()<<"angle"<<angle;
    // Insert new text at the current cursor position
    // ui->textEdit_Sequence->insertPlainText("RobotSequence: Your Mam"+QString::number(angle));
    cursor.insertText("RobotSequence: Your Mam"+QString::number(angle));

    // Update the text edit with the modified cursor
    ui->textEdit_Sequence->setTextCursor(cursor);


}

void RobotDrawUi::adjustRobotRange(float range)
{
    ui->lineEdit_Range->setText(QString::number(range));
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

void RobotDrawUi::on_pushButton_setP1_clicked()
{
    // ui->lineEdit_P1Data->setText("P1:(" + ui->lineEdit_P1X->text()+ "; " + ui->lineEdit_P1Y->text() + ")");
    P1X_Str = ui->lineEdit_P1X->text();
    P1Y_Str = ui->lineEdit_P1Y->text();
    P1 = QVector2D(P1X_Str.toFloat(),P1Y_Str.toFloat());
}


void RobotDrawUi::on_pushButton_setP2_clicked()
{
    P2X_Str = ui->lineEdit_P2X->text();
    P2Y_Str = ui->lineEdit_P2Y->text();
    P2 = QVector2D(P2X_Str.toFloat(),P2Y_Str.toFloat());
}


void RobotDrawUi::on_pushButton_addLine_clicked()
{
    _robDraw->AddLine2Buffer(P1,P2);
    insertRobotSequenceText("Line: Start("+P1X_Str+ "," + P1Y_Str + ")"
                            + "End("+ P2X_Str+ "," + P2Y_Str + ")" );
     _widget3d->addCylinderBetweenPoints(P1.toVector3D(),P2.toVector3D());
    _robDraw->dontDrawPoint = false;
     preview_isDrawn = true;


    // _widget3d->drawPoint(P2,5,QColor(0,255,255));

}

void RobotDrawUi::on_pushButton_addP1_clicked()
{
    // _robDraw->AddL1Adjust2Buffer(P1.toVector3D());
    _robDraw->AddPoint2Buffer(P1.toVector3D());
    _robDraw->AddPoint2Buffer(P1.toVector3D()+QVector3D(0,0,50));
    // _widget3d->drawPoint(P1,5,QColor(255,0,255));
    insertRobotSequenceText("P1:(" + P1X_Str + ", " + P1Y_Str + ")");
}


void RobotDrawUi::insertRobotSequenceText(QString str)
{
    ui->textEdit_Sequence->moveCursor(QTextCursor::End);
    // ui->textEdit_Sequence.
    ui->textEdit_Sequence->insertPlainText("\n");
    ui->textEdit_Sequence->insertPlainText(str);
}



void RobotDrawUi::on_pushButton_addCircle_clicked()
{
    QVariantList circleList;
    float radius = ui->lineEdit_Radius->text().toFloat();
    circleList.append(radius);
    circleList.append(P1);
    circleList.append(QVector2D(0,360));
    insertRobotSequenceText("Circle: r=" + QString::number(radius) + " center: (" + P1X_Str + ", " + P1Y_Str + ")");
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
    ui->textEdit_Sequence->setText("RobotSequence:");
    QString textInput = ui->textEdit_textInput->toPlainText();
    qDebug()<<textInput;
    if(ui->checkBox_grid->isChecked())
        _robDraw->drawGrid();
    _robDraw->constructLetters(textInput);
    preview_isDrawn = true;
    _robDraw->dontDrawPoint = false;
    _robDraw->UpdatePlanePosition();
    removeAllItems();
}


void RobotDrawUi::on_spinBox_letterSize_valueChanged(int arg1)
{
    _robDraw->initLetterSize(float(arg1)/10);
}


void RobotDrawUi::on_horizontalSlider_x_sliderMoved(int position)
{
    // if(position>ui->horizontalSlider_x->value()){
    //     _plane->setTranslation(_plane->translation() + QVector3D(50,0,0));
    // }else{
    //     _plane->setTranslation(_plane->translation() - QVector3D(50,0,0));
    // }
    // _robDraw->UpdatePlanePosition();
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

void RobotDrawUi::on_pushButton_History_clicked()
{
    QString text = ui->lineEdit_Range->text();
    QStringList list = text.split(",");


    QString text1 = ui->lineEdit_2->text();
    QStringList list1 = text1.split(",");

    if(!list.isEmpty()){
        _plane->setToolOffset(list1[0].toFloat(),list1[1].toFloat(),list[0].toFloat(),list[1].toFloat());
    //     _plane->offsetX_plane=list[0].toFloat();
    //     if(list.length()>1)
    //     {
    //         qDebug()<<list,list[0],list[1];
    //         _plane->offsetY_plane=list[1].toFloat();
    //     }
    // }else{
    //     _plane->offsetX_plane=text.toFloat();
    //     qDebug()<<text.toFloat();
    // }
    }
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

// void RobotDrawUi::addLine(const QPointF &start, const QPointF &end)
// {
//     QLineF line(start, end);
//     QGraphicsItem *lineItem = scene->addLine(line);
//     lines.append(lineItem);
// }

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
            insertRobotSequenceText("Circle: r=" + QString::number(radius_plane) + " center: (" + QString::number(pre_point2D.x()) + ", " + QString::number(pre_point2D.y())+ ")");
        }
    }
}

void RobotDrawUi::addPressedPoint(qreal x, qreal y)
{
    addPoint(x,y);
    float plane_multiX = _plane->xLimit/gViewSize.width();
    float plane_multiY = _plane->yLimit/gViewSize.height();


    if(ui->checkBox_circle->isChecked())
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
        insertRobotSequenceText("Line: Start("+QString::number(lineVec1.x())+ "," + QString::number(lineVec1.y())+ ")"
                                + "End("+ QString::number(lineVec2.x())+ "," + QString::number(lineVec2.y()) + ")" );
    }else
    {
        _robDraw->AddPointUP2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,0));
        _robDraw->AddPoint2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,0));
        _robDraw->AddPoint2Buffer(QVector3D(x*plane_multiX,-y*plane_multiY,50));
        insertRobotSequenceText("P:(" + QString::number(x) + ", " + QString::number(-y)+ ")");
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

