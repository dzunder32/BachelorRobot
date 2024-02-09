#include "rv6slkinematik.h"

Rv6slKinematik::Rv6slKinematik(QVector<Qt3DCore::QTransform*>* joints)
{
    _joints=joints;

    a1=85;a2=380;a3=-100;a4=0;a5=0;a6=0;
    d1=350;d2=0;d3=0;d4=425;d5=0;d6=85;
    alpha1=-90;alpha2=0;alpha3=90;alpha4=-90;alpha5=90;alpha6=0;

    j1Max=170;j1Min=-170;
    j2Max=135;j2Min=-92;
    j3Max=166;j3Min=-129;
    j4Max=160;j4Min=-160;
    j5Max=120;j5Min=-120;
    j6Max=360;j6Min=-360;
}

void Rv6slKinematik::updateView()
{
    if(_joints!=nullptr){
         _joints->at(0)->setRotationY(j1());
         _joints->at(1)->setRotationX(j2());
         _joints->at(2)->setRotationX(j3()-90);
         _joints->at(3)->setRotationZ(j4());
         _joints->at(4)->setRotationX(j5());
         _joints->at(5)->setRotationZ(j6());
        if(_joints->size()==7)
            _joints->at(6)->setTranslation(QVector3D(0,0,-j7()));
    }
}

void Rv6slKinematik::direct()
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
    int l_1,l_2,l_3;
    if( (-a2*cos((q2-90)*M_PI/180)-a3*cos((q2+q3-180)*M_PI/180)-d4*sin((q2+q3-180)*M_PI/180))<0)
        l_1=-1;
    else
        l_1=1;
    if((l_1*(d4*cos(q3*M_PI/180)-a3*sin(q3*M_PI/180)))<0)
        l_2=-1;
    else
        l_2=1;
    if(cos(q6*M_PI/180)!=0){
        if((cos(q6*M_PI/180))<0)
            l_3=-1;
        else
            l_3=1;}
    else{
        if((sin(q6*M_PI/180))<0)
            l_3=-1;
        else
            l_3=1;}
    if(l_1==-1)
        l_1=0;
    if(l_2==-1)
        l_2=0;
    if(l_3==-1)
        l_3=0;
    flag1=l_3*pow(2,0)+l_2*pow(2,1)+l_1*pow(2,2);

    //Computate Flg2
    QString flg2AsHexa="0000000";
    if (fabs(q6)>180){
        if (q6>180)
            flg2AsHexa.replace(2,1,"1");
        else
            flg2AsHexa.replace(2,1,"F");
    }
    bool ok;
    flag2=flg2AsHexa.toUInt(&ok,16);


    //**************************************************************************
    // Output
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

void Rv6slKinematik::invers()
{
    // Define In- and Output
    double cX,cY,cZ,cA,cB,cC,cL1;//Koordinaten       (Eingabe)
    unsigned int flag1,flag2;    //Konfiguration     (Eingabe)
    double q1,q2,q3,q4,q5,q6,q7; //Gelenkwinkel      (Ausgabe)

    //Input
    cX=x();cY=y();cZ=z();cA=_a;cB=b();cC=c();cL1=l1();flag1=flg1();flag2=flg2();

    //**************************************************************************
    //Flg1 and Flg2
    int f[3];
    switch (flag1) {
    case 0:{f[0]=-1; f[1]=-1; f[2]=-1; break;}
    case 1:{f[0]=-1; f[1]=-1; f[2]=1;  break;}
    case 2:{f[0]=-1; f[1]=1;  f[2]=-1; break;}
    case 3:{f[0]=-1; f[1]=1;  f[2]=1;  break;}
    case 4:{f[0]=1;  f[1]=-1; f[2]=-1; break;}
    case 5:{f[0]=1;  f[1]=-1; f[2]=1;  break;}
    case 6:{f[0]=1;  f[1]=1;  f[2]=-1; break;}
    case 7:{f[0]=1;  f[1]=1;  f[2]=1;  break;}
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

    // Auxiliary variables
    bool ePointReachable;
    double t,chi,sq4,cq4,sq5,cq5,sq6,cq6,l_e1;
    double alpha,beta,singamma,cosgamma,gamma;
    QVector3D x3,y3,z3,x4,y4,z4,y5,cross_z3_a;
    QVector4D n,s,a,p;
    QVector4D e_0, e_1, e_2;
    QMatrix4x4 T,Ti;

    // Computate Transformationsmatrix + Tool Transformation
    T.setToIdentity();
    Ti.setToIdentity();
    T=CalculateT(cX,cY,cZ,cA,cB,cC);
    T=T*InversT(_toolTransformationMatrix);

    //T=[n s a p]
    n=T.column(0);
    s=T.column(1);
    a=T.column(2);
    p=T.column(3);

    //------------------------------------Q1------------------------------------
    e_0=p-d6*a;
    t=sqrt(pow(a3,2)+pow(d4,2));
    chi=atan2(d4,(-a3));

    q1=(atan2(f[0]*e_0.y(),f[0]*e_0.x()))*180/M_PI;

    Ti=Ti*CalculateTFromJoint(q1,alpha1,a1,d1);
    //------------------------------------Q2------------------------------------
    e_1 = Ti.inverted() * e_0;
    l_e1 = sqrt(pow(e_1.x(),2) + pow(e_1.y(),2) +pow(e_1.z(),2));
    alpha = atan2(e_1.y(),e_1.x());
    cosgamma = (pow(t,2)-pow(l_e1,2)-pow(a2,2))/(-2*l_e1*a2);
    singamma = sqrt(1-pow(cosgamma,2));
    gamma = atan2(singamma,cosgamma);

    q2 =(M_PI/2 - f[1] * gamma + alpha)*180/M_PI;

    Ti=Ti*CalculateTFromJoint(q2-90,alpha2,a2,d2);

    // If the E-Point is not reachable there is no solution for the angles
    if( l_e1 > (a2+t) )
        ePointReachable = false;
    else
        ePointReachable = true;
    //------------------------------------Q3------------------------------------   
    e_2 = Ti.inverted() * e_0;
    beta = atan2(e_2.y(),e_2.x());

    q3 =(M_PI/2 + beta - chi)*180/M_PI;

    Ti=Ti*CalculateTFromJoint(q3+90,alpha3,a3,d3);
    //------------------------------------Q4------------------------------------
    x3=Ti.column(0).toVector3D();
    y3=Ti.column(1).toVector3D();
    z3=Ti.column(2).toVector3D();
    cross_z3_a=QVector3D::crossProduct(z3,a.toVector3D());

    if (cross_z3_a.length()<1e-10)
    {
        // Singularity
        q4=0;
    }
    else
    {
        // No Singularity
        z4 = f[2] * cross_z3_a / cross_z3_a.length();
        sq4 = QVector3D::dotProduct(-z4,x3);
        cq4 = QVector3D::dotProduct(z4,y3);
        q4 = atan2(sq4,cq4)*180/M_PI;
    }

    Ti=Ti*CalculateTFromJoint(q4,alpha4,a4,d4);
    //------------------------------------Q5------------------------------------
    if(cross_z3_a.length()<1e-10)
    {
        // Singularity
        q5=0;
    }
    else
    {
        x4 = Ti.column(0).toVector3D();
        y4 = Ti.column(1).toVector3D();

        sq5 = QVector3D::dotProduct(a.toVector3D(),x4);
        cq5 = QVector3D::dotProduct(-a.toVector3D(),y4);
        q5=atan2(sq5,cq5)*180/M_PI;
    }

    Ti=Ti*CalculateTFromJoint(q5,alpha5,a5,d5);
    //------------------------------------Q6------------------------------------
    y5 = Ti.column(1).toVector3D();
    sq6 = QVector3D::dotProduct(n.toVector3D(),y5);
    cq6 = QVector3D::dotProduct(s.toVector3D(),y5);


    q6 = atan2(sq6,cq6)*180/M_PI;

    if (flg2AsHexa.at(2)=='F')
        q6-=360;
    else if (flg2AsHexa.at(2)=='1')
        q6+=360;

    Ti=Ti*CalculateTFromJoint(q6,alpha6,a6,d6);
    //------------------------------------Q7------------------------------------
    q7=cL1;

    //**************************************************************************
    // Output

    if(ePointReachable)
    {
        _j1=((int)(q1*1000))/(double)1000.0;
        _j2=((int)(q2*1000))/(double)1000.0;
        _j3=((int)(q3*1000))/(double)1000.0;
        _j4=((int)(q4*1000))/(double)1000.0;
        _j5=((int)(q5*1000))/(double)1000.0;
        _j6=((int)(q6*1000))/(double)1000.0;
        _j7=((int)(q7*1000))/(double)1000.0;
//        qDebug()<<_j1<<_j2<<_j3<<_j4<<_j5<<_j6;
    }
    else
        qDebug()<<"E-Point is not reachable";

}

