
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
    connect(this, &MainWindow::getFrame, polaris, &PolarisV::getFrame);
    connect(ui->pbStreaming,&QPushButton::pressed,this,&MainWindow::streaming);
    connect(ui->pbMarkerposition,&QPushButton::pressed,this,&MainWindow::detektMarkers);
//    QMenu *fileMenu = new QMenu("File", this);

//    // Create a new QAction
//    QAction *newAct = new QAction("New", this);

//    // Add the QAction to the QMenu
//    fileMenu->addAction(newAct);


//    // Add the QMenu to the menu bar
//    menuBar()->addMenu(fileMenu);

//    // Set the menu bar for the window
//    setMenuBar(menuBar());

//    connect(newAct,&QAction::triggered,this,&MainWindow::addRomFile);
//    connect(this,&MainWindow::sendRom,polaris,&PolarisV::setRomFile);


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
    {
        ui->textEdit->append(data);
        dataList=data.split(',');
//        qDebug()<<"dataList:"<<dataList;
//        qDebug()<<"ToolHandle"<<dataList[1];
        for (int i=4;i<12;i++){
            RotTransData.append(dataList[i].toDouble());
        }
        if (dataList[1]=="Port:1")
        {
             emit sendPolarisData(RotTransData);
//            qDebug()<<"worked";
        }
        else if(dataList[1]=="Port:2")
        {
            emit sendToolData(RotTransData);
//        qDebug()<<"also worked!";
        }
        else if(dataList[1]=="Port:3")
        {
            emit sendCalibratorData(RotTransData);
        }
//        qDebug()<<"the Data:"<<RotTransData;
    }
    RotTransData.clear();
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::connectWidget(Widget3D* w)
{
    widget=w;
//    widget->setFileName(polaris->getFileName());
    connect(this,&MainWindow::sendToolData,widget,&Widget3D::getToolData);
    connect(this,&MainWindow::sendPolarisData,widget,&Widget3D::getPolarisData);
    connect(this,&MainWindow::sendCalibratorData,widget,&Widget3D::getCalibratorData);

}

void MainWindow::addRomFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open ROM File"), "/path/to/start/dir", tr("ROM Files(*.rom)"));
        if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        QString baseName = fileInfo.baseName();
        qDebug()<<baseName+".rom";
        emit sendRom(baseName);
        }
}
void MainWindow::changePDFName()
{
    QDialog *dialog = new QDialog(this);
          QLineEdit *lineEdit = new QLineEdit(dialog);
          QVBoxLayout *layout = new QVBoxLayout(dialog);
          layout->addWidget(lineEdit);
          dialog->setLayout(layout);
          dialog->exec();
          QString inputText = lineEdit->text();

}
