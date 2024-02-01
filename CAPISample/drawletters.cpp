#include "drawletters.h"
#include "ui_drawletters.h"

DrawLetters::DrawLetters(Kinematik *robot, QVector3D sled_pos, Qt3DCore::QTransform* plane,Widget3D *widget3d, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawLetters)
{
    ui->setupUi(this);

    _widget3d = widget3d;
    _draw = new Draw(robot,sled_pos,plane,widget3d);
    _draw->moveToThread(&robotThread);

    connect(&robotThread,  &QThread::finished, _draw,&QObject::deleteLater);
    connect(_draw, &Draw::sendPoint,this, &DrawLetters::drawPointWidget);

    robotThread.start();
}

DrawLetters::~DrawLetters()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}


void DrawLetters::on_pushButton_clicked()
{
    _draw->setLetter(ui->lineEdit_Letter->text().toInt());
    _draw->TimerStart(ui->lineEdit->text().toInt());

}

void DrawLetters::on_pushButton_2_clicked()
{
    _draw->TimerStop();
}


void DrawLetters::on_buttonPoint_clicked()
{
    _widget3d->drawPoint(QVector3D(-100,0,100),10.0f,QColor(255,255,0));
    qDebug()<<"now!";
}


void DrawLetters::on_buttonDeletePoint_clicked()
{
    _widget3d->deleteAllPoints();

}

void DrawLetters::drawPointWidget(QVector3D point)
{
    _widget3d->drawPoint(point,1.0f,QColor(255,0,0));
}
void DrawLetters::deletePointWidget()
{
    _widget3d->deleteAllPoints();

}
