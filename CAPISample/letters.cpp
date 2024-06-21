#include "letters.h"

Letters::Letters()
{
    scalingFactor = 1;
    LetterSizeX = 70;
    LetterSizeY = 100;
    createLetters();
}

void Letters::createLetters()
{
    F = {{QVector3D(0,0,0),QVector3D(1,0,0)},
         {QVector3D(0,100,0),QVector3D(100,100,0)},
         {QVector3D(0,50,0),QVector3D(100,50,0)}};

    float factorB =  LetterSizeY/3.5;

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
    addLine2Letter(I,QVector2D(35,0), QVector2D(35,100),1);
    m_Letters.append(I);

}

QVector <QVariantList> Letters::getLetterVec(QChar char_letter)
{
    int pos = getLetterPosInVec(char_letter);
    QVariantList errorList;
    errorList << "no Letter found";
    QVector <QVariantList> returnList;

    if(pos==-1)
    {returnList.append(errorList);}
    else
    {returnList = m_Letters[pos];}

    return returnList;

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

void Letters::shiftLetter(QVector <QVariantList> &letter, QVector2D shiftVec)
{
    for (QVariantList &list:letter)
    {
        if(list.first()==LINE){
            list[1] = list[1].value<QVector2D>() + shiftVec;
            list[2] = list[2].value<QVector2D>() + shiftVec;
        }
        else{
            list[2] = list[2].value<QVector2D>() + shiftVec;
        }
    }
}

void Letters::changeLetterSize(/*QVector <QVariantList> &letter,*/ float factor)
{
    LetterSizeX *= factor;
    LetterSizeY *= factor;

    for(auto& list_vec:m_Letters)
    {
        for (QVariantList &list:list_vec)
        {
            if(list.first()==LINE){
                list[1] = list[1].value<QVector2D>() * factor;
                list[2] = list[2].value<QVector2D>() * factor;
            }else{
                list[1] = list[1].value<float>()     * factor;
                list[2] = list[2].value<QVector2D>() * factor;
            }
        }
    }
}
