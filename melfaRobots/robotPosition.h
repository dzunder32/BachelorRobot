#ifndef ROBOTPOSITION_H
#define ROBOTPOSITION_H
#include "position.h"
#include "mathfunktions.h"

class RobotPosition: public Position
{
    Q_OBJECT
public:
    bool isEqual(double,double,double);

    void setJoints(double j1,double j2, double j3 ,double j4 ,double j5, double j6,double _j7);
    void setPoint(double x, double y, double z , double a , double b, double c, double l1);

    void setX(double var) ;
    void setY(double var) ;
    void setZ(double var) ;
    void setA(double var) ;
    void setB(double var) ;
    void setC(double var) ;
    void setL1(double var) ;
    void setFlg1(unsigned int var) ;
    void setFlg2(unsigned int var) ;

    void setJ1(double var) ;
    void setJ2(double var) ;
    void setJ3(double var) ;
    void setJ4(double var) ;
    void setJ5(double var) ;
    void setJ6(double var) ;
    void setJ7(double var) ;

    void WaitForPositionReached();
    void Reached(){_positionReached=true;}

    QMatrix4x4 getTransformationMatrix(){return CalculateT(x(),y(),z(),a(),b(),c());}

    virtual void updateView()=0;

protected:
    double _oldJ1,_oldJ2,_oldJ3,_oldJ4,_oldJ5,_oldJ6,_oldJ7;
    double _oldX,_oldY,_oldZ,_oldA,_oldB,_oldC,_oldL1;
    unsigned int _oldFlg1,_oldFlg2;
    bool _positionReached=true;
    QMatrix4x4 _toolTransformationMatrix;
    void _updateJoints();
    void _updateKart();

signals:
    void xChanged(double);
    void yChanged(double);
    void zChanged(double);
    void aChanged(double);
    void bChanged(double);
    void cChanged(double);
    void l1Changed(double);
    void flg1Changed(unsigned int);
    void flg2Changed(unsigned int);

    void j1Changed(double);
    void j2Changed(double);
    void j3Changed(double);
    void j4Changed(double);
    void j5Changed(double);
    void j6Changed(double);
    void j7Changed(double);

    void jointsChanged();
    void kartChanged();
    void updateRobot();
    void updateRobotFromUi();
};

#endif // ROBOTPOSITION_H
