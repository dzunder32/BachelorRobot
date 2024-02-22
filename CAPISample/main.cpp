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
#include "drawletters.h"
#include "penholder.h"
#include "plane.h"
#include "robot.h"
#include "robotcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow *w=new MainWindow;

//    w->show();
    //Erstellen des Widgets -----------------------------------------------------------------------------------------
    Widget3D *widget3d = new Widget3D();
    widget3d->ShowAsSubWindow();
//    w->connectWidget(widget3d);

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


//Adawakedawra



    //2. Roboter Mesh -----------------------------------------------------------------------------------------------
    RV6SL *robot2 =new RV6SL();
    Rv6slKinematik *robot2Kinematik=new Rv6slKinematik(robot2);
//    ControlPanel *controlpanel=new ControlPanel(robot2Kinematik);
//    controlpanel->show();

    //Hinzufügen eines Tools in die Grafik
//    KinectCamera* camera2 = new KinectCamera();
    PenHolder* penHolder = new PenHolder();
    penHolder->CoordSystem->thinOut(0.5);
    //Hinzufügen einer Linearachse

    LinearAxisRV6SL* linAxis  = new LinearAxisRV6SL();
    LinearAxisRV6SL* linAxis2 = new LinearAxisRV6SL();
//    robot2->setTranslation(QVector3D(-1600,0,0));
//    robot2->addTool(camera2);
    robot2->addTool(penHolder);
    robot2->addLinearAxis(linAxis2);
//    qDebug()<<linAxis2->rotation().toRotationMatrix();
    linAxis2->set_sled_position(linAxis2->rotation().toRotationMatrix());
    qDebug()<<linAxis2->sled_position;
//    drawL->setSledPos(linAxis2->sled_position);
    widget3d->setViewCenter(linAxis2->sled_position + QVector3D(0,0,500));

//    QMatrix4x4 robotMat;
//    robotMat.rotate(90,QVector3D(0,0,1));
//    robotMat.setColumn(3,QVector4D(linAxis2->sled_position,1));
//    qDebug()<<"main:"<<robotMat;
//    qDebug()<<robotMat.inverted();

//    QVector3D pointRobot,pointBase;
//    pointBase = linAxis2->sled_position + QVector3D(100,0,0);
//    pointRobot = QVector3D(robotMat.inverted() * pointBase);
//    qDebug()<<pointRobot;

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

    //Ebene zu Zeichnen


    Plane *plane = new Plane(700.0,450.0);
    plane->setTranslation(linAxis2->sled_position+QVector3D(-100,1000,500));
    // plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(-90,180,0)));
    plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(-90,180,0)) * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180));
    widget3d->addObject(plane);

    Robot *robot = new Robot("143.93.135.15",10001);


    RobotControl *robControl = new RobotControl(robot);
    robControl->show();

    robot->ConnectKinematik(robot2Kinematik);
//    robot->Connect();
//    robot->ServoOn(true);
//    robot->Write("1;1;EXECMVS P_Curr,-100");

//     CoordinateSystem *plane=new CoordinateSystem;
//     plane->setLength(200);
//     plane->setNegativeAxis(false);
//     plane->setTranslation(linAxis2->sled_position+QVector3D(500,-500,500));
//     plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(-90,180,0)));
// //    plane->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180));
//     widget3d->addObject(plane/*,linAxis2->sled_position+QVector3D(0,-500,700),QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),-90)*/);
//     qDebug()<<"trans"<<plane->translation();
// //    drawL->getPlane(static_cast<Qt3DCore::QTransform *>(plane));
     DrawLetters *drawL = new DrawLetters(robot2Kinematik,robot,linAxis2->sled_position,plane,widget3d);
     drawL->show();
    return a.exec();
}
