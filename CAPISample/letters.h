#ifndef LETTERS_H
#define LETTERS_H

#include <QVector>
#include <QVector3D>

class Letters
{
public:
    Letters();
    // QVector <QVariantList> F,B;
    QVector <QVector<QVector3D>> F,B;

private:

    void createLetters();
    float scalingFactor;

};

#endif // LETTERS_H
