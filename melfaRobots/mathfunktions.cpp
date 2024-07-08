#include "mathfunktions.h"

QMatrix4x4 InversT(QMatrix4x4 t)

{
    //*******************************************
    //*******************************************
    // Inverse von T
    //*******************************************
    //*******************************************

    QVector4D v = t.column(3);
    t.setColumn(3,QVector4D(0,0,0,1));
    QMatrix4x4 tReturn = t.transposed();
    v = -tReturn*v;
    v.setW(1);
    tReturn.setColumn(3,v);
    return tReturn;
}

QMatrix4x4 CalculateT(double x, double y, double z, double EW1, double EW2, double EW3)

{
    //*******************************************
    //*******************************************
    // berechnet eine Transformationsmatrix im z,y,x System
    //*******************************************
    //*******************************************
    QMatrix4x4 tReturn;
    tReturn.setToIdentity();

    tReturn(0,0)=cos(EW3*M_PI/180)*cos(EW2*M_PI/180);
    tReturn(0,1)=cos(EW3*M_PI/180)*sin(EW2*M_PI/180)*sin(EW1*M_PI/180)-sin(EW3*M_PI/180)*cos(EW1*M_PI/180);
    tReturn(0,2)=cos(EW1*M_PI/180)*cos(EW3*M_PI/180)*sin(EW2*M_PI/180)+sin(EW1*M_PI/180)*sin(EW3*M_PI/180);

    tReturn(1,0)=sin(EW3*M_PI/180)*cos(EW2*M_PI/180);
    tReturn(1,1)=sin(EW3*M_PI/180)*sin(EW2*M_PI/180)*sin(EW1*M_PI/180)+cos(EW3*M_PI/180)*cos(EW1*M_PI/180);
    tReturn(1,2)=cos(EW1*M_PI/180)*sin(EW3*M_PI/180)*sin(EW2*M_PI/180)-sin(EW1*M_PI/180)*cos(EW3*M_PI/180);

    tReturn(2,0)=-sin(EW2*M_PI/180);
    tReturn(2,1)=sin(EW1*M_PI/180)*cos(EW2*M_PI/180);
    tReturn(2,2)=cos(EW1*M_PI/180)*cos(EW2*M_PI/180);

    tReturn.setColumn(3,QVector4D(x,y,z,1));
    for (int j=0;j<4;j++)
    {
        for (int k=0;k<4;k++)
        {
            if (fabs(tReturn(j,k))<0.001)
                tReturn(j,k)=0;
        }
    }
    return tReturn;
}

QVector3D CalculateEw(QMatrix4x4 mat)

{
    //*******************************************
    //*******************************************
    // berechnet die Eulerwinkel im z,y,x System
    //*******************************************
    //*******************************************
    double c=atan2(mat(1,0),mat(0,0));
    double b=atan2(-mat(2,0),mat(0,0)*cos(c)+mat(1,0)*sin(c));
    double a=atan2(mat(0,2)*sin(c)-mat(1,2)*cos(c),(mat(1,1)*cos(c)-mat(0,1)*sin(c)));
    a = qRadiansToDegrees(a);
    b = qRadiansToDegrees(b);
    c = qRadiansToDegrees(c);
    return QVector3D(a,b,c);
}

QVector3D CalculateXYZ(QMatrix4x4 m)

{
return QVector3D(m(0,3),m(1,3),m(2,3));
}

QMatrix4x4 CalculateTFromJoint(double q,double alpha,double a,double d)

{
    alpha=alpha*M_PI/180;
    q=q*M_PI/180;
    QMatrix4x4 tReturn( cos(q) ,-cos(alpha)*sin(q) , sin(alpha)*sin(q) ,a*cos(q),
                        sin(q) , cos(alpha)*cos(q) ,-sin(alpha)*cos(q) ,a*sin(q),
                        0.0    , sin(alpha)        , cos(alpha)        ,d,
                        0.0    ,0.0                ,0.0                ,1.0);

    for (int j=0;j<4;j++){
        for (int k=0;k<4;k++){
            if (fabs(tReturn(j,k))<0.001)
                tReturn(j,k)=0;
        }
    }
    return tReturn;
}

void RotatateT(QMatrix4x4* trans,int axis,double alpha)

{
    QMatrix4x4 rot;

    switch (axis)
    {
    case 0: rot.rotate(alpha,QVector3D(1,0,0));break;
    case 1: rot.rotate(alpha,QVector3D(0,1,0));break;
    case 2: rot.rotate(alpha,QVector3D(0,0,1));break;
    }
    trans->operator *=(rot);
}

const QMatrix4x4 MatrixTranslationX(double val){QMatrix4x4 t; t.setToIdentity();t(0,3)=val;return t;}
const QMatrix4x4 MatrixTranslationY(double val){QMatrix4x4 t; t.setToIdentity();t(1,3)=val;return t;}
const QMatrix4x4 MatrixTranslationZ(double val){QMatrix4x4 t; t.setToIdentity();t(2,3)=val;return t;}
const QMatrix4x4 MatrixRotationX(double val){QMatrix4x4 t; t.setToIdentity();t.rotate(val,1,0,0);return t;}
const QMatrix4x4 MatrixRotationY(double val){QMatrix4x4 t; t.setToIdentity();t.rotate(val,0,1,0);return t;}
const QMatrix4x4 MatrixRotationZ(double val){QMatrix4x4 t; t.setToIdentity();t.rotate(val,0,0,1);return t;}


