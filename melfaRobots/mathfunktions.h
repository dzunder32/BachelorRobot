#include <QMatrix4x4>
#include "math.h"
#include "QtMath"

const QMatrix4x4 MatrixTranslationX(double val);
const QMatrix4x4 MatrixTranslationY(double val);
const QMatrix4x4 MatrixTranslationZ(double val);
const QMatrix4x4 MatrixRotationX(double val);
const QMatrix4x4 MatrixRotationY(double va);
const QMatrix4x4 MatrixRotationZ(double val);

void RotatateT(QMatrix4x4 *trans, int axis, double alpha);
QVector3D CalculateXYZ(QMatrix4x4 m);
QMatrix4x4 InversT(QMatrix4x4 t);
QMatrix4x4 CalculateT(double x, double y, double z, double EW1, double EW2, double EW3);
QVector3D CalculateEw(QMatrix4x4 mat);
QMatrix4x4 CalculateTFromJoint(double q, double alpha, double a, double d);

