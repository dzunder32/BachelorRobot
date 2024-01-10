#ifndef LIVEPLOT_2_H
#define LIVEPLOT_2_H
#include <fstream>
#include <QMainWindow>
#include <QLineEdit>
#include <qcustomplot.h>
#include <QRandomGenerator>

namespace Ui {
class LivePlot_2;
}

class LivePlot_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LivePlot_2(QWidget *parent = nullptr);
    ~LivePlot_2();
    void clearData();

public slots:
    void on_ClearButton_clicked();
    void addPts(QVector<double> values);

private slots:
    void on_DataButton_clicked();

private:
    Ui::LivePlot_2 *ui;
    int xCount=0;
    QVector<QVector <QVector <double>>> GaussVec=QVector<QVector <QVector <double>>>(3,QVector <QVector<double>>(2));
    QVector <double> max_v=QVector <double>(3,0),min_v=max_v,meanValues=max_v,sigmaValues=max_v;
    QVector <QVector <double>> Values=QVector <QVector <double>>(3);
    double step=0.00001,dstep=step/2;
    void plot();
    void mean();
    void StandardDeviation();
    void PlotText();
    std::ofstream myfile;
    QList <QCustomPlot*> customPlots;
    QVector <QCPItemText*> meanText=QVector<QCPItemText*>(3),sigmaText=meanText;

    void DarkmodePlot();
};

#endif // LIVEPLOT_2_H
