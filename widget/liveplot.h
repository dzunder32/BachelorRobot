#ifndef LIVEPLOT_H
#define LIVEPLOT_H
#include <fstream>
#include <QMainWindow>
#include <QLineEdit>
#include <qcustomplot.h>
#include <QRandomGenerator>

namespace Ui {
class LivePlot;
}

class LivePlot : public QMainWindow
{
    Q_OBJECT


public:
    explicit LivePlot(QWidget *parent = nullptr);
    ~LivePlot();
    void clearData();
    void setConfigName(QString name);
public slots:
    void on_ClearButton_clicked();
    void addPts(QVector <double> values);
    void on_DataButton_clicked();
    void changeName();
    void setDecimalPlaces(int val);
protected:
bool dataExtract50=true,dataExtract100=false,dataExtract200=false;
QString plotName,configName;
    Ui::LivePlot *ui;
    int xCount=0,decimalPlaces;
    QVector<QVector <QVector <double>>> GaussVec;
    QVector <double> max_v,min_v,meanValues,sigmaValues;
    QVector <QVector <double>> Values;
//    double step=0.00001,dstep=step/2;
    QVector <double> step,dstep;
    void plot();
    void mean();
    void StandardDeviation();
    void PlotText();
    std::ofstream myfile;
    QList <QCustomPlot*> customPlots;
    QVector <QCPItemText*> meanText,plotTitle,sigmaText;
    void initVariables();
    void DarkmodePlot();
    void normalPlot();

    int plotRate=30;
    QVector <QString> titleStrings;
    QList <QLineEdit*> lineEdits;
    void DataExtraction();
    void ExtractDataAt100();
    void ExtractDataAt50();
signals:
    void sendDataExtract50();
    void sendConfigName(QString configName);
//    void on_pushButton_clicked();
};

#endif // LIVEPLOT_H
