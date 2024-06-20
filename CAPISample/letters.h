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
    // QVector <QVariantList> F,B;
    QVector <QVariantList> F,B,I;
    QVector <QVector <QVariantList>> m_Letters;
    QVector <QChar> str_LetterVector;

    QVector <QVariantList> getLetterB(){return B;}

    int getLetterPosInVec(QChar str_letter);
private:

    void createLetters();
    float scalingFactor;

    void addLine2Letter(QVector<QVariantList> &letter, QVector2D startPt, QVector2D endPt, float factor);
    void addCircle2Letter(QVector<QVariantList> &letter, float radius, QVector2D centerPt, QVector2D angleRange, float factor);
};

#endif // LETTERS_H
