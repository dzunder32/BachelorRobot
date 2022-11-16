
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    polaris = new PolarisV();

    Widget3D *widget3d = new Widget3D();
    widget3d->ShowAsSubWindow();

    CoordinateSystem *coordSystem=new CoordinateSystem();
    coordSystem->setLength(6000);
    coordSystem->setNegativeAxis(false);
    widget3d->addObject(coordSystem,QVector3D(0,0,0),QQuaternion(0,0,0,0));

    RV6SL *robot =new RV6SL();
    Rv6slKinematik* roboKin= new Rv6slKinematik(robot);
    PolarisPenRv6sl* pen = new PolarisPenRv6sl();
    roboKin->setTool(*pen);
    ControlPanel *robotPanel= new ControlPanel(roboKin);
    robotPanel->showAsSubWindow();
    robotPanel->setWindowTitle("RV-6SL");

    //Verbindung mit dem echten Roboter
    Robot* realRobot =new Robot("143.93.135.15",10001);
    realRobot->ConnectKinematik(roboKin);
    RobotControl* robotControlPanel =new RobotControl(realRobot);
    robotControlPanel->showAsSubWindow();
    robotControlPanel->setWindowTitle("RV-6SL");

    LinearAxis* linAxis =new LinearAxisRV6SL();

    robot->setTranslation(QVector3D(-1600,0,0));
    robot->addTool(pen);
    robot->addLinearAxis(linAxis);

    widget3d->addObject(robot);

    polaris->moveToThread(&_polarisThread);
    connect(&_polarisThread, &QThread::finished, this,&MainWindow::threadFinished);
    connect(polaris, &PolarisV::streamingStopped, this, &MainWindow::stopThread);
    connect(polaris, &PolarisV::sendData, this, &MainWindow::getData);
    connect(this, &MainWindow::startStreaming, polaris, &PolarisV::startStreaming);
    connect(this, &MainWindow::writeCSV, polaris, &PolarisV::writeCSV);
    connect(this, &MainWindow::getLines, polaris, &PolarisV::getData);
    connect(this, &MainWindow::getFrame, polaris, &PolarisV::getFrame);

    connect(ui->pbStreaming,&QPushButton::pressed,this,&MainWindow::streaming);
    connect(ui->pbMarkerposition,&QPushButton::pressed,this,&MainWindow::detektMarkers);


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

void MainWindow::detektMarkers()
{
    _polarisThread.start();
    emit getFrame();
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

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}
