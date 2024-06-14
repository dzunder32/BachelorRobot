#include "letters.h"

Letters::Letters()
{
    scalingFactor = 1;
    createLetters();
}

void Letters::createLetters()
{
    F = {{QVector3D(0,0,0),QVector3D(0,100,0)},
         {QVector3D(0,100,0),QVector3D(100,100,0)},
         {QVector3D(0,50,0),QVector3D(100,50,0)}};
}

