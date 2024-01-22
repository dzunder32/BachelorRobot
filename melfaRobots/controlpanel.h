#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "kinematik.h"
#include "subwindow.h"
#include "coordinatesystem.h"

namespace Ui {
class ControlPanel;
}

class ControlPanel : public SubWindow
{
    Q_OBJECT

public:
    explicit ControlPanel(Kinematik *robot, QWidget *parent = nullptr);
    ~ControlPanel();

private:
    Ui::ControlPanel *ui;
    Kinematik *_robot;

    bool _buttonDown();
private slots:
    void _home();
    void _setJ1(double j1);
    void _setJ2(double j2);
    void _setJ3(double j3);
    void _setJ4(double j4);
    void _setJ5(double j5);
    void _setJ6(double j6);
    void _setJ7(double j7);

    void _setX(double x);
    void _setY(double y);
    void _setZ(double z);
    void _setA(double a);
    void _setB(double b);
    void _setC(double c);
    void _setL1(double l1);
    void _setFlg1(unsigned int flg1);
    void _setKart();
    void _setJoints();

    void _updateRobot();

};

#endif // CONTROLPANEL_H
