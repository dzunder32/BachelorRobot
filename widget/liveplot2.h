#ifndef LIVEPLOT2_H
#define LIVEPLOT2_H

//#include <QMainWindow>
#include <liveplot.h>

namespace Ui {
class LivePlot2;
}

class LivePlot2 : public LivePlot
{
    Q_OBJECT

public:
    explicit LivePlot2(QWidget *parent = nullptr);
    ~LivePlot2();
   void initMode();
public slots:
void getConfigName(QString name);

void getDataExtract50();
private:
    Ui::LivePlot2 *ui;
//signals:
//    update
};

#endif // LIVEPLOT2_H
