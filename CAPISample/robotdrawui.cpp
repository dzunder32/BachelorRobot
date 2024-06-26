#include "robotdrawui.h"
#include "ui_robotdrawui.h"

RobotDrawUi::RobotDrawUi(Kinematik *robotKinematik,Robot *robot, QVector3D sled_pos,Plane* plane,Widget3D *widget3d,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RobotDrawUi)
{
    ui->setupUi(this);
    _widget3d = widget3d;
    _robot = robot;
    _robDraw = new RobotDraw(robotKinematik,_robot,sled_pos,plane,widget3d);
    _robDraw->moveToThread(&robotThread);

    connect(&robotThread,  &QThread::finished, _robDraw,&QObject::deleteLater);
    connect(_robDraw, &RobotDraw::startTimer,this, &RobotDrawUi::startDrawTimer);
    connect(_robDraw, &RobotDraw::stopTimer,this, &RobotDrawUi::stopDrawTimer);
    connect(_robDraw, &RobotDraw::drawLine,this, &RobotDrawUi::drawLineWidget);
    connect(_robDraw, &RobotDraw::drawPoint_Widget,this, &RobotDrawUi::widgetDrawPoint);

    robotThread.start();
}

RobotDrawUi::~RobotDrawUi()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}

void RobotDrawUi::on_pushButtonStart_clicked()
{
//    _robDraw->connectTimer();
    _widget3d->deleteAllLines();
    _widget3d->deleteAllPoints();
    startDrawTimer();
//    disconnect(_robDraw->_timer, &QTimer::timeout,this, &RobotDraw::robDraw_onTimeout);
}


void RobotDrawUi::on_pushButtonDelete_clicked()
{
//    _robDraw->disconnectTimer();
    stopDrawTimer();
}


void RobotDrawUi::on_timerSpeedSlider_sliderMoved(int position)
{
    _robDraw->setTimerTime(position);
    qDebug()<<position;
}

void RobotDrawUi::on_pushButton_setP1_clicked()
{
    ui->lineEdit_P1Data->setText("P1:(" + ui->lineEdit_P1X->text()+ "; " + ui->lineEdit_P1Y->text() + ")");
    P1X_Str = ui->lineEdit_P1X->text();
    P1Y_Str = ui->lineEdit_P1Y->text();
    P1 = QVector2D(P1X_Str.toFloat(),P1Y_Str.toFloat());
}


void RobotDrawUi::on_pushButton_setP2_clicked()
{
    ui->lineEdit_P2Data->setText("P2:(" + ui->lineEdit_P2X->text()+ "; " + ui->lineEdit_P2Y->text() + ")");
    P2X_Str = ui->lineEdit_P2X->text();
    P2Y_Str = ui->lineEdit_P2Y->text();
    P2 = QVector2D(P2X_Str.toFloat(),P2Y_Str.toFloat());
}

void RobotDrawUi::stopDrawTimer(){
    _robDraw->_timer->stop();
    historyText = ui->textEdit_Sequence->toPlainText();
//    ui->textEdit_Sequence->setText("Robot Sequence:");
    qDebug()<<"TimerStopped";
}


void RobotDrawUi::on_pushButton_addLine_clicked()
{
    _robDraw->AddLine2Buffer(P1,P2);
    insertRobotSequenceText("Line: Start("+P1X_Str+ "," + P1Y_Str + ")"
                            + "End("+ P2X_Str+ "," + P2Y_Str + ")" );
    // _widget3d->drawPoint(P1,5,QColor(0,255,255));
    // _widget3d->drawPoint(P2,5,QColor(0,255,255));

}

void RobotDrawUi::on_pushButton_addP1_clicked()
{

    _robDraw->AddPoint2Buffer(P1);
    // _widget3d->drawPoint(P1,5,QColor(255,0,255));
    insertRobotSequenceText("P2:(" + P1X_Str + ", " + P1Y_Str + ")");
}

// void RobotDrawUi::on_pushButton_addP2_clicked()
// {
//     QVector2D planePoint = P2;
//     _robDraw->AddPoint2Buffer(planePoint);
//     _widget3d->drawPoint(planePoint,5,QColor(255,0,255));
//     insertRobotSequenceText("P2:(" + P2X_Str + ", " + P2Y_Str + ")");

// }


void RobotDrawUi::insertRobotSequenceText(QString str)
{
    ui->textEdit_Sequence->moveCursor(QTextCursor::End);
    ui->textEdit_Sequence->insertPlainText("\n");
    ui->textEdit_Sequence->insertPlainText(str);
}

void RobotDrawUi::startDrawTimer()
{
    _robDraw->resetShiftVector();
    _robDraw->_timer->start();
    _robDraw->safeCurrentSequence();
}

void RobotDrawUi::on_pushButton_History_clicked()
{
    qDebug()<<ui->textEdit_Sequence->toPlainText();
    if(ui->textEdit_Sequence->toPlainText()=="Robot Sequence:"){
        initBuffers();
        qDebug()<<"initialized";
    }else{
        ui->textEdit_Sequence->setText(historyText);
        _robDraw->setPreviousSequence();

    }


}

void RobotDrawUi::initBuffers()
{
    for (int i=0;i<50;i+=10){
        QVector2D planePoint = QVector2D(i,i);
        _robDraw->AddPoint2Buffer(planePoint);
    }

    for (int k=0;k<50;k+=10){
        _robDraw->AddLine2Buffer(QVector2D(50,k),QVector2D(-50,k));
    }

}

void RobotDrawUi::on_pushButton_addCircle_clicked()
{
    QVariantList circleList;
    float radius =ui->lineEdit_Radius->text().toFloat();
    circleList.append(radius);
    circleList.append(P1);
    circleList.append(QVector2D(0,360));
    insertRobotSequenceText("Circle: r=" + QString::number(radius) + " center: (" + P1X_Str + ", " + P1Y_Str + ")");
    _robDraw->AddCircle2Buffer(circleList);
}


void RobotDrawUi::on_horizontalScrollBar_XChange_valueChanged(int value)
{
    qDebug()<<value;
    // P1
    // _widget3d->drawPoint()
}


void RobotDrawUi::on_pushButton_draw_clicked()
{
    QString textInput = ui->textEdit_textInput->toPlainText();
    qDebug()<<textInput;
    if(ui->radioButton_grid->isChecked())
        _robDraw->drawGrid();
    _robDraw->constructLetters(textInput);
}


void RobotDrawUi::on_spinBox_letterSize_valueChanged(int arg1)
{
    _robDraw->initLetterSize(float(arg1)/10);
}

