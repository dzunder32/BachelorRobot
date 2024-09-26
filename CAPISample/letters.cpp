#include "letters.h"

Letters::Letters()
{
    scalingFactor = 1;
    LetterSizeX = 60;
    LetterSizeY = 100;
    createLetters();

}

void Letters::createLetters()
{
    float factorB =  LetterSizeY/3.5;
    float factorC =  LetterSizeY/2.5;

    str_LetterVector.append('A');
    addLine2Letter(A,QVector2D(0,0), QVector2D(1,3.5),factorB);
    addLine2Letter(A,QVector2D(1,3.5), QVector2D(2,0),factorB);
    addLine2Letter(A,QVector2D(0.4,1.4), QVector2D(1.6,1.4),factorB);
    m_Letters.append(A);

    str_LetterVector.append('B');
    addLine2Letter(B, QVector2D(0,0), QVector2D(1,0),factorB);
    addCircle2Letter(B,1 , QVector2D(1,1),QVector2D(-90,90),factorB);
    addLine2Letter(B, QVector2D(1,2), QVector2D(0,2),factorB);
    addLine2Letter(B, QVector2D(0,2), QVector2D(1,2),factorB);
    addCircle2Letter(B,0.75, QVector2D(1,2.75),QVector2D(-90,90),factorB);
    addLine2Letter(B, QVector2D(1,3.5), QVector2D(0,3.5),factorB);
    addLine2Letter(B, QVector2D(0,3.5), QVector2D(0,0),factorB);
    m_Letters.append(B);

    str_LetterVector.append('C');
    addLine2Letter(C,QVector2D(1.5,2.5), QVector2D(1,2.5),factorC);
    addCircle2Letter(C,1 , QVector2D(1,1.5),QVector2D(90,180),factorC);
    addLine2Letter(C,QVector2D(0,1.5), QVector2D(0,1),factorC);
    addCircle2Letter(C,1 , QVector2D(1,1),QVector2D(180,270),factorC);
    addLine2Letter(C,QVector2D(1,0), QVector2D(1.5,0),factorC);
    m_Letters.append(C);

    str_LetterVector.append('D');
    addLine2Letter(D,QVector2D(0,0), QVector2D(0.5,0),factorC);
    addCircle2Letter(D,1 , QVector2D(0.5,1),QVector2D(-90,0),factorC);
    addLine2Letter(D,QVector2D(1.5,1), QVector2D(1.5,1.5),factorC);
    addCircle2Letter(D,1 , QVector2D(0.5,1.5),QVector2D(0,90),factorC);
    addLine2Letter(D,QVector2D(0.5,2.5), QVector2D(0,2.5),factorC);
    addLine2Letter(D,QVector2D(0,2.5), QVector2D(0,0),factorC);
    m_Letters.append(D);

    str_LetterVector.append('I');
    addLine2Letter(I,QVector2D(35,0), QVector2D(35,100),1);
    m_Letters.append(I);

    str_LetterVector.append('G');
//    addLine2Letter(G,QVector2D(2,2.5), QVector2D(2,2.5),factorB);
    addCircle2Letter(G,1 , QVector2D(1,2.5),QVector2D(0,180),factorB);
    addLine2Letter(G,QVector2D(0,2.5), QVector2D(0,1),factorB);
    addCircle2Letter(G,1 , QVector2D(1,1),QVector2D(180,360),factorB);
    addLine2Letter(G,QVector2D(2,1), QVector2D(2,1.5),factorB);
    addLine2Letter(G,QVector2D(2,1.5), QVector2D(1,1.5),factorB);
    m_Letters.append(G);

    str_LetterVector.append('J');
    addLine2Letter(J,QVector2D(0,1.5), QVector2D(0,1),factorB);
    addCircle2Letter(J,1 , QVector2D(1,1),QVector2D(180,360),factorB);
    addLine2Letter(J,QVector2D(2,1), QVector2D(2,3.5),factorB);
    addLine2Letter(J,QVector2D(2,3.5), QVector2D(0,3.5),factorB);
    m_Letters.append(J);

    str_LetterVector.append('P');
    addLine2Letter(P, QVector2D(0,2), QVector2D(1,2),factorB);
    addCircle2Letter(P,0.75, QVector2D(1,2.75),QVector2D(-90,90),factorB);
    addLine2Letter(P, QVector2D(1,3.5), QVector2D(0,3.5),factorB);
    addLine2Letter(P, QVector2D(0,3.5), QVector2D(0,0),factorB);
    m_Letters.append(P);

    str_LetterVector.append('R');
    R = P;
    addLine2Letter(R, QVector2D(1,2), QVector2D(2,0),factorB);
    m_Letters.append(R);

    str_LetterVector.append('O');
    addLine2Letter(O,QVector2D(2,1), QVector2D(2,2.5),factorB);
    addCircle2Letter(O,1 , QVector2D(1,2.5),QVector2D(0,180),factorB);
    addLine2Letter(O,QVector2D(0,2.5), QVector2D(0,1),factorB);
    addCircle2Letter(O,1 , QVector2D(1,1),QVector2D(180,360),factorB);
    m_Letters.append(O);

    str_LetterVector.append('Q');
    Q = O;
    addLine2Letter(Q,QVector2D(1,1), QVector2D(2,0),factorB);
    m_Letters.append(Q);

    str_LetterVector.append('S');
    addLine2Letter(S,QVector2D(0,0), QVector2D(1.125,0),factorB);
    addCircle2Letter(S,0.875 , QVector2D(1.125,0.875),QVector2D(-90,90),factorB);
    addLine2Letter(S,QVector2D(2,3.5), QVector2D(0.875,3.5),factorB);
    addCircle2Letter(S,0.875,QVector2D(0.875,2.625), QVector2D(90,270),factorB);
    addLine2Letter(S,QVector2D(0.875,1.75), QVector2D(1.125,1.75),factorB);
    m_Letters.append(S);

    str_LetterVector.append('U');
    addLine2Letter(U,QVector2D(0,3.5), QVector2D(0,1),factorB);
    addCircle2Letter(U,1 , QVector2D(1,1),QVector2D(180,360),factorB);
    addLine2Letter(U,QVector2D(2,1), QVector2D(2,3.5),factorB);
    m_Letters.append(U);

    str_LetterVector.append('F');
    addLine2Letter(F,QVector2D(2,3.5), QVector2D(0,3.5),factorB);
    addLine2Letter(F,QVector2D(0,3.5), QVector2D(0,1.75),factorB);
    addLine2Letter(F,QVector2D(0,1.75), QVector2D(1,1.75),factorB);
    addLine2Letter(F,QVector2D(0,1.75), QVector2D(0,0),factorB);
    m_Letters.append(F);

    E = F;
    str_LetterVector.append('E');
    addLine2Letter(E,QVector2D(0,0), QVector2D(2,0),factorB);
    m_Letters.append(E);

    str_LetterVector.append('H');
    addLine2Letter(H,QVector2D(0,3.5), QVector2D(0,0),factorB);
    addLine2Letter(H,QVector2D(2,3.5), QVector2D(2,0),factorB);
    addLine2Letter(H,QVector2D(0,1.75), QVector2D(2,1.75),factorB);
    m_Letters.append(H);

    str_LetterVector.append('K');
    addLine2Letter(K,QVector2D(0,3.5), QVector2D(0,0),factorB);
    addLine2Letter(K,QVector2D(1.5,3.5), QVector2D(0,1.75),factorB);
    addLine2Letter(K,QVector2D(0,1.75), QVector2D(2,0),factorB);
    m_Letters.append(K);

    str_LetterVector.append('V');
    addLine2Letter(V,QVector2D(0,3.5), QVector2D(1,0),factorB);
    addLine2Letter(V,QVector2D(1,0), QVector2D(2,3.5),factorB);
    m_Letters.append(V);

    str_LetterVector.append('L');
    addLine2Letter(L,QVector2D(0,3.5), QVector2D(0,0),factorB);
    addLine2Letter(L,QVector2D(0,0), QVector2D(2,0),factorB);
    m_Letters.append(L);

    str_LetterVector.append('T');
    addLine2Letter(T,QVector2D(0,3.5), QVector2D(2,3.5),factorB);
    addLine2Letter(T,QVector2D(1,3.5), QVector2D(1,0),factorB);
    m_Letters.append(T);


    str_LetterVector.append('N');
    addLine2Letter(N,QVector2D(0,0), QVector2D(0,3.5),factorB);
    addLine2Letter(N,QVector2D(0,3.5), QVector2D(2,0),factorB);
    addLine2Letter(N,QVector2D(2,0), QVector2D(2,3.5),factorB);
    m_Letters.append(N);

    str_LetterVector.append('W');
    addLine2Letter(W,QVector2D(0,3.5), QVector2D(0.25,0),factorB);
    addLine2Letter(W,QVector2D(0.25,0), QVector2D(1,1.5),factorB);
    addLine2Letter(W,QVector2D(1,1.5), QVector2D(1.75,0),factorB);
    addLine2Letter(W,QVector2D(1.75,0), QVector2D(2,3.5),factorB);
    m_Letters.append(W);

    str_LetterVector.append('M');
    addLine2Letter(M,QVector2D(0,0), QVector2D(0,3.5),factorB);
    addLine2Letter(M,QVector2D(0,3.5), QVector2D(1,1.75),factorB);
    addLine2Letter(M,QVector2D(1,1.75), QVector2D(2,3.5),factorB);
    addLine2Letter(M,QVector2D(2,3.5), QVector2D(2,0),factorB);
    m_Letters.append(M);

    str_LetterVector.append('X');
    addLine2Letter(X,QVector2D(0,3.5), QVector2D(2,0),factorB);
    addLine2Letter(X,QVector2D(0,0), QVector2D(2,3.5),factorB);
    m_Letters.append(X);

    str_LetterVector.append('Y');
    addLine2Letter(Y,QVector2D(0,3.5), QVector2D(1,1.5),factorB);
    addLine2Letter(Y,QVector2D(1,1.5), QVector2D(1,0),factorB);
    addLine2Letter(Y,QVector2D(1,1.5), QVector2D(2,3.5),factorB);
    m_Letters.append(Y);

    str_LetterVector.append('Z');
    addLine2Letter(Z,QVector2D(0,3.5), QVector2D(2,3.5),factorB);
    addLine2Letter(Z,QVector2D(2,3.5), QVector2D(0,0),factorB);
    addLine2Letter(Z,QVector2D(0,0), QVector2D(2,0),factorB);
    addLine2Letter(Z,QVector2D(0.5,1.75), QVector2D(1.5,1.75),factorB);
    m_Letters.append(Z);

    str_LetterVector.append('0');
    l_0 = O;
    addLine2Letter(l_0,QVector2D(0,1), QVector2D(2,2.5),factorB);
    m_Letters.append(l_0);

    str_LetterVector.append('1');
    addLine2Letter(l_1,QVector2D(0,2), QVector2D(1,3.5),factorB);
    addLine2Letter(l_1,QVector2D(1,3.5), QVector2D(1,0),factorB);
    m_Letters.append(l_1);

    str_LetterVector.append('2');
    addLine2Letter(l_2,QVector2D(2,0), QVector2D(0,0),factorB);
    addLine2Letter(l_2,QVector2D(0,0), QVector2D(0,0),factorB);
    addCircle2Letter(l_2,1 , QVector2D(1,2.5),QVector2D(-45,180),factorB);
    addLine2Letter(l_2,QVector2D(0,2.5), QVector2D(0,2.5),factorB);
    m_Letters.append(l_2);

    str_LetterVector.append('3');
    addLine2Letter  (l_3,QVector2D(0,0), QVector2D(1.125,0),factorB);
    addCircle2Letter(l_3,0.875 , QVector2D(1.125,0.875),QVector2D(-90,90),factorB);
    addLine2Letter  (l_3,QVector2D(1.125,1.75), QVector2D(0.8,1.75),factorB);
    addCircle2Letter(l_3,0.875 , QVector2D(1.125,2.625),QVector2D(-90,90),factorB);
    addLine2Letter  (l_3,QVector2D(1.125,3.5), QVector2D(0,3.5),factorB);
    m_Letters.append(l_3);

    str_LetterVector.append('4');
    addLine2Letter(l_4,QVector2D(1.5,0), QVector2D(1.5,3.5),factorB);
    addLine2Letter(l_4,QVector2D(2,1.5), QVector2D(0,1.5),factorB);
    addLine2Letter(l_4,QVector2D(0,1.5), QVector2D(0,3.5),factorB);
    m_Letters.append(l_4);

    str_LetterVector.append('5');
    addLine2Letter(l_5,QVector2D(0,0), QVector2D(1,0),factorB);
    addCircle2Letter(l_5,1 , QVector2D(1,1),QVector2D(-90,90),factorB);
    addLine2Letter(l_5,QVector2D(1,2), QVector2D(0,2),factorB);
    addLine2Letter(l_5,QVector2D(0,2), QVector2D(0,3.5),factorB);
    addLine2Letter(l_5,QVector2D(0,3.5), QVector2D(2,3.5),factorB);
    m_Letters.append(l_5);

    str_LetterVector.append('6');
    addLine2Letter(l_6,QVector2D(2,3.5), QVector2D(1.5,3.5),factorB);
//    addLine2Letter(l_6,QVector2D(2,3.5), QVector2D(1,3.5),factorB);
//    addCircle2Letter(l_6,1 , QVector2D(1,2.5),QVector2D(90,180),factorB);
    addCircle2Letter(l_6,1.5 , QVector2D(1.5,2),QVector2D(90,180),factorB);
    addLine2Letter(l_6,QVector2D(0,2), QVector2D(0,1),factorB);
    addCircle2Letter(l_6,1 , QVector2D(1,1),QVector2D(180,570),factorB);
    addLine2Letter(l_6,QVector2D(0,1), QVector2D(0,1),factorB);
    m_Letters.append(l_6);

    str_LetterVector.append('7');
    addLine2Letter(l_7,QVector2D(0,3.5), QVector2D(2,3.5),factorB);
    addLine2Letter(l_7,QVector2D(2,3.5), QVector2D(0,0),factorB);
    m_Letters.append(l_7);

    str_LetterVector.append('8');
    addLine2Letter(l_8,QVector2D(0.875,0), QVector2D(1.125,0),factorB);
    addCircle2Letter(l_8,0.875 , QVector2D(1.125,0.875),QVector2D(-90,90),factorB);
    addLine2Letter(l_8,QVector2D(1.125,1.75), QVector2D(0.875,1.75),factorB);
    addCircle2Letter(l_8,0.875 , QVector2D(0.875,0.875),QVector2D(90,270),factorB);
    addLine2Letter(l_8,QVector2D(1.125,1.75), QVector2D(1.125,1.75),factorB);
    addCircle2Letter(l_8,0.875 , QVector2D(1.125,2.625),QVector2D(-90,90),factorB);
    addLine2Letter(l_8,QVector2D(1.125,3.5), QVector2D(0.875,3.5),factorB);
    addCircle2Letter(l_8,0.875 , QVector2D(0.875,2.625),QVector2D(90,270),factorB);
    m_Letters.append(l_8);

    str_LetterVector.append('9');
    addLine2Letter(l_9,QVector2D(0,1), QVector2D(0,1),factorB);
    addCircle2Letter(l_9,1 , QVector2D(1,1),QVector2D(180,360),factorB);
    addLine2Letter(l_9,QVector2D(2,1), QVector2D(2,2.5),factorB);
    addCircle2Letter(l_9,1 , QVector2D(1,2.5),QVector2D(0,360),factorB);
    addLine2Letter(l_9,QVector2D(2,2.5), QVector2D(2,2.5),factorB);
    m_Letters.append(l_9);

    changed_Letters = m_Letters;

}

QVector <QVariantList> Letters::getLetterVec(QChar char_letter)
{
    int pos = getLetterPosInVec(char_letter);
    QVariantList errorList;
    errorList << -1;
    QVector <QVariantList> returnList;

    if(pos==-1)
    {returnList.append(errorList);qDebug()<<"Mothernature";}
    else
    {returnList = changed_Letters[pos];}

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

void Letters::changeLetterSize(float factor)
{
    changed_Letters = m_Letters;
    resetLetterSize();
    LetterSizeX *= factor;
    LetterSizeY *= factor;

    for(auto& list_vec:changed_Letters)
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
