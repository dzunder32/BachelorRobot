#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "polarisv.h"
#include <QObject>
#include "widget3d.h"
#include "QDebug"
#include "QVector"
#include "QQuaternion"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    PolarisV* polaris;
    Widget3D* widget;
    QVector <double> RotTransData;
    void connectWidget(Widget3D*);


public slots:
    void changePDFName();
private slots:
    void threadFinished();
    void stopThread();
    void getData(QString);
    void streaming();
    void detektMarkers();
    void on_pushButton_clicked();
    void addRomFile();
private:
    Ui::MainWindow *ui;
    QThread _polarisThread;
    bool isStreaming=false;
    QStringList dataList;

signals:
    void startStreaming();
    void getFrame();
    void writeCSV(std::string name,int lines);
    void getLines(int lines);

    void sendCalibratorData(QVector <double> data);
    void sendToolData(QVector <double> data);
    void sendPolarisData(QVector <double> data);
    void sendRom(QString rom);
};

#endif // MAINWINDOW_H
