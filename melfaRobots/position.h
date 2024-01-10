#ifndef POSITION_H
#define POSITION_H
#include <QObject>
#include <QMatrix4x4>

class Position:public QObject
{
public:
    double x() const{return _x;}
    double y() const{return _y;}
    double z() const{return _z;}
    double a() const{return _a;}
    double b() const{return _b;}
    double c() const{return _c;}
    double l1() const{return _l1;}
    double flg1() const{return _flg1;}
    double flg2() const{return _flg2;}

    void setX(double var){_x=var;}
    void setY(double var){_y=var;}
    void setZ(double var){_z=var;}
    void setA(double var){_a=var;}
    void setB(double var){_b=var;}
    void setC(double var){_c=var;}
    void setL1(double var){_l1=var;}
    void setFlg1(unsigned int var){_flg1=var;}
    void setFlg2(unsigned int var){_flg2=var;}

    double j1() const{return _j1;}
    double j2() const{return _j2;}
    double j3() const{return _j3;}
    double j4() const{return _j4;}
    double j5() const{return _j5;}
    double j6() const{return _j6;}
    double j7() const{return _j7;}

    void setJ1(double var){_j1=var;}
    void setJ2(double var){_j2=var;}
    void setJ3(double var){_j3=var;}
    void setJ4(double var){_j4=var;}
    void setJ5(double var){_j5=var;}
    void setJ6(double var){_j6=var;}
    void setJ7(double var){_j7=var;}

protected:
    double _x,_y,_z,_a,_b,_c,_l1;
    unsigned int _flg1,_flg2;
    double _j1,_j2,_j3,_j4,_j5,_j6,_j7;


};
#endif // POSITION_H
