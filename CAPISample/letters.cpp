#include "letters.h"

Letters::Letters()
{
    scalingFactor = 1;
    createLetters();
}

void Letters::createLetters()
{
    // F.append(QVariantList(QVariant ,QVariant))
    F = {{QVector3D(0,0,0),QVector3D(1,0,0)},
         {QVector3D(0,100,0),QVector3D(100,100,0)},
         {QVector3D(0,50,0),QVector3D(100,50,0)}};

    // B = {{QVector3D(0,0,0),QVector3D(0,100,0)},
    //      {QVector3D(0,100,0),QVector3D(100,100,0)},
    //      {QVector3(0,50,0),QVector3D(100,50,0)}};
    float factorB =  100/3.5;
    // QVariantList addString;
    // addString<<"B";
    // B.append(addString);

    str_LetterVector.append('B');
    addLine2Letter(B, QVector2D(0,0), QVector2D(1,0),factorB);
    addCircle2Letter(B,1 , QVector2D(1,1),QVector2D(-90,90),factorB);
    addLine2Letter(B, QVector2D(1,2), QVector2D(0,2),factorB);
    addLine2Letter(B, QVector2D(0,2), QVector2D(1,2),factorB);
    addCircle2Letter(B,0.75, QVector2D(1,2.75),QVector2D(-90,90),factorB);
    addLine2Letter(B, QVector2D(1,3.5), QVector2D(0,3.5),factorB);
    addLine2Letter(B, QVector2D(0,3.5), QVector2D(0,0),factorB);

    m_Letters.append(B);

    qDebug()<<m_Letters[0][0].first().toString();


    str_LetterVector.append('I');
    addLine2Letter(I,QVector2D(35,0), QVector2D(100,35),1);
    m_Letters.append(I);


    QVector <QVector3D> test1,test2;
    test1 ={QVector3D(4,2,2),QVector3D(0,0,0)};
    test2 = {QVector3D(0,0,0),QVector3D(1,0,0)};

    for (auto it = test2.rbegin(); it!= test2.rend(); ++it) {
        qDebug() << "TEST" <<*it;
        test1.prepend(*it);
    }
    // test1.prepend(test2);

    qDebug()<<"test1"<<test1;
    // qDebug()<<QVector2D(1,1);


}
void Letters::addLine2Letter(QVector <QVariantList>& letter, QVector2D startPt,QVector2D endPt,float factor)
{
    QVariantList list;
    list << LINE << startPt * factor << endPt * factor;
    letter.append(list);
}

void Letters::addCircle2Letter(QVector <QVariantList>& letter,float radius, QVector2D centerPt,QVector2D angleRange, float factor)
{
    QVariantList list;
    list << CIRCLE <<radius *factor << centerPt * factor << angleRange;
    letter.append(list);
}

int Letters::getLetterPosInVec(QChar char_letter)
{
    int position=-1;
    for (int i=0; i < str_LetterVector.length(); i++)
    {
        if(char_letter==str_LetterVector[i]){position = i;}
    }
    return position;

}
