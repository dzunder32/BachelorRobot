#ifndef DRAWLETTERS_H
#define DRAWLETTERS_H

#include <QMainWindow>
#include "kinematik.h"
#include "windows.h"

namespace Ui {
class DrawLetters;
}

class DrawLetters : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawLetters(Kinematik *robot, QWidget *parent = nullptr);
    ~DrawLetters();
    void setPoints(QVector <QVector3D>);
    void setSledPos(QVector3D);
    void getPlane(Qt3DCore::QTransform *plane);
private slots:
    void on_pushButton_clicked();
    void onTimeout();

    void on_pushButton_2_clicked();

private:
    Ui::DrawLetters *ui;
    Kinematik *_robot;
    QThread robotThread;
    QTimer *timer;
    QVector <QVector3D> pointsRobot,pointsBase;
    double a,b,c,l1;
    QVector3D sled_pos;
    QMatrix4x4 robotMat;
    QVector3D pointRobot,pointBase;
    int counter=0;
    Qt3DCore::QTransform *trans_plane;


    void pointsBase2Robot(QVector<QVector3D> points_vec);
signals:
    void passPosition(double x, double y, double z , double a, double b , double c, double l1);

};

#endif // DRAWLETTERS_H
