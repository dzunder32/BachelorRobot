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

#include "CombinedApi.h"
#include "PortHandleInfo.h"
#include "ToolData.h"

class PolarisV : public QObject
{
    Q_OBJECT
public:
    PolarisV();

    void stopStreaming();
    void configurePassiveTools(QString);

public slots:
    int startStreaming();
    void writeCSV(std::string fileName, int numberOfLines);
    int getData(int number);

private:
    CombinedApi capi;
    bool apiSupportsBX2;
    bool _streaming;
    QTimer *timer = new QTimer(this);

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
};

#endif // POLARISV_H
