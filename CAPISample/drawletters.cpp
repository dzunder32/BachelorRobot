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
    connect(_draw, &Draw::deletePoints,this, &DrawLetters::deletePointWidget);
    connect(ui->checkBox_NextLetter,&QCheckBox::stateChanged,_draw,&Draw::inc_letter_changeState);
//    connect(ui->spinBox_robotSpeed,&QSpinBox::valueChanged,_draw,&Draw::RobotSpeedChanged);
//    connect(ui->pushButton_Draw,&QPushButton::clicked,this,&DrawLetters::spinBox_valueChanged);
    connect(ui->pushButton_Draw,&QPushButton::clicked,this,&DrawLetters::pB_draw_clicked);
    connect(_draw,&Draw::stopTimerDraw,this,&DrawLetters::on_pushButton_2_clicked);

    robotThread.start();
}

DrawLetters::~DrawLetters()
{
    robotThread.quit();
    robotThread.wait();
    delete ui;
}

void DrawLetters::pB_draw_clicked()
{
    if(!ui->checkBox_NextLetter->isChecked() && !ui->textEdit_Letter->toPlainText().isEmpty()){
        //        _draw->setLetter(ui->lineEdit_Letter->text());
//        ui->textEdit_Letter

        _draw->getWord(ui->textEdit_Letter->toPlainText());
    }

//    ui->lineEdit_Letter->setText(_draw->getLetterName());
    _draw->setTime(ui->robotSpeedSlider->value());
    _draw->draw_TimerStart();
}

void DrawLetters::on_pushButton_2_clicked()
{
    _draw->draw_TimerStop();
}

void DrawLetters::on_buttonDeletePoint_clicked()
{
    _widget3d->deleteAllPoints();

}

void DrawLetters::drawPointWidget(QVector3D point,float thickness)
{
    _widget3d->drawPoint(point,thickness,QColor(0,255,255));
}
void DrawLetters::deletePointWidget()
{
    _widget3d->deleteAllPoints();
}
