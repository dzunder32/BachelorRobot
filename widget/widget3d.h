#ifndef WIDGET3D_H
#define WIDGET3D_H

#include <QObject>
#include <QWheelEvent>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qforwardrenderer.h>
#include <QScreen>
#include <QWidget>
#include "cameracontroller.h"
#include <QEntity>
#include <QPointLight>
#include <Qt3DExtras>
#include <QMdiSubWindow>
#include <plane.h>
#include <QVector>
#include <liveplot2.h>
#include <QThread>


class Widget3D : public QWidget
{
    Q_OBJECT
public:
    Widget3D(QWidget *parent = nullptr);
    ~Widget3D();

    void addObject(Qt3DCore::QEntity *entity,QVector3D pos,QQuaternion quad);
    void addObject(Qt3DCore::QEntity *entity);
//    void addObject(Qt3DCore::QEntity *entity,const bool& arg);
    void addTransTool(Qt3DCore::QEntity *entity);
    void addTransPolaris(Qt3DCore::QEntity *entity);
    void addTransCalibrator(Qt3DCore::QEntity *entity);

    void setRefMatrix(Qt3DCore::QTransform *ref);
    int toolPlaneDistance = 8;
    QMatrix4x4 DataMatrix(QVector <QVector <double>> &vals,QVector <double> data);

    QMdiSubWindow* ShowAsSubWindow(){QMdiSubWindow* window=new QMdiSubWindow();window->setWidget(_widget3D);window->show();return window;}

    Qt3DCore::QEntity* getRootEntity(){return _rootEntity;}
    Qt3DExtras::QAbstractCameraController* getCamera(){return _camController;}
    QWidget *getQWidget() const;
    QVector <double> meanVector(QVector <QVector <double>> &vec,QVector <double> data);

    void setFileName(QString name);
    void setViewCenter(QVector3D point);
    void addPlane(Plane *plane);

public slots:
    void getToolData(QVector <double>);
    void getPolarisData(QVector <double>);
    void getCalibratorData(QVector <double>);

    void drawPoint(QVector3D position, float size, QColor color);
    void deleteAllPoints();
    void deleteAllLines();
    void addCylinderBetweenPoints(const QVector3D &startPoint, const QVector3D &endPoint);

private:
    Qt3DCore::QEntity* _rootEntity;
    Qt3DCore::QTransform* _transRoot;
    Qt3DExtras::Qt3DWindow *_view;
    Qt3DRender::QCamera *_cameraEntity;
    Qt3DExtras::QAbstractCameraController* _camController;
    QWidget *_widget3D;
    Plane *_plane;
    // Qt3DCore::QTransform *planeToolTransform = new Qt3DCore::QTransform();
    Qt3DCore::QTransform *trans_tool;
    Qt3DCore::QTransform *trans_polaris;
    Qt3DCore::QTransform *trans_calibrator;
    Qt3DCore::QTransform *trans_ref;
    Qt3DCore::QTransform *trans_point;
    int meanVal=20,decimalPlaces;
    QVector <QVector <double>> PolarisVals,ToolVals,CalibratorVals;
    QVector <double> meanDataT=QVector <double>(meanVal,0),meanDataP=QVector <double>(meanVal,0);
    QMatrix4x4 ToolMatrix,PolarisMatrix,CalibratorMatrix;
    LivePlot* livePlot;
    LivePlot2* livePlot2;
    QVector<Qt3DCore::QEntity*> pointEntities,lineEntities;


    double roundDecimalPlaces(double val);
    void setDecimalPlaces(int val);
signals:
    void updatePlt(QVector <double> values);
    void updatePlt2(QVector <double> values);
    void sendAngle(float angle);

};

#endif // WIDGET3D_H
