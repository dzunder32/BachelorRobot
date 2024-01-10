#include "rv4flkinematik.h"

Rv4flKinematik::Rv4flKinematik(QVector<Qt3DCore::QTransform*>* joints)
{
    _joints=joints;

    a1=0;a2=310;a3=-50;a4=0;a5=0;a6=0;
    d1=350;d2=0;d3=0;d4=335;d5=0;d6=0;
    alpha1=-90;alpha2=0;alpha3=90;alpha4=-90;alpha5=90;alpha6=0;

    j1Max=240;j1Min=-240;
    j2Max=120;j2Min=-120;
    j3Max=161;j3Min=0;
    j4Max=200;j4Min=-200;
    j5Max=120;j5Min=-120;
    j6Max=360;j6Min=-360;
}

void Rv4flKinematik::updateView()
{
      if(_joints!=nullptr){
        _joints->at(0)->setRotationY(j1());
        _joints->at(1)->setRotationZ(j2());
        _joints->at(2)->setRotationZ(j3()-90);
        _joints->at(3)->setRotationX(j4());
        _joints->at(4)->setRotationZ(j5());
        _joints->at(5)->setRotationZ(j6());
        if(_joints->size()==7)
            _joints->at(6)->setTranslation(QVector3D(0,0,j7()));
      }

}

void Rv4flKinematik::direct()
{
    //Define In- and Output
    double q1,q2,q3,q4,q5,q6,q7;    //Gelenkwinkel  (Eingabe)
    double cX,cY,cZ,cA,cB,cC,cL1;   //Koordinaten   (Ausgabe)
    unsigned int flag1 = 0,flag2=0; //Konfiguration (Ausgabe)

    //Input
    q1=j1();q2=j2();q3=j3();q4=j4();q5=j5();q6=j6();q7=j7();

    //**************************************************************************
    QMatrix4x4 T;
    T.setToIdentity();

    //Computate Transformationmatrix
    q2-=90;
    q3+=90;
    T=T*CalculateTFromJoint(q1,alpha1,a1,d1);
    T=T*CalculateTFromJoint(q2,alpha2,a2,d2);
    T=T*CalculateTFromJoint(q3,alpha3,a3,d3);
    T=T*CalculateTFromJoint(q4,alpha4,a4,d4);
    T=T*CalculateTFromJoint(q5,alpha5,a5,d5);
    T=T*CalculateTFromJoint(q6,alpha6,a6,d6);
    q2+=90;
    q3-=90;

    T=T*_toolTransformationMatrix;

    //Round
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (fabs(T(i,j))<0.001)
                T(i,j)=0;
        }
    }

    //Computate Eulerwinkel with Transformationmatrix
    cX=T(0,3);
    cY=T(1,3);
    cZ=T(2,3);
    cC=atan2(T(1,0),T(0,0));
    cB=atan2(-T(2,0),T(0,0)*cos(cC)+T(1,0)*sin(cC))*180/M_PI;
    cA=atan2(T(0,2)*sin(cC)-T(1,2)*cos(cC),(T(1,1)*cos(cC)-T(0,1)*sin(cC)))*180/M_PI;
    cC=cC*180/M_PI;
    cL1 = q7;

    //Computate Flg1
    if ((-a3*cos((q2+q3-180)*M_PI/180)-d4*sin((q2+q3-180)*M_PI/180)+a2*cos((q2-90) * M_PI/180))<0)
        flag1=0;
    else
        flag1=4;
    if (q3<atan2 (-a3,d4) *180/M_PI)
        flag1+=0;
    else
        flag1+=2;
    if (q5<0)
        flag1+=0;
    else
        flag1+=1;

    //Computate Flg2
    QString flg2AsHexa="0000000";
    if (fabs(q6)>180){
        if (q6>180)
            flg2AsHexa.replace(2,1,"1");
        else
            flg2AsHexa.replace(2,1,"F");
    }
    if (fabs(q4)>180){
        if (q4>180)
            flg2AsHexa.replace(4,1,"1");
        else
            flg2AsHexa.replace(4,1,"F");
    }
    if (fabs(q1)>180){
        if (q1>180)
            flg2AsHexa.replace(7,1,"1");
        else
            flg2AsHexa.replace(7,1,"F");
    }

    bool ok;
    flag2=flg2AsHexa.toUInt(&ok,16);

    //**************************************************************************
    //Output
    _x=((int)(cX*1000))/(double)1000.0;
    _y=((int)(cY*1000))/(double)1000.0;
    _z=((int)(cZ*1000))/(double)1000.0;
    _a=((int)(cA*1000))/(double)1000.0;
    _b=((int)(cB*1000))/(double)1000.0;
    _c=((int)(cC*1000))/(double)1000.0;
    _l1=((int)(cL1*1000))/(double)1000.0;
    _flg1=flag1;
    _flg2=flag2;
}

void Rv4flKinematik::invers()
{
    // Define In- and Output
    double cX,cY,cZ,cA,cB,cC,cL1;//Koordinaten       (Eingabe)
    unsigned int flag1,flag2;    //Konfiguration     (Eingabe)
    double q1,q2,q3,q4,q5,q6,q7; //Gelenkwinkel      (Ausgabe)

    //Input
    cX=x();cY=y();cZ=z();cA=RobotPosition::a();cB=b();cC=c();cL1=l1();flag1=flg1();flag2=flg2();

    //**************************************************************************
    // Flg1 and Flg2
    int f[3];
    switch (flag1) {
    case 0:{f[0]=-1; f[1]=1;  f[2]=-1; break;}
    case 1:{f[0]=-1; f[1]=1;  f[2]=1;  break;}
    case 2:{f[0]=-1; f[1]=-1; f[2]=-1; break;}
    case 3:{f[0]=-1; f[1]=-1; f[2]=1;  break;}
    case 4:{f[0]=1;  f[1]=1;  f[2]=-1; break;}
    case 5:{f[0]=1;  f[1]=1;  f[2]=1;  break;}
    case 6:{f[0]=1;  f[1]=-1; f[2]=-1; break;}
    case 7:{f[0]=1;  f[1]=-1; f[2]=1;  break;}
    }
    QString flg2AsHexa;
    flg2AsHexa.setNum(flag2,16);
    flg2AsHexa=flg2AsHexa.toUpper();
    if (flg2AsHexa.length()<7)
    {
        for (int i=flg2AsHexa.length();i<7;i++)
        {
            flg2AsHexa.prepend("0");
        }
    }

    // Computate Transformationsmatrix + Tool Transformation
    QMatrix4x4 T,Ti;
    T.setToIdentity();
    Ti.setToIdentity();
    T=CalculateT(cX,cY,cZ,cA,cB,cC);
    T=T*InversT(_toolTransformationMatrix);

    // Computate e-point
    auto temp = T.column(3)-d6*T.column(2);
    QVector3D e(temp.x(),temp.y(),temp.z());

    double r,R;
    R=pow((e.z()-d1),2)+pow(e.x(),2)+pow(e.y(),2);
    r=sqrt(pow(a3,2)+pow(d4,2));
    double alph,beta;

    //------------------------------------Q1------------------------------------
    q1= atan2 (f[0]*e.y(),f[0]*e.x()) *180/M_PI;

    if (fabs(q1)<0.001)
        q1=0;
    if (flg2AsHexa[(5)]=='F')
        q1-=360;
    else if (flg2AsHexa[(5)]=='1')
        q1+=360;

    Ti=Ti*CalculateTFromJoint(q1,alpha1,a1,d1);
    //------------------------------------Q2------------------------------------
    alph=atan2(f[0]*sqrt(pow(e.x(),2)+pow(e.y(),2))/sqrt(R),(e.z()-d1)/sqrt(R)) *180/M_PI;
    beta=atan2 (sqrt(1-pow(((pow(r,2)-R-pow(a2,2))/(-2*a2*sqrt(R))),2)),(pow(r,2)-R-pow(a2,2))/(-2*a2*sqrt(R)))*180/M_PI;
    q2=alph+f[1]*beta;

    if (fabs(q2)<0.001 || q2==360)
        q2=0;
    if (flg2AsHexa[(4)]=='F')
        q2-=360;
    else if (flg2AsHexa[(4)]=='1')
        q2+=360;

    Ti=Ti*CalculateTFromJoint(q2-90,alpha2,a2,d2);
    //------------------------------------Q3------------------------------------
    alph=atan2 (sqrt(1-pow((R-pow(r,2)-pow(a2,2))/(-2*a2*r),2)),f[1]*(R-pow(r,2)-pow(a2,2))/(-2*a2*r)) *180/M_PI;
    beta=atan2 (d4/r,-a3/r) *180/M_PI;
    q3=alph-beta-f[1]*90;

    if (fabs(q3)<0.001 || q3==360)
        q3=0;
    if (flg2AsHexa[(3)]=='F')
        q3-=360;
    else if (flg2AsHexa[(3)]=='1')
        q3+=360;

    Ti=Ti*CalculateTFromJoint(q3+90,alpha3,a3,d3);
    //Eulerhand
    QVector3D x3=Ti.column(0).toVector3D();
    QVector3D y3=Ti.column(1).toVector3D();
    QVector3D z3=Ti.column(2).toVector3D();
    QVector3D n(T(0,0),T(1,0),T(2,0));
    QVector3D s(T(0,1),T(1,1),T(2,1));
    QVector3D a_1(T(0,2),T(1,2),T(2,2));

    QVector3D Cross=QVector3D::crossProduct(z3,a_1);
    //------------------------------------Q4------------------------------------
    if (Cross.length()<1e-10)
    {
        // Singularity
        q4=0;
    }
    else
    {
        // No Singularity
        QVector3D z4;
        z4.setX(fabs(Cross.x()/(sqrt(pow(Cross.x(),2)+pow(Cross.y(),2)+pow(Cross.z(),2)))));
        z4.setY(fabs(Cross.y()/(sqrt(pow(Cross.x(),2)+pow(Cross.y(),2)+pow(Cross.z(),2)))));
        z4.setZ(fabs(Cross.z()/(sqrt(pow(Cross.x(),2)+pow(Cross.y(),2)+pow(Cross.z(),2)))));
        q4=atan2(f[2]*QVector3D::dotProduct(-Cross,x3),f[2]*QVector3D::dotProduct(Cross,y3))*180/M_PI;
    }

    if (flg2AsHexa[(2)]=='F')
        q4-=360;
    else if (flg2AsHexa[(2)]=='1')
        q4+=360;

    Ti=Ti*CalculateTFromJoint(q4,alpha4,a4,d4);
    //------------------------------------Q5------------------------------------
    if(Cross.length()<1e-10)
    {
        // Singularity
        q5=0;
    }
    else
    {
        // No Singularity
        QVector3D x4(Ti(0,0),Ti(1,0),Ti(2,0));
        QVector3D y4(Ti(0,1),Ti(1,1),Ti(2,1));
        q5=atan2(QVector3D::dotProduct(a_1,x4),QVector3D::dotProduct(-a_1,y4))*180/M_PI;
        if (fabs(q5)<0.001)
            q5=0;
    }
    if (flg2AsHexa[(1)]=='F')
        q5-=360;
    else if (flg2AsHexa[(1)]=='1')
        q5+=360;

    Ti=Ti*CalculateTFromJoint(q5,alpha5,a5,d5);
    //------------------------------------Q6------------------------------------
    QVector3D y5(Ti(0,1),Ti(1,1),Ti(2,1));
    q6=atan2(QVector3D::dotProduct(n,y5),QVector3D::dotProduct(s,y5)) *180/M_PI;

    if (fabs(q6)<0.001 )
        q6=0;
    if (flg2AsHexa[(0)]=='F')
        q6-=360;
    else if (flg2AsHexa[(0)]=='1')
        q6+=360;

    Ti=Ti*CalculateTFromJoint(q6,alpha6,a6,d6);
    //------------------------------------Q7------------------------------------
    q7=cL1;

    //**************************************************************************
    // Output
    _j1=((int)(q1*1000))/(double)1000.0;
    _j2=((int)(q2*1000))/(double)1000.0;
    _j3=((int)(q3*1000))/(double)1000.0;
    _j4=((int)(q4*1000))/(double)1000.0;
    _j5=((int)(q5*1000))/(double)1000.0;
    _j6=((int)(q6*1000))/(double)1000.0;
    _j7=((int)(q7*1000))/(double)1000.0;
}

