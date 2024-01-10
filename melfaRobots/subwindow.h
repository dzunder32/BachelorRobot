#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include<QMdiSubWindow>

class SubWindow: public QWidget
{
    Q_OBJECT
public:
    SubWindow(QWidget *parent=nullptr);
    QMdiSubWindow *showAsSubWindow();
};

#endif // SUBWINDOW_H
