#include "liveplot.h"
#include "ui_liveplot.h"

LivePlot::LivePlot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LivePlot)
{
    ui->setupUi(this);
//Variable initialization------------------------------------------------------------------------------------------------------------------
    initVariables();
    decimalPlaces=5;
    double step_val=1/qPow(10,decimalPlaces);
    step={step_val,step_val,step_val};
    dstep={step[0]/2,step[0]/2,step[0]/2};
    meanText=QVector<QCPItemText*>(3);
    plotTitle=meanText;
    sigmaText=meanText;
    titleStrings={"Pitch","Yaw","Roll"};
    customPlots = this->findChildren<QCustomPlot*>();
    lineEdits=this->findChildren<QLineEdit*>();
    plotName="Rot-";
//------------------------------------------------------------------------------------------------------------------------------------------
//        DarkmodePlot();
        normalPlot();

}

LivePlot::~LivePlot()
{
    delete ui;
}
void LivePlot::setConfigName(QString name)
{
    configName=name;
}
void LivePlot::setDecimalPlaces(int val)
{
    decimalPlaces=val;
    double step_val=1/qPow(10,decimalPlaces);
    step={step_val,step_val,step_val};
    dstep={step_val/2,step_val/2,step_val/2};
}
void LivePlot::initVariables(){
    GaussVec=QVector<QVector <QVector <double>>>(3,QVector <QVector<double>>(2));
    Values=QVector <QVector <double>>(3);
    max_v=QVector <double>(3);
    min_v=max_v;
    sigmaValues=max_v;
    meanValues=max_v;
}

void LivePlot::addPts(QVector <double> values){
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
            for (double i=GaussValues[1].last()+step[cnt];i<max_v[cnt]-dstep[cnt];i+=step[cnt]){
                GaussValues[1].append(i);
                GaussValues[0].append(0);
            }
            GaussValues[0].append(1);
            GaussValues[1].append(val);
        }else if(val<min_v[cnt]){
            min_v[cnt]=val;
            for (double i=GaussValues[1].front()-step[cnt];i>min_v[cnt]+dstep[cnt];i-=step[cnt]){
                GaussValues[0].prepend(0);
                GaussValues[1].prepend(i);
            }
            GaussValues[0].prepend(1);
            GaussValues[1].prepend(min_v[cnt]);
        }else{
            GaussValues[0][qRound((val-min_v[cnt])/step[cnt])]++;
        }
         cnt++;
    }
//Home--------------------------------------------------------------------------------------------------------------------------------------
//    for (int i=0;i<3;i++){
//         GaussVec[i][0].push_back(QRandomGenerator::global()->bounded(100.0));
//         GaussVec[i][1].push_back(QRandomGenerator::global()->bounded(100.0));
//    }
//    plot();
//-------------------------------------------------------------------------------------------------------------------------------------------
    if(Values[0].size()%plotRate==0){
        plot();
        PlotText();
    }
    if (/*(Values[0].size()==25000)||*/(Values[0].size()==50000&& dataExtract50)||(Values[0].size()==100000&& dataExtract100)||(Values[0].size()==200000&& dataExtract200)){
        DataExtraction();
    }
}


void LivePlot::ExtractDataAt50(){
    dataExtract50=true;
}
void LivePlot::ExtractDataAt100(){
    dataExtract100=true;
}
void LivePlot::plot()
{
    for (int i=0;i<3;i++)
    {
        customPlots[i]->graph()->setData(GaussVec[i][1],GaussVec[i][0]);
        customPlots[i]->rescaleAxes();
        customPlots[i]->replot();
//        customPlots[i]->update();
    }
}


void LivePlot::clearData()
{
//Home------------------------------------------------------------------------------------------------------------------------------------------
//addPts({0,0,0});
//----------------------------------------------------------------------------------------------------------------------------------------------
    GaussVec.clear();
    Values.clear();
    max_v.clear();
    min_v.clear();
    initVariables();
}

void LivePlot::on_ClearButton_clicked()
{
    clearData();
}
void LivePlot::DataExtraction(){
    if (configName.isEmpty())
        configName="_noName-";

    myfile.open(plotName.toStdString()+configName.toStdString()+"-Val_"+QString::number(Values[0].size()).toStdString()+".txt");
    myfile.clear();
    for (auto& i:Values)
    {
        for (auto &j:i)
            myfile<<j<<" ";
        myfile<<std::endl;
    }
    myfile.close();

    for (int i=0;i!=customPlots.size();i++)
        customPlots[i]->savePdf(titleStrings[i]+"_"+configName+"-"+"Val_"+QString::number(Values[0].size())+".pdf");

}

void LivePlot::on_DataButton_clicked()
{
//Labor---------------------------------------------------------------------------------------------------------------------------------------------------------------
    DataExtraction();
//**********************************************************************************************************************************************************************

//Home-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//    PlotText();
//**********************************************************************************************************************************************************************

}
void LivePlot::mean(){
    int ind=0;
    for (auto& i:Values){
        meanValues[ind]=meanValues[ind]*(Values[0].size()-plotRate);
        for (auto it = i.end() - plotRate; it != i.end(); ++it) {
                   meanValues[ind]+=*it;

               }
        meanValues[ind]=meanValues[ind]/i.size();
        ind++;
    }
//Home-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//    meanValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
//**********************************************************************************************************************************************************************
}

void LivePlot::StandardDeviation(){
    int vecIndex=0;
    for (auto& value_v:Values)
    {
        sigmaValues[vecIndex]=qPow(sigmaValues[vecIndex],2)*(Values[0].size()-plotRate-1);
        for (auto it = value_v.end() - plotRate; it != value_v.end(); ++it) {
                   sigmaValues[vecIndex]+=qPow(*it-meanValues[vecIndex],2);
               }
        sigmaValues[vecIndex]=qSqrt(sigmaValues[vecIndex]/(Values[0].size()-1));
        vecIndex++;
    }
//Home-----------------------------------------------------------------------------------------------------------------------------------------------------------
//    sigmaValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
//**********************************************************************************************************************************************************************
}

void LivePlot::PlotText()
{
    mean();
    StandardDeviation();
//Home------------------------------------------------------------------------------------------------------------------------------------------
//    meanValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
//    sigmaValues={QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0),QRandomGenerator::global()->bounded(100.0)};
//**********************************************************************************************************************************************************************

    for (int i=0;i!=meanText.size();i++){
        meanText[i]->setText("Mean:"+QString::number(meanValues[i]));
        sigmaText[i]->setText("Sigma:"+QString::number(sigmaValues[i]));
    }
    lineEdits[0]->setText(QString::number(Values[0].size()));
//    qDebug()<<meanValues<<sigmaValues;

}

void LivePlot::DarkmodePlot()
{
    this->setStyleSheet("QMainWindow {background-color: #000000;}");
    //adding menubar------------------------------------------------------------------------------------------------------------------
    QMenu *fileMenu = new QMenu("File", this);
    QAction *newAct = new QAction("change Name", this);

    // Add the QAction to the QMenu
    fileMenu->addAction(newAct);
    //fileMenu->setStyleSheet("QMenuBar { background-color: red; }");

    // Add the QMenu to the menu bar
    menuBar()->addMenu(fileMenu);

    fileMenu->setStyleSheet("QMenu { background-color: black; color: lightblue; } QMenu:hover { background-color: lightblue; color:red }");
    menuBar()->setStyleSheet("QMenuBar { background-color: black; color: lightblue; }QMenuBar::item:selected { background-color: blue; }");

    // Set the menu bar for the window
    setMenuBar(menuBar());

    connect(newAct,&QAction::triggered,this,&LivePlot::changeName);

    lineEdits[0]->setStyleSheet("QLineEdit { background-color: darkblue; color: cyan; }");
    auto pushButtons=this->findChildren<QPushButton*>();
//    qDebug()<<pushButtons;
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
    customPlots[i]->addGraph();
    customPlots[i]->graph()->setPen(QPen(QColor(Qt::cyan)));
    customPlots[i]->xAxis->setTickLabelColor(QColor(Qt::white)); // Set the color to red
    customPlots[i]->yAxis->setTickLabelColor(QColor(Qt::white));
    customPlots[i]->xAxis->setTickLabelFont(QFont(font().family(), 12, QFont::Normal));
    customPlots[i]->yAxis->setTickLabelFont(QFont(font().family(), 12, QFont::Normal));
    customPlots[i]->setInteractions(QCP::iRangeDrag| QCP::iRangeZoom);
    customPlots[i]->setBackground(QBrush(gradient));
    plotTitle[i]=new QCPItemText(customPlots[i]);
    plotTitle[i]->setText(titleStrings[i]);
    plotTitle[i]->setColor(QColor("cyan")); // Set the color of the title to red.
    plotTitle[i]->setFont(QFont("sans", 17, QFont::Bold));
    plotTitle[i]->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    plotTitle[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    plotTitle[i]->position->setCoords(0.2, 0); // Position the title at the top center of the axis rect.
    meanText[i]=new QCPItemText(customPlots[i]);
    meanText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    meanText[i]->position->setCoords(0.9,0.03); // Position the text to the right of the circle
    meanText[i]->setText("Mean"); // Set the text
    meanText[i]->setFont(QFont(font().family(), 12, QFont::Bold)); // Make the text bold
    meanText[i]->setPen(QPen(QBrush(Qt::blue), 1)); // Set the text color to black
    meanText[i]->setColor(QColor(Qt::cyan));
    sigmaText[i]=new QCPItemText(customPlots[i]);
    sigmaText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    sigmaText[i]->position->setCoords(0.9,0.1); // Position the text to the right of the circlRe
    sigmaText[i]->setText("Sigma"); // Set the text
    sigmaText[i]->setFont(QFont(font().family(), 12, QFont::Normal)); // Make the text bold
    sigmaText[i]->setPen(QPen(QBrush(Qt::blue), 1)); // Set the text color to black
    sigmaText[i]->setColor(QColor(Qt::cyan));
    }
}
void LivePlot::normalPlot()
{
    //adding menubar------------------------------------------------------------------------------------------------------------------
    QMenu *fileMenu = new QMenu("File", this);
    QAction *newAct = new QAction("change Name", this);
    QAction *dataAct1 = new QAction("extract data at 100.000", this);
    QAction *dataAct2 = new QAction("extract data at 50.000", this);
    QAction *dataAct3 = new QAction("extract data at 200.000", this);



    // Add the QAction to the QMenu
    fileMenu->addAction(newAct);
    fileMenu->addAction(dataAct1);
    fileMenu->addAction(dataAct2);
    fileMenu->addAction(dataAct3);


    // Add the QMenu to the menu bar
    menuBar()->addMenu(fileMenu);

    // Set the menu bar for the window
    setMenuBar(menuBar());

    connect(newAct,&QAction::triggered,this,&LivePlot::changeName);
    connect(dataAct1,&QAction::triggered,[&](){dataExtract100=true;});
    connect(dataAct2,&QAction::triggered,[&](){dataExtract50=true;emit sendDataExtract50();});
    connect(dataAct3,&QAction::triggered,[&](){dataExtract200=true;});



    for (int i=0;i!=meanText.size();i++){
    customPlots[i]->addGraph();
    customPlots[i]->graph()->setPen(QPen(QColor(Qt::blue)));
    customPlots[i]->xAxis->setTickLabelColor(QColor(Qt::black)); // Set the color to red
    customPlots[i]->yAxis->setTickLabelColor(QColor(Qt::black));
    customPlots[i]->xAxis->setTickLabelFont(QFont(font().family(), 12, QFont::Normal));
    customPlots[i]->yAxis->setTickLabelFont(QFont(font().family(), 12, QFont::Normal));
    customPlots[i]->xAxis->grid()->setVisible(true);
    customPlots[i]->xAxis->grid()->setPen(QPen(Qt::black, 0.5));
    customPlots[i]->yAxis->grid()->setVisible(true);
    customPlots[i]->yAxis->grid()->setPen(QPen(Qt::black, 0.5));
    customPlots[i]->setInteractions(QCP::iRangeDrag| QCP::iRangeZoom);

    plotTitle[i]=new QCPItemText(customPlots[i]);
    plotTitle[i]->setText(titleStrings[i]);
    plotTitle[i]->setColor(QColor("black")); // Set the color of the title to red.
    plotTitle[i]->setFont(QFont("sans", 17, QFont::Bold));
    plotTitle[i]->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    plotTitle[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    plotTitle[i]->position->setCoords(0.2, 0); // Position the title at the top center of the axis rect.

    meanText[i]=new QCPItemText(customPlots[i]);
    meanText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    meanText[i]->position->setCoords(0.9,0.03); // Position the text to the right of the circle
    meanText[i]->setText("Mean"); // Set the text
    meanText[i]->setFont(QFont(font().family(), 12, QFont::Bold)); // Make the text bold
    meanText[i]->setPen(QPen(QBrush(Qt::gray), 1)); // Set the text color to black
    meanText[i]->setColor(QColor(Qt::black));

    sigmaText[i]=new QCPItemText(customPlots[i]);
    sigmaText[i]->position->setType(QCPItemPosition::ptAxisRectRatio);
    sigmaText[i]->position->setCoords(0.9,0.1); // Position the text to the right of the circle
    sigmaText[i]->setText("Sigma"); // Set the text
    sigmaText[i]->setFont(QFont(font().family(), 12, QFont::Normal)); // Make the text bold
    sigmaText[i]->setPen(QPen(QBrush(Qt::gray), 1)); // Set the text color to black
    sigmaText[i]->setColor(QColor(Qt::black));
    }
}

void LivePlot::changeName()
{
    QDialog *dialog = new QDialog(this);
          QLineEdit *lineEdit = new QLineEdit(dialog);
          lineEdit->setText(configName);
          QVBoxLayout *layout = new QVBoxLayout(dialog);
          layout->addWidget(lineEdit);
          dialog->setLayout(layout);
          dialog->exec();
          configName = lineEdit->text();
          emit sendConfigName(configName);

}

