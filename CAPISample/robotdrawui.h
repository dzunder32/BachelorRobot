#ifndef ROBOTDRAWUI_H
#define ROBOTDRAWUI_H

#include <QMainWindow>
#include "robotdraw.h"
#include <mousepositionfilter.h>

namespace Ui {
class RobotDrawUi;
}

class RobotDrawUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotDrawUi(Kinematik *robotKinematik, Robot *robot, QVector3D sled_pos, Plane* plane, Widget3D *widget3d, QWidget *parent = nullptr);
    ~RobotDrawUi();
public slots:
    void removeAllItems();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
    void on_timerSpeedSlider_sliderMoved(int position);
    void widgetDrawPoint(QVector3D point , float thickness, QColor color){_widget3d->drawPoint(point,thickness,color);}
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

private:
    Ui::RobotDrawUi *ui;
    RobotDraw *_robDraw;
    Widget3D *_widget3d;
    QThread robotThread;
    Robot *_robot;
    Plane *_plane;
    QVector2D P1,P2;
    QString P1X_Str,P1Y_Str,P2X_Str,P2Y_Str;
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
signals:
    void startDrawing();
    void stopDrawing();
    void changeSpeed(int);

public slots:
    void drawLineWidget(QVector3D start,QVector3D end){_widget3d->addCylinderBetweenPoints(start,end);}
    void planeRegistration();

};

#endif // ROBOTDRAWUI_H
