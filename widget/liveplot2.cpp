#include "liveplot2.h"
#include "ui_liveplot2.h"

LivePlot2::LivePlot2(QWidget *parent) :
    LivePlot(parent),
    ui(new Ui::LivePlot2)
{
    ui->setupUi(this);
//    this->setStyleSheet("QMainWindow {background-color: #000000;}");
    initMode();
    initVariables();
    plotName="Trans-";
    connect(ui->DataButton,&QPushButton::clicked,this,&LivePlot2::on_DataButton_clicked);
    connect(ui->ClearButton,&QPushButton::clicked,this,&LivePlot2::on_ClearButton_clicked);
    step={0.001,0.001,0.01};
    dstep={step[0]/2,step[1]/2,step[2]/2};
    dataExtract50=true;
}

LivePlot2::~LivePlot2()
{
    delete ui;
}

void LivePlot2::initMode()
{
    customPlots = this->findChildren<QCustomPlot*>();
    customPlots.removeFirst();
    customPlots.removeFirst();
    customPlots.removeFirst();
    qDebug()<<lineEdits;
    lineEdits=this->findChildren<QLineEdit*>();
    lineEdits.removeFirst();
    qDebug()<<customPlots;
    titleStrings={"X","Y","Z"};
//    DarkmodePlot();
    normalPlot();
    PlotText();
}

void LivePlot2::getConfigName(QString name)
{
    configName=name;
}
void LivePlot2::getDataExtract50()
{
dataExtract50=true;
}
