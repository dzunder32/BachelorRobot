#include "subwindow.h"

SubWindow::SubWindow(QWidget* parent):
    QWidget(parent)
{

}

QMdiSubWindow* SubWindow::showAsSubWindow()
{
    QMdiSubWindow* window=new QMdiSubWindow();
    window->setWidget(this);
    window->show();
    return window;
}
