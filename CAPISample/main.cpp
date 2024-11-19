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


    //2. Roboter Mesh -----------------------------------------------------------------------------------------------
    RV6SL *robot2 =new RV6SL();
    Rv6slKinematik *robot2Kinematik=new Rv6slKinematik(robot2);
    //Hinzufügen eines Tools in die Grafik
    Tool* penHolder = new PenHolder();
    penHolder->CoordSystem->thinOut(0.5);
    //Hinzufügen einer Linearachse
    LinearAxisRV6SL* linAxis2 = new LinearAxisRV6SL();
    robot2->addTool(penHolder);
    robot2->addLinearAxis(linAxis2);
    robot2Kinematik->setTool(*static_cast<QMatrix4x4*>(penHolder));
    linAxis2->set_sled_position(linAxis2->rotation().toRotationMatrix());
    widget3d->setViewCenter(linAxis2->sled_position + QVector3D(0,0,500));
    widget3d->addObject(robot2);


    //Referenz-Tools
    CoordinateSystem *refTool=new CoordinateSystem;
    refTool->setLength(100);
    refTool->setNegativeAxis(false);
    //Mesh des Referenz Tools
    STLMesh* toolMesh= new STLMesh(refTool);
    toolMesh->setSource("RefTool_C.STL");
    toolMesh->setRotationZ(90);
    toolMesh->setTranslation(QVector3D(-8.77,-72.5,-7));
    widget3d->addObject(refTool,QVector3D(980,380,712),/*QQuaternion(1,0,0,0) * */QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),45)/**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->setRefMatrix(static_cast<Qt3DCore::QTransform*>(refTool->components()[1]));
    //position of ref tool, 300 in y , 40 in x
    widget3d->addCylinderBetweenPoints(QVector3D(980,380,712),QVector3D(980,740,712));
    widget3d->addCylinderBetweenPoints(QVector3D(980,740,712),QVector3D(940,740,712));


    //Polaris als Koordinatensystem --------------------------------------------------------------
    CoordinateSystem *polaris=new CoordinateSystem;
    polaris->setLength(200);
    polaris->setCoordLabel("Polaris",'X');
    polaris->setNegativeAxis(false);
    widget3d->addObject(polaris);
    widget3d->addTransPolaris(polaris);




    //Ebene zu Zeichnen
    Plane *plane = new Plane(650.0,850.0);
    widget3d->addObject(plane);
    widget3d->addPlane(plane);
    plane->setTranslation(linAxis2->sled_position+QVector3D(0,800,500));
    plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(90.01,0,0)));


    Robot *robot = new Robot("143.93.135.15",10001);
    RobotControl *robControl = new RobotControl(robot);
    robControl->show();
    ControlPanel *control = new ControlPanel(robot2Kinematik);
    control->show();
    robot->ConnectKinematik(robot2Kinematik);
    RobotDrawUi *drawL = new RobotDrawUi(robot2Kinematik,robot,linAxis2->sled_position,plane,widget3d);

    CoordinateSystem *calibrator=new CoordinateSystem;
    calibrator->setLength(100);
    calibrator->setCoordLabel("Calibrator",'Z');
    calibrator->setNegativeAxis(false);
    widget3d->addObject(calibrator);
    widget3d->addTransCalibrator(calibrator);


    drawL->show();
    return a.exec();
}
