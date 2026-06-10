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
#include "robotdrawui.h"
#include "penholder.h"
#include "plane.h"
#include "robot.h"
#include "robotcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *PolarisGUI=new MainWindow;

    qDebug()<<"main Thread"<< QThread::currentThreadId();

    PolarisGUI->show();
    //Erstellen des Widgets -----------------------------------------------------------------------------------------
    Widget3D *widget3d = new Widget3D();
    widget3d->ShowAsSubWindow();
    PolarisGUI->connectWidget(widget3d);

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
    toolMesh->setSource("RefTool_Completev10.stl");
    toolMesh->setRotationZ(90);
    toolMesh->setTranslation(QVector3D(-14.4,-72.5-20,-7-5));
    // toolMesh->Material->setDiffuse(QColor(0,0,0));
    // widget3d->addObject(refTool,QVector3D(980,380,715),QQuaternion(1,0,0,0)/* * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),45)*//**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->addObject(refTool,QVector3D(1212.5+54,2867.5-150-10,695.921+12),QQuaternion(1,0,0,0)/* * QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),45)*//**//*QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),180)*/);
    widget3d->setRefMatrix(static_cast<Qt3DCore::QTransform*>(refTool->components()[1]));
    //position of ref tool, 300 in y , 40 in x
    widget3d->addCylinderBetweenPoints(QVector3D(1212.5-3,2745-50,695.921+25),QVector3D(1212.5-3,2745-50,695.921-20));
    widget3d->addCylinderBetweenPoints(QVector3D(1212.5+54,2867.5-150,695.921+25),QVector3D(1212.5+54,2867.5,695.921+25));
    widget3d->addCylinderBetweenPoints(QVector3D(1212.5+54,2867.5,695.921-100),QVector3D(1212.5+54,2867.5,695.921+25));
    // widget3d->addCylinderBetweenPoints(QVector3D(979.6+4.5,3628.75,695.921-30),QVector3D(979.6+4.5,3628.75,695.921+27));

    // widget3d->addCylinderBetweenPoints(QVector3D(988,3328.75,695.921+27),QVector3D(988,3328.75,695.921+20));

    // widget3d->addCylinderBetweenPoints(QVector3D(980,000,732),QVector3D(940,740,732));


    //Polaris als Koordinatensystem --------------------------------------------------------------
    CoordinateSystem *polaris=new CoordinateSystem;
    polaris->setLength(200);
    // polaris->setCoordLabel("Polaris",'X');
    polaris->setNegativeAxis(false);
    widget3d->addObject(polaris);
    widget3d->addTransPolaris(polaris);
    STLMesh* polarisMesh= new STLMesh(polaris);
    polarisMesh->setSource("PolarisDummy v7.stl");

//    STLMesh* mVolumeMesh= new STLMesh(polaris);
//    mVolumeMesh->setSource("mVolume.stl");
//    mVolumeMesh->setTranslation(QVector3D(0,0,-950));
//    mVolumeMesh->setRotationX(90);

//    Qt3DExtras::QDiffuseSpecularMaterial *material = new Qt3DExtras::QDiffusecSpecularMaterial();
//    material->setDiffuse(QColor(0, 0, 255, 200)); // semi-transparent red
//    material->setAlphaBlendingEnabled(true);
//    mVolumeMesh->addComponent(material);

//    material->setDiffuse(QColor(0,0,0,0));


//    // Apply material to mesh
//    mVolumeMesh->addComponent(material);


    //Calibrator als Koordinatensystem --------------------------------------------------------------
    CoordinateSystem *calibrator=new CoordinateSystem;
    calibrator->setLength(100);
    // polaris->setCoordLabel("Polaris",'X');
    calibrator->setNegativeAxis(false);
    widget3d->addObject(calibrator);
    widget3d->addTransCalibrator(calibrator);



    //Ebene zu Zeichnen
    Plane *plane = new Plane(650.0,850.0);
    widget3d->addObject(plane);
    widget3d->addPlane(plane);
    plane->setTranslation(linAxis->sled_position+QVector3D(-500,300,500));
    plane->setRotation(QQuaternion::fromEulerAngles(QVector3D(90.01,0,0)));
    plane->setRotation(plane->rotation() * QQuaternion::fromAxisAndAngle(QVector3D(0,1,0),90));

    Robot *robot = new Robot("143.93.135.15",10001);
    RobotControl *robControl = new RobotControl(robot);
    robControl->show();
    ControlPanel *control = new ControlPanel(robotKinematik);
    control->show();
    robot->ConnectKinematik(robotKinematik);
    RobotDrawUi *drawL = new RobotDrawUi(robotKinematik,robot,linAxis->sled_position,plane,widget3d,PolarisGUI,robControl);

    drawL->show();
//    drawL->getMaterial(material);
    return a.exec();
}
