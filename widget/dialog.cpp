#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    ui->ScrollBarX->rangeChanged(0,180);
    ui->widget->addGraph(0);
}

Dialog::~Dialog()
{
    delete ui;
}




//void Dialog::on_ScrollBar_XP_valueChanged(int value)
//{
//    emit XValue(value);
//}


//void Dialog::on_ScrollBar_YP_valueChanged(int value)
//{
//    emit YValue(value);
//}

//void Dialog::getTransform(STLMesh *mesh)
//{
//    _mesh=mesh;
//}
//void Dialog::getLAxis(LinearAxis* a)
//{
//    _axis=a;
//    connect(this,&Dialog::XValue,_axis,&LinearAxis::adjustPosX);
//}
