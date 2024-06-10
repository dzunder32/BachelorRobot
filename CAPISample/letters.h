#ifndef LETTERS_H
#define LETTERS_H

#include <QVector>
#include <QVector3D>

class Letters
{
public:
    Letters();
    QVector <QVector <QVector3D>> F;

private:

    void createLetters();
    float scalingFactor;
};

#endif // LETTERS_H
