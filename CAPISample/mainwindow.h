#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "polarisv.h"
#include <QObject>
#include "rv6sl.h"
#include "rv6slkinematik.h"
#include "linearaxisrv6sl.h"
#include "widget3d.h"
#include "coordinatesystem.h"
#include "controlpanel.h"
#include "robotcontrol.h"
#include "robot.h"
#include "polarispenrv6sl.h"

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

private slots:
    void threadFinished();
    void stopThread();
    void getData(QString);
    void streaming();
    void detektMarkers();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QThread _polarisThread;
    bool isStreaming=false;

signals:
    void startStreaming();
    void getFrame();
    void writeCSV(std::string name,int lines);
    void getLines(int lines);

};

#endif // MAINWINDOW_H
