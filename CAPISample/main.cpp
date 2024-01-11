#include "mainwindow.h"
#include <QApplication>
#include "linearaxisrv6sl.h"
#include "rv6sl.h"
#include "rv4fl.h"
#include "widget3d.h"
#include "coordinatesystem.h"
#include "kinectcamera.h"
#include "rv6slkinematik.h"
#include "controlpanel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow;

    w->show();
    //Erstellen des Widgets -----------------------------------------------------------------------------------------
    Widget3D *widget3d = new Widget3D();
    widget3d->ShowAsSubWindow();
    w->connectWidget(widget3d);

    //Welt-Koordinatensystem im Raum --------------------------------------------------------------------------------
    CoordinateSystem *coordSystem=new CoordinateSystem();
    coordSystem->setLength(6000);
    coordSystem->setNegativeAxis(true);
    widget3d->addObject(coordSystem,QVector3D(0,0,0),QQuaternion(0,0,0,0));


    CoordinateSystem *CSystem=new CoordinateSystem();
    CSystem->setLength(100);
    CSystem->setNegativeAxis(false);
//    CSystem->setTranslation(QVector3D(100,100,0));
    STLMesh* toolMesh= new STLMesh(CSystem);
    toolMesh->setSource("Tool.STL");
    widget3d->addObject(CSystem);
    widget3d->addTransTool(CSystem);
    static_cast<Qt3DCore::QTransform*>(CSystem->components()[1])->setTranslation(QVector3D(200,-200,0));


//MotherChrist i like you



//    qDebug()<<CSystem->components();
//    widget3d->getTransTool(static_cast<Qt3DCore::QTransform*>(CSystem->components()[0]));
//    auto* trans=CSystem->components()[1];
//
//    auto* change = static_cast<Qt3DCore::QTransform*>(trans);
//    change->setRotationX(30);



    //STL-Datei hinzufügen ------------------------------------------------------------------------------------------
    //Aufgabe
    //Tool.STL mit Translation und Rotation

    //1. Roboter Mesh -----------------------------------------------------------------------------------------------
//    RV4FL* robot1=new RV4FL();
//    widget3d->addObject(robot1);
//    robot1->setTranslation(QVector3D(1600,-1000,0));
//    robot1->setRotationZ(30);


    //2. Roboter Mesh -----------------------------------------------------------------------------------------------
    RV6SL *robot2 =new RV6SL();
    Rv6slKinematik *robot2Kinematik=new Rv6slKinematik(robot2);
    ControlPanel *controlpanel=new ControlPanel(robot2Kinematik);
    controlpanel->show();
    widget3d->addObject(controlpanel->getCoord());


    //Hinzufügen eines Tools in die Grafik
    KinectCamera* camera2=new KinectCamera();

    //Hinzufügen einer Linearachse

    LinearAxisRV6SL* linAxis =new LinearAxisRV6SL();
    LinearAxisRV6SL* linAxis2 =new LinearAxisRV6SL();
//    robot2->setTranslation(QVector3D(-1600,0,0));
    robot2->addTool(camera2);
    robot2->addLinearAxis(linAxis2);
//    qDebug()<<linAxis2->rotation().toRotationMatrix();
    linAxis2->set_sled_position(linAxis2->rotation().toRotationMatrix());
    qDebug()<<linAxis2->sled_position;
    widget3d->addObject(robot2);
    widget3d->addObject(linAxis);

//    linAxis->setTranslation(QVector3D(-400,0,0));

    //Polaris als Koordinatensystem --------------------------------------------------------------
    CoordinateSystem *polaris=new CoordinateSystem;
    polaris->setLength(200);
    polaris->setNegativeAxis(false);
    widget3d->addObject(polaris);
    widget3d->addTransPolaris(polaris);

    //Position des Polaris-Tools
    CoordinateSystem *position=new CoordinateSystem;
    position->setLength(100);
//    position->AxisX->setEnabled(false);
    position->setNegativeAxis(false);
    widget3d->addObject(position,QVector3D(-790,0,800),QQuaternion(1,0,0,0)/*QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),140)**//**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->setPosMatrix(static_cast<Qt3DCore::QTransform*>(position->components()[1]));



    return a.exec();
}
