#ifndef LETTERS_H
#define LETTERS_H

#include <QVector>
#include <QVector3D>
#include <QVariantList>
#include <QDebug>
#include <QVector2D>

#define POINT 1
#define LINE 2
#define CIRCLE 3

class Letters
{
public:
    Letters();
    QVector <QVariantList> F,B,I,C,A,D,G,O,J,P,R,Q,S,U,E,H,K,V,L,T,M,N,W,X,Y,Z;
    QVector <QVector <QVariantList>> m_Letters,changed_Letters;
    QVector <QChar> str_LetterVector;

    float LetterSizeX,LetterSizeY;
    int getLetterPosInVec(QChar str_letter);
    QVector<QVariantList> getLetterVec(QChar char_letter);
    void shiftLetter(QVector<QVariantList> &letter, QVector2D shiftVec);
    void changeLetterSize(/*QVector<QVariantList> &letter, */float factor);
private:

    float scalingFactor;
    void createLetters();

    void addLine2Letter(QVector<QVariantList> &letter, QVector2D startPt, QVector2D endPt, float factor);
    void addCircle2Letter(QVector<QVariantList> &letter, float radius, QVector2D centerPt, QVector2D angleRange, float factor);
    void resetLetterSize(){LetterSizeX = 70;LetterSizeY = 100;}
};

#endif // LETTERS_H
