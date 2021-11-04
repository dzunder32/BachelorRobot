#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "polarisv.h"
#include <QObject>

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

private:
    Ui::MainWindow *ui;
    QThread _polarisThread;
    bool isStreaming=false;

signals:
    void startStreaming();
    void writeCSV(std::string name,int lines);
    void getLines(int lines);

};

#endif // MAINWINDOW_H
