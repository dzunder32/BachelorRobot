#ifndef POLARISV_H
#define POLARISV_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <QThread>
#include <QTimer>
#include <QQuaternion>
#include <QMatrix4x4>


#include "CombinedApi.h"
#include "PortHandleInfo.h"
#include "ToolData.h"
#include "polaristool.h"

class PolarisV : public QObject
{
    Q_OBJECT
public:
    PolarisV();
    void stopStreaming();
    void configurePassiveTools(QString);

//    QString getFileName();
public slots:
    int startStreaming();
    void writeCSV(std::string fileName, int numberOfLines);
    int getData(int number);
    int getFrame();
//    void setRomFile(QString rom);
private:
//    QString fileName;
    CombinedApi capi;
    bool apiSupportsBX2;
    bool _streaming;
    bool _singleFrame = false;
    QTimer *timer = new QTimer(this);
    QVector<PolarisTool> _tools;
//    QString passiveTool;
//    QString default_passiveTool="5_DTrackerW.rom";

    void sleepSeconds(unsigned numSeconds);
    void onErrorPrintDebugMessage(std::string methodName, int errorCode);
    std::string getToolInfo(std::string toolHandle);
    std::string toolDataToCSV(const ToolData &toolData);
    void printToolData(const ToolData &toolData);
    void printTrackingData();
    void initializeAndEnableTools();
    void loadTool(QString);
    void configureActiveTools(std::string scuHostname);
    void configureActiveWirelessTools();
    void configureDummyTools();
    void configureUserParameters();
    void determineApiSupportForBX2();
signals:
    void streamingStopped();
    void sendData(QString);
    void sendToolData(ToolData);

};

#endif // POLARISV_H
