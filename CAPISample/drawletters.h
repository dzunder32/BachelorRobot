#ifndef DRAWLETTERS_H
#define DRAWLETTERS_H

#include <QMainWindow>
//#include "kinematik.h"
#include "windows.h"
#include "draw.h"
namespace Ui {
class DrawLetters;
}

class DrawLetters : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawLetters(Kinematik *robot, QVector3D sled_pos,Qt3DCore::QTransform* plane, Widget3D *widget3d, QWidget *parent = nullptr);
    ~DrawLetters();


public slots:

    void drawPointWidget(QVector3D point);
    void deletePointWidget();
private slots:
//    void on_pushButton_Draw_clicked();
    void on_pushButton_2_clicked();
    void on_buttonDeletePoint_clicked();
//    void spinBox_valueChanged();
    void pB_draw_clicked();
private:
    Ui::DrawLetters *ui;
    Draw *_draw;
    Widget3D *_widget3d;
    Kinematik *_robot;
    QThread robotThread;


};

#endif // DRAWLETTERS_H
