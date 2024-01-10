#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "robot.h"
#include "subwindow.h"

namespace Ui {
class RobotControl;
}

class RobotControl : public SubWindow
{
    Q_OBJECT

public:
    explicit RobotControl(Robot* robot, QWidget *parent = 0);
    ~RobotControl();

public slots:
    void TextOutput(QString text);
private slots:
    void _connectClicked();
    void _servoClicked();
    void _stopClicked();
    void _update();
    void _directUpdate(bool checked);
private:
    Robot* _robot;
    Ui::RobotControl *ui;
    void _disable(bool disable);
};

#endif // ROBOTCONTROL_H
