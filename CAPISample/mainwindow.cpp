
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    polaris = new PolarisV();

    polaris->moveToThread(&_polarisThread);
    connect(&_polarisThread, &QThread::finished, this,&MainWindow::threadFinished);
    connect(polaris, &PolarisV::streamingStopped, this, &MainWindow::stopThread);
    connect(polaris, &PolarisV::sendData, this, &MainWindow::getData);
    connect(this, &MainWindow::startStreaming, polaris, &PolarisV::startStreaming);
    connect(this, &MainWindow::writeCSV, polaris, &PolarisV::writeCSV);
    connect(this, &MainWindow::getLines, polaris, &PolarisV::getData);

    connect(ui->pbStreaming,&QPushButton::pressed,this,&MainWindow::streaming);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::streaming()
{
    if(isStreaming==true)
    {
        polaris->stopStreaming();
        ui->pbStreaming->setDisabled(true);
    }
    else
    {
        _polarisThread.start();
        emit startStreaming();
        ui->pbStreaming->setText("stop streaming");
        isStreaming=true;
    }
}

void MainWindow::threadFinished()
{
    ui->pbStreaming->setText("start streaming");
    isStreaming=false;
    ui->pbStreaming->setEnabled(true);
}

void MainWindow::stopThread()
{
    _polarisThread.quit();
}

void MainWindow::getData(QString data)
{
    if(!data.contains("Missing"))

        ui->textEdit->append(data);
}
