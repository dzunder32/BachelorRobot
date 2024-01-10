#include "liveplot_2.h"
#include "ui_liveplot_2.h"

LivePlot_2::LivePlot_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LivePlot_2)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {background-color: #000000;}");

    ui->plot->addGraph();
    ui->plot_1->addGraph();
    ui->plot_2->addGraph();

   customPlots = this->findChildren<QCustomPlot*>();

DarkmodePlot();
   PlotText();
}

LivePlot_2::~LivePlot_2()
{
    delete ui;
}

void LivePlot_2::addPts(QVector <double> values){
    int cnt=0;
    for (auto& GaussValues:GaussVec)
    {
        double val=values[cnt];
        Values[cnt].append(val);

        if (GaussValues[0].isEmpty()){
            max_v[cnt]=val;
            min_v[cnt]=val;
            GaussValues[0].append(1);
            GaussValues[1].append(val);
        }else if(val>max_v[cnt]){
            max_v[cnt]=val;
            for (double i=GaussValues[1].last()+step;i<max_v[cnt]-dstep;i+=step){
                GaussValues[1].append(i);
                GaussValues[0].append(0);
            }
            GaussValues[0].append(1);
            GaussValues[1].append(val);
        }else if(val<min_v[cnt]){
            min_v[cnt]=val;
            for (double i=GaussValues[1].front()-step;i>min_v[cnt]+dstep;i-=step){
                GaussValues[0].prepend(0);
                GaussValues[1].prepend(i);
            }
            GaussValues[0].prepend(1);
            GaussValues[1].prepend(min_v[cnt]);
        }else{
            GaussValues[0][qRound((val-min_v[cnt])/step)]++;
        }
         cnt++;
    }

if(Values[0].size()%10==0)
    plot();

}

void LivePlot_2::plot()
{
for (int i=0;i<3;i++)
{
    customPlots[i]->graph()->setData(GaussVec[i][1],GaussVec[i][0]);
    customPlots[i]->rescaleAxes();
    customPlots[i]->replot();
    customPlots[i]->update();
}
}


void LivePlot_2::clearData()
{
GaussVec.clear();
Values.clear();
max_v.clear();
min_v.clear();
}

void LivePlot_2::on_ClearButton_clicked()
{
    clearData();
}

void LivePlot_2::on_DataButton_clicked()
{

    myfile.open("data.txt");
    myfile.clear();
    for (auto& i:Values)
    {
        for (auto &j:i)
            myfile<<j<<" ";
        myfile<<std::endl;
    }
    myfile.close();

    PlotText();

}
void LivePlot_2::mean(){
    int ind=0;
    for (auto& i:Values){
        for (auto& j:i){
            meanValues[ind]+=j;
        }
        meanValues[ind]=meanValues[ind]/i.size();
        ind++;
    }
    meanValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
}
void LivePlot_2::StandardDeviation(){
    int vecIndex=0;
    for (auto& value_v:Values)
    {
        for (auto& value:value_v)
        {
            qDebug()<<"index:"<<vecIndex;
            qDebug()<<value-meanValues[vecIndex];
            sigmaValues[vecIndex]+=qPow(value-meanValues[vecIndex],2);
            qDebug()<<"Sigma:"<<sigmaValues[vecIndex];
        }
        sigmaValues[vecIndex]=qSqrt(sigmaValues[vecIndex]/(Values[0].size()-1));
        vecIndex++;
    }
    sigmaValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
}

void LivePlot_2::PlotText()
{
    mean();
    StandardDeviation();
    for (int i=0;i!=meanText.size();i++){
        meanText[i]->setText("Mean:"+QString::number(meanValues[i]));
        sigmaText[i]->setText("Sigma:"+QString::number(sigmaValues[i]));
    }
    qDebug()<<meanValues<<sigmaValues;
}


void LivePlot_2::DarkmodePlot()
{
    auto pushButtons=this->findChildren<QPushButton*>();
    for (int i=0;i!=pushButtons.size();i++)
    {
    pushButtons[i]->setStyleSheet("QPushButton {"
                                              "    color: white;"
                                              "    background-color: darkblue;"
                                              "}"
                                              "QPushButton:hover {"
                                              "    background-color: lightblue;"
                                              "}");
    }

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(0, 0, 120));
    gradient.setColorAt(0.38, QColor(0, 0, 60));
    gradient.setColorAt(1, QColor(0, 0, 0));
    for (int i=0;i!=meanText.size();i++){
//    customPlots[i]->xAxis->setBasePen(QPen(Qt::red));
//    customPlots[i]->yAxis->setBasePen(QPen(Qt::red));
    customPlots[i]->xAxis->setTickLabelColor(QColor(Qt::red)); // Set the color to red
    customPlots[i]->yAxis->setTickLabelColor(QColor(Qt::red)); // Set the color to blue
    customPlots[i]->setInteractions(QCP::iRangeDrag| QCP::iRangeZoom);
    customPlots[i]->setBackground(QBrush(gradient));
    meanText[i]=new QCPItemText(customPlots[i]);
    meanText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    meanText[i]->position->setCoords(0.9,0.03); // Position the text to the right of the circle
    meanText[i]->setText("Mean"); // Set the text
    meanText[i]->setFont(QFont(font().family(), 8, QFont::Normal)); // Make the text bold
    meanText[i]->setPen(QPen(QBrush(Qt::blue), 1)); // Set the text color to black
    meanText[i]->setColor(QColor(Qt::green));
    sigmaText[i]=new QCPItemText(customPlots[i]);
    sigmaText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    sigmaText[i]->position->setCoords(0.9,0.1); // Position the text to the right of the circle
    sigmaText[i]->setText("Sigma"); // Set the text
    sigmaText[i]->setFont(QFont(font().family(), 8, QFont::Normal)); // Make the text bold
    sigmaText[i]->setPen(QPen(QBrush(Qt::yellow), 1)); // Set the text color to black
    sigmaText[i]->setColor(QColor(Qt::magenta));
    }
}
