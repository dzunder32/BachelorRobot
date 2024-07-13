#ifndef KINEMATIK_H
#define KINEMATIK_H

#include "robotPosition.h"
#include <Qt3DCore>

namespace Transformations
{
enum ToolMovement{X,Y,Z,A,B,C};
}

class Kinematik: public RobotPosition
{
protected:
    // Joint limits
    double j1Min,j1Max;
    double j2Min,j2Max;
    double j3Min,j3Max;
    double j4Min,j4Max;
    double j5Min,j5Max;
    double j6Min,j6Max;

    //DH-Parameter
    double a1,a2,a3,a4,a5,a6;
    double d1,d2,d3,d4,d5,d6;
    double alpha1,alpha2,alpha3,alpha4,alpha5,alpha6;

public:
    virtual void direct()=0;
    virtual void invers()=0;

    void setTool(QMatrix4x4 tool);
    void ToolMovement(Transformations::ToolMovement movementDirection,double inc);

    void setX(double var){RobotPosition::setX(var);invers();_updateJoints();updateView();}
    void setY(double var){RobotPosition::setY(var);invers();_updateJoints();updateView();}
    void setZ(double var){RobotPosition::setZ(var);invers();_updateJoints();updateView();}
    void setA(double var){RobotPosition::setA(var);invers();_updateJoints();updateView();}
    void setB(double var){RobotPosition::setB(var);invers();_updateJoints();updateView();}
    void setC(double var){RobotPosition::setC(var);invers();_updateJoints();updateView();}
    void setL1(double var){RobotPosition::setL1(var);invers();_updateJoints();updateView();}
    void setFlg1(unsigned int var){RobotPosition::setFlg1(var);invers();_updateJoints();updateView();}
    void setFlg2(unsigned int var){RobotPosition::setFlg2(var);invers();_updateJoints();updateView();}

    void setJ1(double var){RobotPosition::setJ1(var);direct();_updateKart();updateView();}
    void setJ2(double var){RobotPosition::setJ2(var);direct();_updateKart();updateView();}
    void setJ3(double var){RobotPosition::setJ3(var);direct();_updateKart();updateView();}
    void setJ4(double var){RobotPosition::setJ4(var);direct();_updateKart();updateView();}
    void setJ5(double var){RobotPosition::setJ5(var);direct();_updateKart();updateView();}
    void setJ6(double var){RobotPosition::setJ6(var);direct();_updateKart();updateView();}
    void setJ7(double var){RobotPosition::setJ7(var);direct();_updateKart();updateView();}

    void setJoints(double j1,double j2, double j3 ,double j4 ,double j5, double j6, double j7){RobotPosition::setJoints(j1,j2,j3,j4,j5,j6,j7);direct();_updateKart();updateView();}
    void setPoint(double x,double y, double z ,double a ,double b, double c, double l1){RobotPosition::setPoint(x,y,z,a,b,c,l1);invers();_updateJoints();updateView();}
    void setTransformationMatrix(QMatrix4x4 T){QVector3D ew=CalculateEw(T);QVector3D xyz=CalculateXYZ(T);setPoint(xyz.x(),xyz.y(),xyz.z(),ew.x(),ew.y(),ew.z(),l1());}

    QVector<Qt3DCore::QTransform*>* getTransformObjectJoints(){return _joints;}
    QVector<Qt3DCore::QTransform*>* _joints;
    bool ePointReachable;

    double getJ1Max(){return j1Max;} double getJ1Min(){return j1Min;}
    double getJ2Max(){return j2Max;} double getJ2Min(){return j2Min;}
    double getJ3Max(){return j3Max;} double getJ3Min(){return j3Min;}
    double getJ4Max(){return j4Max;} double getJ4Min(){return j4Min;}
    double getJ5Max(){return j5Max;} double getJ5Min(){return j5Min;}
    double getJ6Max(){return j6Max;} double getJ6Min(){return j6Min;}


};

#endif // KINEMATIK_H
