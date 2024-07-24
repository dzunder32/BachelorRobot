#include "robotPosition.h"

void RobotPosition::setJoints(double j1, double j2, double j3 , double j4 , double j5, double j6, double j7)
{
   _oldJ1=_j1,_oldJ2=_j2,_oldJ3=_j3,_oldJ4=_j4,_oldJ5=_j5,_oldJ6=_j6;_oldJ7=_j7;
   _j1=j1,_j2=j2,_j3=j3,_j4=j4,_j5=j5,_j6=j6;_j7=j7;
   _updateJoints();
}

void RobotPosition::setPoint(double x, double y, double z , double a , double b, double c, double l1)
{
   _oldX=_x,_oldY=_y,_oldZ=_z,_oldA=_a,_oldB=_b,_oldC=_c;_oldL1=_l1;
   _x=x    ,_y=y    ,_z=z     ,_a=a   ,_b=b    ,_c=c     ;_l1=l1;
   _updateKart();
}

void RobotPosition::setX(double val){if(isEqual(val,_x,0.001)){_oldX=_x;_x = val;emit xChanged(_x);}}
void RobotPosition::setY(double val){if(isEqual(val,_y,0.001)){_oldY=_y;_y = val;emit yChanged(_y);}}
void RobotPosition::setZ(double val){if(isEqual(val,_z,0.001)){_oldZ=_z;_z = val;emit zChanged(_z);}}
void RobotPosition::setA(double val){if(isEqual(val,_a,0.001)){_oldA=_a;_a = val;emit aChanged(_a);}}
void RobotPosition::setB(double val){if(isEqual(val,_b,0.001)){_oldB=_b;_b = val;emit bChanged(_b);}}
void RobotPosition::setC(double val){if(isEqual(val,_c,0.001)){_oldC=_c;_c = val;emit cChanged(_c);}}
void RobotPosition::setL1(double val){if(isEqual(val,_l1,0.001)){_oldL1=_l1;_l1 = val;emit l1Changed(_l1);}}
void RobotPosition::setFlg1(unsigned int val){if(val !=_flg1){_oldFlg1=_flg1;_flg1 = val;emit flg1Changed(_flg1);}}
void RobotPosition::setFlg2(unsigned int val){if(val !=_flg2){_oldFlg2=_flg2;_flg2 = val;emit flg2Changed(_flg2);}}

void RobotPosition::setJ1(double val){if(isEqual(val,_j1,0.001)){_oldJ1=_j1;_j1 = val;_positionReached=false;emit j1Changed(_j1);}}
void RobotPosition::setJ2(double val){if(isEqual(val,_j2,0.001)){_oldJ2=_j2;_j2 = val;_positionReached=false;emit j2Changed(_j2);}}
void RobotPosition::setJ3(double val){if(isEqual(val,_j3,0.001)){_oldJ3=_j3;_j3 = val;_positionReached=false;emit j3Changed(_j3);}}
void RobotPosition::setJ4(double val){if(isEqual(val,_j4,0.001)){_oldJ4=_j4;_j4 = val;_positionReached=false;emit j4Changed(_j4);}}
void RobotPosition::setJ5(double val){if(isEqual(val,_j5,0.001)){_oldJ5=_j5;_j5 = val;_positionReached=false;emit j5Changed(_j5);}}
void RobotPosition::setJ6(double val){if(isEqual(val,_j6,0.001)){_oldJ6=_j6;_j6 = val;_positionReached=false;emit j6Changed(_j6);}}
void RobotPosition::setJ7(double val){if(isEqual(val,_j7,0.001)){_oldJ7=_j7;_j7 = val;_positionReached=false;emit j7Changed(_j7);}}


void RobotPosition::_updateJoints()
{
    _positionReached=false;
    emit jointsChanged();
}

void RobotPosition::_updateKart()
{
    emit kartChanged();
}

bool RobotPosition::isEqual(double a,double b,double epsilon)
{
    return !(abs(a-b) <= epsilon);
}

void RobotPosition::WaitForPositionReached()
{
    while(_positionReached==false)
    {
        qDebug()<<"waiting for position to get Reached";
        qDebug()<<QThread::currentThreadId();
    }
}
