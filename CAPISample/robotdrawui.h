#ifndef ROBOTDRAWUI_H
#define ROBOTDRAWUI_H

#include <QMainWindow>
#include "robotdraw.h"
#include <mousepositionfilter.h>
#include "mainwindow.h"
#include "robotcontrol.h"

namespace Ui {
class RobotDrawUi;
}

class RobotDrawUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotDrawUi(Kinematik *robotKinematik, Robot *robot, QVector3D sled_pos, Plane* plane, Widget3D *widget3d,MainWindow *polarisGUI,RobotControl *robControl, QWidget *parent = nullptr);
    ~RobotDrawUi();
    void getMaterial(Qt3DExtras::QDiffuseSpecularMaterial *material);
public slots:
    void removeAllItems();
    void getConnectionPolaris(bool connection);

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
    void on_timerSpeedSlider_sliderMoved(int position);
    void widgetDrawPoint(QVector3D point){_widget3d->drawPoint(point);}
    void on_pushButton_draw_clicked();
    void on_spinBox_letterSize_valueChanged(int arg1);
    void on_spinBox_dist_valueChanged(int arg1);
    void onMousePressed(QPoint globalPos);
    void on_pushButton_lift_clicked();


    void on_spinBox_xRot_valueChanged(int arg1);
    void on_spinBox_yRot_valueChanged(int arg1);

    void on_pushButton_drawLinePoint_clicked();

    void on_pushButton_drawCircle_clicked();

    void on_pushButton_testX_clicked();

    void on_pushButton_testY_clicked();

    void on_pushButton_testDistance_clicked();

    void on_checkBox_clicked();

    void on_pushButton_reset_clicked();

private:
    Ui::RobotDrawUi *ui;
    RobotDraw *_robDraw;
    Widget3D *_widget3d;
    QThread robotThread;
    Robot *_robot;
    Plane *_plane;
    MainWindow *_polarisGUI;
    RobotControl *_robControl;
    QVector2D P1,P2;
    bool preview_isDrawn = false;
    bool point_isDrawn   = false;
    bool liftTip_isTrue  = false;
    MousePositionFilter *mouseFilter;
    QPoint localPos;
    QSize gViewSize;
    QGraphicsScene *scene;
    QList<QPair<QGraphicsLineItem*, QLineF>> lines;
    QList<QGraphicsEllipseItem*> points,circle_points;
    QList<QGraphicsPathItem*> circles;
    void addLine(const QPointF &start, const QPointF &end);
    void addPoint(qreal x, qreal y);
    void addPressedPoint(qreal x, qreal y);
    void drawGWBackground();
    void adjustGWSliders();
    void scaleItems();

    void addCircle(qreal x, qreal y);
    bool circleInsidePlane(QPointF point, float radius);
    void getP1fromStr();
    void setFontSizeForAllAndFutureText(qreal pointSize);
    Qt3DExtras::QDiffuseSpecularMaterial* _material;
    void statusRadioButton();
    void clearAll();
signals:
    void startDrawing();
    void stopDrawing();
    void changeSpeed(int);

public slots:
    void drawLineWidget(QVector3D start,QVector3D end){_widget3d->addCylinderBetweenPoints(start,end);}
    void planeRegistration();
    void setRobotCheckbox(bool status);

};

#endif // ROBOTDRAWUI_H
