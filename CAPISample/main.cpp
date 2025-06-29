#include "mainwindow.h"
#include <QApplication>
#include "linearaxisrv6sl.h"
#include "rv6slkinematik.h"
#include "rv4flkinematik.h"
#include "rv4fl.h"
#include "rv6sl.h"
#include "widget3d.h"
#include "coordinatesystem.h"
#include "kinectcamera.h"
#include "controlpanel.h"
#include "drawletters.h"
#include "robotdrawui.h"
#include "penholder.h"
#include "plane.h"
#include "robot.h"
#include "robotcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow;

    qDebug()<<"main Thread"<< QThread::currentThreadId();

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

    // Roboter Mesh mit Linearachse-----------------------------------------------------------------------------------------------
    RV6SL *robotMesh =new RV6SL();
    Rv6slKinematik *robotKinematik=new Rv6slKinematik(robotMesh);
    //Hinzufügen eines Tools in die Grafik
    Tool* penHolder = new PenHolder();
    penHolder->CoordSystem->thinOut(0.5);
    //Hinzufügen einer Linearachse
    LinearAxisRV6SL* linAxis = new LinearAxisRV6SL();
    robotMesh->addTool(penHolder);
    robotMesh->addLinearAxis(linAxis);
    robotKinematik->setTool(*static_cast<QMatrix4x4*>(penHolder));
    linAxis->set_sled_position(linAxis->rotation().toRotationMatrix());
    widget3d->setViewCenter(linAxis->sled_position + QVector3D(0,0,500));
    widget3d->addObject(robotMesh);

    //Referenz-Tools
    CoordinateSystem *refTool=new CoordinateSystem;
    refTool->setLength(100);
    refTool->setNegativeAxis(false);
    //Mesh des Referenz Tools
    STLMesh* toolMesh= new STLMesh(refTool);
    toolMesh->setSource("RefTool_Complete.stl");
    toolMesh->setRotationZ(90);
    toolMesh->setTranslation(QVector3D(-8.77,-72.5,-7));
    // toolMesh->Material->setDiffuse(QColor(0,0,0));
    // widget3d->addObject(refTool,QVector3D(980,380,715),QQuaternion(1,0,0,0)/* * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),45)*//**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->addObject(refTool,QVector3D(988,3338.75+9.95,695.921+7+20),QQuaternion(1,0,0,0)/* * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),45)*//**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->setRefMatrix(static_cast<Qt3DCore::QTransform*>(refTool->components()[1]));
    //position of ref tool, 300 in y , 40 in x
    widget3d->addCylinderBetweenPoints(QVector3D(988,3328.75,695.921),QVector3D(988,3628.75,695.921));
    widget3d->addCylinderBetweenPoints(QVector3D(988,3328.75,695.921),QVector3D(988,3328.75,695.921+20));

    // widget3d->addCylinderBetweenPoints(QVector3D(980,740,712),QVector3D(940,740,712));

    //Polaris als Koordinatensystem --------------------------------------------------------------
    CoordinateSystem *polaris=new CoordinateSystem;
    polaris->setLength(200);
    // polaris->setCoordLabel("Polaris",'X');
    polaris->setNegativeAxis(false);
    widget3d->addObject(polaris);
    widget3d->addTransPolaris(polaris);
    STLMesh* polarisMesh= new STLMesh(polaris);
    polarisMesh->setSource("PolarisDummy v7.stl");
    // CoordinateSystem *calibrator=new CoordinateSystem;
    // calibrator->setLength(100);
    // calibrator->setCoordLabel("Calibrator",'Z');
    // calibrator->setNegativeAxis(false);
    // widget3d->addObject(calibrator);
    // widget3d->addTransCalibrator(calibrator);

    //Ebene zu Zeichnen
    Plane *plane = new Plane(650.0,850.0);
    widget3d->addObject(plane);
    widget3d->addPlane(plane);
    plane->setTranslation(linAxis->sled_position+QVector3D(-500,800,500));
    plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(90.01,0,0)));
    plane->setRotation(plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90));
    Robot *robot = new Robot("143.93.135.15",10001);
    RobotControl *robControl = new RobotControl(robot);
    robControl->show();
    ControlPanel *control = new ControlPanel(robotKinematik);
    control->show();
    robot->ConnectKinematik(robotKinematik);
    RobotDrawUi *drawL = new RobotDrawUi(robotKinematik,robot,linAxis->sled_position,plane,widget3d);

    drawL->show();
    return a.exec();
}
