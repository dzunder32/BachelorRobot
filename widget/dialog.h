#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QQuaternion>
#include "linearaxisrv6sl.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    float XData,YData,ZData;
    QVector <float> quatData;
    QQuaternion Quat;


private:
    Ui::Dialog *ui;

signals:
    void XValueSet(float value);
    void YValueSet(float value);
    void ZValueSet(float value);
    void sendQuatData(QQuaternion Data);
    void XValue(int value);
    void YValue(int value);
private slots:


};

#endif // DIALOG_H
